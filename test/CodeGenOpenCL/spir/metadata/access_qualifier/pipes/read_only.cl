// RUN: %clang_cc1 %s -O0 -cl-std=CL2.0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -cl-std=CL2.0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef pipe int MyPipe;

kernel void f1(read_only pipe int i){}

kernel void f2(pipe int i){}

kernel void f3(read_only MyPipe i){}

// CHECK: !{!"kernel_arg_access_qual", !"read_only"}
// CHECK-NOT: !{!"kernel_arg_access_qual", !"write_only"}
// CHECK-NOT: !{!"kernel_arg_access_qual", !"read_write"}
// CHECK-NOT: !{!"kernel_arg_access_qual", !"none"}
