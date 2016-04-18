// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0  -o - | FileCheck %s

template <typename T>
struct local_ptr
{
    __local T* ptr;
};

typedef local_ptr<int> local_int;

// CHECK: i32 addrspace(3)* dereferenceable(12) %ptr.coerce
kernel void worker0(local_ptr<int> ptr [[cl::max_size(12)]])
{
}

// CHECK: i32 addrspace(3)* dereferenceable(18) %ptr.coerce
kernel void worker1(local_ptr<int> ptr [[cl::max_size(12), cl::max_size(18)]]) //expected-warning {{attribute 'max_size' is already applied with different parameters}}
{
}

// CHECK: i32 addrspace(3)* dereferenceable(25) %ptr.coerce
kernel void worker2(local_ptr<int> ptr [[cl::max_size(25), cl::max_size(18)]]) //expected-warning {{attribute 'max_size' is already applied with different parameters}}
{
}

// CHECK: i32 addrspace(3)* dereferenceable(2) %ptr.coerce
kernel void worker3(local_int ptr [[cl::max_size(2)]])
{
}

// CHECK: i32 addrspace(3)* dereferenceable(15) %ptr1.coerce, i32 addrspace(3)* dereferenceable(29) %ptr2.coerce
kernel void worker4(local_int ptr1 [[cl::max_size(15)]], local_int ptr2 [[cl::max_size(29)]])
{
}
