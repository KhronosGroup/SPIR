// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

kernel void f1(constant const int* P) {}

// CHECK: !{!"kernel_arg_type_qual", !"const"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"volatile"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"pipe"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"restrict"}
