// RUN: %clang_cc1 %s -emit-llvm -o - -O0 | FileCheck %s

// CHECK: %opencl.sampler_t = type { i32 }

constant sampler_t glb_smp = 7;
// CHECK: @glb_smp = addrspace(2) global %opencl.sampler_t { i32 7 }

void fnc1(image1d_t img) {}
// CHECK: @fnc1(%opencl.image1d_t addrspace(1)*

void fnc1arr(image1d_array_t img) {}
// CHECK: @fnc1arr(%opencl.image1d_array_t addrspace(1)*

void fnc1buff(image1d_buffer_t img) {}
// CHECK: @fnc1buff(%opencl.image1d_buffer_t addrspace(1)*

void fnc2(image2d_t img) {}
// CHECK: @fnc2(%opencl.image2d_t addrspace(1)*

void fnc2arr(image2d_array_t img) {}
// CHECK: @fnc2arr(%opencl.image2d_array_t addrspace(1)*

void fnc3(image3d_t img) {}
// CHECK: @fnc3(%opencl.image3d_t addrspace(1)*

void fnc4smp(sampler_t s) {}
// CHECK-LABEL: define void @fnc4smp(%opencl.sampler_t* byval

kernel void foo(image1d_t img) {
	sampler_t smp = 5;
// CHECK: alloca %opencl.sampler_t
	event_t evt;
// CHECK: alloca %opencl.event_t*
  fnc4smp(smp);
// CHECK: call void @fnc4smp(%opencl.sampler_t* byval
  fnc4smp(glb_smp);
// CHECK: call void @fnc4smp(%opencl.sampler_t* byval
}
