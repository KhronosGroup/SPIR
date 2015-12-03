// RUN: %clang_cc1 %s -cl-std=CL2.0 -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -cl-std=CL2.0 -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

kernel void f1(pipe int P) {}

// CHECK: !{!"kernel_arg_type_qual", !"pipe"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"volatile"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"restrict"}
// CHECK-NOT: !{!"kernel_arg_type_qual", !"const"}
