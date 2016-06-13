//===- CGOpenCLCPlusPlusRuntime.h - Interface to OCLC++ Runtime -*- C++ -*-===//
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
//
// This provides an base class for OpenCL C++ code generation. Derived
// subclasses of this implement code generation for specific OpenCL C++
// flavors of runtime libraries.
//
//===----------------------------------------------------------------------===//


#ifndef LLVM_CLANG_LIB_CODEGEN_CGOPENCLCPLUSPLUSRUNTIME_H
#define LLVM_CLANG_LIB_CODEGEN_CGOPENCLCPLUSPLUSRUNTIME_H

#include "CodeGenModule.h"

#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/ValueHandle.h"

#include <memory>
#include <unordered_map>


namespace clang {
class Expr;
class VarDecl;

namespace CodeGen {
class CodeGenFunction;

/// Execution modes for SPIR-V OpExecutionMode.
enum SPIRVExecutionMode {
  SEM_LocalSize = 17,   ///< Required local size.
  SEM_LocalSizeHint = 18,   ///< Hint about used local size.
  SEM_VecTypeHint = 30,   ///< Vector type hint.
  SEM_ContractionOff = 31,   ///< Floating-point contractions are not allowed.
  SEM_Initializer = 33,   ///< Initializer kernel.
  SEM_Finalizer = 34,    ///< Finalizer kernel.
  SEM_SubgroupSize = 35,
  SEM_SubgroupsPerWorkgroup = 36
};

/// \brief Code generation runtime for OpenCL C++.
///
/// Runtime which acquires and stores additional information about module
/// needed to support OpenCL C++.
/// It also handles generation of specific features of OpenCL C++.
class CGOpenCLCPlusPlusRuntime {
protected:
  /// \brief Verifies whether initializer/finalizer kernel is supported and
  ///        needed for current translation unit.
  ///
  /// Verifies whether initializer/finalizer kernels are needed. If they are
  /// needed, checks whether they are supported.
  /// If they are not supported but needed, the errors are reported to module
  /// code generator ("unsupported" errors or generic errors, depending on
  /// whether we can locate source element which needs this feature).
  ///
  /// \param Funcs Functions that need to be called in initializer/finalizer
  ///              kernels.
  /// \return true if verification succeeded (feature is supported or not
  ///         needed); otherwise, false.
  bool verifyInitDtorKernelSupport(llvm::ArrayRef<llvm::Function *> Funcs);


public:
  /// \brief Constructs OpenCL C++ runtime for code generation.
  ///
  /// \param CGM Module code generator in which runtime will be used.
  CGOpenCLCPlusPlusRuntime(CodeGenModule &CGM)
    : CGM(CGM), VerifyInitDtorKernelSupportErrorsEmitted(false) {}
  /// \brief Destroys runtime (for inheritance purposes).
  virtual ~CGOpenCLCPlusPlusRuntime() = default;

// ====================== INITIALIZERS / FINALIZERS ============================

  /// \brief Emitter of local-scope local memory variable initializers.
  class LocalMemLocalVarInitDtorEmitter {
    /// \brief Emits clean-up (destruction) code for registered variable
    ///        destructors.
    void emitVarCleanup();

  public:
    /// \brief Constructs emitter for initialization (and finalization)
    ///        code for local-scope variables stored in local memory (address
    ///        space).
    ///
    /// \param CGF Function code generator in which emission will take place.
    LocalMemLocalVarInitDtorEmitter(CodeGenFunction &CGF);

    // Objects are only destructible. Cannot be copied or moved.
    LocalMemLocalVarInitDtorEmitter(
        const LocalMemLocalVarInitDtorEmitter &) LLVM_DELETED_FUNCTION;
    LocalMemLocalVarInitDtorEmitter(
        LocalMemLocalVarInitDtorEmitter &&) LLVM_DELETED_FUNCTION;
    LocalMemLocalVarInitDtorEmitter &operator =(
        const LocalMemLocalVarInitDtorEmitter &) LLVM_DELETED_FUNCTION;
    LocalMemLocalVarInitDtorEmitter &operator =(
        LocalMemLocalVarInitDtorEmitter &&) LLVM_DELETED_FUNCTION;

    /// \brief Destroys emitter. Emits some clean-ups before.
    virtual ~LocalMemLocalVarInitDtorEmitter();

    /// \brief Emits initializer / finalizer for variable declaration.
    ///
    /// \param D  Declaration of variable for which initializator / clean-up
    ///           code will be generated.
    /// \param GV Global variable connected to variable declaration D.
    void emit(const VarDecl &D, llvm::GlobalVariable *GV);

    /// \brief Registers destructor stub for local-scope local memory variable.
    ///
    /// Registred stubs will be emitted at clean-up of emitter (destruction)
    /// with final section for local memory destuction.
    ///
    /// Stubs will be called in reverse order of their registration.
    ///
    /// \param DtorStub Finalization function that destroyes variable.
    ///                 Function must not take any parameters (generate stub if
    ///                 necessary).
    ///                 Single function must destroy single variable.
    void registerDtorStub(llvm::Function *DtorStub);

  private:
    /// Code generator for LLVM function.
    CodeGenFunction &CGF;

    // --------------------- initalization section states ----------------------
    /// "alloca" insertion position (for initializer section at function begin).
    llvm::AssertingVH<llvm::Instruction> AllocaIP;

    // --------------------- Function begin initalization ----------------------
    /// Merge insert block of initializer section at function begin. Block where
    /// additional constexpr initializers should be merged to.
    llvm::BasicBlock *InitSectionMergeBlock;
    /// End block of initializer section at function begin. This BB points to
    /// block which terminator from merge block jumps to.
    llvm::BasicBlock *InitSectionEndBlock;

    // ------------------------- Inline initalization --------------------------
    /// Position of final control barrier of last inline initializer section.
    llvm::IRBuilderBase::InsertPoint LastInitSectionCBarrierPos;
    /// Merge insert block of last inline initializer section. Block where
    /// additional initializers should be merged to.
    llvm::BasicBlock *LastInitSectionMergeBlock;
    /// End block of last inline initializer section. This BB points to block
    /// which terminator from merge block jumps to.
    llvm::BasicBlock *LastInitSectionEndBlock;

    // ------------------------- Finalization ----------------------------------
    /// Collection of destructor (stubs) for local variables.
    llvm::SmallVector<llvm::Function *, 4> VarDtorStubs;
  };

  /// \brief Gets (or creates) emitter for initialization (and finalization)
  ///        of local memory (address space) variables.
  ///
  /// This version works for local-scope variables.
  ///
  /// \param CGF Function code generator in which initialized variables
  ///            reside and are generated.
  /// \return Emitter of initializer / finalizer of variable.
  virtual LocalMemLocalVarInitDtorEmitter &getLocalMemEmitter(
      CodeGenFunction &CGF);

  /// \brief Unregisters and destroys emitter for local memory.
  ///
  /// If local emitter was created for LocalMemLocalVarInitDtorEmitter for
  /// currently generated function, the method cleans up (emits optional
  /// final section that contains clean-up with non-trivial destruction),
  /// unregisters emitter and destroys it.
  ///
  /// If there is no emitter connected to function (generator), method does
  /// nothing.
  ///
  /// \param CGF Function code generator connected to emitter.
  void finalizeLocalMemEmitter(CodeGenFunction &CGF);

  /// \brief Indicates that variable declaration declares local-scope
  ///        local memory (address space) variable.
  ///
  /// \param D       Declaration of variable which is tested for
  ///                initialization requirements.
  /// \param HasInit Indicates that there exists at least one initializer
  ///                in (any) declaration of tested variable.
  /// \return true if initialization function for variable is required;
  ///         otherwise, false.
  virtual bool isLocalMemLocalVar(const VarDecl *D) const;

  /// \brief Indicates that variable declaration requires initialization
  ///        function, even if it has trivial- / constexpr-initialization.
  ///
  /// Currently supported and effective only for local-scope.
  ///
  /// \param D     Declaration of variable which is tested for initialization
  ///              requirements.
  /// \param Init  Initializer of variable. Specify nullptr, if there is no
  ///              initializer.
  /// \return true if initialization function for variable is required;
  ///         otherwise, false.
  virtual bool isVarInitFuncRequired(const VarDecl *D, const Expr *Init) const;

  /// \brief Indicates that variable declaration requires zero-initialization
  ///        to be done before actual initialization.
  ///
  /// Currently supported and effective only for local-scope.
  ///
  /// This function is similar to isVarInitFuncRequired() and defines subset
  /// of variables that needs also zero-initialization (if
  /// isVarInitFuncRequired() returns false, this method will also return
  /// false).
  ///
  /// \param D       Declaration of variable which is tested for
  ///                initialization requirements.
  /// \return true if zero-initialization for variable is required before actual
  //          initialization; otherwise, false.
  virtual bool isVarZeroInitRequired(const VarDecl *D) const;

  /// \brief Emits single initialization kernel (initializer kernel).
  ///
  /// Emits initialization kernel which calls all initialization functions
  /// from CtorFuncs list, in correct order, taking into consideration their
  /// priority and position on the list (stable-sorted by priority).
  /// If CtorFuncs is empty, the kernel is not created.
  /// Method generates also the SPIR-V metadata needed for kernel to be
  /// properly handled.
  ///
  /// \param CtorFuncs List of initialization functions to invoke from
  ///                  initializer kernel (prioritized structor list).
  virtual void emitInitKernel(const CodeGenModule::CtorList &CtorFuncs);

  /// \brief Emits single finalization/destruction kernel (finalizer/destructor
  ///        kernel).
  ///
  /// Emits finalization kernel which calls all finalization functions
  /// from DtorFuncs list, in correct order, taking into consideration their
  /// priority and position on the list (stable-sorted by priority and reversed).
  /// If DtorFuncs is empty, the kernel is not created.
  /// Method generates also the SPIR-V metadata needed for kernel to be
  /// properly handled.
  ///
  /// \param DtorFuncs List of finalization functions to invoke from
  ///                 initializer kernel (prioritized structor list).
  virtual void emitDtorKernel(const CodeGenModule::CtorList &DtorFuncs);


  /// \brief Emits declaration of local-scope static-storage-duration variable.
  ///
  /// This method also work for OpenCL C++ local-scope local-memory and
  /// constant-memory variables.
  ///
  /// \param CGF     Function code generator which generates function in which
  ///                variable is declared.
  /// \param D       Variable declaration for which code will be emitted.
  /// \param Linkage Linkage that should be used for variable.
  virtual void emitLocalScopeStaticVarDecl(
      CodeGenFunction &CGF,
      const VarDecl &D,
      llvm::GlobalValue::LinkageTypes Linkage);

  /// \brief Emits declaration of local-scope static-storage-duration variable.
  ///
  /// This method also work for OpenCL C++ local-scope local-memory and
  /// constant-memory variables.
  /// Emitted variable will have internal linkage.
  ///
  /// \param CGF     Function code generator which generates function in which
  ///                variable is declared.
  /// \param D       Variable declaration for which code will be emitted.
  void emitLocalScopeStaticVarDecl(CodeGenFunction &CGF, const VarDecl &D) {
    emitLocalScopeStaticVarDecl(CGF, D, llvm::GlobalValue::InternalLinkage);
  }


  /// \brief Registers global-scope initialization function associated with
  ///        declaration of variable.
  ///
  /// Gathers information about initialization functions and variables
  /// initialized by them. The information is used for ordering destructors when
  /// using createCorrespondingDtorFunc().
  ///
  /// \param D        Declaration of (global-scope) variable which is
  ///                 initialized by InitFunc. Single variable must be
  ///                 initialized by single function.
  /// \param InitFunc Initialization function that initializes variable.
  ///                 Single function may initalize multiple variables.
  ///                 No-op empty initalization function must be resistered as
  ///                 well (function where atexit would be called).
  virtual void registerVarGlobalInitFunc(const VarDecl &D,
                                         llvm::Constant *InitFunc);

  /// \brief Registers global-scope initialization function which groups
  ///        initialization functions (usually by priority).
  ///
  /// Gathers information about initialization functions and variables
  /// initialized by them. The information is used for ordering destructors when
  /// using createCorrespondingDtorFunc().
  ///
  /// \param InitFunc  Initialization function that groups other initialization
  ///                  functions.
  /// \param InitDecls Oredered list of functions called inside grouping
  ///                  function. Order of these functions is used to
  ///                  determine order of destruction when using
  ///                  createCorrespondingDtorFunc().
  virtual void registerVarGlobalInitFunc(
      llvm::Constant *InitFunc,
      llvm::ArrayRef<llvm::Function *> InitDecls);

  /// \brief Registers destruction/finalization function (stub) associated with
  ///        declaration of variable.
  ///
  /// Gathers information about finalization functions and variables
  /// destroyed by them. The information is used for ordering destructors when
  /// using createCorrespondingDtorFunc().
  ///
  /// \param D        Declaration of (global-scope) variable which is
  ///                 destroyed by DtorStub. Single variable must be
  ///                 destroyed by single function.
  /// \param DtorStub Finalization function that destroyes variable.
  ///                 Function must not take any parameters (generate stub if
  ///                 necessary).
  ///                 Single function must destroy single variable.
  virtual void registerVarGlobalDtorStub(const VarDecl &D,
                                         llvm::Function *DtorStub);

  /// \brief Creates finalization/destruction function corresponding to
  ///        selected initialization function.
  ///
  /// Creates or fetches finalization function coresponding to initialization
  /// function, if there is at least one (registered) variable initialized
  /// by the initialization function that needs non-trivial destruction.
  /// If there is no destruction needed or initialization function is not
  /// registered (assert is generated in this case), the nullptr is returned.
  ///
  /// When function is created (two or more destructors needs to be called),
  /// the Name is used to provide new function name. If function if fetched,
  /// Name is ignored.
  ///
  /// Order of destruction is based of order of initialization in InitFunc
  /// (reversed). registerVarGlobalInitFunc() and registerVarGlobalDtorStub()
  /// functions are used to determine correct order.
  ///
  /// \param InitFunc Initialization function for which finalization function
  ///                 will be created (or fetched).
  /// \param Name     Name of newly created finalization function. If function
  ///                 already exists (it is only fetched), the parameter is
  ///                 ignored.
  /// \return         Finalization/destruction function, or nullptr
  ///                 if the function could not be created or it is not needed.
  virtual llvm::Function *createCorrespondingDtorFunc(llvm::Constant *InitFunc,
                                                      const llvm::Twine &Name);

// ============================= METADATA ======================================

  /// \brief Adds metadata (node) with integer constant (immediate).
  ///
  /// \param C     LLVM context (connected to modified module(s)).
  /// \param Value Integral value (arbitrary precision).
  ///
  /// \return Metadata (node) with integral value.
  static llvm::Metadata *addAPIntMetadata(llvm::LLVMContext &C,
                                          const llvm::APInt &Value) {
    auto IntTy = llvm::IntegerType::get(C, Value.getBitWidth());
    auto IntConstant = llvm::Constant::getIntegerValue(IntTy, Value);

    return llvm::ConstantAsMetadata::get(IntConstant);
  }


  /// \brief Adds metadata (node) with 32-bit integer constant (immediate).
  ///
  /// \param C     LLVM context (connected to modified module(s)).
  /// \param Value Integral value (32-bit, signed).
  ///
  /// \return Metadata (node) with integral value.
  static llvm::Metadata *addInt32Metadata(llvm::LLVMContext &C,
                                          int32_t Value) {
    return addAPIntMetadata(C, llvm::APInt(32, Value, true));
  }

  /// \brief Adds metadata (node) with 32-bit integer constant (immediate).
  ///
  /// \param C     LLVM context (connected to modified module(s)).
  /// \param Value Integral value (32-bit, unsigned).
  ///
  /// \return Metadata (node) with integral value.
  static llvm::Metadata *addInt32Metadata(llvm::LLVMContext &C,
                                          uint32_t Value) {
    return addAPIntMetadata(C, llvm::APInt(32, Value));
  }

  /// \brief Adds metadata representing OpString in SPIR-V friendly LLVM.
  ///
  /// \param M   LLVM module.
  /// \param Str Text content stored in metadata node.
  ///
  /// \return Metadata node attached to named metadata which contains added
  ///         information.
  static llvm::Metadata *addOpStringMetadata(llvm::Module &M,
    llvm::StringRef Str);

  /// \brief Adds metadata representing OpExecutionMode in SPIR-V friendly LLVM.
  ///
  /// \param M          LLVM module.
  /// \param EntryPoint Entry point for which execution mode is declared.
  /// \param Mode       Mode of execution for selected EntryPoint.
  /// \param ModeParams Additional parameters for selected mode of execution
  ///                   (optional).
  ///
  /// \return Metadata node attached to named metadata which contains added
  ///         information.
  static llvm::Metadata *addOpExecutionModeMetadata(
    llvm::Module &M,
    llvm::Function &EntryPoint,
    SPIRVExecutionMode Mode,
    llvm::ArrayRef<llvm::Metadata *> ModeParams = llvm::None);

  /// \brief Emits llvm metadata related to specified kernel function.
  ///        Metadata are generated mainly to handle attributes applied to
  ///        kernel such as cl::work_group_size_hint etc.
  ///
  /// \param FD   internal representation of kernel function declaration which
  ///             is checked agains attributes presence
  /// \param Fn   llvm's representation of kernel function, metadata are applied
  ///             to this value
  void emitKernelMetadata(const FunctionDecl *FD,
                          llvm::Function *Fn);


protected:
  /// Module code generator.
  CodeGenModule &CGM;

  /// Collection of local initialization / destruction emitters for local
  /// memory (address space) objects.
  /// NOTE: The llvm::DenseMap does not preserve references to elements
  ///       during grow. Using std::unordered_map instead.
  std::unordered_map<llvm::Function *,
                     std::unique_ptr<LocalMemLocalVarInitDtorEmitter>>
                                                        LocalMemLocalVarIDEmits;

private:
  /// Indicates that some errors were already emitted by
  /// verifyInitDtorKernelSupport(). Used to avoid double emitting of some
  /// errors.
  bool VerifyInitDtorKernelSupportErrorsEmitted;

protected:
  /// Collection of global initialization functions and variables
  /// initialized by them.
  llvm::DenseMap<llvm::Constant *,
                 llvm::SmallVector<const VarDecl *, 1>> GlobalVarInitFuncs;
  /// Collection of variables and their corresponding global destructor (stubs).
  llvm::DenseMap<const VarDecl *, llvm::Function *> GlobalVarDtorStubs;

#ifndef NDEBUG
  /// Assertion helper: Number of variables destroyed by selected finalization
  /// function.
  llvm::DenseMap<llvm::Function *, std::size_t> AssertDtorVarsCounts;
#endif
};

}
}

#endif // LLVM_CLANG_LIB_CODEGEN_CGOPENCLCPLUSPLUSRUNTIME_H
