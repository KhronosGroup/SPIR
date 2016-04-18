// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify

__constant int a = 1;

kernel void worker_constant_assign()
{
    a = 2; // expected-error{{read-only variable is not assignable}}
}

