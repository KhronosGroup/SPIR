// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

typedef unsigned int size_t;

//local pointers as class members
class PrivateClassMembers {
public:
  PrivateClassMembers() = default;
  ~PrivateClassMembers() = default;

  //pointer to local address spaces are allowed to be members of class
  __private int *a;
};

__private int * func1(__private int *arr) {
  return arr;
}

int * func2(__private int *arr) {
  return arr;
}

template<class T>
void func3(T arg) { }

template<class T>
void func6(__private T *arg) { }

void func8(__private int* arg) { }
void func8(__local int* arg) { }
void func8(__global int* arg) { }
void func8(__constant int* arg) { }
void func8(int* arg) { }

kernel void worker( ) {
  __private int privateVar0;
  __private int privateVar3 = 0;
  __private int *privatePtr = &privateVar0;

  __private int privateArray[2];
  int *privatePtr2 = &privateVar0;
  func1(&privateArray[0]);
  func2(&privateArray[0]);

  __private int &privateRef0 = privateVar0;
  __private const int &privateRef2 = privateVar0;

  auto autoVar0 = privateVar0;
  __private auto autoVar1 = 0.1f;
  __private auto autoVar2 = 1;

  func3(privateVar0);
  size_t s = sizeof(privateVar0);

  PrivateClassMembers obj0;

  __private int privateVar1;
  func6(&privateVar1);

  __private int *privatePtr1 = &privateVar1;
  ++privatePtr1;

  if(privatePtr1 != &privateVar1) { }

  __private int arr[10];

  func8(privatePtr1);

  __private PrivateClassMembers obj;
  obj.a = privatePtr1;
}