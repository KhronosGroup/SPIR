// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef global int* PInt;

kernel void f1(global int *I) {}
kernel void f2(PInt I) {}

// CHECK: !{!"kernel_arg_type", !"int*"}
// CHECK: !{!"kernel_arg_base_type", !"int*"}
// CHECK: !{!"kernel_arg_type", !"PInt"}
