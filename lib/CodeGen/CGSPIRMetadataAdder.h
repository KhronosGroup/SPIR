//===- SPIRMetadataAdder.h - Add SPIR related module scope metadata -------===//
//
// TODO: add copyright info
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Module.h"

#ifndef CLANG_CODEGEN_SPIRMETADATAADDER_H
#define CLANG_CODEGEN_SPIRMETADATAADDER_H

namespace clang {

namespace CodeGen {

  void AddSPIRMetadata(llvm::Module &M, int OCLVersion, std::list<std::string> sBuildOptions);

} // end namespace CodeGen
} // end namespace clang
#endif
