//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0

kernel void mykernel() { } //expected-note {{previous definition is here}}
kernel void mykernel(int a) { } //expected-error {{definition with same mangled name as another definition}}

template<class T>
kernel void mykernel2(T a) { } //expected-error {{kernel functions cannot be a template}}

kernel int mykernel3() { return 1; } //expected-error {{kernel must have void return type}}
