// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef struct _Person {
  int id;
} Person;

typedef global Person* PPerson;

kernel void f1(global struct _Person *P) {}
kernel void f2(global Person *P) {}
kernel void f3(PPerson P) {}

// CHECK: !{!"kernel_arg_type", !"struct _Person*"}
// CHECK: !{!"kernel_arg_base_type", !"struct _Person*"}
// CHECK: !{!"kernel_arg_type", !"Person*"}
// CHECK: !{!"kernel_arg_type", !"PPerson"}
