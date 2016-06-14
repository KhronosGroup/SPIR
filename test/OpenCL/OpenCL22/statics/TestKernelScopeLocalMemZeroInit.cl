// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -cl-zero-init-local-mem-vars -emit-llvm -o - | opt -instnamer -S | FileCheck %s --check-prefix=ZCHECK --check-prefix=CHECK
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -cl-zero-init-local-mem-vars -emit-llvm -o - | opt -instnamer -S | FileCheck %s --check-prefix=ZCHECK --check-prefix=CHECK
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s --check-prefix=NCHECK --check-prefix=CHECK
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s --check-prefix=NCHECK --check-prefix=CHECK
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

        constexpr UserConstexprCtorNonAggregate() : a(123), b(456) {}
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


// ZCHECK-DAG: @__spirv_BuiltInLocalInvocationIndex = external addrspace(1) externally_initialized constant i{{32|64}}

// CHECK-DAG: @_ZZ6workerE2v1 = internal addrspace(3) global i32 {{undef|0}}, align 4
// CHECK-DAG: @_ZZ6workerE2v2 = internal addrspace(3) global <3 x float> {{undef|zeroinitializer}}, align 16
// CHECK-DAG: @_ZZ6workerE2v3 = internal addrspace(3) global [[T_AGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_AGG:[1-9]+]]
// CHECK-DAG: @_ZZ6workerE2v4 = internal addrspace(3) global [[T_NAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_NAGG:[1-9]+]]
// CHECK-DAG: @_ZZ6workerE2v5 = internal addrspace(3) global [[T_EDCAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_EDCAGG:[1-9]+]]
// CHECK-DAG: @_ZZ6workerE2v6 = internal addrspace(3) global [[T_EDCNAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_EDCNAGG:[1-9]+]]
// CHECK-DAG: @_ZZ6workerE2v7 = internal addrspace(3) global [[T_DAGG:%([0-9A-Za-z_\.]+|"[^"]+")]] {{undef|zeroinitializer}}, align [[A_DAGG:[1-9]+]]
// CHECK-DAG: @_ZZ6workerE2v8 = internal addrspace(3) global <2 x i32> {{undef|zeroinitializer}}, align 8
// CHECK-DAG: @_ZZ6workerE3va1 = internal addrspace(3) global [2 x [3 x i32]] {{undef|zeroinitializer}}, align 4
// CHECK-DAG: @_ZZ6workerE3va2 = internal addrspace(3) global [2 x [3 x <3 x float>]] {{undef|zeroinitializer}}, align 16
// CHECK-DAG: @_ZZ6workerE3va3 = internal addrspace(3) global [2 x [3 x [[T_AGG]]]] {{undef|zeroinitializer}}, align [[A_AGG]]
// CHECK-DAG: @_ZZ6workerE3va4 = internal addrspace(3) global [2 x [3 x [[T_NAGG]]]] {{undef|zeroinitializer}}, align [[A_NAGG]]
// CHECK-DAG: @_ZZ6workerE3va5 = internal addrspace(3) global [2 x [3 x [[T_EDCAGG]]]] {{undef|zeroinitializer}}, align [[A_EDCAGG]]
// CHECK-DAG: @_ZZ6workerE3va6 = internal addrspace(3) global [2 x [3 x [[T_EDCNAGG]]]] {{undef|zeroinitializer}}, align [[A_EDCNAGG]]
// CHECK-DAG: @_ZZ6workerE3va7 = internal addrspace(3) global [2 x [3 x [[T_DAGG]]]] {{undef|zeroinitializer}}, align [[A_DAGG]]
// CHECK-DAG: @_ZZ6workerE3va8 = internal addrspace(3) global [2 x [3 x <2 x i32>]] {{undef|zeroinitializer}}, align 8
// CHECK-DAG: @_ZZ6workerE3vt1 = internal addrspace(3) global [2 x [2 x [[T_AGG]]]] {{undef|zeroinitializer}}, align [[A_AGG]]
// CHECK-DAG: @_ZZ6workerE3vt2 = internal addrspace(3) global [2 x [2 x [[T_NAGG]]]] {{undef|zeroinitializer}}, align [[A_NAGG]]
// CHECK-DAG: @_ZZ6workerE3vt3 = internal addrspace(3) global [2 x [2 x <2 x i32>]] {{undef|zeroinitializer}}, align 8


// multiple local-mem (no initializer)
kernel void worker(int arg) {      // CHECK-LABEL: define spir_kernel void @worker(
    // ZCHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // ZCHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // ZCHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // NCHECK-NOT: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // ZCHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // ZCHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // ZCHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // ZCHECK: [[CHECK_1]]:
    LOCAL_MEM int                             v1; // NCHECK-NOT: @_ZZ6workerE2v1
                                                  // ZCHECK-NEXT: store i32 0, i32 addrspace(3)* @_ZZ6workerE2v1, align 4
    LOCAL_MEM float3                          v2; // NCHECK-NOT: @_ZZ6workerE2v2
                                                  // ZCHECK-NEXT: store <4 x float> <float {{(0*\.0+|0+\.?0*)([eE][+-]?0+)?}}, float {{(0*\.0+|0+\.?0*)([eE][+-]?0+)?}}, float {{(0*\.0+|0+\.?0*)([eE][+-]?0+)?}}, float undef>, {{.*}} @_ZZ6workerE2v2 {{.*}}, align 16
    LOCAL_MEM TAggregate                      v3; // NCHECK-NOT: @_ZZ6workerE2v3
                                                  // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE2v3 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TNonAggregate                   v4; // NCHECK-NOT: @_ZZ6workerE2v4
                                                  // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE2v4 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM Testers::ExpDefCtorAggregate    v5; // NCHECK-NOT: @_ZZ6workerE2v5
                                                  // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE2v5 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM Testers::ExpDefCtorNonAggregate v6; // NCHECK-NOT: @_ZZ6workerE2v6
                                                  // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE2v6 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM Testers::DerivedAggregate       v7; // NCHECK-NOT: @_ZZ6workerE2v7
                                                  // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE2v7 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TInt2                           v8; // NCHECK-NOT: @_ZZ6workerE2v8
                                                  // ZCHECK-NEXT: store <2 x i32> zeroinitializer, <2 x i32> addrspace(3)* @_ZZ6workerE2v8, align 8

    int l1 = arg;

    LOCAL_MEM int                             va1[2][3]; // NCHECK-NOT: @_ZZ6workerE3va1
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va1 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM float3                          va2[2][3]; // NCHECK-NOT: @_ZZ6workerE3va2
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va2 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TAggregate                      va3[2][3]; // NCHECK-NOT: @_ZZ6workerE3va3
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va3 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TNonAggregate                   va4[2][3]; // NCHECK-NOT: @_ZZ6workerE3va4
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va4 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM Testers::ExpDefCtorAggregate    va5[2][3]; // NCHECK-NOT: @_ZZ6workerE3va5
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va5 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM Testers::ExpDefCtorNonAggregate va6[2][3]; // NCHECK-NOT: @_ZZ6workerE3va6
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va6 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM Testers::DerivedAggregate       va7[2][3]; // NCHECK-NOT: @_ZZ6workerE3va7
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va7 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TInt2                           va8[2][3]; // NCHECK-NOT: @_ZZ6workerE3va8
                                                         // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3va8 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})

    int l2 = l1 + arg / 2;

    LOCAL_MEM TAggregateA22    vt1; // NCHECK-NOT: @_ZZ6workerE3vt1
                                    // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3vt1 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TNonAggregateA22 vt2; // NCHECK-NOT: @_ZZ6workerE3vt2
                                    // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3vt2 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TInt2A22         vt3; // NCHECK-NOT: @_ZZ6workerE3vt3
                                    // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ6workerE3vt3 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    // ZCHECK-NEXT: br label %[[END_1]]


    // NCHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // ZCHECK: [[END_1]]:
    // ZCHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // ZCHECK-NOT: = alloca {{.+}}
}

// multiple local-mem (constexpr initializer of integer constant expression)
kernel void worker_ice(int arg) {      // CHECK-LABEL: define spir_kernel void @worker_ice(
    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    LOCAL_MEM int                                    v1 = 1;   // CHECK-NEXT: store i32 1, i32 addrspace(3)* @_ZZ10worker_iceE2v1, align 4
    LOCAL_MEM float2                                 v2 = 2;   // CHECK-NEXT: store <2 x float> <float {{2(\.0*)?([eE][+-]?0+)?}}, float {{2(\.0*)?([eE][+-]?0+)?}}>, <2 x float> addrspace(3)* @_ZZ10worker_iceE2v2, align 8
    LOCAL_MEM TAggregate                             v3 = {1}; // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ10worker_iceE2v3 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
                                                               // CHECK-NEXT: store i32 1, {{.*}} @_ZZ10worker_iceE2v3, {{.*}}, align 4
                                                               // CHECK-NEXT: store float {{(0*\.0+|0+\.?0*)([eE][+-]?0+)?}}, {{.*}} @_ZZ10worker_iceE2v3, {{.*}}, align 4
    LOCAL_MEM TNonAggregate                          v4;       // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ10worker_iceE2v4 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM Testers::ExpDefCtorAggregate           v5{1, 2}; // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ10worker_iceE2v5 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
                                                               // CHECK-NEXT: store i32 1, {{.*}} @_ZZ10worker_iceE2v5, {{.*}}, align 4
                                                               // CHECK-NEXT: store i64 2, {{.*}} @_ZZ10worker_iceE2v5, {{.*}}, align 8
    LOCAL_MEM Testers::UserConstexprCtorNonAggregate v6;       // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ10worker_iceE2v6 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
                                                               // CHECK-NEXT: call spir_func void @_ZNU3AS47Testers29UserConstexprCtorNonAggregateC1Ev({{.*}} @_ZZ10worker_iceE2v6 {{.*}})

    int l1 = arg;

    LOCAL_MEM int                             va1[2] = {1, 2};   // ZCHECK-NEXT: call void @llvm.memset.{{.*}} @_ZZ10worker_iceE3va1 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
                                                                 // CHECK-NEXT: store i32 1, {{.*}} @_ZZ10worker_iceE3va1, {{.*}}
                                                                 // CHECK-NEXT: store i32 2, {{.*}} @_ZZ10worker_iceE3va1, {{.*}}
    LOCAL_MEM char2                           va2[2] = {{1, 2}}; // ZCHECK: call void @llvm.memset.{{.*}} @_ZZ10worker_iceE3va2, {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})
    LOCAL_MEM TAggregate                      va3[2] = {{1, 2}}; // ZCHECK: call void @llvm.memset.{{.*}} @_ZZ10worker_iceE3va3 {{.*}}, i8 0, i{{32|64}} {{.*}}, i{{32|64}} {{.*}}, i1 {{.*}})

    int l2 = l1 + arg / 2;

    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: ret void
}

// CHECK-NOT: define spir_kernel void @_SPIRV_
