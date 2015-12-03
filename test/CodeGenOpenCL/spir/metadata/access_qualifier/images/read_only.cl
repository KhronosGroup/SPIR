// RUN: %clang_cc1 %s -O0 -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -O0 -triple "spir64-unknown-unknown" -emit-llvm -o - | FileCheck %s

typedef read_only image2d_t MyImage;

kernel void f1(read_only image2d_t i){
}

kernel void f2(image2d_t i){
}

kernel void f3(MyImage i){
}

// CHECK: !{!"kernel_arg_access_qual", !"read_only"}
// CHECK-NOT: !{!"kernel_arg_access_qual", !"write_only"}
// CHECK-NOT: !{!"kernel_arg_access_qual", !"read_write"}
// CHECK-NOT: !{!"kernel_arg_access_qual", !"none"}
