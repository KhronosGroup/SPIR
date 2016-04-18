// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify -emit-llvm -O0 -o /dev/null
// expected-no-diagnostics

struct foo
{
  static int m1;
  static const int m2 = 10;
  static __local int m3;
};

int foo::m1 = 10;
__local int foo::m3 = 10;

foo a;

void func1() {
  foo b;
  static int c = 10;
}
