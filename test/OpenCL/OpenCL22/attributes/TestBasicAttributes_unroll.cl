//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0
//expected-no-diagnostics

constexpr int pass(int arg) { return arg & 0x1 ? (arg>>1) + 1 : arg>>1;}

kernel void worker()
{
    [[cl::unroll_hint]]
    for (int i=0; i<10; ++i)
        continue;
    
    static const int x = 12;
    
    [[cl::unroll_hint(pass(x))]]
    for (int i=0; i<10; ++i)
        continue;
}
