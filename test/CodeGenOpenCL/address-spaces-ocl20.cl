// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=CL2.0 -emit-llvm -O0 -o - | FileCheck %s

typedef unsigned char uchar;

global int baz = 12; // OK. Initialization is allowed
// CHECK: @baz = addrspace(1) global i32 12, align 4

global int * constant ptr3 = &baz; // OK
// CHECK: @ptr3 = addrspace(2) constant i32 addrspace(1)* @baz, align 4

// Pointers work. Also, initialization to a constant known at program load time
global int *global baz_ptr = &baz;
// CHECK: @baz_ptr = addrspace(1) global i32 addrspace(1)* @baz, align 4

const sampler_t sampler = 10;
// CHECK: @sampler = constant %opencl.sampler_t { i32 10 }, align 4

static global int bat; // OK. Internal linkage
// CHECK: @bat = internal addrspace(1) global i32 0, align 4

static int foo3; // OK. Declared in the global address space
// CHECK: @foo3 = internal addrspace(1) global i32 0, align 4

static global int foo4; // OK.
// CHECK: @foo4 = internal addrspace(1) global i32 0, align 4

// func.i is defined later, but it's generated in program scope since it's static
// CHECK: @func.i = internal addrspace(1) global i32 0, align 4

global int foo; // OK.
// CHECK: @foo = common addrspace(1) global i32 0, align 4

int foo2; // OK. Declared in the global address space
// CHECK: @foo2 = common addrspace(1) global i32 0, align 4

global uchar buf[512]; // OK.
// CHECK: @buf = common addrspace(1) global [512 x i8] zeroinitializer, align 1

global uchar bigbuf[1000]; // OK.
// CHECK: @bigbuf = common addrspace(1) global [1000 x i8] zeroinitializer, align 1

int *foo5; // OK. foo is allocated in global address space.
           // pointer to foo in generic address space
// CHECK: @foo5 = common addrspace(1) global i32 addrspace(4)* null, align 4

global int * global ptr; // OK.
// CHECK: @ptr = common addrspace(1) global i32 addrspace(1)* null, align 4

int * global ptr2; // OK.
// CHECK: @ptr2 = common addrspace(1) global i32 addrspace(4)* null, align 4

void func(void)
{
  int *foo; // OK. foo is allocated in private address space.
            // foo points to a location in generic address space.
// CHECK: %foo = alloca i32 addrspace(4)*, align 4
  bat = 5;  // Use bat, so it won't get optimized out
  foo3 = 5;  // Use foo3, so it won't get optimized out
  foo4 = 5;  // Use foo4, so it won't get optimized out

  static int i;
}

//constant int *global ptr=&baz; // error since baz is in global address
                                 // space.
//global image2d_t im; // Error. Invalid type for program scope variables
//global event_t ev; // Error. Invalid type for program scope variables
//global int *bad_ptr; // Error. No implicit address space
