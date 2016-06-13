// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s
// expected-no-diagnostics

#define LOCAL_MEM __local

#include "../opencl_def"

namespace Testers
{
    // implicitly defined defaulted default constructor; aggregate
    struct Aggregate {
        int a;
        float b;
    };

    // implicitly defined defaulted default constructor; non-aggregate
    struct NonAggregate {
        int a;
    private:
        float b;

    public:
        void setB(float val) { b = val; }
    };

    // explicitly defined defaulted default constructor; aggregate
    struct ExpDefCtorAggregate {
        int a;
        long b;

        ExpDefCtorAggregate() = default;
    };

    // explicitly defined defaulted default constructor; non-aggregate
    struct ExpDefCtorNonAggregate {
        int a;
    private:
        long b;

    public:
        ExpDefCtorNonAggregate() = default;
        void setB(long val) { b = val; }
    };

    // user defined defaulted default constructor; non-aggregate
    struct UserCtorNonAggregate {
        int a;
        long b;

        UserCtorNonAggregate();
        UserCtorNonAggregate(int a, int b, int c);
    };

    // user defined defaulted destructor; aggregate
    struct UserDtorAggregate {
        int a;
        long b;

        ~UserDtorAggregate();
    };

    UserDtorAggregate::~UserDtorAggregate() = default;

    // user defined defaulted default constructor; non-aggregate
    struct UserConstexprCtorNonAggregate {
        int a;
        long b;

        constexpr UserConstexprCtorNonAggregate() : a(), b() {}
    };

    // no default constructor; non-aggregate
    struct NonCtorNonAggregate {
        int a;
        int b;

        NonCtorNonAggregate(int a) : a(a), b(a) {}
    };

    // NOTE: Class derived from aggregate is not aggregate (aggregate cannot have base classes).
    struct DerivedAggregate : Aggregate {
        int c;
    };

    struct DerivedUserCtorNonAggregate : UserCtorNonAggregate {};

    struct CompositeUserCtorNonAggregate {
        UserCtorNonAggregate m;
    };

    using TAggregate    = Aggregate;
    using TNonAggregate = NonAggregate;
    typedef UserCtorNonAggregate TUserCtorNonAggregate;
    typedef int2 TInt2;
}

using TAggregate    = Testers::TAggregate;
using TNonAggregate = Testers::TNonAggregate;
typedef Testers::TUserCtorNonAggregate TUserCtorNonAggregate;
typedef Testers::TInt2 TInt2;

using TAggregateA2 = TAggregate[2];
typedef TNonAggregate TNonAggregateA2[2];
using TUserCtorNonAggregateA2 = TUserCtorNonAggregate[2];
typedef TInt2 TInt2A2[2];

using TAggregateA22 = TAggregateA2[2];
typedef TNonAggregateA2 TNonAggregateA22[2];
using TUserCtorNonAggregateA22 = TUserCtorNonAggregateA2[2];
typedef TInt2A2 TInt2A22[2];


// CHECK-DAG: @__spirv_BuiltInLocalInvocationIndex = external addrspace(1) externally_initialized constant i{{32|64}}

// CHECK-DAG: @_ZZ8worker_2E2v1 = internal addrspace(3) global i32 {{undef|0}}, align 4

// CHECK-DAG: @_ZZ8worker_3E2v1 = internal addrspace(3) global i32 {{undef|0}}, align 4
// CHECK-DAG: @_ZZ8worker_3E2v2 = internal addrspace(3) global <3 x float> {{undef|zeroinitializer}}, align 16
// CHECK-DAG: @_ZZ8worker_3E2v3 = internal addrspace(3) global [[T_AGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_AGG:[1-9]+]]
// CHECK-DAG: @_ZZ8worker_3E2v4 = internal addrspace(3) global [[T_NAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_NAGG:[1-9]+]]
// CHECK-DAG: @_ZZ8worker_3E2v5 = internal addrspace(3) global [[T_EDCAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_EDCAGG:[1-9]+]]
// CHECK-DAG: @_ZZ8worker_3E2v6 = internal addrspace(3) global [[T_EDCNAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_EDCNAGG:[1-9]+]]
// CHECK-DAG: @_ZZ8worker_3E2v7 = internal addrspace(3) global [[T_DAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_DAGG:[1-9]+]]
// CHECK-DAG: @_ZZ8worker_3E2v8 = internal addrspace(3) global <2 x i32> {{undef|zeroinitializer}}, align 8
// CHECK-DAG: @_ZZ8worker_3E3va1 = internal addrspace(3) global [2 x [3 x i32]] {{undef|zeroinitializer}}, align 4
// CHECK-DAG: @_ZZ8worker_3E3va2 = internal addrspace(3) global [2 x [3 x <3 x float>]] {{undef|zeroinitializer}}, align 16
// CHECK-DAG: @_ZZ8worker_3E3va3 = internal addrspace(3) global [2 x [3 x [[T_AGG]]]] {{undef|zeroinitializer}}, align [[A_AGG]]
// CHECK-DAG: @_ZZ8worker_3E3va4 = internal addrspace(3) global [2 x [3 x [[T_NAGG]]]] {{undef|zeroinitializer}}, align [[A_NAGG]]
// CHECK-DAG: @_ZZ8worker_3E3va5 = internal addrspace(3) global [2 x [3 x [[T_EDCAGG]]]] {{undef|zeroinitializer}}, align [[A_EDCAGG]]
// CHECK-DAG: @_ZZ8worker_3E3va6 = internal addrspace(3) global [2 x [3 x [[T_EDCNAGG]]]] {{undef|zeroinitializer}}, align [[A_EDCNAGG]]
// CHECK-DAG: @_ZZ8worker_3E3va7 = internal addrspace(3) global [2 x [3 x [[T_DAGG]]]] {{undef|zeroinitializer}}, align [[A_DAGG]]
// CHECK-DAG: @_ZZ8worker_3E3va8 = internal addrspace(3) global [2 x [3 x <2 x i32>]] {{undef|zeroinitializer}}, align 8
// CHECK-DAG: @_ZZ8worker_3E3vt1 = internal addrspace(3) global [2 x [2 x [[T_AGG]]]] {{undef|zeroinitializer}}, align [[A_AGG]]
// CHECK-DAG: @_ZZ8worker_3E3vt2 = internal addrspace(3) global [2 x [2 x [[T_NAGG]]]] {{undef|zeroinitializer}}, align [[A_NAGG]]
// CHECK-DAG: @_ZZ8worker_3E3vt3 = internal addrspace(3) global [2 x [2 x <2 x i32>]] {{undef|zeroinitializer}}, align 8

// CHECK-DAG: @_ZZ8worker_4E2v1 = internal addrspace(3) global i32 {{undef|0}}, align 4

// CHECK-DAG: @_ZZ8worker_5E2v1 = internal addrspace(3) global <4 x i64> {{undef|zeroinitializer}}, align 32

// CHECK-DAG: @_ZZ8worker_6E2v1 = internal addrspace(3) global i64 {{undef|0}}, align 8

// CHECK-DAG: @_ZZ8worker_7E2v1 = internal addrspace(3) global i64 {{undef|0}}, align 8

// CHECK-DAG: @_ZZ8worker_8E2v1 = internal addrspace(3) global i64 {{undef|0}}, align 8

// CHECK-DAG: @_ZZ8worker_9E2v1 = internal addrspace(3) global <2 x i64> {{undef|zeroinitializer}}, align 16

// CHECK-DAG: @_ZZ9worker_10E2v1 = internal addrspace(3) global [10 x i32] {{undef|zeroinitializer}}, align 4

// CHECK-DAG: @_ZZ9worker_11E2v1 = internal addrspace(3) global [2 x [2 x [[T_UCNAGG:%([0-9A-Za-z_\.]+|"[^"]+")]]]] {{undef|zeroinitializer}}, align [[A_UCNAGG:[1-9]+]]

// CHECK-DAG: @_ZZ9worker_12E2v1 = internal addrspace(3) global i32 {{undef|0}}, align 4

// CHECK-DAG: @_ZZ9worker_13E2v1 = internal addrspace(3) global i32 {{undef|0}}, align 4

// CHECK-DAG: @_ZZ9worker_14E2v1 = internal addrspace(3) global [[T_UDAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_UDAGG:[1-9]+]]

// CHECK-DAG: @_ZZ9worker_15E2v1 = internal addrspace(3) global [[T_UDAGG]] {{undef|zeroinitializer}}, align [[A_UDAGG]]


// empty kernel
kernel void worker_1() {             // CHECK-LABEL: define spir_kernel void @worker_1(
}

// single local-mem (no initializer)
kernel void worker_2(int arg) {      // CHECK-LABEL: define spir_kernel void @worker_2(
    LOCAL_MEM int v1; // CHECK-NOT: @_ZZ8worker_2E2v1
}

// multiple local-mem (no initializer)
kernel void worker_3(int arg) {      // CHECK-LABEL: define spir_kernel void @worker_3(
    LOCAL_MEM int                             v1; // CHECK-NOT: @_ZZ8worker_3E2v1
    LOCAL_MEM float3                          v2; // CHECK-NOT: @_ZZ8worker_3E2v2
    LOCAL_MEM TAggregate                      v3; // CHECK-NOT: @_ZZ8worker_3E2v3
    LOCAL_MEM TNonAggregate                   v4; // CHECK-NOT: @_ZZ8worker_3E2v4
    LOCAL_MEM Testers::ExpDefCtorAggregate    v5; // CHECK-NOT: @_ZZ8worker_3E2v5
    LOCAL_MEM Testers::ExpDefCtorNonAggregate v6; // CHECK-NOT: @_ZZ8worker_3E2v6
    LOCAL_MEM Testers::DerivedAggregate       v7; // CHECK-NOT: @_ZZ8worker_3E2v7
    LOCAL_MEM TInt2                           v8; // CHECK-NOT: @_ZZ8worker_3E2v8

    int l1 = arg;

    LOCAL_MEM int                             va1[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va1
    LOCAL_MEM float3                          va2[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va2
    LOCAL_MEM TAggregate                      va3[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va3
    LOCAL_MEM TNonAggregate                   va4[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va4
    LOCAL_MEM Testers::ExpDefCtorAggregate    va5[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va5
    LOCAL_MEM Testers::ExpDefCtorNonAggregate va6[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va6
    LOCAL_MEM Testers::DerivedAggregate       va7[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va7
    LOCAL_MEM TInt2                           va8[2][3]; // CHECK-NOT: @_ZZ8worker_3E3va8

    int l2 = l1 + arg / 2;

    LOCAL_MEM TAggregateA22    vt1; // CHECK-NOT: @_ZZ8worker_3E3vt1
    LOCAL_MEM TNonAggregateA22 vt2; // CHECK-NOT: @_ZZ8worker_3E3vt2
    LOCAL_MEM TInt2A22         vt3; // CHECK-NOT: @_ZZ8worker_3E3vt3
}

// single local-mem (constexpr / integer constant expression initializer; trivial destructor)
kernel void worker_4() {      // CHECK-LABEL: define spir_kernel void @worker_4(
    LOCAL_MEM int v1 = -1234 + static_cast<int>(sizeof(v1)); // CHECK-NEXT: [[ENTRY_W4:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                             // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                             // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                             // CHECK: [[VAL_W4_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                             // CHECK-NEXT: [[VAL_W4_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W4_0]], 0
                                                             // CHECK-NEXT: br i1 [[VAL_W4_1]], label %[[CHECK_W4_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W4_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                             // CHECK: [[CHECK_W4_1]]:
                                                             // CHECK-NEXT: store i32 {{.*}}, i32 addrspace(3)* @_ZZ8worker_4E2v1, align 4
                                                             // CHECK-NEXT: br label %[[END_W4_1]]

                                                             // CHECK: [[END_W4_1]]:
                                                             // CHECK-NEXT: ret void
}

// single local-mem (constexpr / integer constant expression initializer; trivial destructor) + arguments
kernel void worker_5(int arg) {      // CHECK-LABEL: define spir_kernel void @worker_5(
    LOCAL_MEM long4 v1 = -1234 + static_cast<int>(sizeof(v1)); // CHECK-NEXT: [[ENTRY_W5:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                               // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                               // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK: [[VAL_W5_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                               // CHECK-NEXT: [[VAL_W5_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W5_0]], 0
                                                               // CHECK-NEXT: br i1 [[VAL_W5_1]], label %[[CHECK_W5_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W5_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                               // CHECK: [[CHECK_W5_1]]:
                                                               // CHECK-NEXT: store <4 x i64> {{.*}}, <4 x i64> addrspace(3)* @_ZZ8worker_5E2v1, align 32
                                                               // CHECK-NEXT: br label %[[END_W5_1]]

                                                               // CHECK: [[END_W5_1]]:
                                                               // NOTE: -O0 always generates debug code for argument which causes to generate barrier
                                                               // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK-NOT: = alloca {{.+}}
}

// single local-mem (constexpr / integer constant expression initializer; trivial destructor) + following non-local-mem
kernel void worker_6() {      // CHECK-LABEL: define spir_kernel void @worker_6(
    LOCAL_MEM long v1 = -1234 + static_cast<long>(sizeof(v1)); // CHECK-NEXT: [[ENTRY_W6:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                               // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                               // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK: [[VAL_W6_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                               // CHECK-NEXT: [[VAL_W6_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W6_0]], 0
                                                               // CHECK-NEXT: br i1 [[VAL_W6_1]], label %[[CHECK_W6_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W6_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                               // CHECK: [[CHECK_W6_1]]:
                                                               // CHECK-NEXT: store i64 {{.*}}, i64 addrspace(3)* @_ZZ8worker_6E2v1, align 8
                                                               // CHECK-NEXT: br label %[[END_W6_1]]

                                                               // CHECK: [[END_W6_1]]:
                                                               // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK-NOT: = alloca {{.+}}


    auto l1 = v1;                                              // CHECK: [[VAL_W6_2:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i64 addrspace(3)* @_ZZ8worker_6E2v1, align 8
                                                               // CHECK-NOT: = alloca {{.+}}
                                                               // CHECK: store i64 [[VAL_W6_2]]
                                                               // CHECK-NOT: = alloca {{.+}}
}

// single local-mem (constexpr / integer constant expression initializer; trivial destructor) + preceding non-local-mem
kernel void worker_7(long arg) {      // CHECK-LABEL: define spir_kernel void @worker_7(
    auto l1 = arg;
    LOCAL_MEM long v1 = -1234 + static_cast<long>(sizeof(v1)); // CHECK-NEXT: [[ENTRY_W7:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                               // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                               // NOTE: Init moved before automatic variable init (constexpr / ICE opt).
                                                               // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK: [[VAL_W7_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                               // CHECK-NEXT: [[VAL_W7_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W7_0]], 0
                                                               // CHECK-NEXT: br i1 [[VAL_W7_1]], label %[[CHECK_W7_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W7_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                               // CHECK: [[CHECK_W7_1]]:
                                                               // CHECK-NEXT: store i64 {{.*}}, i64 addrspace(3)* @_ZZ8worker_7E2v1, align 8
                                                               // CHECK-NEXT: br label %[[END_W7_1]]

                                                               // CHECK: [[END_W7_1]]:
                                                               // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK-NOT: = alloca {{.+}}
}

// single local-mem (constexpr / integer constant expression initializer; trivial destructor) + between non-local-mem
kernel void worker_8(long arg) {      // CHECK-LABEL: define spir_kernel void @worker_8(
    auto l1 = arg;
    LOCAL_MEM long v1 = -1234 + static_cast<long>(sizeof(v1)); // CHECK-NEXT: [[ENTRY_W8:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                               // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                               // NOTE: Init moved before automatic variable init (constexpr / ICE opt).
                                                               // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK: [[VAL_W8_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                               // CHECK-NEXT: [[VAL_W8_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W8_0]], 0
                                                               // CHECK-NEXT: br i1 [[VAL_W8_1]], label %[[CHECK_W8_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W8_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                               // CHECK: [[CHECK_W8_1]]:
                                                               // CHECK-NEXT: store i64 {{.*}}, i64 addrspace(3)* @_ZZ8worker_8E2v1, align 8
                                                               // CHECK-NEXT: br label %[[END_W8_1]]

                                                               // CHECK: [[END_W8_1]]:
                                                               // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                               // CHECK-NOT: = alloca {{.+}}


    auto l2 = v1 + l1;                                         // CHECK: [[VAL_W8_2:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i64 addrspace(3)* @_ZZ8worker_8E2v1, align 8
                                                               // CHECK-NOT: = alloca {{.+}}
                                                               // CHECK: store i64 [[VAL_W8_3:%([0-9A-Za-z_\.]+|"[^"]+")]]
                                                               // CHECK-NOT: = alloca {{.+}}
}

long func1(const ulong&);
int func2(const long&);

// single local-mem (custom initializer; trivial destructor)
kernel void worker_9() {      // CHECK-LABEL: define spir_kernel void @worker_9(
    LOCAL_MEM long2 v1 = {-1234, func2(func1(sizeof(v1)))}; // CHECK-NEXT: [[ENTRY_W9:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                            // CHECK: [[VAL_W9_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                            // CHECK-NEXT: [[VAL_W9_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W9_0]], 0
                                                            // CHECK-NEXT: br i1 [[VAL_W9_1]], label %[[CHECK_W9_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W9_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                            // CHECK: [[CHECK_W9_1]]:
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: call spir_func i64 @_Z5func1RKU3AS4m
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: call spir_func i32 @_Z5func2RKU3AS4l
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: store <2 x i64> {{.*}}, <2 x i64> addrspace(3)* @_ZZ8worker_9E2v1, align 16
                                                            // CHECK-NEXT: br label %[[END_W9_1]]

                                                            // CHECK: [[END_W9_1]]:
                                                            // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                            // CHECK-NOT: = alloca {{.+}}
}

// single local-mem (custom initializer; trivial destructor) + arguments
kernel void worker_10(int arg, int arg2) {      // CHECK-LABEL: define spir_kernel void @worker_10(
    LOCAL_MEM int v1[10] = {-1234, arg, -arg, 2 * arg - arg2,
                            func2(func1(sizeof(v1)))};        // CHECK-NEXT: [[ENTRY_W10:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                              // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                              // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                              // CHECK-NEXT: [[VAL_W10_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                              // CHECK-NEXT: [[VAL_W10_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W10_0]], 0
                                                              // CHECK-NEXT: br i1 [[VAL_W10_1]], label %[[CHECK_W10_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W10_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                              // CHECK: [[CHECK_W10_1]]:
                                                              // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                              // CHECK-NOT: = alloca {{.+}}
                                                              // CHECK: call spir_func i64 @_Z5func1RKU3AS4m
                                                              // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                              // CHECK-NOT: = alloca {{.+}}
                                                              // CHECK: call spir_func i32 @_Z5func2RKU3AS4l
                                                              // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                              // CHECK-NOT: = alloca {{.+}}
                                                              // CHECK: store i32 {{.*}}, i32 addrspace(3)* getelementptr inbounds ([10 x i32] addrspace(3)* @_ZZ9worker_10E2v1, i{{32|64}} 0, i{{32|64}} 4)
                                                              // CHECK-NEXT: br label %[[LOOP_W10_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                              // CHECK: [[LOOP_W10_1]]:
                                                              // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                              // CHECK-NOT: = alloca {{.+}}
                                                              // CHECK: br i1 {{.*}}, label %[[LOOPE_W10_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[LOOP_W10_1]]

                                                              // CHECK: [[LOOPE_W10_1]]:
                                                              // CHECK-NEXT: br label %[[END_W10_1]]

                                                              // CHECK: [[END_W10_1]]:
                                                              // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                              // CHECK-NOT: = alloca {{.+}}
}

// single local-mem (custom initializer; trivial destructor) + following non-local-mem
kernel void worker_11() {      // CHECK-LABEL: define spir_kernel void @worker_11(
    LOCAL_MEM TUserCtorNonAggregateA22 v1 = {{{},{1,2,3}}}; // CHECK-NEXT: [[ENTRY_W11:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                            // CHECK: [[VAL_W11_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                                            // CHECK-NEXT: [[VAL_W11_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W11_0]], 0
                                                            // CHECK-NEXT: br i1 [[VAL_W11_1]], label %[[CHECK_W11_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W11_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                            // CHECK: [[CHECK_W11_1]]:
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: call spir_func void @_ZNU3AS47Testers20UserCtorNonAggregateC1Ev({{.*}} @_ZZ9worker_11E2v1,
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: call spir_func void @_ZNU3AS47Testers20UserCtorNonAggregateC1Eiii({{.*}} @_ZZ9worker_11E2v1,
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: br label %[[LOOP_W11_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                            // CHECK: [[LOOP_W11_1]]:
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: br label %[[LOOP_W11_2:[0-9A-Za-z_\.]+|"[^"]+"]]

                                                            // CHECK: [[LOOP_W11_2]]:
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: call spir_func void @_ZNU3AS47Testers20UserCtorNonAggregateC1Ev(
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: br i1 {{.*}}, label %[[LOOPE_W11_2:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[LOOP_W11_2]]

                                                            // CHECK: [[LOOPE_W11_2]]:
                                                            // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                                            // CHECK-NOT: = alloca {{.+}}
                                                            // CHECK: br i1 {{.*}}, label %[[LOOPE_W11_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[LOOP_W11_1]]

                                                            // CHECK: [[LOOPE_W11_1]]:
                                                            // CHECK-NEXT: br label %[[END_W11_1]]

                                                            // CHECK: [[END_W11_1]]:
                                                            // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                                            // CHECK-NOT: = alloca {{.+}}


    auto l1 = v1;                                           // CHECK: store [2 x [[T_UCNAGG]]] {{.*}} @_ZZ9worker_11E2v1, {{.*}}, align {{4|8}}
                                                            // CHECK-NOT: = alloca {{.+}}
}

int g1 = 1234;
int g2 = 1235;

// single local-mem (custom initializer; trivial destructor) + preceding non-local-mem
kernel void worker_12(int arg, int arg2) {      // CHECK-LABEL: define spir_kernel void @worker_12(
    int l1 = arg + g1 / arg2;
    LOCAL_MEM int v1 = l1 > 3 ? l1 : g2; // CHECK-NEXT: [[ENTRY_W12:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                         // CHECK-NEXT: [[VAL_W12_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                         // CHECK-NEXT: [[VAL_W12_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W12_0]], 0
                                         // CHECK-NEXT: br i1 [[VAL_W12_1]], label %[[CHECK_W12_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W12_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                         // CHECK: [[CHECK_W12_1]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: br i1 {{.*}}, label %[[IFT_W12_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[IFF_W12_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                         // CHECK: [[IFT_W12_1]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: br label %[[IFE_W12_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                         // CHECK: [[IFF_W12_1]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: br label %[[IFE_W12_1]]

                                         // CHECK: [[IFE_W12_1]]:
                                         // CHECK-NEXT: [[VAL_W12_2:%([0-9A-Za-z_\.]+|"[^"]+")]] = phi i32
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: store i32 [[VAL_W12_2]], i32 addrspace(3)* @_ZZ9worker_12E2v1, align 4
                                         // CHECK-NEXT: br label %[[END_W12_1]]

                                         // CHECK: [[END_W12_1]]:
                                         // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                         // CHECK-NOT: = alloca {{.+}}
}

// single local-mem (custom initializer; trivial destructor) + between non-local-mem
kernel void worker_13(int arg, int arg2) {      // CHECK-LABEL: define spir_kernel void @worker_13(
    int l1 = arg + g1 / arg2;
    LOCAL_MEM int v1 = l1 > 3 ? l1 : g2; // CHECK-NEXT: [[ENTRY_W13:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                         // CHECK-NEXT: [[VAL_W13_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                         // CHECK-NEXT: [[VAL_W13_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W13_0]], 0
                                         // CHECK-NEXT: br i1 [[VAL_W13_1]], label %[[CHECK_W13_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W13_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                         // CHECK: [[CHECK_W13_1]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: br i1 {{.*}}, label %[[IFT_W13_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[IFF_W13_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                         // CHECK: [[IFT_W13_1]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: br label %[[IFE_W13_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                         // CHECK: [[IFF_W13_1]]:
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: br label %[[IFE_W13_1]]

                                         // CHECK: [[IFE_W13_1]]:
                                         // CHECK-NEXT: [[VAL_W13_2:%([0-9A-Za-z_\.]+|"[^"]+")]] = phi i32
                                         // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: store i32 [[VAL_W13_2]], i32 addrspace(3)* @_ZZ9worker_13E2v1, align 4
                                         // CHECK-NEXT: br label %[[END_W13_1]]

                                         // CHECK: [[END_W13_1]]:
                                         // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                         // CHECK-NOT: = alloca {{.+}}


    int l2 = v1;                         // CHECK: [[VAL_W6_2:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i32 addrspace(3)* @_ZZ9worker_13E2v1, align 4
                                         // CHECK-NOT: = alloca {{.+}}
                                         // CHECK: store i32 [[VAL_W6_2]]
                                         // CHECK-NOT: = alloca {{.+}}
}

// single local-mem (trivial initializer; non-trivial destructor) + preceding non-local-mem
kernel void worker_14() {      // CHECK-LABEL: define spir_kernel void @worker_14(
    int l1 = 12345;
    LOCAL_MEM Testers::UserDtorAggregate v1; // CHECK-NEXT: [[ENTRY_W14:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                             // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
                                             // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
                                             // CHECK-NEXT: [[VAL_W14_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                             // CHECK-NEXT: [[VAL_W14_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W14_0]], 0
                                             // CHECK-NEXT: br i1 [[VAL_W14_1]], label %[[CHECK_W14_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W14_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                             // CHECK: [[CHECK_W14_1]]:
                                             // CHECK-NEXT: call spir_func void @__dtor__ZZ9worker_14E2v1()
                                             // CHECK-NEXT: br label %[[END_W14_1]]

                                             // CHECK: [[END_W14_1]]:
                                             // CHECK-NEXT: ret void
}

// single local-mem (trivial initializer; non-trivial destructor)
kernel void worker_15() {      // CHECK-LABEL: define spir_kernel void @worker_15(
    LOCAL_MEM Testers::UserDtorAggregate v1; // CHECK-NEXT: [[ENTRY_W15:^([0-9A-Za-z_\.]+|"[^"]+")]]:
                                             // CHECK-NEXT: [[VAL_W15_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
                                             // CHECK-NEXT: [[VAL_W15_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_W15_0]], 0
                                             // CHECK-NEXT: br i1 [[VAL_W15_1]], label %[[CHECK_W15_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_W15_1:[0-9A-Za-z_\.]+|"[^"]+"]]

                                             // CHECK: [[CHECK_W15_1]]:
                                             // CHECK-NEXT: call spir_func void @__dtor__ZZ9worker_15E2v1()
                                             // CHECK-NEXT: br label %[[END_W15_1]]

                                             // CHECK: [[END_W15_1]]:
                                             // CHECK-NEXT: ret void
}

// CHECK-NOT: define spir_kernel void @_SPIRV_
