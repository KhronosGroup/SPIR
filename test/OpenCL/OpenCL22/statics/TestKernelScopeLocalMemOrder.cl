// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s
// expected-no-diagnostics

#define LOCAL_MEM __local

#include "../opencl_def"


// Class with user constructor (non-trivial).
struct UCC {
    UCC();
};
// Class with user destructor (non-trivial).
struct UDC {
    ~UDC();
};
// Class with user constructor and destructor (non-trivial).
struct UCDC {
    UCDC();
    ~UCDC();
};

kernel void worker() {
    int l1 = 1234;
    LOCAL_MEM UCC  v1;
    LOCAL_MEM UCC  v2;
    LOCAL_MEM UDC  v3;
    LOCAL_MEM UDC  v4;
    LOCAL_MEM UCDC v5;
    LOCAL_MEM UCDC v6;
    LOCAL_MEM UCDC v7;
    LOCAL_MEM UDC  v8;
    LOCAL_MEM UCC  v9;
    int l2 = 1234;

    // CHECK-LABEL: define spir_kernel void @worker(

    // CHECK: call spir_func void @_ZNU3AS43UCCC1Ev({{.*}} @_ZZ6workerE2v1
    // CHECK: call spir_func void @_ZNU3AS43UCCC1Ev({{.*}} @_ZZ6workerE2v2
    // CHECK: call spir_func void @_ZNU3AS44UCDCC1Ev({{.*}} @_ZZ6workerE2v5
    // CHECK: call spir_func void @_ZNU3AS44UCDCC1Ev({{.*}} @_ZZ6workerE2v6
    // CHECK: call spir_func void @_ZNU3AS44UCDCC1Ev({{.*}} @_ZZ6workerE2v7
    // CHECK: call spir_func void @_ZNU3AS43UCCC1Ev({{.*}} @_ZZ6workerE2v9

    // CHECK-NOT: ret void

    // CHECK: call spir_func void @__dtor__ZZ6workerE2v8()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ6workerE2v7()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ6workerE2v6()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ6workerE2v5()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ6workerE2v4()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ6workerE2v3()
    // CHECK-NOT: call spir_func void @__dtor__
    // CHECK: ret void
}

kernel void worker_returns(int arg) {
    int l1 = 1234;
    LOCAL_MEM UCC  v1;
    LOCAL_MEM UCC  v2;
    LOCAL_MEM UDC  v3;
    LOCAL_MEM UDC  v4;
    LOCAL_MEM UCDC v5;
    LOCAL_MEM UCDC v6;
    LOCAL_MEM UCDC v7;
    LOCAL_MEM UDC  v8;
    LOCAL_MEM UCC  v9;
    if (arg > 2) return; // NOTE: possible barrier in divergent control flow (early return case).
    if (arg + l1 > 14) return; // NOTE: possible barrier in divergent control flow (early return case).
    int l2 = 1234;

    // CHECK-LABEL: define spir_kernel void @worker_returns(

    // CHECK: call spir_func void @_ZNU3AS43UCCC1Ev({{.*}} @_ZZ14worker_returnsE2v1
    // CHECK: call spir_func void @_ZNU3AS43UCCC1Ev({{.*}} @_ZZ14worker_returnsE2v2
    // CHECK: call spir_func void @_ZNU3AS44UCDCC1Ev({{.*}} @_ZZ14worker_returnsE2v5
    // CHECK: call spir_func void @_ZNU3AS44UCDCC1Ev({{.*}} @_ZZ14worker_returnsE2v6
    // CHECK: call spir_func void @_ZNU3AS44UCDCC1Ev({{.*}} @_ZZ14worker_returnsE2v7
    // CHECK: call spir_func void @_ZNU3AS43UCCC1Ev({{.*}} @_ZZ14worker_returnsE2v9
    
    // CHECK: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp sgt i32 {{.*}}, 2
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[IFT_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[IFF_1:[0-9A-Za-z_\.]+|"[^"]+"]]
    
    // CHECK: [[IFT_1]]:
    // CHECK-NEXT: br label %[[RET_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[VAL_2:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp sgt i32 {{.*}}, 14
    // CHECK-NEXT: br i1 [[VAL_2]], label %[[IFT_2:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[IFF_2:[0-9A-Za-z_\.]+|"[^"]+"]]
    
    // CHECK: [[IFT_2]]:
    // CHECK-NEXT: br label %[[RET_1]]

    // CHECK-NOT: ret void
    
    // CHECK: [[RET_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)

    // CHECK: call spir_func void @__dtor__ZZ14worker_returnsE2v8()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ14worker_returnsE2v7()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ14worker_returnsE2v6()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ14worker_returnsE2v5()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ14worker_returnsE2v4()
    // CHECK-NEXT: call spir_func void @__dtor__ZZ14worker_returnsE2v3()
    // CHECK-NOT: call spir_func void @__dtor__
    // CHECK: ret void
}


// CHECK-NOT: define spir_kernel void @_SPIRV_
