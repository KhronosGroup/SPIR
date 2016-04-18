// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

template<class T>
class data
{
public:
  constexpr data() __constant: _data(0) { }
  constexpr data(T rhs) __constant: _data(rhs) { }
  constexpr data() __private: _data(0) { }
  constexpr data(T rhs) __private: _data(rhs) { }
  constexpr data() __global: _data(0) { }
  constexpr data(T rhs) __global: _data(rhs) { }
  constexpr data() __generic:_data(0) { }
  constexpr data(T rhs) __generic:_data(rhs) { }
  constexpr data() __local: _data(0) { }
  constexpr data(T rhs) __local: _data(rhs) { }

  constexpr data(__constant const data& rhs) __constant: _data(rhs._data) { }
  constexpr data(const data& rhs) __constant: _data(rhs._data) { }
  constexpr data(const data& rhs) __private: _data(rhs._data) { }
  constexpr data(__constant const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__private const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__global const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__generic const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__local const data& rhs) __global: _data(rhs._data) { }
  constexpr data(const data& rhs) __generic:_data(rhs._data) { }
  constexpr data(const data& rhs) __local: _data(rhs._data) { }

  constexpr data(__constant data&& rhs) __constant = default;
  constexpr data(__private data&& rhs) __private = default;
  constexpr data(__global data&& rhs) __global = default;
  constexpr data(__generic data&& rhs) __generic = default;
  constexpr data(__local data&& rhs) __local = default;

  constexpr data(__local data&& rhs) __global = default;
  constexpr data(__constant data&& rhs) __global = default;
  constexpr data(__private data&& rhs) __global = default;
  constexpr data(__generic data&& rhs) __global = default;

  T _data;
};

template<class T>
class data_delete
{
public:
  constexpr data_delete() __constant = delete;
  constexpr data_delete() __private = delete;
  constexpr data_delete() __global = delete;
  constexpr data_delete() __generic = delete;
  constexpr data_delete() __local = delete;

  constexpr data_delete(__generic const data_delete& rhs) __global = delete;
  constexpr data_delete(__local const data_delete& rhs) __global = delete;
  constexpr data_delete(__constant const data_delete& rhs) __global = delete;
  constexpr data_delete(const data_delete& rhs) __constant = delete;
  constexpr data_delete(const data_delete& rhs) __private = delete;
  constexpr data_delete(const data_delete& rhs) __generic = delete;
  constexpr data_delete(const data_delete& rhs) __local = delete;

  constexpr data_delete(__global data_delete&& rhs) __global = delete;
  constexpr data_delete(__local data_delete&& rhs) __local = delete;
  constexpr data_delete(__private data_delete&& rhs) __private = delete;

  T _data;
};

__global data<int> g0;
__local data<int> g1;
__constant data<int> g2 = 1;
__constant data<int> g21(1);
data<int> g3;


kernel void worker1() {
  __constant data<int> a0 = 1;
  __constant data<int> a01(1);
  __private data<int> a1;
  __private data<int> a11 = 1;
  __private data<int> a12(1);
  static __global data<int> a2;
  static __global data<int> a21 = 1;
  static __global data<int> a22(1);
  __local data<int> a3;
  data<int> a4;
  data<int> a41 = 1;
  data<int> a42(1);

  __constant data<int> b0 = a0;
  __private data<int> b1 = a1;
  static __global data<int> b2 = a2;
  static __global data<int> b20 = a0;
  static __global data<int> b21 = a1;
  static __global data<int> b23 = a3;
  static __global data<int> b24 = a4;
  //__local data<int> b3 = a3; //TODO: __local variable cannot have an initialzer
  data<int> b4 = a4;
}