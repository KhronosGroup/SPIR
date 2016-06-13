// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O2 -emit-llvm -o - | FileCheck %s -check-prefix=CHECK_02
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O2 -emit-llvm -o - | FileCheck %s -check-prefix=CHECK_02
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o - | FileCheck %s -check-prefix=CHECK_O0
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O1 -emit-llvm -o - | FileCheck %s -check-prefix=CHECK_O0
//expected-no-diagnostics

#define GLOBAL_MEM __global

#include "../opencl_def"

struct A;

extern void Marker(A*); //marker od this

struct A {
    int a, b;
    A() { a = 1; }
    ~A() { Marker(this); }
};

GLOBAL_MEM A A_1, A_2;
GLOBAL_MEM A __attribute__((init_priority(1002))) A_3, A_4;

// ----- O0 Optimalization
// CHECK_O0: define spir_kernel void @_SPIRV_GLOBAL__I_{{(.*)}}
// CHECK_O0: call spir_func void @_GLOBAL__I_001002()
// CHECK_O0-NEXT: call spir_func void @_GLOBAL__sub_I{{(.*)}}

// CHECK_O0: define spir_kernel void @_SPIRV_GLOBAL__D_{{(.*)}}
// CHECK_O0: call spir_func void @_GLOBAL__sub_D_{{(.*)}}
// CHECK_O0-NEXT: call spir_func void @_GLOBAL__D_001002()


// ----- O2 Optimalization
// CHECK_02-DAG: define spir_kernel void @_SPIRV_GLOBAL__I_{{(.*)}}
// CHECK_O2: store i32 {{(.*)}} @A_3
// CHECK_O2-NEXT: store i32 {{(.*)}} @A_4
// CHECK_O2-NEXT: store i32 {{(.*)}} @A_1
// CHECK_O2-NEXT: store i32 {{(.*)}} @A_2

// CHECK_02-DAG: define spir_kernel void @_SPIRV_GLOBAL__D_{{(.*)}}
// CHECK_02: tail call spir_func void @_Z6Marker{{(.*)}} @A_2
// CHECK_02-NEXT: tail call spir_func void @_Z6Marker{{(.*)}} @A_1
// CHECK_02-NEXT: tail call spir_func void @_Z6Marker{{(.*)}} @A_4
// CHECK_02-NEXT: tail call spir_func void @_Z6Marker{{(.*)}} @A_3