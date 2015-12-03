// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

kernel void f1(global volatile int* P) {}

// CHECK: !{!"kernel_arg_type_qual", !"volatile"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"restrict"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"pipe"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"const"}
