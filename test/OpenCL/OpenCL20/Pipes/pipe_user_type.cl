// RUN: %clang_cc1 -triple x86_64-unknown-unknown -O0 -cl-std=CL2.0 -emit-llvm %s -o -| FileCheck --check-prefix CHECK64 %s
// RUN: %clang_cc1 -triple i386-unknown-unknown -O0 -cl-std=CL2.0 -emit-llvm %s -o -| FileCheck  --check-prefix CHECK32 %s

struct Person {
  const char *Name;
  bool isFemale;
  int ID;
};

kernel void test_reserved_read_pipe(global struct Person *SDst,
                                    global int *IDst,
                                    read_only pipe struct Person SPipe,
                                    read_only pipe int IPipe) {
  read_pipe (SPipe, SDst);
  // CHECK64: call i32 @_Z9read_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 16)
  // CHECK32: call i32 @_Z9read_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 12)
  read_pipe (IPipe, IDst);
  // CHECK64: call i32 @_Z9read_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  read_pipe (SPipe, SDst);
  // CHECK64: call i32 @_Z9read_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 16)
  // CHECK32: call i32 @_Z9read_pipePU3AS110ocl_pipe_tPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 12)
}
