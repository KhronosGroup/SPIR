// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// expected-no-diagnostics

#include "../opencl_def"

#ifdef cl_khr_fp16
    #pragma OPENCL EXTENSION cl_khr_fp16: enable
#endif

void TestTempBindFun01(long3);
void TestTempBindFun02(const bool8&);
void TestTempBindFun03(float16&&);

template <typename t1_>
    struct TestTempBindCtor
{
    TestTempBindCtor(t1_ val);
};


template <uint idx_>
    struct TestSelector {};

template <typename t1_>
    struct TestMemberEmptyInit
{
    t1_ _member;

    TestMemberEmptyInit(TestSelector<0>) : _member() {}
    TestMemberEmptyInit(TestSelector<1>) : _member{} {}
};


kernel void worker()
{
    int3    vec01{};
    int4    vec02 = {};
    int8    vec03 = int8();
    long2   vec04 = long2{};
#ifdef cl_khr_fp16
    half8   vec05{};
    half16  vec06 = {};
    half3   vec07 = half3();
    half2   vec08 = half2{};
#endif
#ifdef cl_khr_fp64
    double2 vec09 = {};
#endif

    // Initializing cv-qualified types.
    const volatile long2  vec10{};
    volatile short3       vec11 = {};
    const volatile float4 vec12 = float4();
    const volatile char8  vec13 = char8{};

    // Binding to references with empty initializer.
    const int2&    vec14 = {};
    float8&&       vec15 = float8();
    const float3&& vec16 = float3{};

    // In function and constructor call.
    TestTempBindFun01({});
    TestTempBindFun02({});
    TestTempBindFun03({});
    TestTempBindFun01(long3());
    TestTempBindFun02(bool8());
    TestTempBindFun03(float16());
    TestTempBindFun01(long3{});
    TestTempBindFun02(bool8{});
    TestTempBindFun03(float16{});

    TestTempBindCtor<long2>         tester01 = long2();
    TestTempBindCtor<const ulong3&> tester02 = ulong3();
    TestTempBindCtor<uchar2&&>      tester03 = uchar2();
    TestTempBindCtor<long2>         tester04 = long2{};
    TestTempBindCtor<const ulong3&> tester05 = ulong3{};
    TestTempBindCtor<uchar2&&>      tester06 = uchar2{};
    TestTempBindCtor<char8>         tester07({});
    TestTempBindCtor<const uint3&>  tester08({});
    TestTempBindCtor<float2&&>      tester09({});
    TestTempBindCtor<char8>         tester10((char8()));
    TestTempBindCtor<const uint3&>  tester11((uint3()));
    TestTempBindCtor<float2&&>      tester12((float2()));
    TestTempBindCtor<char8>         tester13(char8{});
    TestTempBindCtor<const uint3&>  tester14(uint3{});
    TestTempBindCtor<float2&&>      tester15(float2{});

    // On .ctor initializer list.
    TestMemberEmptyInit<uchar16>    tester16 = TestSelector<0>();
    TestMemberEmptyInit<ushort16>   tester17 = TestSelector<1>();
}
