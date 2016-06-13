// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

template<class T>
class data
{
public:
  data() __constant: _data(0) { }
  constexpr data(T rhs) __constant: _data(rhs) { }
  data() __private: _data(0) { }
  data(T rhs) __private: _data(rhs) { }
  constexpr data(T rhs, int) __private: _data(rhs) { }
  constexpr data() __global: _data(0) { }
  constexpr data(T rhs) __global: _data(rhs) { }
  constexpr data(T rhs, int) __global: _data(rhs) { }
  data() __generic:_data(0) { }
  data(T rhs) __generic: _data(rhs) { }
  constexpr data(T rhs, int) __generic: _data(rhs) { }
  data() __local: _data(0) { }
  data(T rhs) __local: _data(rhs) { }
  constexpr data(T rhs, int) __local: _data(rhs) { }

  constexpr data(__constant const data& rhs) __constant: _data(rhs._data) { }
  constexpr data(const data& rhs) __constant: _data(rhs._data) { }
  data(const data& rhs) __private: _data(rhs._data) { }
  constexpr data(__constant const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__private const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__global const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__generic const data& rhs) __global: _data(rhs._data) { }
  constexpr data(__local const data& rhs) __global: _data(rhs._data) { }
  constexpr data(const data& rhs) __global: _data(rhs._data) { }
  data(const data& rhs) __generic:_data(rhs._data) { }
  data(const data& rhs) __local: _data(rhs._data) { }
  data(__constant const data& rhs) __local: _data(rhs._data) { }

  constexpr data(__constant data&& rhs) __constant = default;
  data(__private data&& rhs) __private = default;
  data(__global data&& rhs) __global = default;
  data(__generic data&& rhs) __generic = default;
  data(__local data&& rhs) __local = default;

  data(__local data&& rhs) __global = default;
  constexpr data(__constant data&& rhs) __global = default;
  data(__private data&& rhs) __global = default;
  data(__generic data&& rhs) __global = default;

  T _data;
};

template<class T>
class data_default
{
public:
  data_default() __constant = default;
  constexpr data_default(T rhs) __constant: _data(rhs) { }
  data_default() __private = default;
  data_default() __global = default;
  data_default() __generic = default;
  data_default() __local = default;

  constexpr data_default(__constant const data_default& rhs) __constant = default;
  data_default(const data_default& rhs) __constant = default;
  data_default(const data_default& rhs) __private = default;
  constexpr data_default(__constant const data_default& rhs) __global = default;
  constexpr data_default(__private const data_default& rhs) __global = default;
  constexpr data_default(__global const data_default& rhs) __global = default;
  constexpr data_default(__generic const data_default& rhs) __global = default;
  constexpr data_default(__local const data_default& rhs) __global = default;
  constexpr data_default(const data_default& rhs) __global = default;
  data_default(const data_default& rhs) __generic = default;
  data_default(const data_default& rhs) __local = default;
  data_default(__constant const data_default& rhs) __local = default;

  constexpr data_default(__constant data_default&& rhs) __constant = default;
  data_default(__private data_default&& rhs) __private = default;
  data_default(__global data_default&& rhs) __global = default;
  data_default(__generic data_default&& rhs) __generic = default;
  data_default(__local data_default&& rhs) __local = default;

  T _data;
};

template<class T>
class data_generic
{
public:
  data_generic(): _data(0) { }
  explicit constexpr data_generic(int): _data(0) { }
  data_generic(const data_generic& rhs): _data(rhs._data) { }
  data_generic(data_generic&& rhs) { }

  T _data;
};

template<class T>
class data_generic_default
{
public:
  data_generic_default() = default;
  data_generic_default(const data_generic_default& rhs) = default;
  data_generic_default(data_generic_default&& rhs) = default;

  T _data;
};

template<class T>
class data_default_generated
{
public:
  T _data;
};

template<class T>
class data_delete
{
public:
  data_delete() __constant = delete;
  data_delete() __private = delete;
  data_delete() __global = delete;
  data_delete() __generic = delete;
  data_delete() __local = delete;

  data_delete(__generic const data_delete& rhs) __global = delete;
  data_delete(__local const data_delete& rhs) __global = delete;
  data_delete(__constant const data_delete& rhs) __global = delete;
  data_delete(const data_delete& rhs) __constant = delete;
  data_delete(const data_delete& rhs) __private = delete;
  data_delete(const data_delete& rhs) __generic = delete;
  data_delete(const data_delete& rhs) __local = delete;

  data_delete(__global data_delete&& rhs) __global = delete;
  data_delete(__local data_delete&& rhs) __local = delete;
  data_delete(__private data_delete&& rhs) __private = delete;

  T _data;
};

kernel void worker1() {
  __constant data<int> a0 = 1;
  __constant data<int> a01(1);
  constexpr __constant data<int> a02(1);
  __private data<int> a1;
  __private data<int> a11 = 1;
  __private data<int> a12(1);
  constexpr __private data<int> a13(1, 0);
  static __global data<int> a2;
  static __global data<int> a21 = 1;
  static __global data<int> a22(1);
  static constexpr __global data<int> a23(1, 0);
  __local data<int> a3;
  __local data<int> a31 = 1;
  __local data<int> a32(1);
  constexpr __local data<int> a33(1, 0);
  data<int> a4;
  data<int> a41 = 1;
  data<int> a42(1);
  constexpr data<int> a43(1, 0);

  __private data<int> b1 = a1;
  static __global data<int> b2 = a23;
  static __global data<int> b20 = a02;
  static __global data<int> b21 = a13;
  static __global data<int> b23 = a33;
  static __global data<int> b24 = a43;
  __local data<int> b3 = a3;
  __local data<int> b30 = a0;
  __local data<int> b31 = a1;
  __local data<int> b32 = a2;
  __local data<int> b34 = a4;
  data<int> b4 = a4;
}

kernel void worker2() {
  __constant data_default<int> a0 = 1;
  __constant data_default<int> a01(1);
  __private data_default<int> a1;
  static __global data_default<int> a2;
  __local data_default<int> a3;
  data_default<int> a4;

  __private data_default<int> b1 = a1;
  static __local data_default<int> b3 = a3;
  static __local data_default<int> b30 = a0;
  static __local data_default<int> b31 = a1;
  static __local data_default<int> b32 = a2;
  static __local data_default<int> b34 = a4;
  data_default<int> b4 = a4;
}

__global data<int> g0;
__constant data<int> g1 = 1;
__constant data<int> g1_1(1);
data<int> g2;

__global data_default<int> g3;
__local data_default<int> g4;
data_default<int> g5;

kernel void worker3() {
  __private data_generic<int> a1;
  static __global data_generic<int> a2(0);
  __local data_generic<int> a3;
  data_generic<int> a4;

  __private data_generic<int> b1 = a1;
  __local data_generic<int> b3 = a3;
  __local data_generic<int> b31 = a1;
  __local data_generic<int> b32 = a2;
  __local data_generic<int> b34 = a4;
  data_generic<int> b4 = a4;
}

__global data_generic_default<int> g6;
__local data_generic_default<int> g7;
data_generic_default<int> g8;
__global data_generic_default<int> gb6_1 = g6;
__global data_generic_default<int> gb6_2 = g7;
__global data_generic_default<int> gb6_3 = g8;
data_generic_default<int> gb8_1 = g6;
data_generic_default<int> gb8_2 = g7;
data_generic_default<int> gb8_3 = g8;

kernel void worker4() {
  __private data_generic_default<int> a1;
  static __global data_generic_default<int> a2;
  __local data_generic_default<int> a3;
  data_generic_default<int> a4;

  __private data_generic_default<int> b1 = a1;
  __local data_generic_default<int> b3 = a3;
  __local data_generic_default<int> b31 = a1;
  __local data_generic_default<int> b32 = a2;
  __local data_generic_default<int> b34 = a4;
  data_generic_default<int> b4 = a4;
}

__global data_default_generated<int> g9;
__local data_default_generated<int> g10;
data_default_generated<int> g11;

kernel void worker5() {
  __private data_default_generated<int> a1;
  static __global data_default_generated<int> a2;
  __local data_default_generated<int> a3;
  data_default_generated<int> a4;

  __private data_default_generated<int> b1 = a1;
  __local data_default_generated<int> b3 = a3;
  __local data_default_generated<int> b31 = a1;
  __local data_default_generated<int> b32 = a2;
  __local data_default_generated<int> b34 = a4;
  data_default_generated<int> b4 = a4;
}