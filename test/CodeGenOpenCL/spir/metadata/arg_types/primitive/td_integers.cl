// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef char  Char;
typedef short Short;
typedef int   Integer;
typedef long  Long;

kernel void f1(Char i){}

kernel void f2(Short i){}

kernel void f3(Integer i){}

kernel void f4(Long j){}

// CHECK: !{!"kernel_arg_type", !"Char"}
// CHECK: !{!"kernel_arg_base_type", !"char"}
// CHECK: !{!"kernel_arg_type", !"Short"}
// CHECK: !{!"kernel_arg_base_type", !"short"}
// CHECK: !{!"kernel_arg_type", !"Integer"}
// CHECK: !{!"kernel_arg_base_type", !"int"}
// CHECK: !{!"kernel_arg_type", !"Long"}
// CHECK: !{!"kernel_arg_base_type", !"long"}
