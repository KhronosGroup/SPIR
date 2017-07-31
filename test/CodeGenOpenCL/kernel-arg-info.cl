// RUN: %clang_cc1 %s -cl-kernel-arg-info -emit-llvm -o - | FileCheck %s

kernel void foo(int *X, int Y, int anotherArg) {
  *X = Y + anotherArg;
}

// CHECK: metadata !{metadata !"kernel_arg_name", metadata !"X", metadata !"Y", metadata !"anotherArg"}

typedef read_only  image1d_t ROImage;
typedef write_only image1d_t WOImage;
typedef read_write image1d_t RWImage;
kernel void foo2(ROImage ro, WOImage wo, RWImage rw) {
}
// CHECK: @foo2
// CHECK: !{metadata !"kernel_arg_access_qual", metadata !"read_only", metadata !"write_only", metadata !"read_write"}
// CHECK: !{metadata !"kernel_arg_type", metadata !"ROImage", metadata !"WOImage", metadata !"RWImage"}
// CHECK: !{metadata !"kernel_arg_base_type", metadata !"image1d_t", metadata !"image1d_t", metadata !"image1d_t"}
// CHECK: !{metadata !"kernel_arg_name", metadata !"ro", metadata !"wo", metadata !"rw"}
