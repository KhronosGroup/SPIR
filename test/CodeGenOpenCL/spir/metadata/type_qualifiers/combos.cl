// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

kernel void f1(constant const int* restrict P) {}
kernel void f2(constant const volatile int* restrict P) {}

// CHECK: !{!"kernel_arg_type_qual", !"restrict const"}
// CHECK: !{!"kernel_arg_type_qual", !"restrict const volatile"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"volatile"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"pipe"}
