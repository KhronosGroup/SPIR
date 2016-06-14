// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

class data
{
public:
  constexpr data() __constant: _data(0) { }
  constexpr data(int rhs) __constant: _data(rhs) { }
  constexpr data() __private: _data(0) { }
  constexpr data(int rhs) __private: _data(rhs) { }
  constexpr data() __global: _data(0) { }
  constexpr data(int rhs) __global: _data(rhs) { }
  constexpr data() __generic:_data(0) { }
  constexpr data(int rhs) __generic:_data(rhs) { }
  constexpr data() __local: _data(0) { }
  constexpr data(int rhs) __local: _data(rhs) { }

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
  constexpr data(__constant const data& rhs) __local: _data(rhs._data) { }

  constexpr data(__constant data&& rhs) __constant = default;
  constexpr data(__private data&& rhs) __private = default;
  constexpr data(__global data&& rhs) __global = default;
  constexpr data(__generic data&& rhs) __generic = default;
  constexpr data(__local data&& rhs) __local = default;

  constexpr data(__local data&& rhs) __global = default;
  constexpr data(__constant data&& rhs) __global = default;
  constexpr data(__private data&& rhs) __global = default;
  constexpr data(__generic data&& rhs) __global = default;

  int _data;
};

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

  int _data;
};

__global data g0;
__constant data g1 = 1;
__constant data g1_1(1);
data g2;

kernel void worker1() {
  __constant data a0 = 1;
  __constant data a01(1);
  constexpr __constant data a02(1);
  __private data a1;
  __private data a11 = 1;
  __private data a12(1);
  constexpr __private data a13(1);
  static __global data a2;
  static __global data a21 = 1;
  static __global data a22(1);
  static constexpr __global data a23(1);
  __local data a3;
  __local data a31 = 1;
  static __local data a32(1);
  constexpr __local data a33(1);
  data a4;
  constexpr data a41;

  __private data b1 = a1;
  static __global data b2 = a23;
  static __global data b20 = a02;
  static __global data b21 = a13;
  static __global data b23 = a33;
  static __global data b24 = a41;
  static __local data b3 = a3;
  __local data b30 = a0;
  static __local data b31 = a1;
  __local data b32 = a2;
  static __local data b34 = a4;
  data b4 = a4;
}