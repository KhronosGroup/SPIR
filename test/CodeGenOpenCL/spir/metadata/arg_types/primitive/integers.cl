// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

kernel void f1(char i){}

kernel void f2(short i){}

kernel void f3(int i){}

kernel void f4(long j){}

// CHECK: !{!"kernel_arg_type", !"char"}
// CHECK: !{!"kernel_arg_base_type", !"char"}
// CHECK: !{!"kernel_arg_type", !"short"}
// CHECK: !{!"kernel_arg_base_type", !"short"}
// CHECK: !{!"kernel_arg_type", !"int"}
// CHECK: !{!"kernel_arg_base_type", !"int"}
// CHECK: !{!"kernel_arg_type", !"long"}
// CHECK: !{!"kernel_arg_base_type", !"long"}
