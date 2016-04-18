//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0
//expected-no-diagnostics

[[cl::required_num_sub_groups(12)]] kernel void worker()
{
}
