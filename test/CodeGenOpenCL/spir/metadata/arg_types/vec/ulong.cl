// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s
typedef unsigned long ulong;

typedef ulong ulong2 __attribute__((ext_vector_type(2)));
typedef ulong ulong3 __attribute__((ext_vector_type(3)));
typedef ulong ulong4 __attribute__((ext_vector_type(4)));
typedef ulong ulong8 __attribute__((ext_vector_type(8)));
typedef ulong ulong16 __attribute__((ext_vector_type(16)));

kernel void f1(ulong c){}
kernel void f2(ulong2 c){}
kernel void f3(ulong3 c){}
kernel void f4(ulong4 c){}
kernel void f8(ulong8 c){}
kernel void f16(ulong16 c){}

// CHECK:!{!"kernel_arg_type", !"ulong"}
// CHECK:!{!"kernel_arg_base_type", !"ulong"}

// CHECK:!{!"kernel_arg_type", !"ulong2"}
// CHECK:!{!"kernel_arg_base_type", !"ulong2"}

// CHECK:!{!"kernel_arg_type", !"ulong3"}
// CHECK:!{!"kernel_arg_base_type", !"ulong3"}

// CHECK:!{!"kernel_arg_type", !"ulong4"}
// CHECK:!{!"kernel_arg_base_type", !"ulong4"}

// CHECK:!{!"kernel_arg_type", !"ulong8"}
// CHECK:!{!"kernel_arg_base_type", !"ulong8"}

// CHECK:!{!"kernel_arg_type", !"ulong16"}
// CHECK:!{!"kernel_arg_base_type", !"ulong16"}
