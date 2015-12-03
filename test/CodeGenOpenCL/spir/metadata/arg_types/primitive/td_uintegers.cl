// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef unsigned char Uchar;
typedef unsigned short Ushort;
typedef unsigned int Uint;
typedef unsigned long Ulong;

kernel void f1(Uchar i){}

kernel void f2(Ushort i){}

kernel void f3(Uint i){}

kernel void f4(Ulong j){}

// CHECK: !{!"kernel_arg_type", !"Uchar"}
// CHECK: !{!"kernel_arg_base_type", !"uchar"}
// CHECK: !{!"kernel_arg_type", !"Ushort"}
// CHECK: !{!"kernel_arg_base_type", !"ushort"}
// CHECK: !{!"kernel_arg_type", !"Uint"}
// CHECK: !{!"kernel_arg_base_type", !"uint"}
// CHECK: !{!"kernel_arg_type", !"Ulong"}
// CHECK: !{!"kernel_arg_base_type", !"ulong"}
