// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp64-enable -emit-llvm -o -
// expected-no-diagnostics

#ifndef cl_khr_fp64
static_assert(false, "cl_khr_fp64 macro shuld be defined when -cl-fp64-enable flag is set");
#endif

