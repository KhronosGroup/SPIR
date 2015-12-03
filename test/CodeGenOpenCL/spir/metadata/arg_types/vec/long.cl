// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef long long2 __attribute__((ext_vector_type(2)));
typedef long long3 __attribute__((ext_vector_type(3)));
typedef long long4 __attribute__((ext_vector_type(4)));
typedef long long8 __attribute__((ext_vector_type(8)));
typedef long long16 __attribute__((ext_vector_type(16)));

kernel void f1(long c){}
kernel void f2(long2 c){}
kernel void f3(long3 c){}
kernel void f4(long4 c){}
kernel void f8(long8 c){}
kernel void f16(long16 c){}

// CHECK:!{!"kernel_arg_type", !"long"}
// CHECK:!{!"kernel_arg_base_type", !"long"}

// CHECK:!{!"kernel_arg_type", !"long2"}
// CHECK:!{!"kernel_arg_base_type", !"long2"}

// CHECK:!{!"kernel_arg_type", !"long3"}
// CHECK:!{!"kernel_arg_base_type", !"long3"}

// CHECK:!{!"kernel_arg_type", !"long4"}
// CHECK:!{!"kernel_arg_base_type", !"long4"}

// CHECK:!{!"kernel_arg_type", !"long8"}
// CHECK:!{!"kernel_arg_base_type", !"long8"}

// CHECK:!{!"kernel_arg_type", !"long16"}
// CHECK:!{!"kernel_arg_base_type", !"long16"}
