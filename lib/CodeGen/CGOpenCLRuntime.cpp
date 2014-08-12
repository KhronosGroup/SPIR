//===----- CGOpenCLRuntime.cpp - Interface to OpenCL Runtimes -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This provides an abstract class for OpenCL code generation.  Concrete
// subclasses of this implement code generation for specific OpenCL
// runtime libraries.
//
//===----------------------------------------------------------------------===//

#include "CGOpenCLRuntime.h"
#include "CodeGenFunction.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalValue.h"
#include <assert.h>

using namespace clang;
using namespace CodeGen;

CGOpenCLRuntime::~CGOpenCLRuntime() {}

void CGOpenCLRuntime::EmitWorkGroupLocalVarDecl(CodeGenFunction &CGF,
                                                const VarDecl &D) {
  return CGF.EmitStaticVarDecl(D, llvm::GlobalValue::InternalLinkage);
}

llvm::Type *CGOpenCLRuntime::convertOpenCLSpecificType(const Type *T) {
  assert(T->isOpenCLSpecificType() &&
         "Not an OpenCL specific type!");
  const unsigned int GlobalAS =
    CGM.getContext().getTargetAddressSpace(LangAS::opencl_global), PrivateAS = 0;

  switch (cast<BuiltinType>(T)->getKind()) {
  default:
    llvm_unreachable("Unexpected opencl builtin type!");
    return 0;
  case BuiltinType::OCLImage1d:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image1d_t"), GlobalAS);
  case BuiltinType::OCLImage1dArray:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image1d_array_t"), GlobalAS);
  case BuiltinType::OCLImage1dBuffer:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image1d_buffer_t"), GlobalAS);
  case BuiltinType::OCLImage2d:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image2d_t"), GlobalAS);
  case BuiltinType::OCLImage2dArray:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image2d_array_t"), GlobalAS);
  case BuiltinType::OCLImage2dDepth:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image2d_depth_t"), GlobalAS);
  case BuiltinType::OCLImage2dArrayDepth:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image2d_array_depth_t"), GlobalAS);
  case BuiltinType::OCLImage2dMSAA:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image2d_msaa_t"), GlobalAS);
  case BuiltinType::OCLImage2dArrayMSAA:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image2d_array_msaa_t"), GlobalAS);
  case BuiltinType::OCLImage2dMSAADepth:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image2d_msaa_depth_t"), GlobalAS);
  case BuiltinType::OCLImage2dArrayMSAADepth:
    return llvm::PointerType::get(llvm::StructType::create(
                                  CGM.getLLVMContext(),
                                  "opencl.image2d_array_msaa_depth_t"),
                                  GlobalAS);
  case BuiltinType::OCLImage3d:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.image3d_t"), GlobalAS);
  case BuiltinType::OCLSampler:
    return llvm::IntegerType::get(CGM.getLLVMContext(),32);
  case BuiltinType::OCLEvent:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.event_t"), 0);
  case BuiltinType::OCLQueue:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.queue_t"), 0);
  case BuiltinType::OCLCLKEvent:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.clk_event_t"), 0);
  case BuiltinType::OCLReserveId:
    return llvm::PointerType::get(llvm::StructType::create(
                           CGM.getLLVMContext(), "opencl.reserve_id_t"), 0);
  }
}

llvm::Type *CGOpenCLRuntime::getPipeType() {
  if (!PipeTy)
    PipeTy = llvm::PointerType::get(llvm::StructType::create(
                                    CGM.getLLVMContext(), "opencl.pipe_t"), 1U);

  return PipeTy;
}

llvm::Type *CGOpenCLRuntime::getBlockType() {
  if (!BlockTy)
    BlockTy = llvm::PointerType::get(llvm::StructType::create(
                                     CGM.getLLVMContext(), "opencl.block"), 0);
  return BlockTy;
}

llvm::Value *CGOpenCLRuntime::getPipeElemSize(const Expr *PipeArg) {
  const PipeType* PipeTy = PipeArg->getType()->getAs<PipeType>();
  // The type of the last (implicit) argument to be passed.
  llvm::Type *Int32Ty = llvm::IntegerType::getInt32Ty(CGM.getLLVMContext());
  unsigned TypeSizeInBits = CGM.getContext().getTypeSize(
                                                      PipeTy->getElementType());
  return llvm::ConstantInt::get(Int32Ty,
                                TypeSizeInBits/8, // Size in bytes.
                                false);
}

llvm::Value *CGOpenCLRuntime::getPipeElemAlign(const Expr *PipeArg) {
  const PipeType* PipeTy = PipeArg->getType()->getAs<PipeType>();
  // The type of the last (implicit) argument to be passed.
  llvm::Type *Int32Ty = llvm::IntegerType::getInt32Ty(CGM.getLLVMContext());
  unsigned TypeSizeInBits = CGM.getContext().getTypeAlign(
                                                      PipeTy->getElementType());
  return llvm::ConstantInt::get(Int32Ty,
                                TypeSizeInBits/8, // Size in bytes.
                                false);
}

//
// Ocl20Mangler
//

Ocl20Mangler::Ocl20Mangler(llvm::SmallVectorImpl<char>& SS): MangledString(&SS) {}

Ocl20Mangler& Ocl20Mangler::appendReservedId() {
  this->appendString("16ocl_reserve_id_t");
  return *this;
}

Ocl20Mangler& Ocl20Mangler::appendPipe() {
  this->appendString("10ocl_pipe_t");
  return *this;
}

Ocl20Mangler& Ocl20Mangler::appendInt() {
  MangledString->push_back('i');
  return *this;
}

Ocl20Mangler& Ocl20Mangler::appendUint() {
  MangledString->push_back('j');
  return *this;
}

Ocl20Mangler& Ocl20Mangler::appendVoid() {
  MangledString->push_back('v');
  return *this;
}

Ocl20Mangler& Ocl20Mangler::appendPointer() {
  this->appendString("P");
  return *this;
}

Ocl20Mangler& Ocl20Mangler::appendPointer(int addressSpace) {
  assert(addressSpace >=0 && addressSpace <= 4 &&
         "Illegal address space for OpenCL");
  if (!addressSpace)
    return appendPointer();

  this->appendString("PU3AS");
  MangledString->push_back('0' + addressSpace);
  return *this;
}

Ocl20Mangler& Ocl20Mangler::appendString(llvm::StringRef S) {
  MangledString->append(S.begin(), S.end());
  return *this;
}

