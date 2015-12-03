// RUN: %clang_cc1 -emit-llvm -O0 -cl-std=CL2.0 -o - %s | FileCheck %s

// CHECK: %opencl.pipe_t = type opaque

void test1(read_only pipe int p) {
// CHECK: define void @test1(%opencl.pipe_t addrspace(1)* %p)
  reserve_id_t rid;
// CHECK: %rid = alloca %opencl.reserve_id_t
}

void test2(write_only pipe float p) {
// CHECK: define void @test2(%opencl.pipe_t addrspace(1)* %p)
  reserve_id_t rid;
}
