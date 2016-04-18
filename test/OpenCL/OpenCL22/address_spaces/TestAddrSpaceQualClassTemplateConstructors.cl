// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

template<class T>
class data
{
public:
  data() __constant: _data(0) { }
  data(T rhs) __constant: _data(rhs) { }
  data() __private: _data(0) { }
  data(T rhs) __private: _data(rhs) { }
  data() __global: _data(0) { }
  data(T rhs) __global: _data(rhs) { }
  data() __generic:_data(0) { }
  data(T rhs) __generic:_data(rhs) { }
  data() __local: _data(0) { }
  data(T rhs) __local: _data(rhs) { }

  data(__constant const data& rhs) __constant: _data(rhs._data) { }
  data(const data& rhs) __constant: _data(rhs._data) { }
  data(const data& rhs) __private: _data(rhs._data) { }
  data(__constant const data& rhs) __global: _data(rhs._data) { }
  data(__private const data& rhs) __global: _data(rhs._data) { }
  data(__global const data& rhs) __global: _data(rhs._data) { }
  data(__generic const data& rhs) __global: _data(rhs._data) { }
  data(__local const data& rhs) __global: _data(rhs._data) { }
  data(const data& rhs) __generic:_data(rhs._data) { }
  data(const data& rhs) __local: _data(rhs._data) { }

  data(__constant data&& rhs) __constant = default;
  data(__private data&& rhs) __private = default;
  data(__global data&& rhs) __global = default;
  data(__generic data&& rhs) __generic = default;
  data(__local data&& rhs) __local = default;

  data(__local data&& rhs) __global = default;
  data(__constant data&& rhs) __global = default;
  data(__private data&& rhs) __global = default;
  data(__generic data&& rhs) __global = default;

  T _data;
};

template<class T>
class data_default
{
public:
  data_default() __constant = default;
  data_default(T rhs) __constant: _data(rhs) { }
  data_default() __private = default;
  data_default() __global = default;
  data_default() __generic = default;
  data_default() __local = default;

  data_default(__constant const data_default& rhs) __constant = default;
  data_default(const data_default& rhs) __constant = default;
  data_default(const data_default& rhs) __private = default;
  data_default(__constant const data_default& rhs) __global = default;
  data_default(__private const data_default& rhs) __global = default;
  data_default(__global const data_default& rhs) __global = default;
  data_default(__generic const data_default& rhs) __global = default;
  data_default(__local const data_default& rhs) __global = default;
  data_default(const data_default& rhs) __generic = default;
  data_default(const data_default& rhs) __local = default;

  data_default(__constant data_default&& rhs) __constant = default;
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
  data_generic():_data(0) { }
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

kernel void worker2() {
  __constant data_default<int> a0 = 1;
  __constant data_default<int> a01(1);
  __private data_default<int> a1;
  static __global data_default<int> a2;
  __local data_default<int> a3;
  data_default<int> a4;

  __constant data_default<int> b0 = a0;
  __private data_default<int> b1 = a1;
  static __global data_default<int> b2 = a2;
  static __global data_default<int> b20 = a0;
  static __global data_default<int> b21 = a1;
  static __global data_default<int> b23 = a3;
  static __global data_default<int> b24 = a4;
  //__local data_default<int> b3 = a3; //TODO: __local variable cannot have an initialzer
  data_default<int> b4 = a4;
}

__global data<int> g0;
__local data<int> g1;
__constant data<int> g2 = 1;
__constant data<int> g21(1);
data<int> g3;

__global data_default<int> g4;
__local data_default<int> g5;
data_default<int> g6;

kernel void worker3() {
  __private data_generic<int> a1;
  static __global data_generic<int> a2;
  __local data_generic<int> a3;
  data_generic<int> a4;

  __private data_generic<int> b1 = a1;
  static __global data_generic<int> b2 = a2;
  static __global data_generic<int> b21 = a1;
  static __global data_generic<int> b23 = a3;
  static __global data_generic<int> b24 = a4;
  //__local data_generic<int> b3 = a3; //TODO: __local variable cannot have an initialzer
  data_generic<int> b4 = a4;
}

__global data_generic_default<int> g7;
__local data_generic_default<int> g8;
data_generic_default<int> g9;

kernel void worker4() {
  __private data_generic_default<int> a1;
  static __global data_generic_default<int> a2;
  __local data_generic_default<int> a3;
  data_generic_default<int> a4;

  __private data_generic_default<int> b1 = a1;
  static __global data_generic_default<int> b2 = a2;
  static __global data_generic_default<int> b21 = a1;
  static __global data_generic_default<int> b23 = a3;
  static __global data_generic_default<int> b24 = a4;
  //__local data_generic_default<int> b3 = a3; //TODO: __local variable cannot have an initialzer
  data_generic_default<int> b4 = a4;
}

__global data_default_generated<int> g10;
__local data_default_generated<int> g11;
data_default_generated<int> g13;

kernel void worker5() {
  __private data_default_generated<int> a1;
  static __global data_default_generated<int> a2;
  __local data_default_generated<int> a3;
  data_default_generated<int> a4;

  __private data_default_generated<int> b1 = a1;
  static __global data_default_generated<int> b2 = a2;
  static __global data_default_generated<int> b21 = a1;
  static __global data_default_generated<int> b23 = a3;
  static __global data_default_generated<int> b24 = a4;
  //__local data_default_generated<int> b3 = a3; //TODO: __local variable cannot have an initialzer
  data_default_generated<int> b4 = a4;
}