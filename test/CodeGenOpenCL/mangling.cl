// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=CL2.0 -emit-llvm -O0 -o - | FileCheck %s

typedef float float2 __attribute__((ext_vector_type(2)));

float __attribute__((overloadable)) dot(float2 p0, float2 p1);
kernel void test(float2 f) {
  dot(f,f);
// CHECK: _Z3dotDv2_fDv2_f
}
