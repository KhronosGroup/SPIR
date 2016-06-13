// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -cl-zero-init-local-mem-vars -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -cl-zero-init-local-mem-vars -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -cl-zero-init-local-mem-vars -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -cl-zero-init-local-mem-vars -o - | FileCheck %s
// expected-no-diagnostics

#define LOCAL_MEM __local

#include "../opencl_def"

struct Aggregate {
    int a;
    int b;
    int c;
};

class NonAggregate {
    int a;
    Aggregate b;

public:
    NonAggregate() = default;

    auto getA() { return a; }
    auto getB() { return b; }
};

struct Derived : Aggregate, NonAggregate {
    long2 d;
};

typedef Derived TDerived;


// Single
LOCAL_MEM int          TrivialType;      // CHECK: @TrivialType = addrspace(3) global i32 0, align 4
LOCAL_MEM float4       TrivialVecType;   // CHECK: @TrivialVecType = addrspace(3) global <4 x float> zeroinitializer, align 16
LOCAL_MEM Aggregate    AggregateType;    // CHECK: @AggregateType = addrspace(3) global [[T_AGG:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_AGG:[1-9]+]]
LOCAL_MEM NonAggregate NonAggregateType; // CHECK: @NonAggregateType = addrspace(3) global [[T_NAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_NAGG:[1-9]+]]
LOCAL_MEM TDerived     DerivedType;      // CHECK: @DerivedType = addrspace(3) global [[T_DER:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_DER:[1-9]+]]

// Arrays
LOCAL_MEM long         TrivialArrType[3];        // CHECK: @TrivialArrType = addrspace(3) global [3 x i64] zeroinitializer, align 8
LOCAL_MEM uchar3       TrivialVecArrType[4][5];  // CHECK: @TrivialVecArrType = addrspace(3) global [4 x [5 x <3 x i8>]] zeroinitializer, align 4
LOCAL_MEM Aggregate    AggregateArrType[6];      // CHECK: @AggregateArrType = addrspace(3) global [6 x [[T_AGG]]] zeroinitializer, align [[A_AGG]]
LOCAL_MEM NonAggregate NonAggregateArrType[7];   // CHECK: @NonAggregateArrType = addrspace(3) global [7 x [[T_NAGG]]] zeroinitializer, align [[A_NAGG]]
LOCAL_MEM TDerived     DerivedArrType[8][9][10]; // CHECK: @DerivedArrType = addrspace(3) global [8 x [9 x [10 x [[T_DER]]]]] zeroinitializer, align [[A_DER]]

// Template variables
template <typename T> LOCAL_MEM T TemplateVarType;
template <typename T> LOCAL_MEM T TemplateVarArrType[4];

template <> LOCAL_MEM int TemplateVarType<int>;           // CHECK: @_Z15TemplateVarTypeIiE = addrspace(3) global i32 0, align 4
template <> LOCAL_MEM long2 TemplateVarType<long2>;       // CHECK: @_Z15TemplateVarTypeIDv2_lE = addrspace(3) global <2 x i64> zeroinitializer, align 16
template <> LOCAL_MEM TDerived TemplateVarType<TDerived>; // CHECK: @_Z15TemplateVarTypeI7DerivedE = addrspace(3) global [[T_DER]] zeroinitializer, align [[A_DER]]

template <> LOCAL_MEM float TemplateVarArrType<float>[4];       // CHECK: @_Z18TemplateVarArrTypeIfE = addrspace(3) global [4 x float] zeroinitializer, align 4
template <> LOCAL_MEM uint8 TemplateVarArrType<uint8>[4];       // CHECK: @_Z18TemplateVarArrTypeIDv8_jE = addrspace(3) global [4 x <8 x i32>] zeroinitializer, align 32
template <> LOCAL_MEM TDerived TemplateVarArrType<TDerived>[4]; // CHECK: @_Z18TemplateVarArrTypeI7DerivedE = addrspace(3) global [4 x [[T_DER]]] zeroinitializer, align [[A_DER]]

// CHECK-NOT: define spir_kernel void @_SPIRV_