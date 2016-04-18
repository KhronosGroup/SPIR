// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify -emit-llvm -O0 -o /dev/null
// expected-no-diagnostics

struct A{};

A foo2() {
  return A();
}

__global A a = foo2();

kernel void w() {
  __local A b = foo2();
  A c = foo2();
}
