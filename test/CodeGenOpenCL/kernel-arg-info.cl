// RUN: %clang_cc1 %s -cl-std=CL2.0 -cl-kernel-arg-info -emit-llvm -o - -triple spir-unknown-unknown | FileCheck %s -check-prefix ARGINFO
// RUN: %clang_cc1 %s -cl-std=CL2.0 -emit-llvm -o - -triple spir-unknown-unknown | FileCheck %s

kernel void foo(__global int * restrict X, __constant const int * Y,
                __global volatile int * anotherArg, __constant float * restrict Z) {
  *X = *Y + *anotherArg;
}

// CHECK:  !{!"kernel_arg_addr_space", i32 1, i32 2, i32 1, i32 2}
// CHECK:  !{!"kernel_arg_access_qual", !"none", !"none", !"none", !"none"}
// CHECK:  !{!"kernel_arg_type", !"int*", !"int*", !"int*", !"float*"}
// CHECK:  !{!"kernel_arg_base_type", !"int*", !"int*", !"int*", !"float*"}
// CHECK:  !{!"kernel_arg_type_qual", !"restrict", !"const", !"volatile", !"restrict const"}
// ARGINFO: !{!"kernel_arg_name", !"X", !"Y", !"anotherArg", !"Z"}
// CHECK-NOT: !{!"kernel_arg_name", !"X", !"Y", !"anotherArg", !"Z"}

kernel void foo2(read_only image1d_t img1, image2d_t img2, write_only image2d_array_t img3) {
}
// CHECK:  !{!"kernel_arg_addr_space", i32 1, i32 1, i32 1}
// CHECK:  !{!"kernel_arg_access_qual", !"read_only", !"read_only", !"write_only"}
// CHECK:  !{!"kernel_arg_type", !"__read_only image1d_t", !"__read_only image2d_t", !"__write_only image2d_array_t"}
// CHECK:  !{!"kernel_arg_base_type", !"__read_only image1d_t", !"__read_only image2d_t", !"__write_only image2d_array_t"}
// CHECK:  !{!"kernel_arg_type_qual", !"", !"", !""}
// ARGINFO: !{!"kernel_arg_name", !"img1", !"img2", !"img3"}
// CHECK-NOT: !{!"kernel_arg_name", !"img1", !"img2", !"img3"}

kernel void foo3(__global half * X) {
}
// CHECK:  !{!"kernel_arg_addr_space", i32 1}
// CHECK:  !{!"kernel_arg_access_qual", !"none"}
// CHECK:  !{!"kernel_arg_type", !"half*"}
// CHECK:  !{!"kernel_arg_base_type", !"half*"}
// CHECK:  !{!"kernel_arg_type_qual", !""}
// ARGINFO: !{!"kernel_arg_name", !"X"}
// CHECK-NOT: !{!"kernel_arg_name", !"X"}

typedef unsigned int myunsignedint;
kernel void foo4(__global unsigned int * X, __global myunsignedint * Y) {
}
// CHECK:  !{!"kernel_arg_addr_space", i32 1, i32 1}
// CHECK:  !{!"kernel_arg_access_qual", !"none", !"none"}
// CHECK:  !{!"kernel_arg_type", !"uint*", !"myunsignedint*"}
// CHECK:  !{!"kernel_arg_base_type", !"uint*", !"uint*"}
// CHECK:  !{!"kernel_arg_type_qual", !"", !""}
// ARGINFO: !{!"kernel_arg_name", !"X", !"Y"}
// CHECK-NOT: !{!"kernel_arg_name", !"X", !"Y"}

typedef image1d_t myImage;
kernel void foo5(myImage img1, write_only image1d_t img2) {
}
// CHECK:  !{!"kernel_arg_access_qual", !"read_only", !"write_only"}
// CHECK:  !{!"kernel_arg_type", !"myImage", !"__write_only image1d_t"}
// CHECK:  !{!"kernel_arg_base_type", !"__read_only image1d_t", !"__write_only image1d_t"}
// ARGINFO: !{!"kernel_arg_name", !"img1", !"img2"}
// CHECK-NOT: !{!"kernel_arg_name", !"img1", !"img2"}

typedef read_only  image1d_t ROImage;
typedef write_only image1d_t WOImage;
typedef read_write image1d_t RWImage;
kernel void foo6(ROImage ro, WOImage wo, RWImage rw) {
}
// CHECK: @foo6
// CHECK: !{!"kernel_arg_access_qual", !"read_only", !"write_only", !"read_write"}
// CHECK: !{!"kernel_arg_type", !"ROImage", !"WOImage", !"RWImage"}
// CHECK: !{!"kernel_arg_base_type", !"__read_only image1d_t", !"__write_only image1d_t", !"__read_write image1d_t"}
// CHECK-NOT: !kernel_arg_name
// ARGINFO: !"kernel_arg_name", !"ro", !"wo", !"rw"}
