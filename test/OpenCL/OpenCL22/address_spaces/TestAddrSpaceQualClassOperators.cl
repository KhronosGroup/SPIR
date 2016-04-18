// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

class data_explicit
{
public:
  data_explicit() = default;
  
  data_explicit(const data_explicit& rhs) = default;
  data_explicit(data_explicit&& rhs) = default;

  __private data_explicit &operator=(const data_explicit &r) __private { _data = r._data; return *this; };
  __private data_explicit &operator=(data_explicit &&r) __private { _data = r._data; return *this; };
  
  __global data_explicit &operator=(const data_explicit &r) __global { _data = r._data; return *this; };
  __global data_explicit &operator=(data_explicit &&r) __global { _data = r._data; return *this; };
  
  __local data_explicit &operator=(const data_explicit &r) __local { _data = r._data; return *this; };
  __local data_explicit &operator=(data_explicit &&r) __local { _data = r._data; return *this; };
  
  int _data;
};

kernel void test1() {
  __local data_explicit obj1;
  __local data_explicit obj2;
  obj1 = obj2;
  obj1 = data_explicit();
}

kernel void test2() {
  __private data_explicit obj1;
  __private data_explicit obj2;
  obj1 = obj2;
  obj1 = data_explicit();
  
  data_explicit obj3 = data_explicit();
}

kernel void test3() {
  static __global data_explicit obj1;
  static __global data_explicit obj2;
  obj1 = obj2;
  obj1 = data_explicit();
  
  static __global data_explicit obj3 = data_explicit();
}

class data_explicit_default
{
public:
  data_explicit_default() = default;
  data_explicit_default(const data_explicit_default& rhs) = default;
  data_explicit_default(data_explicit_default&& rhs) = default;

  __private data_explicit_default &operator=(const data_explicit_default &r) __private = default;
  __private data_explicit_default &operator=(data_explicit_default &&r) __private = default;
  
  __global data_explicit_default &operator=(__global const data_explicit_default &r) __global = default;
  __global data_explicit_default &operator=(const data_explicit_default &r) __global = default;
  __global data_explicit_default &operator=(__global data_explicit_default &&r) __global = default;
  //TODO: negative case __global data_explicit_default &operator=(data_explicit_default &&r) __global = default;
  
  __local data_explicit_default &operator=(__local const data_explicit_default &r) __local = default;
  __local data_explicit_default &operator=(const data_explicit_default &r) __local = default;
  __local data_explicit_default &operator=(__local data_explicit_default &&r) __local = default;
  //TODO: negative case __local data_explicit_default &operator=(data_explicit_default &&r) __local = default;

  int _data;
};

kernel void test4() {
  __local data_explicit_default obj1;
  __local data_explicit_default obj2;
  obj1 = obj2;
  obj1 = data_explicit_default();
}

kernel void test5() {
  __private data_explicit_default obj1;
  __private data_explicit_default obj2;
  obj1 = obj2;
  obj1 = data_explicit_default();
  
  data_explicit_default obj3 = data_explicit_default();
}

kernel void test6() {
  static __global data_explicit_default obj1;
  static __global data_explicit_default obj2;
  obj1 = obj2;
  obj1 = data_explicit_default();
  
  static __global data_explicit_default obj3 = data_explicit_default();
}

class data_generic
{
public:
  data_generic() = default;
  data_generic(const data_generic& rhs) = default;
  data_generic(data_generic&& rhs) = default;

  data_generic &operator=(const data_generic &r) { _data = r._data; return *this; };
  data_generic &operator=(data_generic &&r) { _data = r._data; return *this; };

  int _data;
};

kernel void test7() {
  __local data_generic obj1;
  __local data_generic obj2;
  obj1 = obj2;
  obj1 = data_generic();
}

kernel void test8() {
  data_generic obj1;
  data_generic obj2;
  obj1 = obj2;
  obj1 = data_generic();
  
  data_generic obj3 = data_generic();
}

kernel void test9() {
  static __global data_generic obj1;
  static __global data_generic obj2;
  obj1 = obj2;
  obj1 = data_generic();
  
  static __global data_generic obj3 = data_generic();
}

class data_generic_default
{
public:
  data_generic_default() = default;
  data_generic_default(const data_generic_default& rhs) = default;
  data_generic_default(data_generic_default&& rhs) = default;

  data_generic_default &operator=(const data_generic_default &r) = default;
  data_generic_default &operator=(data_generic_default &&r) = default;

  int _data;
};

kernel void test10() {
  __local data_generic_default obj1;
  __local data_generic_default obj2;
  obj1 = obj2;
  obj1 = data_generic_default();
}

kernel void test11() {
  data_generic_default obj1;
  data_generic_default obj2;
  obj1 = obj2;
  obj1 = data_generic_default();
  
  data_generic_default obj3 = data_generic_default();
}

kernel void test12() {
  static __global data_generic_default obj1;
  static __global data_generic_default obj2;
  obj1 = obj2;
  obj1 = data_generic_default();
  
  static __global data_generic_default obj3 = data_generic_default();
}

class data_default
{
public:
  int _data;
};

kernel void test13() {
  __local data_default obj1;
  __local data_default obj2;
  obj1 = obj2;
  obj1 = data_default();
}

kernel void test14() {
  data_default obj1;
  data_default obj2;
  obj1 = obj2;
  obj1 = data_default();
  
  data_default obj3 = data_default();
}

kernel void test15() {
  static __global data_default obj1;
  static __global data_default obj2;
  obj1 = obj2;
  obj1 = data_default();
  
  static __global data_default obj3 = data_default();
}