//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0
//expected-no-diagnostics

[[cl::required_work_group_size(1, 2, 3)]] kernel void worker()
{
}
