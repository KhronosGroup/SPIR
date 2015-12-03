// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float3 __attribute__((ext_vector_type(3)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));
typedef float float16 __attribute__((ext_vector_type(16)));

kernel void f1(float c){}
kernel void f2(float2 c){}
kernel void f3(float3 c){}
kernel void f4(float4 c){}
kernel void f8(float8 c){}
kernel void f16(float16 c){}

// CHECK:!{!"kernel_arg_type", !"float"}
// CHECK:!{!"kernel_arg_base_type", !"float"}

// CHECK:!{!"kernel_arg_type", !"float2"}
// CHECK:!{!"kernel_arg_base_type", !"float2"}

// CHECK:!{!"kernel_arg_type", !"float3"}
// CHECK:!{!"kernel_arg_base_type", !"float3"}

// CHECK:!{!"kernel_arg_type", !"float4"}
// CHECK:!{!"kernel_arg_base_type", !"float4"}

// CHECK:!{!"kernel_arg_type", !"float8"}
// CHECK:!{!"kernel_arg_base_type", !"float8"}

// CHECK:!{!"kernel_arg_type", !"float16"}
// CHECK:!{!"kernel_arg_base_type", !"float16"}
