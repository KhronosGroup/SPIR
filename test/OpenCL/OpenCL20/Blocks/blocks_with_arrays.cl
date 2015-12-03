// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -triple spir64-unkown-unkown -emit-llvm %s -o -| FileCheck %s

typedef int (^block_t)();

int block_typedef_kernel(global int* res) {
  int a[3] = {1, 2, 3};
  block_t b = ^() {
// CHECK:   %{{.*}} = getelementptr inbounds [3 x i32]* %{{.*}}, i32 0, i64 0
    return a[0];
  };
  return b();
}
