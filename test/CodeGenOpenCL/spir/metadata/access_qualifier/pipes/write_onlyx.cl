// XFAIL: *
// RUN: %clang_cc1 -cl-std=CL2.0 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 -cl-std=CL2.0 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef write_only pipe int MyPipe;

kernel void f(MyPipe p){}
// CHECK: !{!"kernel_arg_access_qual", !"write_only"}
// CHECK-NOT: !{!"kernel_arg_access_qual", matadata !"read_only"}
// CHECK-NOT: !{!"kernel_arg_access_qual", matadata !"read_write"}
// CHECK-NOT: !{!"kernel_arg_access_qual", matadata !"none"}
