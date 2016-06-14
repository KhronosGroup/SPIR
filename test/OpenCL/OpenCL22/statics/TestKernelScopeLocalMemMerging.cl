// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | opt -instnamer -S | FileCheck %s
// expected-no-diagnostics

#define LOCAL_MEM __local

#include "../opencl_def"


// Type of variable (default local-mem) added:
// E - added to entry section
// F - added to final section
// I - added to inline section
// N - non-local-memory variable

int fun();
int fun(const int &);
// Class with user destructor (non-trivial).
struct UDC {
    ~UDC();
};


kernel void simple_EE() {
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM int v2 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_EE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_EEE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_EEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_EEEE() {
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM int v2 = 1234;
    LOCAL_MEM int v3 = 1234;
    LOCAL_MEM int v4 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_EEEE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_EEEEE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_EEEEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_EEEEE2v3, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_EEEEE2v4, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_EI() {
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM int v2 = fun();

    // CHECK-LABEL: define spir_kernel void @simple_EI(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_EIE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_EIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_EF() {
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM UDC v2;

    // CHECK-LABEL: define spir_kernel void @simple_EF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_EFE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ9simple_EFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_IE()
{
    LOCAL_MEM int v1 = fun();
    LOCAL_MEM int v2 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_IE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_IEE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_IEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_II()
{
    LOCAL_MEM int v1 = fun();
    LOCAL_MEM int v2 = fun();

    // CHECK-LABEL: define spir_kernel void @simple_II(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_IIE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_IIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_IIII() {
    LOCAL_MEM int v1 = fun();
    LOCAL_MEM int v2 = fun();
    LOCAL_MEM int v3 = fun();
    LOCAL_MEM int v4 = fun();

    // CHECK-LABEL: define spir_kernel void @simple_IIII(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_IIIIE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_IIIIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_IIIIE2v3, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ11simple_IIIIE2v4, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_IF() {
    LOCAL_MEM int v1 = fun();
    LOCAL_MEM UDC v2;

    // CHECK-LABEL: define spir_kernel void @simple_IF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_IFE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ9simple_IFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_FE() {
    LOCAL_MEM UDC v1;
    LOCAL_MEM int v2 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_FE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_FEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ9simple_FEE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_FI() {
    LOCAL_MEM UDC v1;
    LOCAL_MEM int v2 = fun();

    // CHECK-LABEL: define spir_kernel void @simple_FI(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ9simple_FIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ9simple_FIE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_FF() {
    LOCAL_MEM UDC v1;
    LOCAL_MEM UDC v2;

    // CHECK-LABEL: define spir_kernel void @simple_FF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ9simple_FFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ9simple_FFE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_FFFF() {
    LOCAL_MEM UDC v1;
    LOCAL_MEM UDC v2;
    LOCAL_MEM UDC v3;
    LOCAL_MEM UDC v4;

    // CHECK-LABEL: define spir_kernel void @simple_FFFF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ11simple_FFFFE2v4()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ11simple_FFFFE2v3()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ11simple_FFFFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ11simple_FFFFE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

// -------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------

kernel void simple_NEE() {
    int l1 = 1234;
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM int v2 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_NEE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NEEE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NEEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_NEEEE(int arg) {
    int l1 = arg;
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM int v2 = 1234;
    LOCAL_MEM int v3 = 1234;
    LOCAL_MEM int v4 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_NEEEE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NEEEEE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NEEEEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NEEEEE2v3, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NEEEEE2v4, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_NEI(int arg) {
    int l1 = arg;
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM int v2 = fun();

    // CHECK-LABEL: define spir_kernel void @simple_NEI(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NEIE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}


    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0A:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1A:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0A]], 0
    // CHECK-NEXT: br i1 [[VAL_1A]], label %[[CHECK_1A:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1A:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1A]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NEIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1A]]

    // CHECK: [[END_1A]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_NEF(int arg) {
    int l1 = arg;
    LOCAL_MEM int v1 = 1234;
    LOCAL_MEM UDC v2;

    // CHECK-LABEL: define spir_kernel void @simple_NEF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NEFE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}


    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0A:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1A:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0A]], 0
    // CHECK-NEXT: br i1 [[VAL_1A]], label %[[CHECK_1A:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1A:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1A]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ10simple_NEFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1A]]

    // CHECK: [[END_1A]]:
    // CHECK-NEXT: ret void
}

kernel void simple_NIE(int arg)
{
    int l1 = arg;
    LOCAL_MEM int v1 = fun(l1);
    LOCAL_MEM int v2 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_NIE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NIEE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NIEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_NII(int arg, int arg1)
{
    auto l1 = arg;
    auto l2 = l1 + arg1;
    LOCAL_MEM int v1 = fun(l1);
    LOCAL_MEM int v2 = fun(l2);

    // CHECK-LABEL: define spir_kernel void @simple_NII(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NIIE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NIIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_NIIII() {
    int l1; // NOTE: uninitialized should omit barrier.
    LOCAL_MEM int v1 = fun();
    LOCAL_MEM int v2 = fun(l1);
    LOCAL_MEM int v3 = fun();
    LOCAL_MEM int v4 = fun(l1);

    // CHECK-LABEL: define spir_kernel void @simple_NIIII(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NIIIIE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NIIIIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NIIIIE2v3, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ12simple_NIIIIE2v4, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void simple_NIF(int arg) {
    auto l1 = arg;
    LOCAL_MEM int v1 = fun(l1);
    LOCAL_MEM UDC v2;

    // CHECK-LABEL: define spir_kernel void @simple_NIF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NIFE2v1, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ10simple_NIFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_NFE(int arg) {
    int l1 = arg;
    LOCAL_MEM UDC v1;
    LOCAL_MEM int v2 = 1234;

    // CHECK-LABEL: define spir_kernel void @simple_NFE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NFEE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}


    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0A:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1A:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0A]], 0
    // CHECK-NEXT: br i1 [[VAL_1A]], label %[[CHECK_1A:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1A:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1A]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ10simple_NFEE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1A]]

    // CHECK: [[END_1A]]:
    // CHECK-NEXT: ret void
}

kernel void simple_NFI(int arg) {
    auto l1 = arg;
    LOCAL_MEM UDC v1;
    LOCAL_MEM int v2 = fun(l1);

    // CHECK-LABEL: define spir_kernel void @simple_NFI(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: store i32 {{.*}}, i32 addrspace(3)* @_ZZ10simple_NFIE2v2, align 4
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ10simple_NFIE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_NFF(int arg) {
    auto l1 = arg;
    LOCAL_MEM UDC v1;
    LOCAL_MEM UDC v2;

    // CHECK-LABEL: define spir_kernel void @simple_NFF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NEXT: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ10simple_NFFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ10simple_NFFE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void simple_NFFFF() {
    int l1; // NOTE: uninitialized should omit barrier.
    int l2;
    long l3;
    LOCAL_MEM UDC v1;
    LOCAL_MEM UDC v2;
    LOCAL_MEM UDC v3;
    LOCAL_MEM UDC v4;

    // CHECK-LABEL: define spir_kernel void @simple_NFFFF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ12simple_NFFFFE2v4()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ12simple_NFFFFE2v3()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ12simple_NFFFFE2v2()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: call spir_func void @__dtor__ZZ12simple_NFFFFE2v1()
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

// -------------------------------------------------------------------------------------------------------
// Complex merging (multiple block initializers)
//  * ensuring only two precedessors of end block
// -------------------------------------------------------------------------------------------------------

kernel void complex_EE() {
    LOCAL_MEM int v1[5] = {1234, 567};
    LOCAL_MEM int v2[7] = {1234, 468, 223};

    // CHECK-LABEL: define spir_kernel void @complex_EE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]
    // CHECK-NOT: = alloca {{.+}}
    // CHECK-NOT: br {{.*}} label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void complex_ENE() {
    LOCAL_MEM int v1[5] = {1234, 567};
    auto l1 = v1[3];
    LOCAL_MEM int v2[7] = {1234, 468, 223};

    // CHECK-LABEL: define spir_kernel void @complex_ENE(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]
    // CHECK-NOT: = alloca {{.+}}
    // CHECK-NOT: br {{.*}} label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void complex_EI() {
    LOCAL_MEM int v1[5] = {1234, 567};
    LOCAL_MEM int v2[7] = {1234, fun(), fun() ? fun(1) : 0};

    // CHECK-LABEL: define spir_kernel void @complex_EI(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]
    // CHECK-NOT: = alloca {{.+}}
    // CHECK-NOT: br {{.*}} label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void complex_EF() {
    LOCAL_MEM int v1[5] = {1234, 567};
    LOCAL_MEM UDC v2[7][1][2];

    // CHECK-LABEL: define spir_kernel void @complex_EF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]
    // CHECK-NOT: = alloca {{.+}}
    // CHECK-NOT: br {{.*}} label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

kernel void complex_II() {
    LOCAL_MEM int v1[5][2] = {{1234, 567}, {fun(), fun() ? -fun(): 2+fun()}};
    LOCAL_MEM int v2[7] = {1234, fun(), fun() ? fun(1) : 0};

    // CHECK-LABEL: define spir_kernel void @complex_II(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]
    // CHECK-NOT: = alloca {{.+}}
    // CHECK-NOT: br {{.*}} label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK-NOT: = alloca {{.+}}
}

kernel void complex_IF() {
    LOCAL_MEM int v1[5][2] = {{1234, 567}, {fun(), fun() ? -fun(): 2+fun()}};
    LOCAL_MEM UDC v2[7][7];

    // CHECK-LABEL: define spir_kernel void @complex_IF(

    // CHECK-NEXT: [[ENTRY:^([0-9A-Za-z_\.]+|"[^"]+")]]:
    // CHECK-NOT: {{^([0-9A-Za-z_\.]+|"[^"]+"):}}
    // CHECK-NOT: call spir_func void @_Z22__spirv_ControlBarrierjjj(i32 2, i32 2, i32 272)
    // CHECK: [[VAL_0:%([0-9A-Za-z_\.]+|"[^"]+")]] = load i{{32|64}} addrspace(1)* @__spirv_BuiltInLocalInvocationIndex
    // CHECK-NEXT: [[VAL_1:%([0-9A-Za-z_\.]+|"[^"]+")]] = icmp eq i{{32|64}} [[VAL_0]], 0
    // CHECK-NEXT: br i1 [[VAL_1]], label %[[CHECK_1:[0-9A-Za-z_\.]+|"[^"]+"]], label %[[END_1:[0-9A-Za-z_\.]+|"[^"]+"]]

    // CHECK: [[CHECK_1]]:
    // CHECK-NOT: = alloca {{.+}}
    // CHECK: br label %[[END_1]]
    // CHECK-NOT: = alloca {{.+}}
    // CHECK-NOT: br {{.*}} label %[[END_1]]

    // CHECK: [[END_1]]:
    // CHECK-NEXT: ret void
}

// CHECK-NOT: define spir_kernel void @_SPIRV_
