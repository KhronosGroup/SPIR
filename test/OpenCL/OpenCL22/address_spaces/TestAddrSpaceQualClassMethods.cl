// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

class data
{
public:
  data(): _data(0) { }
  data(int rhs): _data(rhs) { }
  constexpr data(int rhs) __global: _data(rhs) { }
  constexpr data(int rhs) __constant: _data(rhs) { }

  data(const data& rhs) __constant = default;
  data(const data& rhs) = default;

  data(__constant data&& rhs) __constant = default;
  data(data&& rhs) = default;

  __constant int *get() __constant { return &_data; }
  __constant const int *get() __constant const { return &_data; }
  __constant volatile int *get() __constant volatile { return &_data; }

  __private int *get() __private { return &_data; }
  __private const int *get() __private const { return &_data; }
  __private volatile int *get() __private volatile { return &_data; }

  __global int *get() __global { return &_data; }
  __global const int *get() __global const { return &_data; }
  __global volatile int *get() __global volatile { return &_data; }

  __generic int *get() __generic { return &_data; }
  __generic const int *get() __generic const { return &_data; }
  __generic volatile int *get() __generic volatile { return &_data; }

  __local int *get() __local { return &_data; }
  __local const int *get() __local const { return &_data; }
  __local volatile int *get() __local volatile { return &_data; }

  int _data;
};

class data_generic
{
public:
  data_generic() = default;
  data_generic() __constant = default;

  data_generic(int rhs): _data(rhs) { }
  constexpr data_generic(int rhs) __global: _data(rhs) { }
  constexpr data_generic(int rhs) __constant: _data(rhs) { }

  data_generic(const data_generic& rhs) = default;
  constexpr data_generic(const data_generic& rhs) __constant = default;

  data_generic(data_generic&& rhs) = default;
  constexpr data_generic(__constant data_generic&& rhs) __constant = default;

  int *get() { return &_data; }
  __constant int *get() __constant { return &_data; }

  const int *get() const { return &_data; }
  __constant const int *get() __constant const { return &_data; }

  volatile int *get() volatile { return &_data; }
  __constant volatile int *get() __constant volatile { return &_data; }

  int _data;
};

__global data g00;
const __global data g01 = 1;
volatile __global data g02;

data g10;
const data g11;
volatile data g12;

__constant data g30 = 30;
const __constant data g31 = 31;
volatile __constant data g32 = 32;

__global data_generic g40;
const __global data_generic g41 = 41;
volatile __global data_generic g42;

data_generic g50;
const data_generic g51 = 51;
volatile data_generic g52;

__local data_generic g60;
//const __local data_generic g61; //const objects must be initialized, but local memory can't be initialized
volatile __local data_generic g62;

__constant data_generic g70 = 70;
const __constant data_generic g71 = 71;
volatile __constant data_generic g72 = 72;

kernel void worker() {
  static __global data l00 = 0;
  int *l00_ptr0 = l00.get();
  __global int *l00_ptr1 = l00.get();

  static const __global data l01 = 1;
  const int *l01_ptr0 = l01.get();
  __global const int *l01_ptr1 = l01.get();

  static volatile __global data l02 = 2;
  volatile int *l02_ptr0 = l02.get();
  __global volatile int *l02_ptr1 = l02.get();

  data l10;
  int *l10_ptr0 = l10.get();

  const data l11;
  const int *l11_ptr0 = l11.get();

  volatile data l12;
  volatile int *l12_ptr0 = l12.get();

  __local data l20;
  int *l20_ptr0 = l20.get();
  __local int *l20_ptr1 = l20.get();

  const __local data l21;
  const int *l21_ptr0 = l21.get();
  __local const int *l21_ptr1 = l21.get();

  volatile __local data l22;
  volatile int *l22_ptr0 = l22.get();
  __local volatile int *l22_ptr1 = l22.get();

  __constant data l30 = 30;
  __constant int *l30_ptr1 = l30.get();

  const __constant data l31 = 31;
  const __constant int *l31_ptr1 = l31.get();

  volatile __constant data l32 = 32;
  volatile __constant int *l32_ptr1 = l32.get();

  static __global data_generic l40;
  int *l40_ptr0 = l40.get();

  static const __global data_generic l41 = 41;
  const int *l41_ptr0 = l41.get();

  static volatile __global data_generic l42;
  volatile int *l42_ptr0 = l42.get();

  data_generic l50;
  volatile int *l50_ptr0 = l50.get();

  const data_generic l51 = 51;
  const int *l51_ptr0 = l51.get();

  volatile data_generic l52;
  volatile int *l52_ptr0 = l52.get();

  __local data_generic l60;
  int *l60_ptr0 = l60.get();

  const __local data_generic l61{};
  const int *l61_ptr0 = l61.get();

  volatile __local data_generic l62;
  volatile int *l62_ptr0 = l62.get();

  __constant data_generic l70 = 70;
  __constant int *l70_ptr0 = l70.get();

  __constant const data_generic l71 = 71;
  __constant const int *l71_ptr0 = l71.get();

  __constant volatile data_generic l72 = 72;
  __constant volatile int *l72_ptr0 = l72.get();
}

class Test13 {
public:
  Test13(int rhs): _m(rhs) { }
  Test13(const Test13 &rhs) = default;
  Test13(Test13 &&rhs) = default;

  constexpr Test13(int rhs) __constant: _m(rhs) { }
  constexpr Test13(const Test13 &rhs) __constant = default;
  constexpr Test13(Test13 &&rhs) __constant = default;
  
  __constant int &dataget() __constant { return _m; }
  __constant const int &dataget() __constant const { return _m; }
  
  int &dataget() { return _m; }
  const int &dataget() const { return _m; }
  
private:
  int _m;
};

class constant_obj_ptr {
  public:
    using object_type = Test13;
    using const_pointer = const __constant object_type*;
    using pointer = __constant object_type*;
    using const_reference = const __constant object_type&;
    using reference = __constant object_type&;

    constant_obj_ptr() = default;
    constant_obj_ptr(const constant_obj_ptr &rhs) = default;
    constant_obj_ptr(__constant object_type *rhs): _ptr(rhs) { };

    const_reference operator*() const { return *_ptr; }
    reference operator*() { return *_ptr; }

    const_pointer operator->() const { return _ptr; }
    pointer operator->() { return _ptr; }

  private:
    __constant object_type* _ptr;
};

kernel void test13() {
  __constant Test13 var0(0);
  constant_obj_ptr ptr0(&var0);
  int var1 = ptr0->dataget();
  int var2 = (*ptr0).dataget();
}


class TestClass15 {
public:
  constexpr TestClass15(int rhs) __constant: _m(rhs) { }
  TestClass15(int rhs): _m(rhs) { }
  constexpr TestClass15(__constant const TestClass15 &rhs) __constant: _m(rhs._m) { }
  TestClass15(const TestClass15 &rhs): _m(rhs._m) { }
  int &get() { return _m; }
  const int &get() const { return _m; }
  __constant int &get() __constant { return _m; }
  int _m;
};

kernel void test14() {
   __constant TestClass15 obj0(1);
   int a = obj0.get();

   const TestClass15 obj1(1);
   int b = obj1.get();
}


class TestClass16 {
public:
  constexpr TestClass16(int rhs) __constant: _m(rhs) { }
  TestClass16(int rhs): _m(rhs) { }
  constexpr TestClass16(__constant const TestClass16 &rhs) __constant: _m(rhs._m) { }
  TestClass16(const TestClass16 &rhs): _m(rhs._m) { }
  int &get() { return _m; }
  //const int &get() const { return _m; }
  __constant int &get() __constant { return _m; }
  int _m;
};

template <class T>
class TestWrapperClass16 {
public:
  constexpr TestWrapperClass16(T &rhs) __constant: _m(rhs) { }
  TestWrapperClass16(T &rhs): _m(rhs) { }

  constexpr TestWrapperClass16() __constant = default;
  TestWrapperClass16() = default;
  constexpr TestWrapperClass16(const TestWrapperClass16 &rhs) __constant = default;
  TestWrapperClass16(const TestWrapperClass16 &rhs) = default;
  constexpr TestWrapperClass16(__constant const TestWrapperClass16 &rhs) __constant = default;

  __constant T &data() __constant { return _m; }
  T &data() { return _m; }

  T _m;
};

kernel void test16() {
  __constant TestClass16 obj0(1);
  int a = obj0.get();
}