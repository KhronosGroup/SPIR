// RUN: %clang_cc1 -O0 -cl-std=CL2.0  -emit-llvm %s -o -| FileCheck %s

reserve_id_t my_mystery_function();

kernel void test_reserved_commit_read_pipe(read_only pipe int Pipe) {
  reserve_id_t ID = my_mystery_function();
// CHECK: call void @_Z16commit_read_pipePU3AS110ocl_pipe_t16ocl_reserve_id_ti(%opencl.pipe_t addrspace(1)* %{{.*}}, %opencl.reserve_id_t* %{{.*}}, i32 4)
  commit_read_pipe (Pipe, ID);
}
