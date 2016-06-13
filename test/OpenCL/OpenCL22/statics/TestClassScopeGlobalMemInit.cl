// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - 
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O2 -emit-llvm -o - 
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O1 -emit-llvm -o - 


#define GLOBAL_MEM __global

#include "../opencl_def"

class A {
public:
    static GLOBAL_MEM int a;
    static GLOBAL_MEM int b;
    static GLOBAL_MEM int c;
    static GLOBAL_MEM int d; 
    static GLOBAL_MEM int e;
    static GLOBAL_MEM int f[];
    static GLOBAL_MEM int g[];
};

int nce_int() { return 1; } // expected-note{{declared here}}
constexpr int ce_int() { return 2; } 

template<typename T>
T nce_t_var = T(3); //expected-note{{declared here}}

template<typename T>
constexpr T ce_t_var = T(4);

GLOBAL_MEM int A::a = 10;
GLOBAL_MEM int A::b = ce_int();
GLOBAL_MEM int A::c = ce_t_var<int>;
GLOBAL_MEM int A::d = nce_int(); // expected-error{{static data member with global storage (global address space) requires trivial or constant expression initialization}} expected-note{{non-constexpr function 'nce_int' cannot be used in a constant expression}}
GLOBAL_MEM int A::e = nce_t_var<int>; // expected-error{{static data member with global storage (global address space) requires trivial or constant expression initialization}} expected-note{{read of non-const variable 'nce_t_var<int>' is not allowed in a constant expression}}

GLOBAL_MEM int A::f[4] = { 1,2,3,4 };

class B {
public:
    static GLOBAL_MEM int a;
    static GLOBAL_MEM int b;
};

typedef B td_B;

GLOBAL_MEM int td_B::a = 10;

struct C_NT {
    C_NT() { } //expected-note{{declared here}}
};

struct D_NT {
    ~D_NT() { }
};

struct C {
    static GLOBAL_MEM B b;
    static GLOBAL_MEM C_NT c_nt;
    static GLOBAL_MEM D_NT d_nt;
};

GLOBAL_MEM B C::b = B();
GLOBAL_MEM C_NT C::c_nt = C_NT(); // expected-error{{static data member with global storage (global address space) must be initialized with trivial default or constant expression constructor}} expected-note{{non-constexpr constructor 'C_NT' cannot be used in a constant expression}}
GLOBAL_MEM D_NT C::d_nt = D_NT(); // expected-error{{static data member with global storage (global address space) must be initialized with trivial default or constant expression constructor}} expected-error{{static data member with global storage (global address space) must have trivial destructor}}