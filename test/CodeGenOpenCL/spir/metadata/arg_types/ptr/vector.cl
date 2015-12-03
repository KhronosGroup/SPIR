// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef int int2 __attribute__((ext_vector_type(2)));
typedef global int2* PvInt2;

kernel void f1(global int2 *I) {}
kernel void f2(PvInt2 I) {}

// CHECK: !{!"kernel_arg_type", !"int2*"}
// CHECK: !{!"kernel_arg_base_type", !"int2*"}
// CHECK: !{!"kernel_arg_type", !"PvInt2"}
