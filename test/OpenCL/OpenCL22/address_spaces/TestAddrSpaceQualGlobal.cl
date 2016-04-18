// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

typedef unsigned int size_t;

//global pointers as class members
class GlobalClassMembers {
public:
  GlobalClassMembers() = default;
  ~GlobalClassMembers() = default;

  //pointers to global address spaces are allowed to be members of class/struct/...
  __global int *a;
};

__global int * func1(__global int *arr) {
  return arr;
}

int * func2(__global int *arr) {
  return arr;
}

template<class T>
void func3(T arg) { }

template<class T>
void func6(__global T *arg) { }

void func8(__global int* arg) { }
void func8(__local int* arg) { }
void func8(__private int* arg) { }
void func8(__constant int* arg) { }
void func8(int* arg) { }

__global int globalVar0 = 1;
__global int globalVar1[10] = { 1 };
__global int globalVar2;
__global int globalVar3[10];
static __global int globalVar4;
__global int *globalPtr;

struct s {
 int x;
} __global g;

template <typename _A, typename _B>
struct is_same { enum { value = false }; };

template <typename _A>
struct is_same<_A, _A> { enum { value = true }; };

int globalVar5 = 1;
__global int* __global ptr;

typedef __global int* __global type0;
static_assert(is_same<decltype(ptr), type0>::value, "#1: dectype does not match");
static_assert(is_same<type0, type0>::value, "#2: dectype does not match");

__global int* i = &globalVar5;
static_assert(is_same<decltype(ptr), decltype(i)>::value, "#3: dectype does not match");

type0 j = &globalVar5;
static_assert(is_same<decltype(ptr), decltype(j)>::value, "#4: dectype does not match");
static_assert(is_same<decltype(ptr), decltype(ptr)>::value, "#5: dectype does not match");

static_assert(is_same<decltype(i), decltype(j)>::value, "#6: dectype does not match");
static_assert(is_same<decltype(i), decltype(i)>::value, "#7: dectype does not match");
static_assert(is_same<decltype(j), decltype(j)>::value, "#8: dectype does not match");

typedef __global int& type1;
__global int& k = globalVar5;
type1 l = globalVar5;
type1 m = globalVar5;
static_assert(is_same<decltype(k), decltype(l)>::value, "#11: dectype does not match");
static_assert(is_same<decltype(l), decltype(m)>::value, "#12: dectype does not match");
static_assert(is_same<decltype(l), decltype(l)>::value, "#13: dectype does not match");

//passing pointers and references as OpenCL kernel arguments
kernel void worker( __global int &globalArg, __global int *globalArgPtr ) {
  //TODO: __global int globalVar0 = 10; //do we need to add static ? What is the difference betwen global and static global?
  static __global int globalVar2 = 10;
  static __global int globalVar3;
  __global int *globalPtr = &globalVar0;

  static __global int globalArray[2] = { 2 };
  int *globalPtr2 = globalArgPtr;
  func1(&globalArray[0]);
  func2(&globalArray[0]);

  __global int &globalRef0 = globalVar0;
  __global const int &globalRef01 = globalVar0;

  auto autoVar0 = globalVar0;
  static __global auto autoVar1 = 0.1f;
  static __global auto autoVar2 = 1;
   
  func3(globalVar0);
  size_t s = sizeof(globalVar0);

  GlobalClassMembers obj0;

  static __global int globalVar1 = 1;
  func6(&globalVar1);

  __global int *globalPtr1 = &globalVar1;
  ++globalPtr1;

  if(globalPtr1 != &globalVar1) { }

  if(globalPtr1 != &globalArgPtr[10]) { }

  static __global int arr[10] = { 0 };

  func8(globalPtr1);

  static __global GlobalClassMembers obj;
  obj.a = globalPtr1;
}
