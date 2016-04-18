//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0
//expected-no-diagnostics

kernel void worker()
{
    [[cl::ivdep]]
    for (int i=0; i<10; ++i)
        continue;
        
    [[cl::ivdep(12)]]
    for (int i=0; i<10; ++i)
        continue;
}

