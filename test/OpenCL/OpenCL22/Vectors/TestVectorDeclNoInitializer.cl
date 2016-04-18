// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// expected-no-diagnostics

#include "../opencl_def"

#ifdef cl_khr_fp16
    #pragma OPENCL EXTENSION cl_khr_fp16: enable
#endif

kernel void worker()
{
    bool2  vecB_2;
    bool3  vecB_3;
    bool4  vecB_4;
    bool8  vecB_8;
    bool16 vecB_16;

    char2  vecI8_2;
    char3  vecI8_3;
    char4  vecI8_4;
    char8  vecI8_8;
    char16 vecI8_16;

    uchar2  vecU8_2;
    uchar3  vecU8_3;
    uchar4  vecU8_4;
    uchar8  vecU8_8;
    uchar16 vecU8_16;

    short2  vecI16_2;
    short3  vecI16_3;
    short4  vecI16_4;
    short8  vecI16_8;
    short16 vecI16_16;

    ushort2  vecU16_2;
    ushort3  vecU16_3;
    ushort4  vecU16_4;
    ushort8  vecU16_8;
    ushort16 vecU16_16;

    int2  vecI32_2;
    int3  vecI32_3;
    int4  vecI32_4;
    int8  vecI32_8;
    int16 vecI32_16;

    uint2  vecU32_2;
    uint3  vecU32_3;
    uint4  vecU32_4;
    uint8  vecU32_8;
    uint16 vecU32_16;

    long2  vecI64_2;
    long3  vecI64_3;
    long4  vecI64_4;
    long8  vecI64_8;
    long16 vecI64_16;

    ulong2  vecU64_2;
    ulong3  vecU64_3;
    ulong4  vecU64_4;
    ulong8  vecU64_8;
    ulong16 vecU64_16;

#ifdef cl_khr_fp16
    half2  vecF16_2;
    half3  vecF16_3;
    half4  vecF16_4;
    half8  vecF16_8;
    half16 vecF16_16;
#endif

    float2  vecF32_2;
    float3  vecF32_3;
    float4  vecF32_4;
    float8  vecF32_8;
    float16 vecF32_16;

#ifdef cl_khr_fp64
    double2  vecF64_2;
    double3  vecF64_3;
    double4  vecF64_4;
    double8  vecF64_8;
    double16 vecF64_16;
#endif
}