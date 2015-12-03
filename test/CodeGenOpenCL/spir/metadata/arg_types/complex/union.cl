// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

union _YN {
  int x;
  float y;
};

typedef union _YN YN;

kernel void f1(union _YN x) {}

kernel void f2(YN x) {}

// CHECK: !{!"kernel_arg_type", !"union _YN"}
// CHECK: !{!"kernel_arg_base_type", !"union _YN"}

// CHECK: !{!"kernel_arg_type", !"YN"}
