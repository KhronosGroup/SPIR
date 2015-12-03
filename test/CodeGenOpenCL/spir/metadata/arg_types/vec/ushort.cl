// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef unsigned short ushort;

typedef ushort ushort2 __attribute__((ext_vector_type(2)));
typedef ushort ushort3 __attribute__((ext_vector_type(3)));
typedef ushort ushort4 __attribute__((ext_vector_type(4)));
typedef ushort ushort8 __attribute__((ext_vector_type(8)));
typedef ushort ushort16 __attribute__((ext_vector_type(16)));

kernel void f1(ushort c){}
kernel void f2(ushort2 c){}
kernel void f3(ushort3 c){}
kernel void f4(ushort4 c){}
kernel void f8(ushort8 c){}
kernel void f16(ushort16 c){}

// CHECK:!{!"kernel_arg_type", !"ushort"}
// CHECK:!{!"kernel_arg_base_type", !"ushort"}

// CHECK:!{!"kernel_arg_type", !"ushort2"}
// CHECK:!{!"kernel_arg_base_type", !"ushort2"}

// CHECK:!{!"kernel_arg_type", !"ushort3"}
// CHECK:!{!"kernel_arg_base_type", !"ushort3"}

// CHECK:!{!"kernel_arg_type", !"ushort4"}
// CHECK:!{!"kernel_arg_base_type", !"ushort4"}

// CHECK:!{!"kernel_arg_type", !"ushort8"}
// CHECK:!{!"kernel_arg_base_type", !"ushort8"}

// CHECK:!{!"kernel_arg_type", !"ushort16"}
// CHECK:!{!"kernel_arg_base_type", !"ushort16"}
