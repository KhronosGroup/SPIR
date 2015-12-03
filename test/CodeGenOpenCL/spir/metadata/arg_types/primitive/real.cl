// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

#pragma OPENCL EXTENSION cl_khr_fp64 : enable

kernel void f2(float i){}

kernel void f3(double i){}

// CHECK: !{!"kernel_arg_type", !"float"}
// CHECK: !{!"kernel_arg_base_type", !"float"}

// CHECK: !{!"kernel_arg_type", !"double"}
// CHECK: !{!"kernel_arg_base_type", !"double"}
