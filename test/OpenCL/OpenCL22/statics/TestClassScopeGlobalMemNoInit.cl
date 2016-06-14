// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O2 -emit-llvm -o - | FileCheck %s 
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O2 -emit-llvm -o - | FileCheck %s 
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s 
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O1 -emit-llvm -o - | FileCheck %s 
//expected-no-diagnostics

#define GLOBAL_MEM __global

#include "../opencl_def"

class A {
public:
    static GLOBAL_MEM int a;
};

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
class WrapperClass1 {
    static GLOBAL_MEM int          TrivialType;
    static GLOBAL_MEM float4       TrivialVecType;
    static GLOBAL_MEM Aggregate    AggregateType;
    static GLOBAL_MEM NonAggregate NonAggregateType;
    static GLOBAL_MEM TDerived     DerivedType;
};

GLOBAL_MEM int          WrapperClass1::TrivialType;      // CHECK: @_ZN13WrapperClass111TrivialTypeE = addrspace(1) global i32 0, align 4
GLOBAL_MEM float4       WrapperClass1::TrivialVecType;   // CHECK: @_ZN13WrapperClass114TrivialVecTypeE = addrspace(1) global <4 x float> zeroinitializer, align 16
GLOBAL_MEM Aggregate    WrapperClass1::AggregateType;    // CHECK: @_ZN13WrapperClass113AggregateTypeE = addrspace(1) global [[T_AGG:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_AGG:[1-9]+]]
GLOBAL_MEM NonAggregate WrapperClass1::NonAggregateType; // CHECK: @_ZN13WrapperClass116NonAggregateTypeE = addrspace(1) global [[T_NAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_NAGG:[1-9]+]]
GLOBAL_MEM TDerived     WrapperClass1::DerivedType;      // CHECK: @_ZN13WrapperClass111DerivedTypeE = addrspace(1) global [[T_DER:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_DER:[1-9]+]]

// Arrays
struct WrapperClass2 {
    static GLOBAL_MEM long         TrivialArrType[3];
    static GLOBAL_MEM uchar3       TrivialVecArrType[4][5];
    static GLOBAL_MEM Aggregate    AggregateArrType[6];
    static GLOBAL_MEM NonAggregate NonAggregateArrType[7];
    static GLOBAL_MEM TDerived     DerivedArrType[8][9][10];
};

GLOBAL_MEM long         WrapperClass2::TrivialArrType[3];        // CHECK: @_ZN13WrapperClass214TrivialArrTypeE = addrspace(1) global [3 x i64] zeroinitializer, align 8
GLOBAL_MEM uchar3       WrapperClass2::TrivialVecArrType[4][5];  // CHECK: @_ZN13WrapperClass217TrivialVecArrTypeE = addrspace(1) global [4 x [5 x <3 x i8>]] zeroinitializer, align 4
GLOBAL_MEM Aggregate    WrapperClass2::AggregateArrType[6];      // CHECK: @_ZN13WrapperClass216AggregateArrTypeE = addrspace(1) global [6 x [[T_AGG]]] zeroinitializer, align [[A_AGG]]
GLOBAL_MEM NonAggregate WrapperClass2::NonAggregateArrType[7];   // CHECK: @_ZN13WrapperClass219NonAggregateArrTypeE = addrspace(1) global [7 x [[T_NAGG]]] zeroinitializer, align [[A_NAGG]]
GLOBAL_MEM TDerived     WrapperClass2::DerivedArrType[8][9][10]; // CHECK: @_ZN13WrapperClass214DerivedArrTypeE = addrspace(1) global [8 x [9 x [10 x [[T_DER]]]]] zeroinitializer, align [[A_DER]]

struct WrapperClass3 {
    static GLOBAL_MEM char TrivialUArrType[];
};

GLOBAL_MEM char WrapperClass3::TrivialUArrType[4]; // CHECK: @_ZN13WrapperClass315TrivialUArrTypeE = addrspace(1) global [4 x i8] zeroinitializer, align 1

// Type dependant entities
template <typename T> struct WrapperClass4 {
    static GLOBAL_MEM T TDepType;
    static GLOBAL_MEM T TDepArrType[3];
    static GLOBAL_MEM T TDepUArrType[][4];
};

template <typename T> GLOBAL_MEM T WrapperClass4<T>::TDepType;
template <typename T> GLOBAL_MEM T WrapperClass4<T>::TDepArrType[3];
template <typename T> GLOBAL_MEM T WrapperClass4<T>::TDepUArrType[2][4];

                                          // CHECK-DAG: @_ZN13WrapperClass4I9AggregateE11TDepArrTypeE = {{[a-z_]+}} addrspace(1) global [3 x [[T_AGG]]] zeroinitializer, align [[A_AGG]]
template struct WrapperClass4<Aggregate>; // CHECK-DAG: @_ZN13WrapperClass4I9AggregateE8TDepTypeE = {{[a-z_]+}} addrspace(1) global [[T_AGG]] zeroinitializer, align [[A_AGG]]
                                          // CHECK-DAG: @_ZN13WrapperClass4I9AggregateE12TDepUArrTypeE = {{[a-z_]+}} addrspace(1) global [2 x [4 x [[T_AGG]]]] zeroinitializer, align [[A_AGG]]
template struct WrapperClass4<int3>;      // CHECK-DAG: @_ZN13WrapperClass4IDv3_iE8TDepTypeE = {{[a-z_]+}} addrspace(1) global <3 x i32> zeroinitializer, align 16
                                          // CHECK-DAG: @_ZN13WrapperClass4IDv3_iE11TDepArrTypeE = {{[a-z_]+}} addrspace(1) global [3 x <3 x i32>] zeroinitializer, align 16
                                          // CHECK-DAG: @_ZN13WrapperClass4IDv3_iE12TDepUArrTypeE = {{[a-z_]+}} addrspace(1) global [2 x [4 x <3 x i32>]] zeroinitializer, align 16

void fun(const TDerived &, int);

// CHECK-DAG: @_ZN13WrapperClass4IiE11TDepArrTypeE = {{[a-z_]+}} addrspace(1) global [3 x i32] zeroinitializer, align 4
// CHECK-DAG: @_ZN13WrapperClass4I7DerivedE8TDepTypeE = {{[a-z_]+}} addrspace(1) global [[T_DER]] zeroinitializer, align [[A_DER]]

kernel void worker() {                                      // CHECK: define spir_kernel void @worker()
                                                            // CHECK-NOT: store {{.*}}, [3 x i32] addrspace(1)* @_ZN13WrapperClass4IiE11TDepArrTypeE, align
                                                            // CHECK-NOT: store {{.*}}, [[T_DER]] addrspace(1)* @_ZN13WrapperClass4I7DerivedE8TDepTypeE, align
    const auto &v1 = WrapperClass4<int>::TDepArrType; 
    const auto &v2 = WrapperClass4<TDerived>::TDepType;
    fun(v2, v1[0]);                                         // CHECK: call spir_func void @_Z3funRKU3AS47Derivedi(
                                                            // CHECK-NEXT: ret void
}

// CHECK-NOT: define spir_kernel void @_SPIRV_
