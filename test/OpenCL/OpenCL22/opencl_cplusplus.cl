// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -O0 -o %t
// RUN: opt -verify %t
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-spirv -O0 -o %t
// RUN: llvm-spirv --to-text %t -o - | FileCheck %s
// CHECK: "testKernel"

template<typename T>
T Func(T var) {
  return var + 5;
}

kernel void testKernel() {
  int var = Func(10);
}
