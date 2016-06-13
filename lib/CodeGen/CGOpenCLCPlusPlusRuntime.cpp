//=== CGOpenCLCPlusPlusRuntime.cpp - Interface to OCLC++ Runtime *- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//
//
// Copyright (c) 2016 The Khronos Group Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and/or associated documentation files (the
// "Materials"), to deal in the Materials without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Materials, and to
// permit persons to whom the Materials are furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Materials.
//
// THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
//
//===----------------------------------------------------------------------===//


#include "CGOpenCLCPlusPlusRuntime.h"

#include "CodeGenFunction.h"

#include "clang/AST/ExprCXX.h"

#include "llvm/ADT/DenseSet.h"
#include "llvm/ADT/Hashing.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/Twine.h"
#include "llvm/IR/Metadata.h"
#include "llvm/Support/FileUtilities.h"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>


using namespace clang;
using namespace CodeGen;


/// \brief Gets external LLVM variable that stores information about local
///        linear identifier in OpenCL C++.
///
/// If variable exists, it is fetched from LLVM module. If it does not exist,
/// it is created.
///
/// \param CGM Module code generator from which variable will be fetched.
static llvm::GlobalValue *getLocalLinearIdVar(CodeGenModule &CGM) {
  // Name and type of local linear identifier variable in OpenCL C++.
  static const std::string LLIdName =
      "_ZN2cl7__spirv23VarLocalInvocationIndexE";
  llvm::IntegerType * const LLIdTy = CGM.SizeTy;


  auto LLIdVar = CGM.GetGlobalValue(LLIdName);
  if (LLIdVar == nullptr) {
    // Create the external variable with local linear identifier.
    LLIdVar = new llvm::GlobalVariable(CGM.getModule(), LLIdTy, true,
                                       llvm::GlobalValue::ExternalLinkage,
                                       nullptr, LLIdName, nullptr,
                                       llvm::GlobalValue::NotThreadLocal,
                                       CGM.getContext().getTargetAddressSpace(
                                           LangAS::openclcpp_global), true);
  }
  return LLIdVar;
}

/// \brief Gets LLVM function that creates full workgroup control barrier
///        on local memory (address space) in OpenCL C++.
///
/// If function exists, it is fetched from LLVM module. If it does not exist,
/// the declaration is created.
///
/// \param CGM Module code generator from which function will be fetched.
static llvm::Constant *getLocalMemCBarrier(CodeGenModule &CGM) {
  // Name and type of barrier function in OpenCL C++.
  static const std::string CBarrierFuncName =
      "_ZN2cl7__spirv16OpControlBarrierEjjj";
  llvm::Type *CBarrierFuncParamsTy[] = {
    CGM.Int32Ty,
    CGM.Int32Ty,
    CGM.Int32Ty
  };
  llvm::FunctionType * const CBarrierFuncTy =
      llvm::FunctionType::get(CGM.VoidTy, CBarrierFuncParamsTy, false);


  return CGM.CreateRuntimeFunction(CBarrierFuncTy, CBarrierFuncName,
                                   llvm::AttributeSet::get(
                                       CGM.getLLVMContext(),
                                       llvm::AttributeSet::FunctionIndex,
                                       llvm::Attribute::NoUnwind));
}

/// \brief Checks whether insert points are valid and equal.
///
/// \param LHS Left operand of comparision and verification.
/// \param RHS Right operand of comparision and verification.
/// \return true if both operands are set (valid) and equal; otherwise, false.
inline static bool isIPValidAndEqual(const CGBuilderTy::InsertPoint &LHS,
                                     const CGBuilderTy::InsertPoint &RHS) {
  return LHS.isSet() && RHS.isSet() &&
      LHS.getBlock() == RHS.getBlock() &&
      LHS.getPoint() == RHS.getPoint();
}

/// \brief Gets insert position (point) where additional initializers /
///        finalizers can be added to merge basic block.
///
/// \param MergeBlock Basic block where additional initializers / finalizers
///                   will be added. Function asserts if MergeBlock is invalid
///                   or does not have terminator.
/// \return Insert position for merged instructions.
inline static CGBuilderTy::InsertPoint getMergeInsertPoint(
    llvm::BasicBlock *MergeBlock) {
  assert(MergeBlock != nullptr && MergeBlock->getTerminator() != nullptr &&
         "Merge block must exist and be terminated.");

  return llvm::IRBuilderBase::InsertPoint(MergeBlock,
                                          --MergeBlock->getInstList().end());
}

/// \brief Gets position of last instruction added in builder.
///
/// \param Builder Code builder currently used in code generator.
/// \return Position of last instruction, or unset position if builder has
///         no position information or there is no instruction added yet.
inline static CGBuilderTy::InsertPoint getLastInstrPos(CGBuilderTy &Builder) {
  auto CurBB = Builder.GetInsertBlock();
  if (CurBB == nullptr || CurBB->getInstList().empty())
    return llvm::IRBuilderBase::InsertPoint();

  return llvm::IRBuilderBase::InsertPoint(CurBB,
                                          --CurBB->getInstList().end());
}


/// \brief Emits full workgroup control barrier call in function generated by
///        selected function code generator.
///
/// \param CGF Function code generator in which call to barrier will be
///            generated.
static void emitLocalMemCBarrier(CodeGenFunction &CGF) {
  // Default parameters for function call.
  llvm::Value *CBarrierParams[] = {
    llvm::ConstantInt::get(CGF.Int32Ty, 2),    // Workgorup
    llvm::ConstantInt::get(CGF.Int32Ty, 2),    // Workgorup
    llvm::ConstantInt::get(CGF.Int32Ty, 0x110) // WorkgorupMemory, SeqConsistent
  };


  auto CBarrier = getLocalMemCBarrier(CGF.CGM);
  CGF.EmitNounwindRuntimeCall(CBarrier, CBarrierParams);
}

namespace
{
  /// \brief Extended RAII guard for builder position and alloca insert point.
  class InsertPointAllocaGuard {
  public:
    /// \brief Creates RAII object that stores state of builder and
    ///        alloca insertion point.
    ///
    /// \param CGF Function code generator which state will be partially
    ///             guarded (builder insert position and alloca insert point.
    explicit InsertPointAllocaGuard(CodeGenFunction &CGF)
      : CGF(CGF), IPG(CGF.Builder), AllocaIP(CGF.AllocaInsertPt) {}

    /// \brief Restores (partially) state of guarded code generator.
    ~InsertPointAllocaGuard() {
      CGF.AllocaInsertPt = AllocaIP;
    }

    // Copy / move forbidden.
    InsertPointAllocaGuard(
        const InsertPointAllocaGuard &) LLVM_DELETED_FUNCTION;
    InsertPointAllocaGuard(InsertPointAllocaGuard &&) LLVM_DELETED_FUNCTION;
    InsertPointAllocaGuard & operator =(
        const InsertPointAllocaGuard &) LLVM_DELETED_FUNCTION;
    InsertPointAllocaGuard & operator =(
        InsertPointAllocaGuard &&) LLVM_DELETED_FUNCTION;
  private:
    /// Guarded function code generator.
    CodeGenFunction &CGF;
    /// Guard for insert point in builder.
    CGBuilderTy::InsertPointGuard IPG;
    /// Old value for alloca insertion point.
    llvm::AssertingVH<llvm::Instruction> AllocaIP;
  };
}

/// \brief Move "alloca"'s and "alloca" insert position to the new basic block.
///
/// Changes builder position if necessary (if points to "alloca" block).
///
/// \param CGF   Function code generator in which "alloca"s and "alloca" IP will
///              be moved (if possible).
/// \param NewBB Basic block to which "alloca"'s and "alloca" IP will be moved.
///              Asserts if NewBB is nullptr or it is not attached to function
///              generated by CGF.
///
/// \return true if operation succeeded; otherwise, false. The function is not
///         modified, if operation failed.
static bool moveAllocasAndAllocaInsertPoint(CodeGenFunction &CGF,
                                            llvm::BasicBlock *NewBB) {
  if (NewBB == nullptr || NewBB->getParent() != CGF.CurFn) {
    assert(false && "Selected BB is not attached to generated function.");
    return false;
  }

  llvm::Instruction *AllocaIP = CGF.AllocaInsertPt;
  // No "alloca" IP -> nothing to move.
  if (AllocaIP == nullptr)
    return true;
  // "alloca" already in selected block -> nothing to move.
  auto *AllocaBB = AllocaIP->getParent();
  if (NewBB == AllocaBB)
    return true;
  // Find first "alloca" from start of block to (and excluding) "alloca" IP.
  llvm::BasicBlock::iterator AllocaB(AllocaIP), AllocaE(AllocaIP);
  for (auto B = AllocaBB->begin(), E = AllocaE; B != E; ++B) {
    if (llvm::isa<llvm::AllocaInst>(*B)) {
      AllocaB = B;
      break;
    }
  }
  // If there are different instructions than "alloca" inside found range,
  // fail move.
  for (auto B = AllocaB, E = AllocaE; B != E; ++B) {
    if (!llvm::isa<llvm::AllocaInst>(*B))
      return false;
  }
  ++AllocaE;

  // Test whether IRBuilder needs to be repositioned.
  auto &Builder = CGF.Builder;
  llvm::IRBuilderBase::InsertPoint BuilderOldIP = Builder.saveIP(),
                                   BuilderNewIP;
  if (BuilderOldIP.isSet() && BuilderOldIP.getBlock() == AllocaBB) {
    for (auto B = AllocaB, E = AllocaE; B != E; ++B) {
      if (B == BuilderOldIP.getPoint()) {
        BuilderNewIP = llvm::IRBuilderBase::InsertPoint(NewBB, B);
        break;
      }
    }
  }

  // Move instructions and builder if necessary.
  NewBB->getInstList().splice(NewBB->end(), AllocaBB->getInstList(),
                              AllocaB, AllocaE);
  if (BuilderNewIP.isSet())
    Builder.restoreIP(BuilderNewIP);
  return true;
}

/// \brief Emits "alloca" insert position and registers it into code generator.
///
/// \param CGF Function code generator in which dummy "alloca" insert position
///            will be created.
static void emitAllocaInsertPoint(CodeGenFunction &CGF) {
  auto &Builder = CGF.Builder;
  auto CurBB = Builder.GetInsertBlock();

  // Create a marker to make it easy to insert allocas into the entryblock
  // later.  Don't create this with the builder, because we don't want it
  // folded.
  llvm::Value *Undef = llvm::UndefValue::get(CGF.Int32Ty);
  CGF.AllocaInsertPt = new llvm::BitCastInst(Undef, CGF.Int32Ty, "", CurBB);
  if (Builder.isNamePreserving())
    CGF.AllocaInsertPt->setName("allocapt");
}

/// \brief Cleans-up dummy "alloca" insert point (if it differs from standard
///        one).
///
/// \param CGF      Function code generator in which dummy "alloca" insert
///                 position resides.
/// \param AllocaIP Handle to "alloca" insert position that will be cleaned up.
static void cleanupAllocaInsertPoint(
    CodeGenFunction &CGF,
    llvm::AssertingVH<llvm::Instruction> &AllocaIP) {
  llvm::Instruction *AllocaI = AllocaIP;
  llvm::Instruction *CGFAllocaI = CGF.AllocaInsertPt;
  if (AllocaI != nullptr && AllocaI != CGFAllocaI) {
    AllocaIP = nullptr;
    AllocaI->eraseFromParent();
  }
}

/// \brief Checks whether currently generated function is empty or contains only
///        standard "alloca" entries.
///
/// \param CGF Function code generator to test.
/// \return true if function is empty or contains only alloca entries generated
///         at "alloca" pointer (will be empty if finalized at this point);
///         otherwise, false.
static bool isEmptyOrAllocaFunc(const CodeGenFunction &CGF) {
  const auto *Fn = CGF.CurFn;
  if (Fn->empty())
    return true;

  const llvm::Instruction *AllocaIP = CGF.AllocaInsertPt;
  const auto &EntryBB = Fn->getEntryBlock();
  if (Fn->size() != 1 || (!EntryBB.empty() && (AllocaIP == nullptr ||
                                               &EntryBB.back() != AllocaIP))) {
    return false;
  }

  // Ensure that all instructions are "alloca"s (some runtimes do different
  // things around "alloca").
  for (const auto &I : EntryBB) {
    if (&I != AllocaIP && !llvm::isa<llvm::AllocaInst>(I))
      return false;
  }
  return true;
}

/// \brief Emits basic block before entry basic block in the function.
///
/// Creates basic block and emits it before entry basic block, if necessary.
/// If, during creation, builder position is changed and needs to be restored
/// later, the guard with old insert position of builder is returned and,
/// additionally, original entry basic block.
///
/// \param CGF Function code generator in which entry block will be generated.
/// \return Pair with following values:
///          - first  - original entry basic block, or nullptr if current
///                     entry basic block is reused or there was no entry block.
///                     It can be used to create branch to original entry at
///                     finish of emitted block.
///          - second - builder insert guard with original position (to restore
///                     later).
///                     Guard can be empty, if entry basic block is reused
///                     or there was no entry block (freshly created in empty
///                     body).
static std::pair<llvm::BasicBlock *,
                 std::unique_ptr<InsertPointAllocaGuard>>
emitBlockBeforeFuncEntry(CodeGenFunction &CGF) {
  typedef std::unique_ptr<InsertPointAllocaGuard> IPGTy;

  auto Fn = CGF.CurFn;
  auto &Builder = CGF.Builder;
  assert(Fn != nullptr && "Function code generator does not have function.");

  // No body or alloca handle -> assert and return.
  llvm::Instruction *AllocaIP = CGF.AllocaInsertPt;
  if (Fn->empty() || AllocaIP == nullptr) {
    assert(false && "Malformed function base. StartFunction was not used?");
    return std::make_pair(nullptr, IPGTy());
  }
  auto EntryBB = &Fn->getEntryBlock();
  // Empty single entry block -> no job to do; there is no need to restore
  //                             the builder position.
  if (isEmptyOrAllocaFunc(CGF)) {
    // Assume that builder is in entry block. The following should be true:
    // Builder.SetInsertPoint(EntryBB);
    return std::make_pair(nullptr, IPGTy());
  }

  // New basic block needed -> create new basic block and attach it in front,
  //                           move alloca's and alloca pointer (if possible)
  //                           or create new alloca pointer to handle temporary
  //                           allocas, builder position needs to be restored.
  auto PreEntryBB = CGF.createBasicBlock("entry.localmem.pre", Fn, EntryBB);
  bool AllocaIPMoved = moveAllocasAndAllocaInsertPoint(CGF, PreEntryBB);

  IPGTy RetIPG(new InsertPointAllocaGuard(CGF));

  Builder.SetInsertPoint(PreEntryBB);
  if (!AllocaIPMoved)
    emitAllocaInsertPoint(CGF);
  return std::make_pair(EntryBB, std::move(RetIPG));
}

/// \brief Emits into function calls to destructor stubs (in order they are in
///        collection).
///
/// \param CGF       Function code generator in which calls will be generated.
/// \param DtorStubs Ordered collection of destruction stubs to which calls
///                  will be emitted.
static void emitDtorStubNounwindCalls(
    CodeGenFunction &CGF,
    llvm::ArrayRef<llvm::Function *> DtorStubs) {
  for (auto DtorStub : DtorStubs) {
    if (DtorStub != nullptr) {
      // These functions must be "noexcept". Ensuring that.
      DtorStub->setDoesNotThrow();
      CGF.EmitNounwindRuntimeCall(DtorStub);
    }
  }
}

/// \brief Checks whether specified function is no-op (no-operation) function.
///
/// Function which do not return anything and which does nothing except
/// calling/invoking other functions that also do nothing is considered to be
/// no-op function. Following simple heuristic is implemented:
/// - Function declaration (without body) or intrinsic is never considered
///   to be no-op function.
/// - Empty function is considered always to be no-op function.
/// - Function which only contains basic block(s) with "call"/"invoke" of other
///   functions that are no-op and with (optional) "ret" terminator is also
///   considered to be no-op function, but only if return value is discarded
///   on top/root level of recurse scanning.
/// - Other functions are not considered to be no-op.
///
/// If method detects infinite resursion, assert is generated and function
/// is not considered to be no-op.
///
/// This is helper overload used for recustion. Please use second overload
/// of this function (isNoOperationFunction(const llvm::Function *)). The helper
/// does not test return values.
///
/// \param Fn         Tested function.
/// \param VisitedFns Collection of state of the function visit during scan.
///                   Keys are visited/scanned functions; value indicates
///                   whether scan is in-progress (false) or was finished (true).
///                   true value also indicates that function is no-op function
///                   (when function is not no-op, short-circuiting is used).
/// \return true if function is no-op function; otherwise, false.
static bool isNoOperationFunction(
    const llvm::Function *Fn,
    llvm::DenseMap<const llvm::Function *, bool> &VisitedFns) {
  // No function is assumed to be always no-op.
  if (Fn == nullptr)
    return true;
  // Function declaration or intrinsic is assumed to be never no-op.
  if (Fn->isDeclaration() || Fn->isIntrinsic())
    return false;

  // Check whether function was already visited. If so, return visit result.
  // Due to short-circuiting nature of scanning (for false result), the "false"
  // value in VisitedFns is used to mark that the selected function is currently
  // being processed (true - no-op function; false - function is being scanned).
  auto VisitedFn = VisitedFns.find(Fn);
  if (VisitedFn != VisitedFns.end()) {
    assert(VisitedFn->second &&
           "Function is being visited again during scan of the same function. "
           "Infinite recursion?");
    return VisitedFn->second;
  }
  // Mark function as being processed.
  VisitedFns.insert(std::make_pair(Fn, false));

  // Recursively check body of function (short-circuit "false" result).
  // In no-op function we allow only:
  // - direct call to no-op function
  // - direct invoke to no-op function
  // - ret block terminator (with optional value, as long as value is discarded
  //                         on highest level)
  // - (any basic block with any content after ret terminator - unreachable)
  for (const auto &BB : *Fn) {
    for (const auto &I : BB) {
      if (const auto CI = llvm::dyn_cast<llvm::CallInst>(&I)) {
        // Currently we assume that indirect function call is never no-op.
        if (CI->getCalledFunction() == nullptr)
          return false;
        if (!isNoOperationFunction(CI->getCalledFunction(), VisitedFns))
          return false;
      }
      else if (const auto II = llvm::dyn_cast<llvm::InvokeInst>(&I)) {
        // Currently we assume that indirect function invoke is never no-op.
        if (II->getCalledFunction() == nullptr)
          return false;
        if (!isNoOperationFunction(II->getCalledFunction(), VisitedFns))
          return false;
      }
      else if (llvm::dyn_cast<llvm::ReturnInst>(&I)) {
        VisitedFns[Fn] = true;
        return true;
      }
      else
        return false;
    }
  }

  // Block without terminator case...
  VisitedFns[Fn] = true;
  return true;
}

/// \brief Checks whether specified function is no-op (no-operation) function.
///
/// Function which do not return anything and which does nothing except
/// calling/invoking other functions that also do nothing is considered to be
/// no-op function. Following simple heuristic is implemented:
/// - Function declaration (without body) or intrinsic is never considered
///   to be no-op function.
/// - Empty function is considered always to be no-op function.
/// - Function which only contains basic block(s) with "call"/"invoke" of other
///   functions that are no-op and with (optional) "ret" terminator is also
///   considered to be no-op function, but only if return value is discarded
///   on top/root level of recurse scanning.
/// - Other functions are not considered to be no-op.
///
/// If method detects infinite resursion, assert is generated and function
/// is not considered to be no-op.
///
/// \param Fn Tested function.
/// \return true if function is no-op function; otherwise, false.
inline static bool isNoOperationFunction(const llvm::Function *Fn) {
  llvm::DenseMap<const llvm::Function *, bool> VisitedFns;
  // No function is assumed to be always no-op.
  if (Fn == nullptr)
    return true;

  // Recursively check function.
  if (!isNoOperationFunction(Fn, VisitedFns))
    return false;
  // Check whether return value on highest level is discarded.
  return Fn->getFunctionType()->getReturnType()->isVoidTy();
}


/// \brief Extracts and orders initialization functions from prioritized
///        structor list.
///
/// \param CtorFuncs List of initialization/finalization functions (prioritized
///                  structor list) to order.
/// \return          Ordered list of initialization function to call, in order
///                  of C++ initialization.
///                  List must be reversed when used to order finalization
///                  functions.
static std::vector<llvm::Function *> extractAndOrderInitFuncs(
    CodeGenModule::CtorList CtorFuncs) {
  if (CtorFuncs.empty())
    return std::vector<llvm::Function *>();

  // Sort by priority, but do not change order of elements with the same
  // priority.
  std::stable_sort(CtorFuncs.begin(), CtorFuncs.end(),
                   [](const CodeGenModule::Structor &Lhs,
                      const CodeGenModule::Structor &Rhs) {
    return Lhs.Priority < Rhs.Priority;
  });

  // Transform ordered list to functions.
  std::vector<llvm::Function *> OrderedInitFuncs;
  OrderedInitFuncs.reserve(CtorFuncs.size());
  for (const auto &CtorFunc : CtorFuncs) {
    if (auto F = llvm::dyn_cast_or_null<llvm::Function>(CtorFunc.Initializer))
      OrderedInitFuncs.push_back(F);
    else {
      assert(false &&
             "Global initializer/finalizer/destructor is not a function.");
    }
  }

  return OrderedInitFuncs; // NRVO should do copy/move elision.
}

static std::vector<llvm::Function *> eliminateNoOpFuncs(
    llvm::ArrayRef<llvm::Function *> Funcs) {
  if (Funcs.empty())
    return std::vector<llvm::Function *>();

  std::vector<llvm::Function *> FilteredFuncs;
  FilteredFuncs.reserve(Funcs.size());
  std::remove_copy_if(Funcs.begin(), Funcs.end(),
                      std::back_inserter(FilteredFuncs),
                      [] (const llvm::Function *F) {
    return isNoOperationFunction(F);
  });
  return FilteredFuncs; // NRVO should do copy/move elision.
}

/// \brief Creates initializer or finalizer kernel declaration and body.
///
/// Metadata for kernel is not generated by this function.
///
/// \param CGM        Module code generator where kernel will be generated.
/// \param NamePrefix Prefix for kernel name. Name will have format:
///                   {prefix}{hash of full file path (hex)}_{file name}
/// \param Funcs      Ordered list of functions that will be called in
///                   created kernel.
/// \return           Function that represents created kernel, or nullptr if
///                   there is no need to create kernel.
static llvm::Function *createInitOrDtorKernel(
    CodeGenModule &CGM,
    llvm::StringRef NamePrefix,
    llvm::ArrayRef<llvm::Function *> Funcs) {
  if (Funcs.empty())
    return nullptr;

  // Gather data for kernel name generation.
  llvm::SmallString<128> FileName;
  std::size_t FilePathHash;
  SourceManager &SM = CGM.getContext().getSourceManager();
  if (const FileEntry *MainFile = SM.getFileEntryForID(SM.getMainFileID())) {
    FileName = llvm::sys::path::filename(MainFile->getName());
    FilePathHash = llvm::hash_value(StringRef(MainFile->getName()));
  }
  else {
    FileName = SmallString<128>("<null>");
    FilePathHash = llvm::hash_combine_range(Funcs.begin(), Funcs.end());
  }

  // Create kernel function (external linkage, spir_kernel, noinline).
  llvm::FunctionType *KernelFuncTy = llvm::FunctionType::get(CGM.VoidTy, false);
  llvm::Function *KernelFunc = CGM.CreateGlobalInitOrDestructFunction(
      KernelFuncTy, llvm::Twine(NamePrefix)
                      .concat(Twine::utohexstr(FilePathHash))
                      .concat(Twine("_", FileName)));
  KernelFunc->setCallingConv(llvm::CallingConv::SPIR_KERNEL);
  KernelFunc->addFnAttr(llvm::Attribute::NoInline);
  KernelFunc->setLinkage(llvm::GlobalValue::ExternalLinkage);

  // Create kernel body.
  CodeGenFunction(CGM).GenerateCXXGlobalInitFunc(KernelFunc, Funcs);

  return KernelFunc;
}

/// \brief Emits error connected to unsupported feature.
///
/// \param CGM     Module code generator where error will be emitted.
/// \param D       Declaration which triggered error.
/// \param Message Description of an error.
inline static void emitUnsupportedFeatureError(CodeGenModule &CGM,
                                               const Decl *D,
                                               StringRef Message) {
  std::string Msg = "Unsupported SPIR-V feature: " + Message.str();
  CGM.Error(D != nullptr ? D->getLocation() : SourceLocation(), Msg);
}

/// \brief Emits error connected to unsupported feature.
///
/// \param CGM     Module code generator where error will be emitted.
/// \param Message Description of an error.
inline static void emitUnsupportedFeatureError(CodeGenModule &CGM,
                                               StringRef Message) {
  emitUnsupportedFeatureError(CGM, nullptr, Message);
}


bool CGOpenCLCPlusPlusRuntime::verifyInitDtorKernelSupport(
    llvm::ArrayRef<llvm::Function *> Funcs) {
  if (CGM.getLangOpts().SPIRVInitDtorKernelEnable || Funcs.empty())
    return true;

  for (auto Func : Funcs) {
    if (GlobalVarInitFuncs.find(Func) != GlobalVarInitFuncs.end()) {
      const auto &InitVars = GlobalVarInitFuncs[Func];
      for (auto InitVar : InitVars) {
        emitUnsupportedFeatureError(CGM, InitVar,
            "Entity requires initializer/finalizer kernel. In currently "
            "selected SPIR-V version initializer/finalizer kernels are "
            "not supported.");
        VerifyInitDtorKernelSupportErrorsEmitted = true;
      }
    }
  }

  if (!VerifyInitDtorKernelSupportErrorsEmitted) {
    emitUnsupportedFeatureError(CGM,
        "Some language constructs used in current translation unit require "
        "initializer/finalizer kernel. In currently selected SPIR-V version "
        "initializer/finalizer kernels are not supported.");
    VerifyInitDtorKernelSupportErrorsEmitted = true;
  }

  return false;
}

void CGOpenCLCPlusPlusRuntime::LocalMemLocalVarInitDtorEmitter::
emitVarCleanup() {
  CGBuilderTy &Builder = CGF.Builder;
  bool IsCBarrierAdjacent = isIPValidAndEqual(LastInitSectionCBarrierPos,
                                              getLastInstrPos(Builder));

  // Remove unnecessary barrier at the end if merge will be done to existing
  // section.
  // NOTE: The return should be checked in future, if kernel will be able
  //       to return something else than void.
  if (IsCBarrierAdjacent)
    LastInitSectionCBarrierPos.getPoint()->eraseFromParent();

  if (VarDtorStubs.empty())
    return;
  std::reverse(VarDtorStubs.begin(), VarDtorStubs.end());

  // Merge clean-up code to existing section for local init if possible.
  if (IsCBarrierAdjacent) {
    InsertPointAllocaGuard IPG(CGF);
    Builder.restoreIP(getMergeInsertPoint(LastInitSectionMergeBlock));

    emitDtorStubNounwindCalls(CGF, VarDtorStubs);
    return;
  }

  // Create section for separate clean-up.
  if (!isEmptyOrAllocaFunc(CGF))
    emitLocalMemCBarrier(CGF);

  auto LLIdLoad = Builder.CreateLoad(getLocalLinearIdVar(CGF.CGM));
  auto IsDtorLThread = Builder.CreateIsNull(LLIdLoad);

  auto LDtorBB = CGF.createBasicBlock("dtor.localmem.check");
  auto LEndBB = CGF.createBasicBlock("dtor.localmem.end");
  Builder.CreateCondBr(IsDtorLThread, LDtorBB, LEndBB);

  CGF.EmitBlock(LDtorBB);
  emitDtorStubNounwindCalls(CGF, VarDtorStubs);
  CGF.EmitBlock(LEndBB);
}

CGOpenCLCPlusPlusRuntime::LocalMemLocalVarInitDtorEmitter::
LocalMemLocalVarInitDtorEmitter(CodeGenFunction &CGF)
  : CGF(CGF), AllocaIP(CGF.AllocaInsertPt),
  InitSectionMergeBlock(nullptr), InitSectionEndBlock(nullptr),
  LastInitSectionMergeBlock(nullptr), LastInitSectionEndBlock(nullptr) {}

CGOpenCLCPlusPlusRuntime::LocalMemLocalVarInitDtorEmitter::
~LocalMemLocalVarInitDtorEmitter() {
  cleanupAllocaInsertPoint(CGF, AllocaIP);
  emitVarCleanup();
}

void CGOpenCLCPlusPlusRuntime::LocalMemLocalVarInitDtorEmitter::emit(
    const VarDecl &D,
    llvm::GlobalVariable *GV) {
  CGBuilderTy &Builder = CGF.Builder;

  // Merge multiple initializations into one if possible (adjacent sections).
  if (isIPValidAndEqual(LastInitSectionCBarrierPos,
                        getLastInstrPos(Builder))) {
    InsertPointAllocaGuard IPG(CGF);
    bool SameInitBlock = (LastInitSectionMergeBlock == InitSectionMergeBlock);
    Builder.restoreIP(getMergeInsertPoint(LastInitSectionMergeBlock));
    // NOTE: Removing terminator works as a workaround for some emits that
    //       expect only to append (not insert) code.
    Builder.GetInsertPoint()->eraseFromParent();
    Builder.SetInsertPoint(LastInitSectionMergeBlock);
    CGF.AllocaInsertPt = AllocaIP;

    CGF.EmitCXXGlobalVarDeclInit(D, GV, true /*ShouldPerformInit*/);
    LastInitSectionMergeBlock = Builder.GetInsertBlock();
    if (SameInitBlock)
      InitSectionMergeBlock = LastInitSectionMergeBlock;
    CGF.EmitBranch(LastInitSectionEndBlock);
    return;
  }

  llvm::Constant *Init = D.getInit() != nullptr
                             ? CGF.CGM.EmitConstantInit(D, &CGF)
                             : llvm::Constant::getNullValue(GV->getType());

  // Inline initialization of local-scope local memory (address space) variable.
  // This case is for custom initialization where we cannot quickly determine
  // whether we can move initialization to start of function.
  if (Init == nullptr) {
    // Create section for separate inline initialization.
    if (!isEmptyOrAllocaFunc(CGF))
      emitLocalMemCBarrier(CGF);

    auto LLIdLoad = Builder.CreateLoad(getLocalLinearIdVar(CGF.CGM));
    auto IsInitLThread = Builder.CreateIsNull(LLIdLoad);

    auto LInitBB = CGF.createBasicBlock("init.localmem.check");
    auto LEndBB = CGF.createBasicBlock("init.localmem.end");
    Builder.CreateCondBr(IsInitLThread, LInitBB, LEndBB);

    CGF.EmitBlock(LInitBB);
    CGF.EmitCXXGlobalVarDeclInit(D, GV, true /*ShouldPerformInit*/);
    LastInitSectionMergeBlock = Builder.GetInsertBlock();
    LastInitSectionEndBlock = LEndBB;
    CGF.EmitBlock(LEndBB);

    emitLocalMemCBarrier(CGF);
    LastInitSectionCBarrierPos = getLastInstrPos(Builder);
    return;
  }

  // Merge multiple initializations into one if possible (at function start).
  if (InitSectionMergeBlock != nullptr) {
      InsertPointAllocaGuard IPG(CGF);
      bool SameInitBlock = (LastInitSectionMergeBlock == InitSectionMergeBlock);
      Builder.restoreIP(getMergeInsertPoint(InitSectionMergeBlock));
      // NOTE: Removing terminator works as a workaround for some emits that
      //       expect only to append (not insert) code.
      Builder.GetInsertPoint()->eraseFromParent();
      Builder.SetInsertPoint(InitSectionMergeBlock);
      CGF.AllocaInsertPt = AllocaIP;

      CGF.EmitCXXGlobalVarDeclInit(D, GV, true /*ShouldPerformInit*/);
      InitSectionMergeBlock = Builder.GetInsertBlock();
      if (SameInitBlock)
        LastInitSectionMergeBlock = InitSectionMergeBlock;
      CGF.EmitBranch(InitSectionEndBlock);
      return;
  }

  // Create section for initialization at begining of function (new entry pt).
  auto PreEntryBBState = emitBlockBeforeFuncEntry(CGF);
  AllocaIP = CGF.AllocaInsertPt;

  auto LLIdLoad = Builder.CreateLoad(getLocalLinearIdVar(CGF.CGM));
  auto IsInitLThread = Builder.CreateIsNull(LLIdLoad);

  auto LInitBB = CGF.createBasicBlock("init.entry.localmem.check");
  auto LEndBB  = CGF.createBasicBlock("init.entry.localmem.end");
  Builder.CreateCondBr(IsInitLThread, LInitBB, LEndBB);

  CGF.EmitBlock(LInitBB);
  CGF.EmitCXXGlobalVarDeclInit(D, GV, true /*ShouldPerformInit*/);
  InitSectionMergeBlock = Builder.GetInsertBlock();
  InitSectionEndBlock = LEndBB;
  CGF.EmitBlock(LEndBB);

  emitLocalMemCBarrier(CGF);
  if (PreEntryBBState.first != nullptr)
    CGF.EmitBranch(PreEntryBBState.first);
  else {
    // Merge inline section with pre-entry section if there is no
    // code generated between.
    LastInitSectionMergeBlock = InitSectionMergeBlock;
    LastInitSectionEndBlock   = InitSectionEndBlock;
    LastInitSectionCBarrierPos = getLastInstrPos(Builder);
  }

  // PreEntryBBState guard EOL (restore of builder IP and "alloca" IP)
}

void CGOpenCLCPlusPlusRuntime::LocalMemLocalVarInitDtorEmitter::
registerDtorStub(llvm::Function *DtorStub) {
  assert(DtorStub != nullptr && "Destructor stub does not exist.");

  // Set initial priority to default priority.
  if (DtorStub != nullptr)
    VarDtorStubs.push_back(DtorStub);
}

CGOpenCLCPlusPlusRuntime::LocalMemLocalVarInitDtorEmitter &
CGOpenCLCPlusPlusRuntime::getLocalMemEmitter(CodeGenFunction &CGF) {
  auto FoundEmitter = LocalMemLocalVarIDEmits.find(CGF.CurFn);
  if (FoundEmitter != LocalMemLocalVarIDEmits.end())
    return *FoundEmitter->second;

  LocalMemLocalVarIDEmits.emplace(std::make_pair(
      CGF.CurFn, std::unique_ptr<LocalMemLocalVarInitDtorEmitter>(
                     new LocalMemLocalVarInitDtorEmitter(CGF))));
  return *LocalMemLocalVarIDEmits.at(CGF.CurFn);
}

void CGOpenCLCPlusPlusRuntime::finalizeLocalMemEmitter(CodeGenFunction &CGF) {
  auto FoundEmitter = LocalMemLocalVarIDEmits.find(CGF.CurFn);
  if (FoundEmitter == LocalMemLocalVarIDEmits.end())
    return;
  LocalMemLocalVarIDEmits.erase(FoundEmitter);
}

bool CGOpenCLCPlusPlusRuntime::isLocalMemLocalVar(const VarDecl *D) const {
  if (D == nullptr || D->isFileVarDecl() || D->isStaticDataMember())
    return false;

  auto &Ctx = CGM.getContext();
  const auto LocalAs = Ctx.getTargetAddressSpace(LangAS::openclcpp_local);

  auto VarTy = Ctx.getBaseElementType(D->getType());
  auto VarAs = Ctx.getTargetAddressSpace(VarTy);

  return VarAs == LocalAs;
}

bool CGOpenCLCPlusPlusRuntime::isVarInitFuncRequired(const VarDecl *D,
                                                     const Expr *Init) const {
  // Generic conditions required for initialization or forced
  // zero-initialization.
  if (D == nullptr)
    return false;

  auto &Ctx = CGM.getContext();
  const auto LocalAs = Ctx.getTargetAddressSpace(LangAS::openclcpp_local);

  auto VarTy = Ctx.getBaseElementType(D->getType());
  auto VarAs = Ctx.getTargetAddressSpace(VarTy);
  if (D->isFileVarDecl())
    VarAs = CGM.GetGlobalVarAddressSpace(D, VarAs);

  if (VarAs != LocalAs)
    return false;
  if (CGM.getLangOpts().CLZeroInitLocalMemVars)
    return true;

  // Additional conditions required only for initialization (check whether
  // something is emitted).
  if (Init == nullptr)
    return false;

  if (VarTy->isRecordType() &&
      VarTy->getAsCXXRecordDecl()->hasTrivialDefaultConstructor()) {
    if (auto CE = dyn_cast<CXXConstructExpr>(Init)) {
      auto CD = CE->getConstructor();
      if (CD->isTrivial() && CD->isDefaultConstructor())
        return false;
    }
  }
  return true;
}

bool CGOpenCLCPlusPlusRuntime::isVarZeroInitRequired(const VarDecl *D) const {
  // Method defines subset of isVarInitFuncRequired().
  return isVarInitFuncRequired(D, nullptr);
}

void CGOpenCLCPlusPlusRuntime::emitInitKernel(
    const CodeGenModule::CtorList &CtorFuncs) {
  auto OrderedInitFuncs = eliminateNoOpFuncs(extractAndOrderInitFuncs(
                                               CtorFuncs));
  verifyInitDtorKernelSupport(OrderedInitFuncs);
  auto Func = createInitOrDtorKernel(CGM, "_SPIRV_GLOBAL__I_",
                                     OrderedInitFuncs);
  if (Func == nullptr)
    return;

  addOpExecutionModeMetadata(CGM.getModule(), *Func, SEM_Initializer);
  llvm::Metadata *LocalSizes[] = {
    addInt32Metadata(CGM.getLLVMContext(), 1),
    addInt32Metadata(CGM.getLLVMContext(), 1),
    addInt32Metadata(CGM.getLLVMContext(), 1)
  };
  addOpExecutionModeMetadata(CGM.getModule(), *Func, SEM_LocalSize, LocalSizes);
}

void CGOpenCLCPlusPlusRuntime::emitDtorKernel(
    const CodeGenModule::CtorList &DtorFuncs) {
  auto OrderedDtorFuncs = extractAndOrderInitFuncs(DtorFuncs);
  auto FilteredOrdDtorFuncs = eliminateNoOpFuncs(OrderedDtorFuncs);
  std::reverse(FilteredOrdDtorFuncs.begin(), FilteredOrdDtorFuncs.end());
  verifyInitDtorKernelSupport(FilteredOrdDtorFuncs);

#ifndef NDEBUG
  // Count vars for check whether all registered destructors were called.
  auto DtorVarsCount =
    std::accumulate(OrderedDtorFuncs.begin(), OrderedDtorFuncs.end(),
                    std::size_t(), [this] (std::size_t Acc, llvm::Function *F) {
      return F != nullptr ? Acc + AssertDtorVarsCounts[F] : Acc;
    });
  assert(DtorVarsCount == GlobalVarDtorStubs.size() &&
         "Not all registered destructors were emitted in finalization kernel.");
#endif

  auto Func = createInitOrDtorKernel(CGM, "_SPIRV_GLOBAL__D_",
                                     FilteredOrdDtorFuncs);
  if (Func == nullptr)
    return;

  addOpExecutionModeMetadata(CGM.getModule(), *Func, SEM_Finalizer);
  llvm::Metadata *LocalSizes[] = {
    addInt32Metadata(CGM.getLLVMContext(), 1),
    addInt32Metadata(CGM.getLLVMContext(), 1),
    addInt32Metadata(CGM.getLLVMContext(), 1)
  };
  addOpExecutionModeMetadata(CGM.getModule(), *Func, SEM_LocalSize, LocalSizes);
}

void CGOpenCLCPlusPlusRuntime::emitLocalScopeStaticVarDecl(
    CodeGenFunction &CGF,
    const VarDecl &D,
    llvm::GlobalValue::LinkageTypes Linkage) {
  // Collect information about local-scope static-storage-duration objects,
  // if necessary.
  return CGF.EmitStaticVarDecl(D, Linkage);
}

void CGOpenCLCPlusPlusRuntime::registerVarGlobalDtorStub(
  const VarDecl &D,
  llvm::Function *DtorStub) {
  assert(DtorStub != nullptr && "Destructor stub does not exist.");
  assert(GlobalVarDtorStubs.find(&D) == GlobalVarDtorStubs.end() &&
         "Destructor stub already registered for current variable.");
  assert(AssertDtorVarsCounts.find(DtorStub) == AssertDtorVarsCounts.end() &&
         "Destructor stub already registered for different variable.");

  // Set initial priority to default priority.
  if (DtorStub != nullptr) {
    GlobalVarDtorStubs[&D] = DtorStub;

#ifndef NDEBUG
    // Count vars for check whether all registered destructors were called.
    AssertDtorVarsCounts[DtorStub] = 1;
#endif
  }
}

void CGOpenCLCPlusPlusRuntime::registerVarGlobalInitFunc(
    const VarDecl &D,
    llvm::Constant *InitFunc) {
  assert(InitFunc != nullptr && "Initialization function does not exist.");

  GlobalVarInitFuncs[InitFunc].push_back(&D);
}

void CGOpenCLCPlusPlusRuntime::registerVarGlobalInitFunc(
    llvm::Constant *InitFunc,
    llvm::ArrayRef<llvm::Function *> InitDecls) {
  assert(InitFunc != nullptr && "Initialization function does not exist.");

  for (auto InitDecl : InitDecls) {
    if (InitDecl == nullptr)
      continue;
    if (InitDecl != InitFunc) {
      GlobalVarInitFuncs[InitFunc].append(GlobalVarInitFuncs[InitDecl].begin(),
                                          GlobalVarInitFuncs[InitDecl].end());
    }
    else
      assert(false && "Declarator for initialization function does not exist.");
  }

#ifndef NDEBUG
  // Check that initialization is not done twice.
  llvm::DenseSet<const VarDecl *> UniquenessChecker;
  UniquenessChecker.insert(GlobalVarInitFuncs[InitFunc].begin(),
                           GlobalVarInitFuncs[InitFunc].end());
  assert(UniquenessChecker.size() == GlobalVarInitFuncs[InitFunc].size() &&
         "Initialization function performs (partial) double initialization.");
#endif
}

llvm::Function * CGOpenCLCPlusPlusRuntime::createCorrespondingDtorFunc(
    llvm::Constant *InitFunc,
    const llvm::Twine &Name) {
  if (InitFunc == nullptr ||
      GlobalVarInitFuncs.find(InitFunc) == GlobalVarInitFuncs.end()) {
    assert(false && "Initialization function was not registered.");
    return nullptr;
  }

  const auto &OrderedInitVars = GlobalVarInitFuncs[InitFunc];
  llvm::SmallVector<llvm::Function *, 8> DtorFuncs;

  for (auto OrderedInitVar : OrderedInitVars) {
    auto FoundDtor = GlobalVarDtorStubs.find(OrderedInitVar);
    if (FoundDtor != GlobalVarDtorStubs.end())
      DtorFuncs.push_back(FoundDtor->second);
  }

  if (DtorFuncs.empty())
    return nullptr;

  // There is no need to wrap single destroy function in another function.
  if (DtorFuncs.size() == 1)
    return DtorFuncs[0];

  llvm::FunctionType *FuncTy = llvm::FunctionType::get(CGM.VoidTy, false);
  llvm::Function *Func = CGM.CreateGlobalInitOrDestructFunction(
      FuncTy, Name);

  std::reverse(DtorFuncs.begin(), DtorFuncs.end());
  CodeGenFunction(CGM).GenerateCXXGlobalInitFunc(Func, DtorFuncs);

#ifndef NDEBUG
  // Count vars for check whether all registered destructors were called.
  auto DtorVarsCount =
    std::accumulate(DtorFuncs.begin(), DtorFuncs.end(), std::size_t(),
                    [this] (std::size_t Acc, llvm::Function *F) {
      return F != nullptr ? Acc + AssertDtorVarsCounts[F] : Acc;
    });
  AssertDtorVarsCounts[Func] = DtorVarsCount;
#endif

  return Func;
}

#define OP_MD_PREFIX "spirv."

llvm::Metadata *CGOpenCLCPlusPlusRuntime::addOpStringMetadata(
    llvm::Module &M,
    llvm::StringRef Str) {
  llvm::LLVMContext &C = M.getContext();


  auto MDOpStringNodes = M.getOrInsertNamedMetadata(OP_MD_PREFIX "String");

  auto MDOpStringString = llvm::MDString::get(C, Str);
  auto MDOpStringNode = llvm::MDNode::get(C, MDOpStringString);
  MDOpStringNodes->addOperand(MDOpStringNode);

  return MDOpStringNode;
}

llvm::Metadata *CGOpenCLCPlusPlusRuntime::addOpExecutionModeMetadata(
    llvm::Module &M,
    llvm::Function &EntryPoint,
    SPIRVExecutionMode Mode,
    llvm::ArrayRef<llvm::Metadata *> ModeParams) {
  llvm::LLVMContext &C = M.getContext();


  auto MDOpExecModeNodes =
    M.getOrInsertNamedMetadata(OP_MD_PREFIX "ExecutionMode");
  llvm::SmallVector<llvm::Metadata *, 4> MDOpExecMode;

  // Entry point: function <id>.
  auto MDOpExecModeEntryPoint = llvm::ConstantAsMetadata::get(&EntryPoint);
  MDOpExecMode.push_back(MDOpExecModeEntryPoint);
  // Mode of execution.
  auto MDOpSourceVersion = addInt32Metadata(C, Mode);
  MDOpExecMode.push_back(MDOpSourceVersion);
  // Additional parameters for mode of execution.
  for (auto ModeParam : ModeParams)
    MDOpExecMode.push_back(ModeParam);

  auto MDOpExecModeNode = llvm::MDNode::get(C, MDOpExecMode);
  MDOpExecModeNodes->addOperand(MDOpExecModeNode);

  return MDOpExecModeNode;
}

namespace {
  enum SPIRVVecTypeHintDataType {
    SVTHDT_8BIT_INT = 0,
    SVTHDT_16BIT_INT = 1,
    SVTHDT_32BIT_INT = 2,
    SVTHDT_64BIT_INT = 3,
    SVTHDT_16BIT_FP = 4,
    SVTHDT_32BIT_FP = 5,
    SVTHDT_64BIT_FP = 6
  };
}

static uint32_t getTypeIndexForSPIRVVecTypeHint(CodeGenModule& CGM,
  QualType hintQTy) {
  auto& Context = CGM.getTypes().getContext();

  const ExtVectorType *hintEltQTy = hintQTy->getAs<ExtVectorType>();
  uint32_t VecHint = (hintEltQTy ? hintEltQTy->getNumElements() : 1);
  VecHint <<= 16;

  if (hintEltQTy)
    hintQTy = hintEltQTy->getElementType();

  auto elQTy = Context.getCanonicalType(hintQTy);
  bool isFp = elQTy->isFloatingType();

  switch (Context.getTypeSize(elQTy))
  {
  case 8:   assert(!isFp && "8-bit floating point type?");
            VecHint |= SVTHDT_8BIT_INT; break;
  case 16:  VecHint |= (isFp ? SVTHDT_16BIT_FP : SVTHDT_16BIT_INT); break;
  case 32:  VecHint |= (isFp ? SVTHDT_32BIT_FP : SVTHDT_32BIT_INT); break;
  case 64:  VecHint |= (isFp ? SVTHDT_64BIT_FP : SVTHDT_64BIT_INT); break;
  default:
    llvm_unreachable("Invalid vec type hint size!");
  }

  return VecHint;
}

void CGOpenCLCPlusPlusRuntime::emitKernelMetadata(
    const FunctionDecl *FD,
    llvm::Function *Fn) {
  if (!FD->hasAttr<OpenCLKernelAttr>())
    return;

  auto& Context = Fn->getContext();

  using AttrArgT = llvm::SmallVector<llvm::Metadata *, 4>;
  using AttrT = std::pair<SPIRVExecutionMode, AttrArgT>;
  llvm::SmallVector<AttrT, 5> AttrsToAdd;

  if (const VecTypeHintAttr *A = FD->getAttr<VecTypeHintAttr>()) {
    AttrsToAdd.push_back(AttrT{
      SEM_VecTypeHint,
      AttrArgT(1, addInt32Metadata(Context,
                      getTypeIndexForSPIRVVecTypeHint(CGM, A->getTypeHint())))
    });
  }

  if (const WorkGroupSizeHintAttr *A = FD->getAttr<WorkGroupSizeHintAttr>()) {
    llvm::Metadata *args[] = {
      addInt32Metadata(Context, A->getXDim()),
      addInt32Metadata(Context, A->getYDim()),
      addInt32Metadata(Context, A->getZDim()) };
    AttrsToAdd.push_back(AttrT{ SEM_LocalSizeHint, AttrArgT(std::begin(args),
                                                            std::end(args)) });
  }

  if (const ReqdWorkGroupSizeAttr *A = FD->getAttr<ReqdWorkGroupSizeAttr>()) {
    llvm::Metadata *args[] = {
      addInt32Metadata(Context, A->getXDim()),
      addInt32Metadata(Context, A->getYDim()),
      addInt32Metadata(Context, A->getZDim()) };
    AttrsToAdd.push_back(AttrT{ SEM_LocalSize, AttrArgT(std::begin(args),
                                                        std::end(args)) });
  }

  if (auto A = FD->getAttr<ReqdSubGroupSizeAttr>()) {
    AttrsToAdd.push_back(AttrT{
      SEM_SubgroupSize, AttrArgT(1, addInt32Metadata(Context, A->getXDim()))
    });
  }

  if (auto A = FD->getAttr<ReqdNumSubGroupsAttr>()) {
    AttrsToAdd.push_back(AttrT{
      SEM_SubgroupsPerWorkgroup,
      AttrArgT(1, addInt32Metadata(Context, A->getNumSubGroups()))
    });
  }

  for (auto& A : AttrsToAdd)
    addOpExecutionModeMetadata(*Fn->getParent(), *Fn, A.first, A.second);
}

#undef OP_MD_PREFIX