// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

typedef unsigned int size_t;

//constant pointers as class members
class ConstantClassMembers {
public:
  ConstantClassMembers() = default;
  ~ConstantClassMembers() = default;

  //pointers to constant address spaces are allowed to be members of class
  __constant int *a;
};

__constant int * func1(__constant int *arr) {
  return arr;
}

template<class T>
void func3(T arg) { }

template<class T>
void func6(__constant T *arg) { }

void func8(__constant int* arg) { }
void func8(__local int* arg) { }
void func8(__global int* arg) { }
void func8(__private int* arg) { }
void func8(int* arg) { }

__constant int globalVar0 = 1;
__constant int globalVar1[10] = { 1 };
__constant int *globalPtr;

//passing pointers and references as OpenCL kernel arguments
kernel void worker( __constant int &constantArg, __constant int *constantArgPtr ) {
  __constant int constantVar0 = 10; //constant variables must be initialized
  static __constant int constantVar2 = 10;
  __constant int *constantPtr = &constantVar0;

  __constant int constantArray[2] = { 2 };
  func1(&constantArray[0]);

  __constant int &constantRef0 = constantVar0;
  __constant const int &constantRef2 = constantVar0;

  auto autoVar0 = constantVar0;
  __constant auto autoVar1 = 0.1f;
  __constant auto autoVar2 = 1;

  func3(constantVar0);
  size_t s = sizeof(constantVar0);

  ConstantClassMembers obj0;

  __constant int constantVar1 = 1;
  func6(&constantVar1);

  __constant int *constantPtr1 = &constantVar1;
  ++constantPtr1;

  if(constantPtr1 != &constantVar1) { }

  if(constantPtr1 != &constantArgPtr[10]) { }

  __constant int arr[10] = { 0 };

  func8(constantPtr1);
}