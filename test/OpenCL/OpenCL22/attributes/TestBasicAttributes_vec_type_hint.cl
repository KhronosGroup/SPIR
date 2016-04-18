//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0
//expected-no-diagnostics

#include "../opencl_def"

int4 foo();

template <typename T>
struct trait {
    typedef T dependant;
};

template <typename T>
struct trait<trait<T>> {
    typedef typename trait<T>::dependant dependant;
};

[[cl::vec_type_hint(float)]] kernel void worker0() { }
[[cl::vec_type_hint(const float16)]] kernel void worker1() { }
[[cl::vec_type_hint(decltype(foo()))]] kernel void worker2() { }
[[cl::vec_type_hint(typename trait<double>::dependant)]] kernel void worker3() { }
[[cl::vec_type_hint(typename trait<trait<int16>>::dependant)]] kernel void worker4() { }
