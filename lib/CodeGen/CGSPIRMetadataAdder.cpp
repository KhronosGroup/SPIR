//===- SPIRMetadataAdder.cpp - Add SPIR related module scope metadata -----===//
//
// TODO: add copyright info
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//


#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/TypeFinder.h"
#include <list>
#include "CGSPIRMetadataAdder.h"
#include <set>

using namespace llvm;
using namespace clang;
using namespace CodeGen;

static const char *ImageTypeNames[] = {
  "opencl.image1d_t", "opencl.image1d_array_t", "opencl.image1d_buffer_t",
  "opencl.image2d_t", "opencl.image2d_array_t",
  "opencl.image2d_depth_t", "opencl.image2d_array_depth_t",
  "opencl.image2d_msaa_t", "opencl.image2d_array_msaa_t",
  "opencl.image2d_msaa_depth_t", "opencl.image2d_array_msaa_depth_t",
  "opencl.image3d_t"
};

static const char *ImageDepthTypeNames[] = {
  "opencl.image2d_depth_t", "opencl.image2d_array_depth_t"
};

static const char *ImageMSAATypeNames[] = {
  "opencl.image2d_msaa_t", "opencl.image2d_array_msaa_t",
  "opencl.image2d_msaa_depth_t", "opencl.image2d_array_msaa_depth_t"
};

struct OCLExtensionsTy {
#define OPENCLEXT(nm)  unsigned _##nm : 1;
#include "clang/Basic/OpenCLExtensions.def"

  OCLExtensionsTy() {
#define OPENCLEXT(nm)   _##nm = 0;
#include "clang/Basic/OpenCLExtensions.def"
  }
};

typedef void (*func_call_handler)(CallInst *callInstr, OCLExtensionsTy &exts);

void baseAtomics64(CallInst *callInstr, OCLExtensionsTy &exts) {
  PointerType *firstArgType = dyn_cast<PointerType>(callInstr->getArgOperand(0)->getType());

  if (firstArgType && 
      firstArgType->getPointerElementType()->isIntegerTy() &&
      firstArgType->getPointerElementType()->getScalarSizeInBits() == 64)
    exts._cl_khr_int64_base_atomics = 1;
}

void extAtomics64(CallInst *callInstr, OCLExtensionsTy &exts) {
  PointerType *firstArgType = dyn_cast<PointerType>(callInstr->getArgOperand(0)->getType());

  if (firstArgType && 
      firstArgType->getPointerElementType()->isIntegerTy() &&
      firstArgType->getPointerElementType()->getScalarSizeInBits() == 64)
    exts._cl_khr_int64_extended_atomics = 1;
}

void image3DWrite(CallInst *callInstr, OCLExtensionsTy &exts) {
  PointerType *firstArgType = dyn_cast<PointerType>(callInstr->getArgOperand(0)->getType());

  if (firstArgType && 
      firstArgType->getPointerElementType()->isStructTy() &&
      !firstArgType->getPointerElementType()->getStructName().compare("opencl.image3d_t"))
    exts._cl_khr_3d_image_writes = 1;
}

typedef struct {
  const char *funcName;
  func_call_handler handler;
} funcCallHandlersTy;

static const funcCallHandlersTy funcCallHandlers[] = {
  {"_Z8atom_add", baseAtomics64},
  {"_Z8atom_sub", baseAtomics64},
  {"_Z9atom_xchg", baseAtomics64},
  {"_Z8atom_inc", baseAtomics64},
  {"_Z8atom_dec", baseAtomics64},
  {"_Z12atom_cmpxchg", baseAtomics64},
  {"_Z8atom_min", extAtomics64},
  {"_Z8atom_max", extAtomics64},
  {"_Z8atom_and", extAtomics64},
  {"_Z7atom_or", extAtomics64},
  {"_Z8atom_xor", extAtomics64},
  {"_Z12write_imagef", image3DWrite},
  {"_Z12write_imagei", image3DWrite},
  {"_Z13write_imageui", image3DWrite}
};

static bool searchTypeInType (llvm::Type *ty1, llvm::Type *ty2, bool ignorePtrs);

static bool searchTypeInType (llvm::Type *ty1, llvm::Type *ty2, bool ignorePtrs, std::set<llvm::Type*> &typesList) {
  if (ty1 == ty2)
    return true;

  if (ty1->isVectorTy())
    return searchTypeInType(ty1->getVectorElementType(), ty2, ignorePtrs, typesList);

  if (ty1->isArrayTy())
    return searchTypeInType(ty1->getArrayElementType(), ty2, ignorePtrs, typesList);

  if (!ignorePtrs && ty1->isPointerTy()) {
    // prevent infinte loop (such a struct that conatinc pointer to itself)
    std::set<llvm::Type*>::iterator itr = typesList.find(ty1->getPointerElementType());
    if ( itr != typesList.end() ) {
      return false;
    }
    return searchTypeInType(ty1->getPointerElementType(), ty2, ignorePtrs, typesList);
  }

  if (ty1->isStructTy()) {
    typesList.insert( ty1 );
    llvm::StructType *strTy = dyn_cast<llvm::StructType>(ty1);

    for (StructType::element_iterator EI = strTy->element_begin(),
         EE = strTy->element_end(); EI != EE; ++EI)
      if (searchTypeInType((*EI), ty2, ignorePtrs, typesList))
        return true;
  }

  if (ty1->isFunctionTy()) {
    typesList.insert( ty1 );
    FunctionType *FuncTy = dyn_cast<llvm::FunctionType>(ty1);

    if (searchTypeInType(FuncTy->getReturnType(), ty2, ignorePtrs))
      return true;

    for (FunctionType::param_iterator PI = FuncTy->param_begin(),
         PE = FuncTy->param_end(); PI != PE; ++PI)
      if (searchTypeInType((*PI), ty2, ignorePtrs))
        return true;
  }

  return false;
}

static bool searchTypeInType (llvm::Type *ty1, llvm::Type *ty2, bool ignorePtrs) {
  std::set<llvm::Type*> typesList;
  return searchTypeInType( ty1, ty2, ignorePtrs, typesList);
}

static void FunctionAddSPIRMetadata(Function &F, bool &bUseDoubles, OCLExtensionsTy &sUsedExts);

void clang::CodeGen::AddSPIRMetadata(Module &M, int OCLVersion, std::list<std::string> sBuildOptions) {
  Type *pDoubleType = Type::getDoubleTy(M.getContext());
  Type *pHalfType = Type::getHalfTy(M.getContext());

  OCLExtensionsTy sUsedExts;

  bool bUseDoubles = false;
  bool bUseImages  = false;

  for (Module::global_iterator GI = M.global_begin(), GE = M.global_end();
       GI != GE; ++GI) {
    if (searchTypeInType(GI->getType(), pDoubleType, false))
      bUseDoubles = true;
    if (searchTypeInType(GI->getType(), pHalfType, true))
      sUsedExts._cl_khr_fp16 = true;
  }

  //check if image types are defined
  for (size_t i = 0; i < sizeof(ImageTypeNames)/sizeof(ImageTypeNames[0]); i++) {
    if (M.getTypeByName(ImageTypeNames[i])) {
      bUseImages = true;
      break;
    }
  }

  //check if depth image types are defined
  for (size_t i = 0; i < sizeof(ImageDepthTypeNames)/sizeof(ImageDepthTypeNames[0]); i++) {
    if (M.getTypeByName(ImageDepthTypeNames[i])) {
      sUsedExts._cl_khr_depth_images = true;
      break;
    }
  }

  //check if msaa image types are defined
  for (size_t i = 0; i < sizeof(ImageMSAATypeNames)/sizeof(ImageMSAATypeNames[0]); i++) {
    if (M.getTypeByName(ImageMSAATypeNames[i])) {
      sUsedExts._cl_khr_gl_msaa_sharing = true;
      break;
    }
  }

  // scan all functions
  for (Module::iterator FI = M.begin(), FE = M.end();
       FI != FE; ++FI) {
    FunctionAddSPIRMetadata(*FI, bUseDoubles, sUsedExts);
  }

  // Add SPIR version (1.2)
  Value *SPIRVerElts[] = {
    ConstantInt::get(Type::getInt32Ty(M.getContext()), 2),
    ConstantInt::get(Type::getInt32Ty(M.getContext()), 0)
  };
  llvm::NamedMDNode *SPIRVerMD =
    M.getOrInsertNamedMetadata("opencl.spir.version");
  SPIRVerMD->addOperand(llvm::MDNode::get(M.getContext(), SPIRVerElts));

  // Add OpenCL version
  Value *OCLVerElts[] = {
    ConstantInt::get(Type::getInt32Ty(M.getContext()), OCLVersion / 100),
    ConstantInt::get(Type::getInt32Ty(M.getContext()), (OCLVersion % 100) / 10)
  };
  llvm::NamedMDNode *OCLVerMD =
    M.getOrInsertNamedMetadata("opencl.ocl.version");
  OCLVerMD->addOperand(llvm::MDNode::get(M.getContext(), OCLVerElts));

  // Add used extensions
  llvm::SmallVector< llvm::Value*, 5> OCLExtElts;

#define OPENCLEXT(nm)  if (sUsedExts._##nm) \
  OCLExtElts.push_back(llvm::MDString::get(M.getContext(), #nm));
#include "clang/Basic/OpenCLExtensions.def"

  llvm::NamedMDNode *OCLExtMD =
    M.getOrInsertNamedMetadata("opencl.used.extensions");

  OCLExtMD->addOperand(llvm::MDNode::get(M.getContext(), OCLExtElts));

  // Add used optional core features
  llvm::SmallVector< llvm::Value*, 5> OCLOptCoreElts;

  if (bUseDoubles)
    OCLOptCoreElts.push_back(llvm::MDString::get(M.getContext(), "cl_doubles"));

  if (bUseImages)
    OCLOptCoreElts.push_back(llvm::MDString::get(M.getContext(), "cl_images"));

  llvm::NamedMDNode *OptCoreMD =
    M.getOrInsertNamedMetadata("opencl.used.optional.core.features");
  OptCoreMD->addOperand(llvm::MDNode::get(M.getContext(), OCLOptCoreElts));

  // Add build options
  llvm::NamedMDNode *OCLCompOptsMD =
    M.getOrInsertNamedMetadata("opencl.compiler.options");
      llvm::SmallVector<llvm::Value*,5> OCLBuildOptions;
  for (std::list<std::string>::const_iterator it = sBuildOptions.begin(),
       e = sBuildOptions.end(); it != e ; ++it){
        OCLBuildOptions.push_back(llvm::MDString::get(M.getContext(), *it));
  }
  OCLCompOptsMD->addOperand(llvm::MDNode::get(M.getContext(), OCLBuildOptions));
}

static void FunctionAddSPIRMetadata(Function &F, bool &bUseDoubles, OCLExtensionsTy &sUsedExts) {
  Type *pDoubleType = Type::getDoubleTy(F.getParent()->getContext());
  Type *pHalfType = Type::getHalfTy(F.getParent()->getContext());

  for (Function::arg_iterator AI = F.arg_begin(), AE = F.arg_end();
       AI != AE; ++AI) {
    if (searchTypeInType(AI->getType(), pDoubleType, false))
      bUseDoubles = true;
    if (searchTypeInType(AI->getType(), pHalfType, true))
      sUsedExts._cl_khr_fp16 = true;
  }

  for (Function::iterator BB = F.begin(), E = F.end(); BB != E; ++BB)
    for (BasicBlock::iterator I = BB->begin(), E = BB->end(); I != E; ++I) {
      if (searchTypeInType(I->getType(), pDoubleType, false))
        if (!(dyn_cast<FPExtInst>(I)))
          bUseDoubles = true;
      if (searchTypeInType(I->getType(), pHalfType, true))
        sUsedExts._cl_khr_fp16 = true;

      for (Instruction::op_iterator OI = (*I).op_begin(), OE = (*I).op_end();
           OI != OE; ++OI) {
        if (searchTypeInType((*OI)->getType(), pDoubleType, false))
          if (!(dyn_cast<CallInst>(I) &&
                dyn_cast<CallInst>(I)->getCalledFunction()->isVarArg()))
            bUseDoubles = true;
        if (searchTypeInType((*OI)->getType(), pHalfType, true))
          sUsedExts._cl_khr_fp16 = true;
      }

      CallInst* pCallInst = dyn_cast<CallInst>(I);
      if (pCallInst && pCallInst->getCalledFunction()) {
        std::string funcName = pCallInst->getCalledFunction()->getName().str();

        for (size_t i = 0; i < sizeof(funcCallHandlers)/sizeof(funcCallHandlers[0]); i++) {
          if (funcName.find(funcCallHandlers[i].funcName) == 0)
            funcCallHandlers[i].handler(pCallInst, sUsedExts);
        }
      }
    }
}
