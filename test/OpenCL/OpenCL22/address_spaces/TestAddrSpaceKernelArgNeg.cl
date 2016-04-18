// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify

kernel void worker0(int *arg) { } //expected-error {{pointer and reference arguments to kernel functions must reside in '__global', '__constant' or '__local' address space}}

kernel void worker1(int &arg) { } //expected-error {{pointer and reference arguments to kernel functions must reside in '__global', '__constant' or '__local' address space}}