// RUN: %clang_cc1 -triple spir64-unknown-unknown -emit-llvm %s -o - | FileCheck %s

__attribute__((noinline)) __kernel void callee(__global int* out)
{
    out[0] = 0;
}

__kernel void caller(__global int* out)
{
    // CHECK: call cc76 void @callee
    callee(out + 10);
}
