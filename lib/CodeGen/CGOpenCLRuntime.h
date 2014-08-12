//===----- CGOpenCLRuntime.h - Interface to OpenCL Runtimes -----*- C++ -*-===//
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

#ifndef CLANG_CODEGEN_OPENCLRUNTIME_H
#define CLANG_CODEGEN_OPENCLRUNTIME_H

#include "clang/AST/Type.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Value.h"

namespace clang {

class VarDecl;

namespace CodeGen {

class CodeGenFunction;
class CodeGenModule;

class CGOpenCLRuntime {
protected:
  CodeGenModule &CGM;

  llvm::Type *PipeTy;
  llvm::Type *BlockTy;
public:
  CGOpenCLRuntime(CodeGenModule &CGM) : CGM(CGM), PipeTy(0), BlockTy(0) {}
  virtual ~CGOpenCLRuntime();

  /// Emit the IR required for a work-group-local variable declaration, and add
  /// an entry to CGF's LocalDeclMap for D.  The base class does this using
  /// CodeGenFunction::EmitStaticVarDecl to emit an internal global for D.
  virtual void EmitWorkGroupLocalVarDecl(CodeGenFunction &CGF,
                                         const VarDecl &D);

  virtual llvm::Type *convertOpenCLSpecificType(const Type *T);

  llvm::Type *getPipeType();

  llvm::Type *getBlockType();

  // \brief Returnes a value which indicates the size in bytes of the pipe
  // element.
  llvm::Value *getPipeElemSize(const Expr *PipeArg);
  llvm::Value *getPipeElemAlign(const Expr *PipeArg);
};

class Ocl20Mangler {
public:
  Ocl20Mangler(llvm::SmallVectorImpl<char>&);

  // \brief Appends the mangled representation of reserve_id_t parameter to the
  //  mangled string.
  Ocl20Mangler& appendReservedId();

  // \brief Appends the mangled representation of pipe_t parameter to the
  //  mangled string.
  Ocl20Mangler& appendPipe();

  // \brief Appends the mangled representation of 'int' parameter to the
  //  mangled string.
  Ocl20Mangler& appendInt();

  // \brief Appends the mangled representation of 'unsigned int' parameter to the
  // mangled string.
  Ocl20Mangler& appendUint();

  // \brief Appends the mangled representation of a pointer.
  Ocl20Mangler& appendPointer();

  // \brief Appends the mangled representation of void.
  Ocl20Mangler& appendVoid();
  
  // \brief Appends the mangled representation of a pointer with a given address
  // space.
  // \param addressSapace The address space of the pointer. Valid values are
  // [0,4].
  Ocl20Mangler& appendPointer(int addressSapace);

private:

  // \brief Appends the given string to the mangled prototype.
  Ocl20Mangler& appendString(llvm::StringRef);

  llvm::SmallVectorImpl<char> *MangledString;
};

}
}

#endif
