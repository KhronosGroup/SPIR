// RUN: %clang_cc1 %s -triple spir-unknown-unknown -emit-llvm -o - -O0 | FileCheck %s

// CHECK: %opencl.sampler_t = type { i32 }

#define CLK_NORMALIZED_COORDS_TRUE 0x01
#define CLK_ADDRESS_REPEAT 0x02
#define CLK_FILTER_NEAREST 0x04

const sampler_t gs = 2;
// CHECK: @gs = constant %opencl.sampler_t { i32 2 }, align 4

constant sampler_t cgs = 3;
// CHECK: @cgs = addrspace(2) global %opencl.sampler_t { i32 3 }, align 4

// CHECK: @bar.kst = internal constant %opencl.sampler_t { i32 5 }, align 4
// CHECK: @bar.cst = internal addrspace(2) global %opencl.sampler_t { i32 6 }, align 4
// CHECK: @bar.lst = internal constant %opencl.sampler_t { i32 7 }, align 4
// CHECK: @bar.dd = internal addrspace(2) global %opencl.sampler_t { i32 3 }, align 4


void foo(const sampler_t st){}
// CHECK: define cc75 void @foo(%opencl.sampler_t* byval %st)

kernel void bar(const sampler_t ast) {
// CHECK: define cc76 void @bar(%opencl.sampler_t* byval %ast)

// CHECK: %ost = alloca %opencl.sampler_t, align 4
// CHECK: [[Q_SAMPLER:%.*]] = alloca %opencl.sampler_t, align 4
// CHECK: [[LITERAL_ARG:%.*]] = alloca %opencl.sampler_t, align 4
// CHECK: [[DD_SAMPLER:%.*]] = alloca %opencl.sampler_t, align 4
// CHECK: [[LITERAL_ARG2:%.*]] = alloca %opencl.sampler_t, align 4

    const sampler_t kst = 5;
    foo(kst);
// CHECK: call cc75 void @foo(%opencl.sampler_t* byval @bar.kst)

    constant sampler_t cst = 6;
    const sampler_t ost = cst;
// CHECK: [[OST:%.*]] = bitcast %opencl.sampler_t* %ost to i8*
// CHECK: call void @llvm.memcpy.p0i8.p2i8.i32(i8* [[OST]], i8 addrspace(2)* bitcast (%opencl.sampler_t addrspace(2)* @bar.cst to i8 addrspace(2)*), i32 4, i32 4, i1 false)

    const sampler_t lst = CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT|CLK_FILTER_NEAREST;
    foo(lst);
// CHECK: call cc75 void @foo(%opencl.sampler_t* byval @bar.lst)

    const int q = CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT;
    foo(q);
// CHECK: [[Q_PTR:%.*]] = getelementptr inbounds %opencl.sampler_t* [[Q_SAMPLER]], i32 0, i32 0
// CHECK:  store i32 3, i32* [[Q_PTR]]
// CHECK:  call cc75 void @foo(%opencl.sampler_t* byval [[Q_SAMPLER]])

    foo(CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT);
// CHECK: [[LIT_PTR:%.*]] = getelementptr inbounds %opencl.sampler_t* [[LITERAL_ARG]], i32 0, i32 0
// CHECK:  store i32 3, i32* [[LIT_PTR]]
// CHECK:  call cc75 void @foo(%opencl.sampler_t* byval [[LITERAL_ARG]])

    constant sampler_t dd = q;
    foo(dd);
// CHECK:  [[DD_PTR:%.*]] = bitcast %opencl.sampler_t* [[DD_SAMPLER]] to i8*
// CHECK:  call void @llvm.memcpy.p0i8.p2i8.i32(i8* [[DD_PTR]], i8 addrspace(2)* bitcast (%opencl.sampler_t addrspace(2)* @bar.dd to i8 addrspace(2)*), i32 4, i32 4, i1 false)
// CHECK:  call cc75 void @foo(%opencl.sampler_t* byval [[DD_SAMPLER]])

    foo(1);
// CHECK:  [[LIT_PTR:%.*]] = getelementptr inbounds %opencl.sampler_t* [[LITERAL_ARG2]], i32 0, i32 0
// CHECK:  store i32 1, i32* [[LIT_PTR]]
// CHECK:  call cc75 void @foo(%opencl.sampler_t* byval [[LITERAL_ARG2]])

}