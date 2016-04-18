// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -
// XFAIL: *

#ifndef cl_khr_fp16
static_assert(false, "cl_khr_fp16 macro shuld be defined when -cl-fp16-enable flag is set");
#endif

