// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef constant char* ConstPChar;

kernel void f1(constant char* i){}
kernel void f3(ConstPChar i){}

// CHECK: !{!"kernel_arg_addr_space", i32 2}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 0}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 1}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 3}
// CHECK-NOT: !{!"kernel_arg_addr_space", i32 4}
