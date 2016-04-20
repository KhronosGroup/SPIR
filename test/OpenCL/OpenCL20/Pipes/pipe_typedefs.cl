// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -emit-llvm %s -triple spir-unkown-unkown -O0 -o -| FileCheck %s
typedef read_only image2d_t RImage;
typedef read_only pipe int  IPipe;

kernel void f(RImage img, IPipe p){
}

// CHECK-DAG: [[MDNODE:![0-9]+]] = !{!"kernel_arg_access_qual", !"read_only", !"read_only"}
// CHECK-DAG: [[MDNODE:![0-9]+]] = !{!"kernel_arg_type_qual", !"", !"pipe"}
// CHECK-DAG: [[MDNODE:![0-9]+]] = !{!"kernel_arg_base_type", !"__read_only image2d_t", !"int"}
