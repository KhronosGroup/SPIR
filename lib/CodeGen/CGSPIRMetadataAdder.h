//===- SPIRMetadataAdder.h - Add SPIR related module scope metadata -------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Module.h"
#include <list>
#include <string>

#ifndef CLANG_CODEGEN_SPIRMETADATAADDER_H
#define CLANG_CODEGEN_SPIRMETADATAADDER_H

namespace clang {

namespace CodeGen {

  void AddSPIRMetadata(llvm::Module &M, int OCLVersion, std::list<std::string> sBuildOptions);

} // end namespace CodeGen
} // end namespace clang
#endif
