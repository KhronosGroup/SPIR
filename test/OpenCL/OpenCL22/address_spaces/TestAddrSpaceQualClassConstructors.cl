// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

class data
{
public:
  constexpr data() __constant: _data(0) { }
  constexpr data(int rhs) __constant: _data(rhs) { }
  data() __private: _data(0) { }
  data(int rhs) __private: _data(rhs) { }
  constexpr data(int rhs, int) __private: _data(rhs) { }
  constexpr data() __global: _data(0) { }
  constexpr data(int rhs) __global: _data(rhs) { }
  constexpr data(int rhs, int) __global: _data(rhs) { }
  data() __generic:_data(0) { }
  data(int rhs) __generic: _data(rhs) { }
  constexpr data(int rhs, int) __generic: _data(rhs) { }
  data() __local: _data(0) { }
  data(int rhs) __local: _data(rhs) { }
  constexpr data(int rhs, int) __local: _data(rhs) { }

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
  data(__constant data&& rhs) __global = default;
  data(__private data&& rhs) __global = default;
  data(__generic data&& rhs) __global = default;

  int _data;
};

class data_default
{
public:
  constexpr data_default(int rhs) __constant: _data(rhs) { }
  data_default() __private = default;
  data_default() __global = default;
  data_default() __generic = default;
  data_default() __local = default;

  constexpr data_default(__constant const data_default& rhs) __constant = default;
  constexpr data_default(const data_default& rhs) __constant = default;
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

  int _data;
};

class data_generic
{
public:
  data_generic(): _data(0) { }
  explicit constexpr data_generic(int): _data(0) { }
  data_generic(const data_generic& rhs): _data(rhs._data) { }
  data_generic(data_generic&& rhs) { }

  int _data;
};

class data_generic_default
{
public:
  data_generic_default() = default;
  data_generic_default(const data_generic_default& rhs) = default;
  data_generic_default(data_generic_default&& rhs) = default;

  int _data;
};

class data_default_generated
{
public:
  int _data;
};

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

  int _data;
};

kernel void worker1() {
  __constant data a0 = { 1 };
  __constant data a01(1);
  constexpr __constant data a02(1);
  __private data a1;
  __private data a11 = 1;
  __private data a12(1);
  constexpr __private data a13(1, 0);
  static __global data a2;
  static __global data a21 = 1;
  static __global data a22(1);
  static constexpr __global data a23(1, 0);
  __local data a3;
  __local data a31 = 1;
  __local data a32(1);
  constexpr __local data a33(1, 0);
  data a4;
  constexpr data a41(1, 0);

  __private data b1 = a1;
  static __global data b2 = a23;
  static __global data b20 = a02;
  static __global data b21 = a13;
  static __global data b23 = a33;
  static __global data b24(a41);
  __local data b3 = a3;
  __local data b30 = a0;
  __local data b31 = a1;
  __local data b32 = a2;
  __local data b34 = a4;
  data b4 = a4;
}

kernel void worker2() {
  __constant data_default a0 = 1;
  __constant data_default a01(1);
  __private data_default a1;
  static __global data_default a2;
  __local data_default a3;
  data_default a4;

  __private data_default b1 = a1;
  static __local data_default b3 = a3;
  static __local data_default b30 = a0;
  static __local data_default b31 = a1;
  static __local data_default b32 = a2;
  static __local data_default b34 = a4;
  data_default b4 = a4;
}

__global data g0;
__constant data g1 = 1;
__constant data g1_1(1);
data g2;

__global data_default g3;
__local data_default g4;
data_default g5;

kernel void worker3() {
  __private data_generic a1;
  static __global data_generic a2(0);
  __local data_generic a3;
  data_generic a4;

  __private data_generic b1 = a1;
  __local data_generic b3 = a3;
  __local data_generic b31 = a1;
  __local data_generic b32 = a2;
  __local data_generic b34 = a4;
  data_generic b4 = a4;
}

__global data_generic_default g6;
__local data_generic_default g7;
data_generic_default g8;
__global data_generic_default gb6_1 = g6;
__global data_generic_default gb6_2 = g7;
__global data_generic_default gb6_3 = g8;
data_generic_default gb8_1 = g6;
data_generic_default gb8_2 = g7;
data_generic_default gb8_3 = g8;

kernel void worker4() {
  __private data_generic_default a1;
  static __global data_generic_default a2;
  __local data_generic_default a3;
  data_generic_default a4;

  __private data_generic_default b1 = a1;
  __local data_generic_default b3 = a3;
  __local data_generic_default b31 = a1;
  __local data_generic_default b32 = a2;
  __local data_generic_default b34 = a4;
  data_generic_default b4 = a4;
}

__global data_default_generated g9;
__local data_default_generated g10;
data_default_generated g11;

kernel void worker5() {
  __private data_default_generated a1;
  static __global data_default_generated a2;
  __local data_default_generated a3;
  data_default_generated a4;

  __private data_default_generated b1 = a1;
  __local data_default_generated b3 = a3;
  __local data_default_generated b31 = a1;
  __local data_default_generated b32 = a2;
  __local data_default_generated b34 = a4;
  data_default_generated b4 = a4;
}

template<class T>
class global
{
  public:
    constexpr global(T rhs): _data(rhs) { }
    T& front() { return _data; }
    const T& front() const { return _data; }

    T _data;
}; 

kernel void worker6() {
  const static __global global<int> var1 = 1;
  const int& var4 = var1.front();
}