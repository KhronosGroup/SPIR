// RUN: %clang_cc1 -fsyntax-only -verify %s

float __attribute__((overloadable)) ocl_builtin_func(float f) { return f; }
float __attribute__((overloadable)) ocl_builtin_func_2args(float arg1, float arg2) { return arg1 + arg2; }

__kernel void test() {
  int p = ocl_builtin_func(3); // expected-warning {{implicit conversion from integral type to floating point type for overloadable function might lead to ambiguity}}
  int q = ocl_builtin_func_2args(3.f, 3); // expected-warning {{implicit conversion from integral type to floating point type for overloadable function might lead to ambiguity}}
}
