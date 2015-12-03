// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef char char2 __attribute__((ext_vector_type(2)));
typedef char char3 __attribute__((ext_vector_type(3)));
typedef char char4 __attribute__((ext_vector_type(4)));
typedef char char8 __attribute__((ext_vector_type(8)));
typedef char char16 __attribute__((ext_vector_type(16)));

kernel void f1(char c){}
kernel void f2(char2 c){}
kernel void f3(char3 c){}
kernel void f4(char4 c){}
kernel void f8(char8 c){}
kernel void f16(char16 c){}

// CHECK:!{!"kernel_arg_type", !"char"}
// CHECK:!{!"kernel_arg_base_type", !"char"}

// CHECK:!{!"kernel_arg_type", !"char2"}
// CHECK:!{!"kernel_arg_base_type", !"char2"}

// CHECK:!{!"kernel_arg_type", !"char3"}
// CHECK:!{!"kernel_arg_base_type", !"char3"}

// CHECK:!{!"kernel_arg_type", !"char4"}
// CHECK:!{!"kernel_arg_base_type", !"char4"}

// CHECK:!{!"kernel_arg_type", !"char8"}
// CHECK:!{!"kernel_arg_base_type", !"char8"}

// CHECK:!{!"kernel_arg_type", !"char16"}
// CHECK:!{!"kernel_arg_base_type", !"char16"}
