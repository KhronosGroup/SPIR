// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -triple spir64-unknown-unknown -emit-llvm %s -o -| FileCheck %s

typedef union {
  unsigned char  Char;
  unsigned short Short;
  unsigned int   Int;
  unsigned long  Long;
} IntegerWidth;

kernel void test_reserved_write_pipe(global int *Dst, read_only pipe int OutPipe) {
  IntegerWidth iw;
  iw.Long = 0;
  // CHECK:  zext i8 %{{.*}} to i32
  // CHECK: call %opencl.reserve_id_t* @_Z18reserve_write_pipePU3AS110ocl_pipe_tji(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 %{{.*}}, i32 4)
  reserve_id_t id = reserve_write_pipe (OutPipe, iw.Char);
  // CHECK:  zext i16 %{{.*}} to i32
  // CHECK: call %opencl.reserve_id_t* @_Z18reserve_write_pipePU3AS110ocl_pipe_tji(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 %{{.*}}, i32 4)
  id = reserve_write_pipe (OutPipe, iw.Short);
  // CHECK: call %opencl.reserve_id_t* @_Z18reserve_write_pipePU3AS110ocl_pipe_tji(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 %{{.*}}, i32 4)
  id = reserve_write_pipe (OutPipe, iw.Int);
  // CHECK:  trunc i64 %{{.*}} to i32
  // CHECK: call %opencl.reserve_id_t* @_Z18reserve_write_pipePU3AS110ocl_pipe_tji(%opencl.pipe_t addrspace(1)* %{{.*}}, i32 %{{.*}}, i32 4)
  id = reserve_write_pipe (OutPipe, iw.Long);
}
