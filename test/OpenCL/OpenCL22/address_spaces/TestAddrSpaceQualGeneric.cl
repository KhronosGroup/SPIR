// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

//local pointers as class members
class GenericClassMembers {
public:
  GenericClassMembers() = default;
  ~GenericClassMembers() = default;

  //pointers to local address spaces are allowed to be members of class
  int *a;
};

int * func1(int *arr) {
  return arr;
}

template<class T>
void func3(T arg) { }

template<class T>
void func6(T *arg) { }

void func8(int* arg) { }

int globalVar0;
int globalVar1[10];
static int globalVar2;
static int globalVar3[10];
int globalVar4 = 0;
int globalVar5[10] = { 0 };
static int globalVar6 = 0;
static int globalVar7[10] = { 0 };
int *globalPtr;

//passing pointers and references as OpenCL kernel arguments
kernel void worker( __local int* localArgPtr, __global int* globalArgPtr, __constant int* constantArgPtr ) {

  int genericVar0;
  static int genericVar2;
  int genericVar3 = 0;
  static int genericVar4 = 0;
  int *genericPtr = &genericVar0;
  int *genericPtr2 = &genericVar0;
  const int *constGenericPtr = &genericVar0;
  genericPtr = genericPtr2 = localArgPtr;
  genericPtr = globalArgPtr;
  if(genericPtr != genericPtr2) { }

  const __local int* constLocalPtr = localArgPtr;

  int genericArray[2];
  func1(&genericArray[0]);

  int &genericRef0 = genericVar0;

  const int &genericRef2 = genericVar0;

  auto autoVar0 = genericVar0;
  auto autoVar1 = 0.1f;
  auto autoVar2 = 1;

  func3(genericVar0);

  GenericClassMembers obj0;

  int genericVar1;
  func6(&genericVar1);

  int *genericPtr1 = &genericVar1;
  ++genericPtr1;

  if(genericPtr1 != &genericVar1) { }

  int arr[10];

  func8(genericPtr1);
}

kernel void worker2() {
  int genericVar0;
  static __global int var = 0;
  int &genericRef0 = genericVar0;
  genericRef0 = var;
}

void funcGlobal(__global int &arg) { }

kernel void worker3() {
  static __global int genericVar0;
  funcGlobal(genericVar0);
}

void funcGeneric(int &arg) { }

kernel void worker4() {
  int genericVar0;
  funcGeneric(genericVar0);
}

kernel void worker5() {
  __local int genericVar0;
  __local int var;
  __local int &genericRef0 = genericVar0;
  genericRef0 = var;
}
