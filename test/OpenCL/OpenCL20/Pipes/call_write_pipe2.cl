// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -emit-llvm %s -o - | FileCheck %s

kernel void test_write_pipe(global int *Src, write_only pipe int Pipe) {
  // CHECK: call i32 @_Z10write_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  write_pipe (Pipe, Src);
}

kernel void test_twice_write_pipe(global int *Src, write_only pipe int Pipe) {
  // CHECK: call i32 @_Z10write_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  write_pipe (Pipe, Src);
  // CHECK: call i32 @_Z10write_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  write_pipe (Pipe, Src);
}

kernel void test_two_pipes(global int *Buf, write_only pipe int Pout, read_only pipe int Pin) {
  write_pipe(Pout, Buf);
  read_pipe(Pin, Buf);
}
