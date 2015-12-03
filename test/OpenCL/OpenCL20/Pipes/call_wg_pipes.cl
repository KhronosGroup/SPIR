// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -emit-llvm %s -o -| FileCheck %s

extern reserve_id_t my_mystery_function();

reserve_id_t test_call_read_pipe(pipe int Pipe) {
// CHECK: call %opencl.reserve_id_t* @_Z28work_group_reserve_read_pipePU3AS110ocl_pipe_tji(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 4, i32 4)
  return work_group_reserve_read_pipe(Pipe, 4U);
}

reserve_id_t test_call_write_pipe(pipe int Pipe) {
// CHECK: call %opencl.reserve_id_t* @_Z29work_group_reserve_write_pipePU3AS110ocl_pipe_tji(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 4, i32 4)
  return work_group_reserve_write_pipe(Pipe, 4U);
}

void test_call_commit_read(pipe int Pipe) {
  reserve_id_t id = my_mystery_function();
// CHECK: call void @_Z27work_group_commit_read_pipePU3AS110ocl_pipe_t16ocl_reserve_id_ti(%opencl.pipe_t addrspace(1)* %{{.*}}, %opencl.reserve_id_t* %{{.*}}, i32 4)
  work_group_commit_read_pipe(Pipe, id);
}

void test_call_commit_write(pipe int Pipe) {
  reserve_id_t id = my_mystery_function();
// CHECK: call void @_Z28work_group_commit_write_pipePU3AS110ocl_pipe_t16ocl_reserve_id_ti(%opencl.pipe_t addrspace(1)* %{{.*}}, %opencl.reserve_id_t* %{{.*}}, i32 4)
  work_group_commit_write_pipe(Pipe, id);
}
