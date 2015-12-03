// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

#pragma OPENCL EXTENSION cl_khr_fp64 : enable

typedef double double2 __attribute__((ext_vector_type(2)));
typedef double double3 __attribute__((ext_vector_type(3)));
typedef double double4 __attribute__((ext_vector_type(4)));
typedef double double8 __attribute__((ext_vector_type(8)));
typedef double double16 __attribute__((ext_vector_type(16)));

kernel void f1(double c){}
kernel void f2(double2 c){}
kernel void f3(double3 c){}
kernel void f4(double4 c){}
kernel void f8(double8 c){}
kernel void f16(double16 c){}

// CHECK:!{!"kernel_arg_type", !"double"}
// CHECK:!{!"kernel_arg_base_type", !"double"}

// CHECK:!{!"kernel_arg_type", !"double2"}
// CHECK:!{!"kernel_arg_base_type", !"double2"}

// CHECK:!{!"kernel_arg_type", !"double3"}
// CHECK:!{!"kernel_arg_base_type", !"double3"}

// CHECK:!{!"kernel_arg_type", !"double4"}
// CHECK:!{!"kernel_arg_base_type", !"double4"}

// CHECK:!{!"kernel_arg_type", !"double8"}
// CHECK:!{!"kernel_arg_base_type", !"double8"}

// CHECK:!{!"kernel_arg_type", !"double16"}
// CHECK:!{!"kernel_arg_base_type", !"double16"}
