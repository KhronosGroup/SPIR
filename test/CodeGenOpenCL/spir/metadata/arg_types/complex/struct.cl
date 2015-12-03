// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

struct _YN {
  int x;
  float y;
};

typedef struct _YN YN;

kernel void f1(struct _YN x) {}

kernel void f2(YN x) {}

// CHECK: !{!"kernel_arg_type", !"struct _YN"}
// CHECK: !{!"kernel_arg_base_type", !"struct _YN"}

// CHECK: !{!"kernel_arg_type", !"YN"}
