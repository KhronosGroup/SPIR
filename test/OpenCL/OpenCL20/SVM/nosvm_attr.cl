// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -fsyntax-only -verify  %s
// RUN: %clang_cc1 -O0 -cl-std=CL1.2 -D OCL12 -fsyntax-only -verify  %s

#ifndef OCL12

int __attribute__((nosvm)) i; // expected-error {{nosvm attribute should be used with pointer variables only}}
int __attribute__((nosvm)) *pi; // should compile fine

kernel void foo(global int __attribute__((nosvm)) *in) { // should compile fine
}

kernel void foo2(int __attribute__((nosvm)) i) { // expected-error {{nosvm attribute should be used with pointer variables only}}
}

#else

int __attribute__((nosvm)) * constant pi = (int *)0; // expected-error {{nosvm attribute supported in OpenCL 2.0 and above}}

#endif