// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s
typedef struct {
  int f;
} Anonymous;

typedef global Anonymous* PAnonymous;

kernel void f1(global Anonymous *A) {}
kernel void f2(PAnonymous P) {}

// CHECK: !{!"kernel_arg_type", !"Anonymous*"}
// CHECK: !{!"kernel_arg_base_type", !"struct __Anonymous*"}
// CHECK: !{!"kernel_arg_type", !"PAnonymous"}
