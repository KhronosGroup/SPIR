// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

class data
{
public:
  data() __constant: _data(0) { }
  data(int rhs) __constant: _data(rhs) { }
  data() __private: _data(0) { }
  data(int rhs) __private: _data(rhs) { }
  data() __global: _data(0) { }
  data(int rhs) __global: _data(rhs) { }
  data() __generic:_data(0) { }
  data(int rhs) __generic:_data(rhs) { }
  data() __local: _data(0) { }
  data(int rhs) __local: _data(rhs) { }

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

  int _data;
};

class data_default
{
public:
  data_default() __constant = default;
  data_default(int rhs) __constant: _data(rhs) { }
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

  int _data;
};

class data_generic
{
public:
  data_generic():_data(0) { }
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
  __constant data a0 = 1;
  __constant data a01(1);
  __private data a1;
  __private data a11 = 1;
  __private data a12(1);
  static __global data a2;
  static __global data a21 = 1;
  static __global data a22(1);
  __local data a3;
  data a4;

  __constant data b0 = a0;
  __private data b1 = a1;
  static __global data b2 = a2;
  static __global data b20 = a0;
  static __global data b21 = a1;
  static __global data b23 = a3;
  static __global data b24 = a4;
  //__local data b3 = a3; //TODO: __local variable cannot have an initialzer
  data b4 = a4;
}

kernel void worker2() {
  __constant data_default a0 = 1;
  __constant data_default a01(1);
  __private data_default a1;
  static __global data_default a2;
  __local data_default a3;
  data_default a4;

  __constant data_default b0 = a0;
  __private data_default b1 = a1;
  static __global data_default b2 = a2;
  static __global data_default b20 = a0;
  static __global data_default b21 = a1;
  static __global data_default b23 = a3;
  static __global data_default b24 = a4;
  //__local data_default b3 = a3; //TODO: __local variable cannot have an initialzer
  data_default b4 = a4;
}

__global data g0;
__local data g1;
__constant data g2 = 1;
__constant data g21(1);
data g3;

__global data_default g4;
__local data_default g5;
data_default g6;

kernel void worker3() {
  __private data_generic a1;
  static __global data_generic a2;
  __local data_generic a3;
  data_generic a4;

  __private data_generic b1 = a1;
  static __global data_generic b2 = a2;
  static __global data_generic b21 = a1;
  static __global data_generic b23 = a3;
  static __global data_generic b24 = a4;
  //__local data_generic b3 = a3; //TODO: __local variable cannot have an initialzer
  data_generic b4 = a4;
}

__global data_generic_default g7;
__local data_generic_default g8;
data_generic_default g9;

kernel void worker4() {
  __private data_generic_default a1;
  static __global data_generic_default a2;
  __local data_generic_default a3;
  data_generic_default a4;

  __private data_generic_default b1 = a1;
  static __global data_generic_default b2 = a2;
  static __global data_generic_default b21 = a1;
  static __global data_generic_default b23 = a3;
  static __global data_generic_default b24 = a4;
  //__local data_generic_default b3 = a3; //TODO: __local variable cannot have an initialzer
  data_generic_default b4 = a4;
}

__global data_default_generated g10;
__local data_default_generated g11;
data_default_generated g13;

kernel void worker5() {
  __private data_default_generated a1;
  static __global data_default_generated a2;
  __local data_default_generated a3;
  data_default_generated a4;

  __private data_default_generated b1 = a1;
  static __global data_default_generated b2 = a2;
  static __global data_default_generated b21 = a1;
  static __global data_default_generated b23 = a3;
  static __global data_default_generated b24 = a4;
  //__local data_default_generated b3 = a3; //TODO: __local variable cannot have an initialzer
  data_default_generated b4 = a4;
}

template<class T>
class global
{
  public:
    global(T rhs): _data(rhs) { }
    T& front() { return _data; }
    const T& front() const { return _data; }

    T _data;
}; 

kernel void worker6() {
  const static __global global<int> var1 = 1;
  const int& var4 = var1.front();
}