// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify -emit-llvm -O0 -o /dev/null
// expected-no-diagnostics

class Foo
{
 public:
  int x;
  int y;
  Foo (int i, int j) { x = i; y = j; }
};


Foo foo(10, 11);

kernel void w() {
  int Foo::* pmi = &Foo::y;
}  