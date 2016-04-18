// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

int vg0[5] = { 0 };
kernel void worker0() {
  int vp0[5] = { 0 };
  int (&c)[5] = vg0;
  int (&d)[5] = vp0;
}

//////////////////////////////////////

void foo1(const int (&)[4]) { }

int vg1[4] = {1, 2, 3, 4};
kernel void worker1() {
  int vp1[4] = {1, 2, 3, 4};
  foo1(vg1);
  foo1(vp1);
}

//////////////////////////////////////

void foo2(const int (*)[4]) { }

int vg2[4] = {1, 2, 3, 4};
kernel void worker2() {
  int vp[4] = {1, 2, 3, 4};
  foo2(&vg2);
  foo2(&vp);
}
//////////////////////////////////////

template<int N> void foo3(const int (&)[N]) { }

int vg3[] = {1, 2, 3, 4};
kernel void worker3() {
  int vp[] = {1, 2, 3, 4};
  foo3(vg3);
  foo3(vp);
}

//////////////////////////////////////

template<int N> void foo4(const int (*)[N]) { }

int vg4[] = {1, 2, 3, 4};
kernel void worker4() {
  int vp[] = {1, 2, 3, 4};
  foo4(&vg4);
  foo4(&vp);
}
