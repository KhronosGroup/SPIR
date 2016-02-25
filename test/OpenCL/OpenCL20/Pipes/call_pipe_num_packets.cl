// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -emit-llvm %s -o -| FileCheck %s

void test_call_get_num_packets(pipe int Pipe, global unsigned int *N) {
  *N = get_pipe_num_packets(Pipe);
// CHECK: call i32 @_Z20get_pipe_num_packetsPU3AS18ocl_pipejj(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 4, i32 4)
}

void test_call_get_max_packets(pipe int Pipe, global unsigned *N) {
  *N = get_pipe_max_packets(Pipe);
// CHECK: call i32 @_Z20get_pipe_max_packetsPU3AS18ocl_pipejj(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 4, i32 4)
}
