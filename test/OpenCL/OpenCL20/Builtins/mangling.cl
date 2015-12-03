// We check that the address spaces are mangled the same in both version of OpenCL

// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -triple spir-unknown-unknown -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -O0 -cl-std=CL1.2 -triple spir-unknown-unknown -emit-llvm -o - %s | FileCheck %s

__attribute__((overloadable)) void foo(private char *);
__attribute__((overloadable)) void foo(global char *);
__attribute__((overloadable)) void foo(constant char *);
__attribute__((overloadable)) void foo(local char *);

void bar(global char *gp, constant char *cp, local char *lp) {
  private char* pp;
// CHECK: call spir_func void @_Z3fooPc
  foo(pp);
// CHECK: call spir_func void @_Z3fooPU3AS1c
  foo(gp);
// CHECK: call spir_func void @_Z3fooPU3AS2c
  foo(cp);
// CHECK: call spir_func void @_Z3fooPU3AS3c
  foo(lp);
}
