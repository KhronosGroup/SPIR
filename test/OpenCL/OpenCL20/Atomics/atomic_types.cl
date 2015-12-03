// RUN: %clang_cc1 -emit-llvm -O0 -cl-std=CL2.0 -o - %s | FileCheck %s

#pragma OPENCL EXTENSION cl_khr_int64_base_atomics:enable
#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics:enable

void test_atomic() {

  atomic_int a1;
// CHECK: %a1 = alloca i32
  atomic_uint a2;
// CHECK: %a2 = alloca i32
  atomic_long a3;
// CHECK: %a3 = alloca i64
  atomic_ulong a4;
// CHECK: %a4 = alloca i64
  atomic_float a5;
// CHECK: %a5 = alloca float
  atomic_double a6;
// CHECK: %a6 = alloca double
}
