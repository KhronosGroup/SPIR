// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o - | FileCheck %s -check-prefix=CHECK_O3
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o - | FileCheck %s -check-prefix=CHECK_O3
//expected-no-diagnostics

#define GLOBAL_MEM __global

#include "../opencl_def"

extern int ConstexprBreaker(float);
extern void ConstexprBreaker();

int nce_int() { return 2; }
constexpr int ce_int() { return 2; }

float nce_float() { return 2.0f; }
constexpr float ce_float() { return 2.0f; }

auto lambda = []() { return 6666; };

template<class T>
constexpr T ce_t() { return T(4444); }

template<class T>
T nce_t_var;
template<>
int nce_t_var<int> = 10;
template<>
float nce_t_var<float> = 10.0;

template<class T>
constexpr T ce_t_var = T(3333);
template<>
constexpr int ce_t_var<int> = 3333;

template<class T>
T nce_t() { return T(5555); }

struct A {
    A() = default;
    int a, b;
};

struct B {
    B() { }
    int a, b;
};

struct C {
    C() { }
    ~C() { }
    int a, b;
};

typedef A td_A; // CHECK-NOT: td_A
typedef B td_B; // CHECK-NOT: td_B

// Struct initializations
GLOBAL_MEM A a1 = { 1, 2 };                                    // CHECK-DAG: @a1 = addrspace(1) global %struct.A { i32 1, i32 2 }, align 4
GLOBAL_MEM A a2 = { 1, nce_int() };                            // CHECK-DAG: @a2 = addrspace(1) global %struct.A zeroinitializer, align 4
GLOBAL_MEM A a3 = { 1, ce_int() };                             // CHECK-DAG: @a3 = addrspace(1) global %struct.A { i32 1, i32 2 }, align 4
GLOBAL_MEM A a4 = { 1, ce_t<int>() };                          // CHECK-DAG: @a4 = addrspace(1) global %struct.A { i32 1, i32 4444 }, align 4
GLOBAL_MEM A a5 = { 1, ce_t_var<int> };                        // CHECK-DAG: @a5 = addrspace(1) global %struct.A { i32 1, i32 3333 }, align 4

GLOBAL_MEM td_A td_a1 = { 1, 2 };                              // CHECK-DAG: @td_a1 = addrspace(1) global %struct.A { i32 1, i32 2 }, align 4
GLOBAL_MEM td_A td_a2 = { 1, nce_int() };                      // CHECK-DAG: @td_a2 = addrspace(1) global %struct.A zeroinitializer, align 4
GLOBAL_MEM td_A td_a3 = { 1, ce_int() };                       // CHECK-DAG: @td_a3 = addrspace(1) global %struct.A { i32 1, i32 2 }, align 4
GLOBAL_MEM td_A td_a4 = { 1, ce_t<int>() };                    // CHECK-DAG: @td_a4 = addrspace(1) global %struct.A { i32 1, i32 4444 }, align 4

// Global static
static GLOBAL_MEM int gs_i1 = 1000;                 // CHECK-DAG: @_ZL5gs_i1 = internal addrspace(1) global i32 1000, align 4
static GLOBAL_MEM int gs_i3 = ce_int();             // CHECK-DAG: @_ZL5gs_i3 = internal addrspace(1) global i32 2, align 4
static GLOBAL_MEM int gs_i5 = ce_t_var<int>;        // CHECK-DAG: @_ZL5gs_i5 = internal addrspace(1) global i32 3333, align 4
static GLOBAL_MEM int gs_i7 = ce_t<int>();          // CHECK-DAG: @_ZL5gs_i7 = internal addrspace(1) global i32 4444, align 4

static GLOBAL_MEM int gs_i9 = nce_t<int>();         // CHECK-DAG: @_ZL5gs_i9 = internal addrspace(1) global i32 0, align 4
static GLOBAL_MEM int gs_i11 = nce_int();           // CHECK-DAG: @_ZL6gs_i11 = internal addrspace(1) global i32 0, align 4
static GLOBAL_MEM int gs_i13 = nce_t_var<int>;      // CHECK-DAG: @_ZL6gs_i13 = internal addrspace(1) global i32 0, align 4
static GLOBAL_MEM int gs_i15 = lambda();            // CHECK-DAG: @_ZL6gs_i15 = internal addrspace(1) global i32 0, align 4

static GLOBAL_MEM float gs_f1 = 1000.0f;            // CHECK-DAG: @_ZL5gs_f1 = internal addrspace(1) global float 1.000000e+03, align 4
static GLOBAL_MEM float gs_f3 = ce_float();         // CHECK-DAG: @_ZL5gs_f3 = internal addrspace(1) global float 2.000000e+00, align 4
static GLOBAL_MEM float gs_f5 = ce_t_var<float>;    // CHECK-DAG: @_ZL5gs_f5 = internal addrspace(1) global float 3.333000e+03, align 4
static GLOBAL_MEM float gs_f7 = ce_t<float>();      // CHECK-DAG: @_ZL5gs_f7 = internal addrspace(1) global float 4.444000e+03, align 4

static GLOBAL_MEM float gs_f9 = nce_t<float>();     // CHECK-DAG: @_ZL5gs_f9 = internal addrspace(1) global float 0.000000e+00, align 4
static GLOBAL_MEM float gs_f11 = nce_float();       // CHECK-DAG: @_ZL6gs_f11 = internal addrspace(1) global float 0.000000e+00, align 4
static GLOBAL_MEM float gs_f13 = nce_t_var<float>;  // CHECK-DAG: @_ZL6gs_f13 = internal addrspace(1) global float 0.000000e+00, align 4
static GLOBAL_MEM float gs_f15 = lambda();          // CHECK-DAG: @_ZL6gs_f15 = internal addrspace(1) global float 0.000000e+00, align 4

static GLOBAL_MEM A gs_A1 = A();                    // CHECK-DAG: @_ZL5gs_A1 = internal addrspace(1) global %struct.A zeroinitializer, align 4

GLOBAL_MEM int gs_i2 = gs_i1;                       // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i2, align 4
                                                    // CHECK_O3: store i32 1000, i32 addrspace(1)* @gs_i2, align 4, {{.*}}
GLOBAL_MEM int gs_i4 = gs_i3;                       // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i4, align 4
                                                    // CHECK_O3: store i32 2, i32 addrspace(1)* @gs_i4, align 4, {{.*}}
GLOBAL_MEM int gs_i6 = gs_i5;                       // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i6, align 4
                                                    // CHECK_O3: store i32 3333, i32 addrspace(1)* @gs_i6, align 4, {{.*}}
GLOBAL_MEM int gs_i8 = gs_i7;                       // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i8, align 4
                                                    // CHECK_O3: store i32 4444, i32 addrspace(1)* @gs_i8, align 4, {{.*}}
GLOBAL_MEM int gs_i10 = gs_i9;                      // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i10, align 4
                                                    // CHECK_O3: store i32 5555, i32 addrspace(1)* @gs_i10, align 4, {{.*}}
GLOBAL_MEM int gs_i12 = gs_i11;                     // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i12, align 4
                                                    // CHECK_O3: store i32 2, i32 addrspace(1)* @gs_i12, align 4, {{.*}}
GLOBAL_MEM int gs_i14 = gs_i13;                     // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i14, align 4
                                                    // CHECK_O3: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i14, align 4, {{.*}}
GLOBAL_MEM int gs_i16 = gs_i15;                     // CHECK: store i32 %{{[0-9a-zA-Z_\.]+}}, i32 addrspace(1)* @gs_i16, align 4
                                                    // CHECK_03: store i32 6666, i32 addrspace(1)* @gs_i16, align 4, {{.*}}
GLOBAL_MEM float gs_f2 = gs_f1;                     // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f2, align 4
                                                    // CHECK_O3: store float 1.000000e+03, float addrspace(1)* @gs_f2, align 4
GLOBAL_MEM float gs_f4 = gs_f3;                     // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f4, align 4
                                                    // CHECK_O3: store float 2.000000e+00, float addrspace(1)* @gs_f4, align 4
GLOBAL_MEM float gs_f6 = gs_f5;                     // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f6, align 4
                                                    // CHECK_O3: store float 3.333000e+03, float addrspace(1)* @gs_f6, align 4
GLOBAL_MEM float gs_f8 = gs_f7;                     // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f8, align 4
                                                    // CHECK_O3: store float 4.444000e+03, float addrspace(1)* @gs_f8, align 4
GLOBAL_MEM float gs_f10 = gs_f9;                    // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f10, align 4
                                                    // CHECK_O3: store float 5.555000e+03, float addrspace(1)* @gs_f10, align 4
GLOBAL_MEM float gs_f12 = gs_f11;                   // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f12, align 4
                                                    // CHECK_O3: store float 2.000000e+00, float addrspace(1)* @gs_f12, align 4
GLOBAL_MEM float gs_f14 = gs_f13;                   // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f14, align 4
                                                    // CHECK_O3: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f14, align 4
GLOBAL_MEM float gs_f16 = gs_f15;                   // CHECK: store float %{{[0-9a-zA-Z_\.]+}}, float addrspace(1)* @gs_f16, align 4
                                                    // CHECK_O3: store float 6.666000e+03, float addrspace(1)* @gs_f16, align 4

GLOBAL_MEM A gs_A2 = gs_A1;                         // CHECK: call void @llvm.memcpy{{.*}} @gs_A2 {{.*}} @_ZL5gs_A1 {{.*}}
                                                    // CHECK_O3: store i64 0, i64 addrspace(1)* bitcast (%struct.A addrspace(1)* @gs_A2 to i64 addrspace(1)*), align 8

template<typename T> GLOBAL_MEM const T& TemplateLVarType2 = 1234;
template<> GLOBAL_MEM const int& TemplateLVarType2<int> = 123;