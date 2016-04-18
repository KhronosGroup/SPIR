// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -

#include "../opencl_def"

#ifdef cl_khr_fp64
    #pragma OPENCL EXTENSION cl_khr_fp64 : enable
#endif


kernel void worker_const_assign()
{
    const int4 vs1 {1UL, 2UL, 3UL, 4UL};

    // Single component access (write).
    vs1.r = 11UL; // expected-error {{read-only variable is not assignable}}
    vs1.g = 12UL; // expected-error {{read-only variable is not assignable}}
    vs1.b = 13UL; // expected-error {{read-only variable is not assignable}}
    vs1.a = 14UL; // expected-error {{read-only variable is not assignable}}

    // Swizzle (write).
    vs1.bgra      = vs1.aaaa; // expected-error {{read-only variable is not assignable}}
    vs1.gbr.gr.rg = vs1.lo;   // expected-error {{read-only variable is not assignable}}
    vs1.gr        = vs1.hi;   // expected-error {{read-only variable is not assignable}}
}