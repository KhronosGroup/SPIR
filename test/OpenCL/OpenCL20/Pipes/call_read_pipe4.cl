// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -triple spir64-unknown-unknown -emit-llvm %s -o - | FileCheck %s

reserve_id_t my_mystery_function();

typedef union {
  unsigned char  Char;
  unsigned short Short;
  unsigned int   Int;
  unsigned long  Long;
} IntegerWidth;

kernel void test_read_pipe(global int *Dst, read_only pipe int Pipe) {
  reserve_id_t ID = my_mystery_function();
  IntegerWidth iw;
  iw.Long = 0;
// CHECK:  zext i8 %{{.*}} to i32
// CHECK:  call i32 @_Z9read_pipePU3AS110ocl_pipe_t16ocl_reserve_id_tjPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, %opencl.reserve_id_t* %{{.*}}, i32 %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  read_pipe (Pipe, ID, iw.Char, Dst);
// CHECK:  zext i16 %{{.*}} to i32
// CHECK:  call i32 @_Z9read_pipePU3AS110ocl_pipe_t16ocl_reserve_id_tjPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, %opencl.reserve_id_t* %{{.*}}, i32 %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  read_pipe (Pipe, ID, iw.Short, Dst);
// CHECK:  call i32 @_Z9read_pipePU3AS110ocl_pipe_t16ocl_reserve_id_tjPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, %opencl.reserve_id_t* %{{.*}}, i32 %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  read_pipe (Pipe, ID, iw.Int, Dst);
// CHECK:  trunc i64 %{{.*}} to i32
// CHECK:  call i32 @_Z9read_pipePU3AS110ocl_pipe_t16ocl_reserve_id_tjPU3AS4vi(%opencl.pipe_t addrspace(1)* %{{.*}}, %opencl.reserve_id_t* %{{.*}}, i32 %{{.*}}, i8 addrspace(4)* %{{.*}}, i32 4)
  read_pipe (Pipe, ID, iw.Long, Dst);
}
