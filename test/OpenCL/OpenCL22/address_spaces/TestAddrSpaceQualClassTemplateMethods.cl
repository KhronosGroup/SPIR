// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

//TODO: inherint classes
//TODO: static methods?
//TODO: methods overwriting
template<class T>
class data
{
public:
  data(): _data(0) { }
  data(T rhs): _data(rhs) { }
  constexpr data(T rhs) __global: _data(rhs) { }
  constexpr data(T rhs) __constant: _data(rhs) { }

  constexpr data(const data& rhs) __constant = default;
  data(const data& rhs) = default;

  data(__constant data&& rhs) __constant = default;
  data(data&& rhs) = default;

  __constant T *get() __constant { return &_data; }
  __constant const T *get() __constant const { return &_data; }
  __constant volatile T *get() __constant volatile { return &_data; }

  __private T *get() __private { return &_data; }
  __private const T *get() __private const { return &_data; }
  __private volatile T *get() __private volatile { return &_data; }

  __global T *get() __global { return &_data; }
  __global const T *get() __global const { return &_data; }
  __global volatile T *get() __global volatile { return &_data; }

  __generic T *get() __generic { return &_data; }
  __generic const T *get() __generic const { return &_data; }
  __generic volatile T *get() __generic volatile { return &_data; }

  __local T *get() __local { return &_data; }
  __local const T *get() __local const { return &_data; }
  __local volatile T *get() __local volatile { return &_data; }

  T _data;
};

template<class T>
class data_generic
{
public:
  data_generic() = default;
  data_generic() __constant = default;

  data_generic(T rhs): _data(rhs) { }
  constexpr data_generic(T rhs) __global: _data(rhs) { }
  constexpr data_generic(T rhs) __constant: _data(rhs) { }

  data_generic(const data_generic& rhs) = default;
  constexpr data_generic(const data_generic& rhs) __constant = default;

  data_generic(data_generic&& rhs) = default;
  constexpr data_generic(__constant data_generic&& rhs) __constant = default;

  T *get() { return &_data; }
  __constant T *get() __constant { return &_data; }

  const T *get() const { return &_data; }
  __constant const T *get() __constant const { return &_data; }

  volatile T *get() volatile { return &_data; }
  __constant volatile T *get() __constant volatile { return &_data; }

  T _data;
};

__global data<int> g00;
const __global data<int> g01 = 1;
volatile __global data<int> g02;

data<int> g10;
const data<int> g11;
volatile data<int> g12;

__constant data<int> g30 = 30;
const __constant data<int> g31 = 31;
volatile __constant data<int> g32 = 32;

__global data_generic<int> g40;
const __global data_generic<int> g41 = 41;
volatile __global data_generic<int> g42;

data_generic<int> g50;
const data_generic<int> g51 = 51;
volatile data_generic<int> g52;

__local data_generic<int> g60;
//const __local data_generic<int> g61; //const objects must be initialized, but local memory can't be initialized
volatile __local data_generic<int> g62;

__constant data_generic<int> g70 = 70;
const __constant data_generic<int> g71 = 71;
volatile __constant data_generic<int> g72 = 72;

kernel void test1() {
  static __global data<int> l00 = 0;
  int *l00_ptr0 = l00.get();
  __global int *l00_ptr1 = l00.get();

  static const __global data<int> l01 = 1;
  const int *l01_ptr0 = l01.get();
  __global const int *l01_ptr1 = l01.get();

  static volatile __global data<int> l02 = 2;
  volatile int *l02_ptr0 = l02.get();
  __global volatile int *l02_ptr1 = l02.get();

  data<int> l10;
  int *l10_ptr0 = l10.get();

  const data<int> l11;
  const int *l11_ptr0 = l11.get();

  volatile data<int> l12;
  volatile int *l12_ptr0 = l12.get();

  __local data<int> l20;
  int *l20_ptr0 = l20.get();
  __local int *l20_ptr1 = l20.get();

  const __local data<int> l21;
  const int *l21_ptr0 = l21.get();
  __local const int *l21_ptr1 = l21.get();

  volatile __local data<int> l22;
  volatile int *l22_ptr0 = l22.get();
  __local volatile int *l22_ptr1 = l22.get();

  __constant data<int> l30 = 30;
  __constant int *l30_ptr1 = l30.get();

  const __constant data<int> l31 = 31;
  const __constant int *l31_ptr1 = l31.get();

  volatile __constant data<int> l32 = 32;
  volatile __constant int *l32_ptr1 = l32.get();

  static __global data_generic<int> l40;
  int *l40_ptr0 = l40.get();

  static const __global data_generic<int> l41 = 41;
  const int *l41_ptr0 = l41.get();

  static volatile __global data_generic<int> l42;
  volatile int *l42_ptr0 = l42.get();

  data_generic<int> l50;
  volatile int *l50_ptr0 = l50.get();

  const data_generic<int> l51 = 51;
  const int *l51_ptr0 = l51.get();

  volatile data_generic<int> l52;
  volatile int *l52_ptr0 = l52.get();

  __local data_generic<int> l60;
  int *l60_ptr0 = l60.get();

  const __local data_generic<int> l61{};
  const int *l61_ptr0 = l61.get();

  volatile __local data_generic<int> l62;
  volatile int *l62_ptr0 = l62.get();

  __constant data_generic<int> l70 = 70;
  __constant int *l70_ptr0 = l70.get();

  __constant const data_generic<int> l71 = 71;
  __constant const int *l71_ptr0 = l71.get();

  __constant volatile data_generic<int> l72 = 72;
  __constant volatile int *l72_ptr0 = l72.get();
}