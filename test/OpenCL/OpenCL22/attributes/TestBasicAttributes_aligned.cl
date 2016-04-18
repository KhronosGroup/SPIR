//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0
//expected-no-diagnostics

struct [[cl::aligned(8)]] my_struct
{
    my_struct(short s, char c) : a(s), b(c) {}
    
    short a;
    char b;
};

typedef int more_aligned_int [[cl::aligned(8)]];

more_aligned_int tab[2];

void foo(my_struct);
void bar(more_aligned_int);

kernel void worker()
{
    foo(my_struct{1,1});
    bar(tab[1]);
    
    static_assert(alignof(more_aligned_int) == 8, "");
}
