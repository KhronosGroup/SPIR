// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef int int2 __attribute__((ext_vector_type(2)));
typedef int int3 __attribute__((ext_vector_type(3)));
typedef int int4 __attribute__((ext_vector_type(4)));
typedef int int8 __attribute__((ext_vector_type(8)));
typedef int int16 __attribute__((ext_vector_type(16)));

kernel void f1(int c){}
kernel void f2(int2 c){}
kernel void f3(int3 c){}
kernel void f4(int4 c){}
kernel void f8(int8 c){}
kernel void f16(int16 c){}

// CHECK:!{!"kernel_arg_type", !"int"}
// CHECK:!{!"kernel_arg_base_type", !"int"}

// CHECK:!{!"kernel_arg_type", !"int2"}
// CHECK:!{!"kernel_arg_base_type", !"int2"}

// CHECK:!{!"kernel_arg_type", !"int3"}
// CHECK:!{!"kernel_arg_base_type", !"int3"}

// CHECK:!{!"kernel_arg_type", !"int4"}
// CHECK:!{!"kernel_arg_base_type", !"int4"}

// CHECK:!{!"kernel_arg_type", !"int8"}
// CHECK:!{!"kernel_arg_base_type", !"int8"}

// CHECK:!{!"kernel_arg_type", !"int16"}
// CHECK:!{!"kernel_arg_base_type", !"int16"}
