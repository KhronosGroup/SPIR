// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o -

struct A
{
    int a;
};

struct B : virtual A //expected-error {{OpenCL C++ prohibits use of virtual inheritance}}
{
    int b;
};

struct C : virtual A //expected-error {{OpenCL C++ prohibits use of virtual inheritance}}
{
    int c;
};

struct D : B, C
{
    int d;
};

kernel void worker()
{
    D d;
    
    d.a = 1; //expected-error {{no member named 'a' in 'D'}}
    d.b = 2;
    d.c = 3;
    d.d = 4;
}
