//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0
//expected-no-diagnostics

[[cl::work_group_size_hint(1, 2, 3)]] kernel void worker()
{
}
