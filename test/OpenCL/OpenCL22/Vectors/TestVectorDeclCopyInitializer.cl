// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -

#include "../opencl_def"

#ifdef cl_khr_fp16
    #pragma OPENCL EXTENSION cl_khr_fp16: enable
#endif


void TestTempBindFun01(long3);
void TestTempBindFun02(const bool8&);
void TestTempBindFun03(float16&&);

template <typename t1_, typename t2_, typename t3_>
    struct TestTempBindCtors
{
    TestTempBindCtors(t1_);
    TestTempBindCtors(const t2_&);
    TestTempBindCtors(t3_&&);
};

struct TestDummy {};


kernel void worker_literals()
{
    int3    vec01 = 1;                 // no narrowing
    int4    vec02 = 2L;                // integer narrowing (no truncation)
                                       // integer narrowing (truncation)
    int8    vec03 = 20000000000L;      // expected-warning-re {{implicit conversion from {{.*}} to {{.*}} changes value}}
#ifdef cl_khr_fp16
    half8   vec04 = -10UL;             // integer-fp conversion (no precision loss)
    half16  vec05 = -10000000000000UL; // integer-fp conversion (precision loss)
    half3   vec06 = 3.0f;              // fp conversion (no precision loss)
    half2   vec07 = 3.14159265359f;    // fp conversion (precision loss)
    half4   vec08 = 5e20f;             // fp conversion (out of half range)
#endif
#ifdef cl_khr_fp64
    double2 vec09 = 1.1f;              // fp conversion (no precision loss)
#endif

    // Initializing cv-qualified types.
    const volatile long2  vec10 = -3;
    volatile short3       vec11 = 120;
    const volatile float4 vec12 = 7UL;

    // Binding to references with copy initializer.
    const int2& vec13 = 3;
    float8&&    vec14 = -33L;

    // In function and constructor call.
    TestTempBindFun01(1);
    TestTempBindFun02(false);
    TestTempBindFun03(123456789UL);

    using TestTempBindCtors01 = TestTempBindCtors<int, long2, long2>;
    TestTempBindCtors01 tester01 = 1L;
    TestTempBindCtors01 tester02 = long2{1, 2};

    using TestTempBindCtors02 = TestTempBindCtors<long2, int, int>;
    TestTempBindCtors02 tester03 = 1L;
    TestTempBindCtors02 tester04 = long2{1, 2};

    using TestTempBindCtors03 = TestTempBindCtors<TestDummy, short3, short3>;
    TestTempBindCtors03 tester05 = -1;
    TestTempBindCtors03 tester06 = 1UL;
    TestTempBindCtors03 tester07(-1);
    TestTempBindCtors03 tester08(1UL);
}

kernel void worker_variables()
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


    int3    vec01 = sv06;              // no narrowing
    int4    vec02 = sv08;              // integer narrowing (possible truncation)
    int8    vec03 = sv09;              // integer narrowing (possible truncation)
#ifdef cl_khr_fp16
    half8   vec04 = sv01;              // integer-fp conversion (no precision loss)
    half16  vec05 = sv07;              // integer-fp conversion (possible precision loss)
    half3   vec06 = sv02;              // fp conversion (no precision loss)
    half2   vec07 = sv11;              // fp conversion (possible precision loss)
    #ifdef cl_khr_fp64
    half4   vec08 = sv13;              // fp conversion (possible precision loss)
    #endif
#endif
#ifdef cl_khr_fp64
    double2 vec09 = sv12;              // fp conversion (no precision loss)
#endif

    // Initializing cv-qualified types.
    const volatile long2  vec10 = sv04;
    volatile short3       vec11 = sv05;
    const volatile float4 vec12 = sv08;

    // Binding to references with copy initializer.
    const int2& vec13 = sv03;
    float8&&    vec14 = sv08;

    // In function and constructor call.
    TestTempBindFun01(sv07);
    TestTempBindFun02(sv02);
    TestTempBindFun03(sv08);

    using TestTempBindCtors01 = TestTempBindCtors<int, long2, long2>;
    TestTempBindCtors01 tester01 = sv08;
    TestTempBindCtors01 tester02 = long2{1, 2};

    using TestTempBindCtors02 = TestTempBindCtors<long2, int, int>;
    TestTempBindCtors02 tester03 = int(1L);
    TestTempBindCtors02 tester04 = long2{1, 2};

    using TestTempBindCtors03 = TestTempBindCtors<TestDummy, short3, short3>;
    TestTempBindCtors03 tester05 = sv07;
    TestTempBindCtors03 tester06 = sv09;
    TestTempBindCtors03 tester07(sv08);
    TestTempBindCtors03 tester08(sv09);
}