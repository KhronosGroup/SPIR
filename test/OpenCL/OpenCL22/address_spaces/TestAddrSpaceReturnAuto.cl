// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

#include "../opencl_def"

struct A {
  int a;

  operator auto() { return a; }	
  operator auto() __local { return a; }

  auto fun1() { return a; }
  auto fun1() __local { return a; }
  auto fun1() const { return a; }

  auto fun2() { return &a; }
  auto fun2() __local { return &a; }
  auto fun2() const { return &a; }

  int fun3() { return a; }
  int fun3() __local { return a; }
  int fun3() const { return a; }

  int* fun4() { return &a; }	
  int* fun4() __local { return &a; }
  const int* fun4() const { return &a; }
  
  auto& fun5() { return a; }
  auto& fun5() __local { return a; }
  auto& fun5() const { return a; }
  
  auto* fun6() { return &a; }
  auto* fun6() __local { return &a; }
  auto* fun6() const { return &a; }
};

auto fun1(int a) { return a; }
auto fun2(int &a) { return a; }

template<typename T>
auto fun3(T a) {
  return a;
}

template<typename T>
auto fun4(T &a) {
  return a;
}

kernel void worker() {
  A var0;
  auto a00 = var0.fun1();
  auto a01 = var0.fun2();
  auto a02 = var0.fun3();
  auto a03 = var0.fun4();
  auto a04 = var0.fun5();
  auto a05 = var0.fun6();
  auto a06 = fun3(var0);
  auto a07 = fun4(var0);

  __local A var1;
  auto a10 = var1.fun1();
  auto a11 = var1.fun2();
  auto a12 = var1.fun3();
  auto a13 = var1.fun4();
  auto a14 = var1.fun5();
  auto a15 = var1.fun6();
  auto a16 = fun3(var1);
  auto a17 = fun4(var1);

  int var2;
  auto a20 = fun1(var2);
  auto a21 = fun2(var2);
  auto a22 = fun3(var2);
  auto a23 = fun4(var2);

  const A var3 = { 1 };
  auto a30 = var3.fun1();
  auto a31 = var3.fun2();
  auto a32 = var3.fun3();
  auto a33 = var3.fun4();
  auto a34 = var3.fun5();
  auto a35 = var3.fun6();
}

template <class T, size_t Size>
struct i
{
public:
    template <size_t... Sizes>
    auto s( ) { return 1; }
};

template <class T, size_t Size>
struct j: public i<T, Size>
{
  auto m() { return this->template s<100>(); }
};

kernel void k() {
  j<int, 5> a;
  a.m();
};