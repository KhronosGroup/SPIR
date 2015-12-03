// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef global char* GlobalPChar;

kernel void f1(global char* i){}
kernel void f2(GlobalPChar i){}

// CHECK: !{!"kernel_arg_addr_space", i32 1}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 0}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 2}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 3}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 4}
