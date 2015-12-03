// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef unsigned char uchar;

typedef uchar uchar2 __attribute__((ext_vector_type(2)));
typedef uchar uchar3 __attribute__((ext_vector_type(3)));
typedef uchar uchar4 __attribute__((ext_vector_type(4)));
typedef uchar uchar8 __attribute__((ext_vector_type(8)));
typedef uchar uchar16 __attribute__((ext_vector_type(16)));

kernel void f1(uchar c){}
kernel void f2(uchar2 c){}
kernel void f3(uchar3 c){}
kernel void f4(uchar4 c){}
kernel void f8(uchar8 c){}
kernel void f16(uchar16 c){}

// CHECK:!{!"kernel_arg_type", !"uchar"}
// CHECK:!{!"kernel_arg_base_type", !"uchar"}

// CHECK:!{!"kernel_arg_type", !"uchar2"}
// CHECK:!{!"kernel_arg_base_type", !"uchar2"}

// CHECK:!{!"kernel_arg_type", !"uchar3"}
// CHECK:!{!"kernel_arg_base_type", !"uchar3"}

// CHECK:!{!"kernel_arg_type", !"uchar4"}
// CHECK:!{!"kernel_arg_base_type", !"uchar4"}

// CHECK:!{!"kernel_arg_type", !"uchar8"}
// CHECK:!{!"kernel_arg_base_type", !"uchar8"}

// CHECK:!{!"kernel_arg_type", !"uchar16"}
// CHECK:!{!"kernel_arg_base_type", !"uchar16"}
