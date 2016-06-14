// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O2 -emit-llvm -o - 
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O1 -emit-llvm

#define GLOBAL_MEM __global

#include "../opencl_def"

struct A {
    A() = default;
    ~A() = default;
};

struct B {
    B() { }             // expected-note{{declared here}}
    ~B() = default;     
};

struct C {
    C() = default;
    ~C() { }
};

struct D {
    D() { }             // expected-note{{declared here}}
    ~D() { }
};

int nce_int() { return 1; } // expected-note{{declared here}}
constexpr int ce_int() { return 2; }

kernel void worker() {
    static GLOBAL_MEM A a;
    static GLOBAL_MEM B b; // expected-error{{local-scope variable with global storage (global address space) must be initialized with trivial default or constant expression constructor}} expected-note{{non-constexpr constructor 'B' cannot be used in a constant expression}}
    static GLOBAL_MEM C c; // expected-error{{local-scope variable with global storage (global address space) must have trivial destructor}}
    static GLOBAL_MEM D d; // expected-error{{local-scope variable with global storage (global address space) must be initialized with trivial default or constant expression constructor}} expected-error{{local-scope variable with global storage (global address space) must have trivial destructor}} expected-note{{non-constexpr constructor 'D' cannot be used in a constant expression}}
    static GLOBAL_MEM int i = nce_int(); // expected-error{{local-scope variable with global storage (global address space) requires trivial or constant expression initialization}} expected-note{{non-constexpr function 'nce_int' cannot be used in a constant expression}}
    static GLOBAL_MEM int ii = ce_int(); 
}