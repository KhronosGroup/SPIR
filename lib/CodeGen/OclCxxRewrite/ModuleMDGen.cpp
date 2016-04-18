//===- ModuleMDGen.cpp - Module metadata generator pass (OCLC++)-*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//
//
// Copyright (c) 2015 The Khronos Group Inc.
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


#include "clang/CodeGen/OclCxxRewrite/ModuleMDGen.h"

#include "llvm/Pass.h"
#include "llvm/PassSupport.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Module.h"

#define DEBUG_TYPE "OclCxxModuleMDGen"


/// \brief Adds metadata (node) with integer constant (immediate).
///
/// \param C     LLVM context (connected to modified module(s)).
/// \param Value Integral value (arbitrary precision).
///
/// \return Metadata (node) with integral value.
inline static llvm::Metadata *addAPIntMetadata(llvm::LLVMContext &C,
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


#define OP_MD_PREFIX "spirv."

/// \brief Adds metadata representing OpString in SPIR-V friendly LLVM.
///
/// \param M   LLVM module.
/// \param Str Text content stored in metadata node.
///
/// \return Metadata node attached to named metadata which contains added
///         information.
static llvm::Metadata *addOpStringMetadata(llvm::Module &M,
                                           llvm::StringRef Str) {
  llvm::LLVMContext &C = M.getContext();


  auto MDOpStringNodes = M.getOrInsertNamedMetadata(OP_MD_PREFIX "String");

  auto MDOpStringString = llvm::MDString::get(C, Str);
  auto MDOpStringNode = llvm::MDNode::get(C, MDOpStringString);
  MDOpStringNodes->addOperand(MDOpStringNode);

  return MDOpStringNode;
}

/// \brief Indicates that LLVM module has got metadata representing OpSource.
///
/// \param M Checked LLVM module.
///
/// \return <b>true</b> if module contains metadata representing OpSource;
///         otherwise, <b>false</b>.
static bool hasOpSourceMetadata(llvm::Module &M) {
  return M.getNamedMetadata(OP_MD_PREFIX "Source") != nullptr;
}

/// \brief Adds metadata representing OpSource in SPIR-V friendly LLVM.
///
/// \param M           LLVM module.
/// \param OclVersion  Version of OpenCL (single number in form:
///                    "Major" * 100 + "Minor")
/// \param SrcFilePath Path to file with source code (optional).
/// \param SrcCode     Embedded source code (optional).
///                    Whole or part of source code directly embedded in module.
///
/// \return Metadata node attached to named metadata which contains added
///         information.
static llvm::Metadata *addOpSourceMetadata(
    llvm::Module &M,
    int32_t OclVersion,
    llvm::StringRef SrcFilePath = llvm::StringRef(),
    llvm::StringRef SrcCode = llvm::StringRef()) {
  llvm::LLVMContext &C = M.getContext();


  auto MDOpSourceNodes = M.getOrInsertNamedMetadata(OP_MD_PREFIX "Source");
  llvm::SmallVector<llvm::Metadata *, 4> MDOpSource;

  // Language: OpenCL_CPP (4).
  auto MDOpSourceLanguage = addInt32Metadata(C, 4);
  MDOpSource.push_back(MDOpSourceLanguage);
  // OpenCL (language) version.
  auto MDOpSourceVersion  = addInt32Metadata(C, OclVersion);
  MDOpSource.push_back(MDOpSourceVersion);

  // [Optional] Source file (<id> of OpString).
  if (!SrcFilePath.empty()) {
    auto MDOpSourceFilePathNode = addOpStringMetadata(M, SrcFilePath);
    MDOpSource.push_back(MDOpSourceFilePathNode);
  }

  // [Optional] Direct source code.
  if (!SrcCode.empty()) {
    auto MDSourceCode = llvm::MDString::get(C, SrcCode);
    MDOpSource.push_back(MDSourceCode);
  }

  auto MDOpSourceNode = llvm::MDNode::get(C, MDOpSource);
  MDOpSourceNodes->addOperand(MDOpSourceNode);

  return MDOpSourceNode;
}

#undef OP_MD_PREFIX


namespace {

struct OclCxxModuleMDGen : llvm::ModulePass {
  /// Identifier of the pass (its address).
  static char ID;

  OclCxxModuleMDGen() : ModulePass(ID) {}


  bool runOnModule(llvm::Module &M) override {
    if (hasOpSourceMetadata(M))
      return false;

    addOpSourceMetadata(M, 202000, M.getModuleIdentifier());

    return true;
  }
};
}

char OclCxxModuleMDGen::ID = 0;

using namespace llvm;
INITIALIZE_PASS(OclCxxModuleMDGen,
                "oclcxx-module-md-gen",
                "Module metadata generator for OpenCL C++",
                false, false)

ModulePass *llvm::createOclCxxModuleMDGenPass() {
  return new OclCxxModuleMDGen;
}
