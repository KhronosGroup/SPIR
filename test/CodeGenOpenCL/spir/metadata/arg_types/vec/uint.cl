// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef unsigned int uint;

typedef uint uint2 __attribute__((ext_vector_type(2)));
typedef uint uint3 __attribute__((ext_vector_type(3)));
typedef uint uint4 __attribute__((ext_vector_type(4)));
typedef uint uint8 __attribute__((ext_vector_type(8)));
typedef uint uint16 __attribute__((ext_vector_type(16)));

kernel void f1(uint c){}
kernel void f2(uint2 c){}
kernel void f3(uint3 c){}
kernel void f4(uint4 c){}
kernel void f8(uint8 c){}
kernel void f16(uint16 c){}

// CHECK:!{!"kernel_arg_type", !"uint"}
// CHECK:!{!"kernel_arg_base_type", !"uint"}

// CHECK:!{!"kernel_arg_type", !"uint2"}
// CHECK:!{!"kernel_arg_base_type", !"uint2"}

// CHECK:!{!"kernel_arg_type", !"uint3"}
// CHECK:!{!"kernel_arg_base_type", !"uint3"}

// CHECK:!{!"kernel_arg_type", !"uint4"}
// CHECK:!{!"kernel_arg_base_type", !"uint4"}

// CHECK:!{!"kernel_arg_type", !"uint8"}
// CHECK:!{!"kernel_arg_base_type", !"uint8"}

// CHECK:!{!"kernel_arg_type", !"uint16"}
// CHECK:!{!"kernel_arg_base_type", !"uint16"}
