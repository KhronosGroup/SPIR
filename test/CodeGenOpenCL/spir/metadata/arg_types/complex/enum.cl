// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

enum _YN {Yes, No};

typedef enum _YN YN;

kernel void f1(enum _YN x) {}

kernel void f2(YN x) {}

// CHECK: !{!"kernel_arg_type", !"enum _YN"}
// CHECK: !{!"kernel_arg_base_type", !"enum _YN"}

// CHECK: !{!"kernel_arg_type", !"YN"}
