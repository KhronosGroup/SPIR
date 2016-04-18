// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

struct A {
  A();
  A() __constant;
  ~A();

  void fun();
  void fun() __local;
  void fun() __global;
  void fun() __private;
  void fun() __constant;

  bool fun2();
};

A::A() { }
A::A() __constant { }
A::~A() { }
void A::fun() { }
void A::fun() __local { }
void A::fun() __global { }
void A::fun() __private { }
void A::fun() __constant { }
bool A::fun2() { return true; }

int fun() { return 1; }

template<class T>
struct B {
  B();
  B() __constant;
  ~B();

  void fun();
  void fun() __local;
  void fun() __global;
  void fun() __private;
  void fun() __constant;

  bool fun2();
};

template<class T>
B<T>::B() { }

template<class T>
B<T>::B() __constant { }

template<class T>
B<T>::~B() { }

template<class T>
void B<T>::fun() { }

template<class T>
void B<T>::fun() __local { }

template<class T>
void B<T>::fun() __global { }

template<class T>
void B<T>::fun() __private { }

template<class T>
void B<T>::fun() __constant { }

template<class T>
bool B<T>::fun2() { return true; }

kernel void worker() {
  A v0;
  v0.fun();

  __local A v1;
  v1.fun();

  static __global A v2;
  v2.fun();

  int v3 = fun();

  B<int> v4;
  v4.fun();

  __local B<int> v5;
  v5.fun();

  static __global B<int> v6;
  v6.fun();
}