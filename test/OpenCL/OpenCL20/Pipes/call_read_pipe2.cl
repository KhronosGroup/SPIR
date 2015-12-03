// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -emit-llvm %s -o -| FileCheck %s

kernel void test_reserved_read_pipe(global int *Dst, read_only pipe int OutPipe) {
  // CHECK: call i32 @_Z9read_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  read_pipe (OutPipe, Dst);
}
