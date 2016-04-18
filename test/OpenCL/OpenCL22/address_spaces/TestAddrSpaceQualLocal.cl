// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

typedef unsigned int size_t;

//local pointers as class members
class LocalClassMembers {
public:
  LocalClassMembers() = default;
  ~LocalClassMembers() = default;

  //pointers to local address spaces are allowed to be members of class
  __local int *a;
};

__local int * func1(__local int *arr) {
  return arr;
}

int * func2(__local int *arr) {
  return arr;
}

template<class T>
void func3(T arg) { }

template<class T>
void func6(__local T *arg) { }

void func8(__local int* arg) { }
void func8(__private int* arg) { }
void func8(__global int* arg) { }
void func8(__constant int* arg) { }
void func8(int* arg) { }

__local int globalVar0;
__local int globalVar1[10];
static __local int globalVar2;
static __local int globalVar3[10];
__local int *globalPtr;

//passing pointers and references as OpenCL kernel arguments
kernel void worker( __local int &localArg, __local int *localArgPtr ) {
  __local int localVar0; //local variables can't be initialized
  static __local int localVar2;
  __local int *localPtr = &localVar0;

  __local int localArray[2];
  int *localPtr2 = &localVar0;
  func1(&localArray[0]);
  func2(&localArray[0]);

  __local int &localRef0 = localVar0;
  __local const int &localRef2 = localVar0;

  auto autoVar0 = localVar0;

  func3(localVar0);
  size_t s = sizeof(localVar0);

  LocalClassMembers obj0;

  __local int localVar1;
  func6(&localVar1);

  __local int *localPtr1 = &localVar1;
  ++localPtr1;

  if(localPtr1 != &localVar1) { }

  if(localPtr1 != &localArgPtr[10]) { }

  __local int arr[10];

  func8(localPtr1);

  __local LocalClassMembers obj;
  obj.a = localPtr1;
}