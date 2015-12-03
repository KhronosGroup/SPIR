// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef short short2 __attribute__((ext_vector_type(2)));
typedef short short3 __attribute__((ext_vector_type(3)));
typedef short short4 __attribute__((ext_vector_type(4)));
typedef short short8 __attribute__((ext_vector_type(8)));
typedef short short16 __attribute__((ext_vector_type(16)));

kernel void f1(short c){}
kernel void f2(short2 c){}
kernel void f3(short3 c){}
kernel void f4(short4 c){}
kernel void f8(short8 c){}
kernel void f16(short16 c){}

// CHECK:!{!"kernel_arg_type", !"short"}
// CHECK:!{!"kernel_arg_base_type", !"short"}

// CHECK:!{!"kernel_arg_type", !"short2"}
// CHECK:!{!"kernel_arg_base_type", !"short2"}

// CHECK:!{!"kernel_arg_type", !"short3"}
// CHECK:!{!"kernel_arg_base_type", !"short3"}

// CHECK:!{!"kernel_arg_type", !"short4"}
// CHECK:!{!"kernel_arg_base_type", !"short4"}

// CHECK:!{!"kernel_arg_type", !"short8"}
// CHECK:!{!"kernel_arg_base_type", !"short8"}

// CHECK:!{!"kernel_arg_type", !"short16"}
// CHECK:!{!"kernel_arg_base_type", !"short16"}
