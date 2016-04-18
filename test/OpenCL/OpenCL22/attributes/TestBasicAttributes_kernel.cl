// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0  -o - | FileCheck %s
//expected-no-diagnostics

kernel void myfunc(int a) { }
// CHECK: define spir_kernel void @myfunc(i32 %a) #0 {

struct C { };

void f3(C a) { }
// CHECK: define spir_func void @_Z2f31C(%struct.C* byval %a) #0 {
C f33() { return C(); }
// CHECK: define spir_func void @_Z3f33v(%struct.C addrspace(4)* noalias sret %agg.result) #0 {

struct A
{
 __global int *a;
};

kernel void f1(A a, A b) { }
// CHECK: define spir_kernel void @f1(i32 addrspace(1)* %a.coerce, i32 addrspace(1)* %b.coerce) #0 {

A f11() { return A(); }
// CHECK: define spir_func i32 addrspace(1)* @_Z3f11v() #0 {

struct B
{
 int *a;
 int *b;
};

void f2(B a) { }
// CHECK: define spir_func void @_Z2f21B(%struct.B* byval %a) #0 {

B f22() { return B(); }
// CHECK: define spir_func void @_Z3f22v(%struct.B addrspace(4)* noalias sret %agg.result) #0 {

class C2 { };

void f4(C2 a) { }
// CHECK: define spir_func void @_Z2f42C2(%class.C2* byval %a) #0 {
C2 f44() { return C2(); }
// CHECK: define spir_func void @_Z3f44v(%class.C2 addrspace(4)* noalias sret %agg.result) #0 {

class A2
{
 __global int *a;
};

kernel void f5(A2 a, A2 b) { }
// CHECK: define spir_kernel void @f5(i32 addrspace(1)* %a.coerce, i32 addrspace(1)* %b.coerce) #0 {

A2 f55() { return A2(); }
// CHECK: define spir_func i32 addrspace(1)* @_Z3f55v() #0 {

struct B2
{
 int *a;
 int *b;
};

void f6(B2 a) { }
// CHECK: define spir_func void @_Z2f62B2(%struct.B2* byval %a) #0 {

B2 f66() { return B2(); }
// CHECK: define spir_func void @_Z3f66v(%struct.B2 addrspace(4)* noalias sret %agg.result) #0 {

template<class T>
struct D
{
  T a;
};

kernel void mykernel(D<int> a) { }
// CHECK: define spir_kernel void @mykernel(i32 %a.coerce) #0 {

class E1
{
 __global int *a;
};

class E2: public E1
{
};

void f7(E2 a) { }
// CHECK: define spir_func void @_Z2f72E2(i32 addrspace(1)* %a.coerce) #0 {