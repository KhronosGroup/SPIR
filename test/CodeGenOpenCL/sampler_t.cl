// RUN: %clang_cc1 %s -triple spir-unknown-unknown -emit-llvm -o - -O0 | FileCheck %s

// CHECK: %opencl.sampler_t = type { i32 }

#define CLK_NORMALIZED_COORDS_TRUE 0x01
#define CLK_ADDRESS_REPEAT 0x02
#define CLK_FILTER_NEAREST 0x04

const sampler_t gs = 2;
// CHECK: @gs = constant %opencl.sampler_t { i32 2 }, align 4

constant sampler_t cgs = 3;
// CHECK: @cgs = addrspace(2) constant %opencl.sampler_t { i32 3 }, align 4

// CHECK: @bar.kst = internal constant %opencl.sampler_t { i32 5 }, align 4
// CHECK: @bar.cst = internal addrspace(2) constant %opencl.sampler_t { i32 6 }, align 4
// CHECK: @bar.lst = internal constant %opencl.sampler_t { i32 7 }, align 4
// CHECK: @bar.dd = internal addrspace(2) constant %opencl.sampler_t { i32 3 }, align 4


void foo(const sampler_t st){}
// CHECK: define spir_func void @foo(%opencl.sampler_t* byval %st)

kernel void bar(const sampler_t ast) {
// CHECK: define spir_kernel void @bar(%opencl.sampler_t* byval %ast)

// CHECK: {{.*}} = alloca %opencl.sampler_t, align 4
// CHECK: [[Q_SAMPLER:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4
// CHECK: [[LITERAL_ARG:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4
// CHECK: [[DD_SAMPLER:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4
// CHECK: [[LITERAL_ARG2:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t, align 4

    const sampler_t kst = 5;
    foo(kst);
// CHECK: call spir_func void @foo(%opencl.sampler_t* byval @bar.kst)

    constant sampler_t cst = 6;
    const sampler_t ost = cst;
// CHECK: [[SMP:%[0-9]+]] = load %opencl.sampler_t addrspace(2)* @bar.cst
// CHECK: store %opencl.sampler_t [[SMP]], %opencl.sampler_t* %ost

    const sampler_t lst = CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT|CLK_FILTER_NEAREST;
    foo(lst);
// CHECK: call spir_func void @foo(%opencl.sampler_t* byval @bar.lst)

    const int q = CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT;
    foo(q);
// CHECK: [[Q_PTR:%[A-Za-z0-9_\.]+]] = getelementptr inbounds %opencl.sampler_t* [[Q_SAMPLER]], i32 0, i32 0
// CHECK: store i32 3, i32* [[Q_PTR]]
// CHECK: call spir_func void @foo(%opencl.sampler_t* byval [[Q_SAMPLER]])

    foo(CLK_NORMALIZED_COORDS_TRUE|CLK_ADDRESS_REPEAT);
// CHECK: [[LIT_PTR:%[A-Za-z0-9_\.]+]] = getelementptr inbounds %opencl.sampler_t* [[LITERAL_ARG]], i32 0, i32 0
// CHECK: store i32 3, i32* [[LIT_PTR]]
// CHECK: call spir_func void @foo(%opencl.sampler_t* byval [[LITERAL_ARG]])

    constant sampler_t dd = q;
    foo(dd);
// CHECK: [[SMP:%[0-9]+]] = load %opencl.sampler_t addrspace(2)* @bar.dd
// CHECK: store %opencl.sampler_t [[SMP]], %opencl.sampler_t* [[TMP:%[A-Za-z0-9_\.]+]]
// CHECK: call spir_func void @foo(%opencl.sampler_t* byval [[TMP]])

    foo(1);
// CHECK: [[LIT_PTR:%[A-Za-z0-9_\.]+]] = getelementptr inbounds %opencl.sampler_t* [[LITERAL_ARG2]], i32 0, i32 0
// CHECK: store i32 1, i32* [[LIT_PTR]]
// CHECK: call spir_func void @foo(%opencl.sampler_t* byval [[LITERAL_ARG2]])

}
