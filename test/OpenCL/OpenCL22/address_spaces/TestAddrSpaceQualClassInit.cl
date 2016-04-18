// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics 

struct A { int a, b; int f(); };

int fn1(int x) {
  return A{x, 5}.f();
}

struct B { int &r; int &f() { return r; } };

int &fn2(int &v) {
  return B{v}.f();
}

namespace NonTrivialInit {
  struct A { A(); A(const A&) = delete; ~A(); };
  struct B { A a[20]; };
  B b[30] = {};
}
