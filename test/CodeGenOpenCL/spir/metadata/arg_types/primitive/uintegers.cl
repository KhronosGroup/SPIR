// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

kernel void f1(unsigned char i){}

kernel void f2(unsigned short i){}

kernel void f3(unsigned int i){}

kernel void f4(unsigned long j){}

// CHECK: !{!"kernel_arg_type", !"uchar"}
// CHECK: !{!"kernel_arg_base_type", !"uchar"}

// CHECK: !{!"kernel_arg_type", !"uint"}
// CHECK: !{!"kernel_arg_base_type", !"uint"}

// CHECK: !{!"kernel_arg_type", !"ulong"}
// CHECK: !{!"kernel_arg_base_type", !"ulong"}
