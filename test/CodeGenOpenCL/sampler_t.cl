// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 | FileCheck %s
// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 -cl-keep-sampler-type | FileCheck -check-prefix CHECK-SAMPLER-TYPE %s

// CHECK-SAMPLER-TYPE: %opencl.sampler_t = type { i32 }

#define CLK_NORMALIZED_COORDS_TRUE 0x01
#define CLK_ADDRESS_REPEAT 0x02
#define CLK_FILTER_NEAREST 0x04

const sampler_t gs = 2;
// CHECK: @gs = constant i32 2
// CHECK-SAMPLER-TYPE: @gs = constant %opencl.sampler_t { i32 2 }, align 4

constant sampler_t cgs = 3;
// CHECK: @cgs = addrspace(2) constant i32 3
// CHECK-SAMPLER-TYPE: @cgs = addrspace(2) constant %opencl.sampler_t { i32 3 }, align 4

// CHECK: @bar.cst = internal addrspace(2) constant i32 6
// CHECK: @bar.dd = internal addrspace(2) constant i32 3
// CHECK-SAMPLER-TYPE: @bar.kst = internal constant %opencl.sampler_t { i32 5 }, align 4
// CHECK-SAMPLER-TYPE: @bar.cst = internal addrspace(2) constant %opencl.sampler_t { i32 6 }, align 4
// CHECK-SAMPLER-TYPE: @bar.lst = internal constant %opencl.sampler_t { i32 7 }, align 4
// CHECK-SAMPLER-TYPE: @bar.dd = internal addrspace(2) constant %opencl.sampler_t { i32 3 }, align 4

void foo(const sampler_t st){}
// CHECK: define spir_func void @foo(i32
// CHECK-SAMPLER-TYPE: define spir_func void @foo(%opencl.sampler_t* byval %st)

kernel void bar(const sampler_t ast) {
// CHECK: define spir_kernel void @bar(i32
// CHECK-SAMPLER-TYPE: define spir_kernel void @bar(%opencl.sampler_t* byval %ast)

// CHECK: {{.*}} = alloca i32
// CHECK: %kst = alloca i32
// CHECK: %ost = alloca i32
// CHECK: %lst = alloca i32
// CHECK: %q = alloca i32

// CHECK-SAMPLER-TYPE: {{.*}} = alloca %opencl.sampler_t, align 4
// CHECK-SAMPLER-TYPE: [[Q_SAMPLER:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4
// CHECK-SAMPLER-TYPE: [[LITERAL_ARG:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4
// CHECK-SAMPLER-TYPE: [[DD_SAMPLER:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4
// CHECK-SAMPLER-TYPE: [[LITERAL_ARG2:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4

    const sampler_t kst = 5;
    foo(kst);
// CHECK: call spir_func void @foo(i32
// CHECK-SAMPLER-TYPE: call spir_func void @foo(%opencl.sampler_t* byval @bar.kst)

    constant sampler_t cst = 6;
    const sampler_t ost = cst;
// CHECK: [[CST:%[0-9]+]] = load i32 addrspace(2)* @bar.cst
// CHECK: store i32 [[CST]], i32* %ost
// CHECK-SAMPLER-TYPE: [[SMP:%[0-9]+]] = load %opencl.sampler_t addrspace(2)* @bar.cst
// CHECK-SAMPLER-TYPE: store %opencl.sampler_t [[SMP]], %opencl.sampler_t* %ost

    const sampler_t lst = CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT|CLK_FILTER_NEAREST;
    foo(lst);
// CHECK: call spir_func void @foo(i32
// CHECK-SAMPLER-TYPE: call spir_func void @foo(%opencl.sampler_t* byval @bar.lst)

    const int q = CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT;
    foo(q);
// CHECK: call spir_func void @foo(i32 3)
// CHECK-SAMPLER-TYPE: [[Q_PTR:%[A-Za-z0-9_\.]+]] = getelementptr inbounds %opencl.sampler_t* [[Q_SAMPLER]], i32 0, i32 0
// CHECK-SAMPLER-TYPE: store i32 3, i32* [[Q_PTR]]
// CHECK-SAMPLER-TYPE: call spir_func void @foo(%opencl.sampler_t* byval [[Q_SAMPLER]])

    foo(CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT);
// CHECK: call spir_func void @foo(i32 3)
// CHECK-SAMPLER-TYPE: [[LIT_PTR:%[A-Za-z0-9_\.]+]] = getelementptr inbounds %opencl.sampler_t* [[LITERAL_ARG]], i32 0, i32 0
// CHECK-SAMPLER-TYPE: store i32 3, i32* [[LIT_PTR]]
// CHECK-SAMPLER-TYPE: call spir_func void @foo(%opencl.sampler_t* byval [[LITERAL_ARG]])

    constant sampler_t dd = q;
    foo(dd);
// CHECK: [[DD:%[A-Za-z0-9_\.]+]] = load i32 addrspace(2)* @bar.dd
// CHECK: call spir_func void @foo(i32 [[DD]])
// CHECK-SAMPLER-TYPE: [[SMP:%[0-9]+]] = load %opencl.sampler_t addrspace(2)* @bar.dd
// CHECK-SAMPLER-TYPE: store %opencl.sampler_t [[SMP]], %opencl.sampler_t* [[TMP:%[A-Za-z0-9_\.]+]]
// CHECK-SAMPLER-TYPE: call spir_func void @foo(%opencl.sampler_t* byval [[TMP]])

    foo(1);
// CHECK: call spir_func void @foo(i32 1)
// CHECK-SAMPLER-TYPE: [[LIT_PTR:%[A-Za-z0-9_\.]+]] = getelementptr inbounds %opencl.sampler_t* [[LITERAL_ARG2]], i32 0, i32 0
// CHECK-SAMPLER-TYPE: store i32 1, i32* [[LIT_PTR]]
// CHECK-SAMPLER-TYPE: call spir_func void @foo(%opencl.sampler_t* byval [[LITERAL_ARG2]])

}
