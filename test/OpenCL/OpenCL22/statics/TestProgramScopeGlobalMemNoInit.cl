// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o - | FileCheck %s
// expected-no-diagnostics

#define GLOBAL_MEM __global

#include "../opencl_def"

extern int ConstexprBreaker(float);
extern void ConstexprBreaker();

// Trivial constructor, trivial destructor
struct T_T { int m1; float m2; };

// Defaulted trivial constructor, defaulted trivial destructor
struct DT_DT 
{
    int m1;
    float m2;

    DT_DT() = default;
    ~DT_DT() = default;
};

// Constexpr constructor, trivial destructor
struct CX_T
{
    int m1;
    float m2;

    constexpr CX_T() : m1(1), m2(2) { m2 = 3; }
};

// Custom non-trivial non-constexpr constructor, trivial destructor
struct CU_T 
{ 
    int m1;
    float m2;

    CU_T() : m2(1.0) 
    {
        m1 = ConstexprBreaker(1.0);
    }
};

// Trivial constructor, custom non-trivial destructor
struct T_CU
{
    int m1;
    float m2;

    ~T_CU() { ConstexprBreaker(); }
};

// Custom classes
GLOBAL_MEM int TestIntegral_TrivialType_NoInit;
GLOBAL_MEM float TestFloating_TrivialType_NoInit;
GLOBAL_MEM int4 TestIntegralVec_TrivialType_NoInit;
GLOBAL_MEM float3 TestFloatingVec_TrivialType_NoInit;
GLOBAL_MEM T_T TestT_T_CustomType_NoInit;
GLOBAL_MEM DT_DT TestDTDTCustomType_NoInit;
GLOBAL_MEM CX_T TestC_T_CustomType_NoInit;
GLOBAL_MEM CU_T TestN_T_CustomType_NoInit;
GLOBAL_MEM T_CU TestT_N_CustomType_NoInit2;


// Global declarations
// Single
GLOBAL_MEM int      TrivialIntegral;            // CHECK-DAG: @TrivialIntegral = addrspace(1) global i32 0, align 4
static GLOBAL_MEM int TrivialIntegral_S;        // CHECK-NOT: @TrivialIntegral_S = {{.*}}
GLOBAL_MEM float    TrivialFloat;               // CHECK: @TrivialFloat = addrspace(1) global float {{[0.e+]+}}, align 4
static GLOBAL_MEM float TrivialFloat_S;         // CHECK-NOT: @TrivialFloat_S = {{.*}}
GLOBAL_MEM int4     TrivialIntegralVec;         // CHECK: @TrivialIntegralVec = addrspace(1) global <4 x i32> zeroinitializer, align 16
static GLOBAL_MEM int4 TrivialIntegralVec_S;    // CHECK-NOT: @TrivialIntegralVec_S = {{.*}}
GLOBAL_MEM float4   TrivialFloatVec;            // CHECK: @TrivialFloatVec = addrspace(1) global <4 x float> zeroinitializer, align 16


// Arrays
GLOBAL_MEM int      TrivialArrInteger[3];       // CHECK: @TrivialArrInteger = addrspace(1) global [3 x i32] zeroinitializer, align 4
GLOBAL_MEM float    TrivialArrFloat[3];         // CHECK: @TrivialArrFloat = addrspace(1) global [3 x float] zeroinitializer, align 4


// Template variables
template<typename T> GLOBAL_MEM T TemplateVar;
template<typename T> GLOBAL_MEM T TemplateVarArr[4];    

template<> GLOBAL_MEM int TemplateVar<int>;             // CHECK: @_Z11TemplateVarIiE = addrspace(1) global i32 0, align 4
template<> GLOBAL_MEM int2 TemplateVar<int2>;           // CHECK: @_Z11TemplateVarIDv2_iE = addrspace(1) global <2 x i32> zeroinitializer, align 8

template<> GLOBAL_MEM int TemplateVarArr<int>[4];       // CHECK: @_Z14TemplateVarArrIiE = addrspace(1) global [4 x i32] zeroinitializer, align 4
template<> GLOBAL_MEM int2 TemplateVarArr<int2>[4];     // CHECK: @_Z14TemplateVarArrIDv2_iE = addrspace(1) global [4 x <2 x i32>] zeroinitializer, align 8

struct A 
{ 
    int a, b; 
};
struct B : A 
{ 
    int c, d; 
};

typedef A TBase;
typedef B TDerived;

template<> GLOBAL_MEM TBase TemplateVar<TBase>;             // CHECK: @_Z11TemplateVarI1AE = addrspace(1) global %struct.A zeroinitializer, align 4
template<> GLOBAL_MEM TBase TemplateVarArr<TBase>[4];       // CHECK: @_Z14TemplateVarArrI1AE = addrspace(1) global [4 x %struct.A] zeroinitializer, align 4

template<> GLOBAL_MEM TDerived TemplateVar<TDerived>;       // CHECK: @_Z11TemplateVarI1BE = addrspace(1) global %struct.B zeroinitializer, align 4
template<> GLOBAL_MEM TDerived TemplateVarArr<TDerived>[4]; // CHECK: @_Z14TemplateVarArrI1BE = addrspace(1) global [4 x %struct.B] zeroinitializer, align 4

// Aggregate and non-aggregate
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

typedef Derived AGGRS_TDerived;

// Single
GLOBAL_MEM Aggregate        AggregateType;    // CHECK: @AggregateType = addrspace(1) global [[T_AGG:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_AGG:[1-9]+]]
GLOBAL_MEM NonAggregate     NonAggregateType; // CHECK: @NonAggregateType = addrspace(1) global [[T_NAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_NAGG:[1-9]+]]
GLOBAL_MEM AGGRS_TDerived   DerivedType;      // CHECK: @DerivedType = addrspace(1) global [[T_DER:%([0-9A-Za-z_\.]+|"[^"]+")]] zeroinitializer, align [[A_DER:[1-9]+]]

// Arrays
GLOBAL_MEM Aggregate        AggregateArrType[6];      // CHECK: @AggregateArrType = addrspace(1) global [6 x [[T_AGG]]] zeroinitializer, align [[A_AGG]]
GLOBAL_MEM NonAggregate     NonAggregateArrType[7];   // CHECK: @NonAggregateArrType = addrspace(1) global [7 x [[T_NAGG]]] zeroinitializer, align [[A_NAGG]]
GLOBAL_MEM AGGRS_TDerived   DerivedArrType[8][9][10]; // CHECK: @DerivedArrType = addrspace(1) global [8 x [9 x [10 x [[T_DER]]]]] zeroinitializer, align [[A_DER]]
