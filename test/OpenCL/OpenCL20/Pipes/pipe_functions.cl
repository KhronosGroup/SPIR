// RUN: %clang_cc1 -emit-llvm -O0 -cl-std=CL2.0 -o - %s | FileCheck %s

kernel void test( read_only pipe int p1, write_only pipe int p2 ) {
// CHECK: define void @test(%opencl.pipe_t addrspace(1)* %p1, %opencl.pipe_t addrspace(1)* %p2)

  int i;
  read_pipe( p1, &i );
  write_pipe( p2, &i );

}
