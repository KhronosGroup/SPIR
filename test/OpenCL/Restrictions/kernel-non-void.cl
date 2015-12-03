// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only

kernel int test(global int* d) { // expected-error {{kernel must have void return type}}
  int a = 5;
  return a;
}
