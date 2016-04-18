// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT===" -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT===" -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT===" -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT===" -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=!=" -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=!=" -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=!=" -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=!=" -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<" -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<" -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<" -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<" -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<=" -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<=" -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<=" -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=<=" -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>" -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>" -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>" -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>" -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>=" -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>=" -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>=" -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify "-DCOP_LIT=>=" -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -

#include "../opencl_def"

#ifndef COP_LIT
    #error Literal for comparison iterator was not specified. Please add "-DCOP_LIT=<op literal>" to command-line.
#endif

#ifdef cl_khr_fp16
    #pragma OPENCL EXTENSION cl_khr_fp16: enable
#endif

template <typename T, typename U> struct is_same { static constexpr bool value = false; };
template <typename T> struct is_same<T,T> { static constexpr bool value = true; };

kernel void worker_equals()
{
    const bool          sv01 = false;
    const volatile char sv02 = 1;
    volatile uchar      sv03 = 2;
    short  sv04 = 3;
    ushort sv05 = 4;
    int    sv06 = 5;
    uint   sv07 = 6;
    long   sv08 = 7;
    ulong  sv09 = 8;
#ifdef cl_khr_fp16
    half   sv10 = static_cast<half>(9);
#endif
    float  sv11 = 10.0f;
    float  sv12 = 11.0f;
#ifdef cl_khr_fp64
    double sv13 = 12.0;
#endif

    int8                  vec01_l = {1, 2, 3, 4,  5,  6,  7, 2};
    const int8            vec01_r = {1, 2, 3, 14, 5, 16, 17, 8};
    const volatile float4 vec02_l = {1.0f, 2.0f, 3.0f, 4.0f};
    const float4          vec02_r = {-1.0f, 2.0f, -3.0f, 4.0f};
    volatile uint3        vec03_l = {10, 20, 30};
    const uint3           vec03_r = {10, 21, 30};


    // Compare vectors.
    bool8 c01 = vec01_l COP_LIT vec01_r;
    bool4 c02 = vec02_l COP_LIT vec02_r;
    bool3 c03 = vec03_l COP_LIT vec03_r;

    auto  c04 = vec01_l COP_LIT vec01_r;
    auto  c05 = vec02_l COP_LIT vec02_r;
    auto  c06 = vec03_l COP_LIT vec03_r;

    static_assert(is_same<decltype(c04), bool8>::value, "");
    static_assert(is_same<decltype(c05), bool4>::value, "");
    static_assert(is_same<decltype(c06), bool3>::value, "");
    static_assert(is_same<decltype(vec01_l COP_LIT vec01_r), bool8>::value, "");
    static_assert(is_same<decltype(vec02_l COP_LIT vec02_r), bool4>::value, "");
    static_assert(is_same<decltype(vec03_l COP_LIT vec03_r), bool3>::value, "");


    // Compare vector & scalar (literal).
    bool8 c07 = 2 COP_LIT vec01_r;
    bool8 c08 = vec01_l COP_LIT 2;
    bool4 c09 = '2' COP_LIT vec02_r;
    bool4 c10 = vec02_l COP_LIT '2';
    bool4 c11 = 10 COP_LIT vec02_r;
    bool4 c12 = vec02_l COP_LIT 10;
#ifdef cl_khr_fp16
    bool4 c13 = static_cast<half>(3.2f) COP_LIT vec02_r;
    bool4 c14 = vec02_l COP_LIT static_cast<half>(3.3f);
#endif
    // NOTE: Conversion sequence have restriction lifted for OpenCL C++ (no rank restriction).
    //       It mimics behavior when two operands are scalar (in terms of restrictions).
    //       If we optionally enable implicit conversion between vectors the bahvior
    //       for vector-vector, vector-scalar, scalar-vector binary operation will reflect
    //       fully behavior for scalar-scalar operations.
    bool3 c15 = 3.0f COP_LIT vec03_r;
    bool3 c16 = vec03_l COP_LIT 3.0f;
    bool3 c17 = 3UL COP_LIT vec03_r;
    bool3 c18 = vec03_l COP_LIT 3UL;
    bool3 c19 = 30000000000UL COP_LIT vec03_r; // expected-warning {{}} expected-warning {{}} expected-note {{}}
    bool3 c20 = vec03_l COP_LIT 30000000000UL; // expected-warning {{}} expected-warning {{}} expected-note {{}}

    // Compare vector & scalar (variable).
    bool3 c21 = sv06 COP_LIT vec03_r; // expected-warning {{}} expected-note {{}}
    bool3 c22 = vec03_l COP_LIT sv05;
    bool3 c23 = sv08 COP_LIT vec03_r; // expected-warning {{}} expected-note {{}} 
    bool3 c24 = vec03_l COP_LIT sv08; // expected-warning {{}} expected-note {{}}
}
