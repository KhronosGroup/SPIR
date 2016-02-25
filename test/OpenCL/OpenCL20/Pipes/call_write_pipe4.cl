// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -emit-llvm %s -o - | FileCheck %s

reserve_id_t my_mystery_function();

kernel void test_write_pipe(global int *Src, write_only pipe int Pipe) {
  // CHECK: call i32 @_Z10write_pipePU3AS18ocl_pipe13ocl_reserveidjPU3AS4vjj(%opencl.pipe_t addrspace(1)* {{.*}}, %opencl.reserve_id_t* {{.*}}, i32 0, i8 addrspace(4)* {{.*}}, i32 4, i32 4)
  reserve_id_t ID = my_mystery_function();
  write_pipe (Pipe, ID, 0U, Src);
}
