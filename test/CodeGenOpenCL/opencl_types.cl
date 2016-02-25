// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 | FileCheck %s
// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 -cl-keep-sampler-type | FileCheck -check-prefix CHECK-SAMPLER-TYPE %s

constant sampler_t glb_smp = 7;
// CHECK: constant i32 7
// CHECK-SAMPLER-TYPE: constant %opencl.sampler_t { i32 7 }

void fnc1(image1d_t img) {}
// CHECK: @fnc1(%opencl.image1d_t {{.*}}*

void fnc1arr(image1d_array_t img) {}
// CHECK: @fnc1arr(%opencl.image1d_array_t {{.*}}*

void fnc1buff(image1d_buffer_t img) {}
// CHECK: @fnc1buff(%opencl.image1d_buffer_t {{.*}}*

void fnc2(image2d_t img) {}
// CHECK: @fnc2(%opencl.image2d_t {{.*}}*

void fnc2arr(image2d_array_t img) {}
// CHECK: @fnc2arr(%opencl.image2d_array_t {{.*}}*

void fnc3(image3d_t img) {}
// CHECK: @fnc3(%opencl.image3d_t {{.*}}*

void fnc4smp(sampler_t s) {}
// CHECK: define spir_func void @fnc4smp(i32
// CHECK-SAMPLER-TYPE: define spir_func void @fnc4smp(%opencl.sampler_t* byval

kernel void foo(image1d_t img) {
// CHECK: define spir_kernel void @foo(%opencl.image1d_t {{.*}}*
// CHECK-SAMPLER-TYPE: define spir_kernel void @foo(%opencl.image1d_t {{.*}}*

  sampler_t smp = 5;
  // CHECK: alloca i32
  // CHECK-SAMPLER-TYPE: [[SMP_PTR:%[A-Za-z0-9_\.]+]] = alloca %opencl.sampler_t

	event_t evt;
  // CHECK: alloca %opencl.event_t*

  fnc4smp(smp);
  // CHECK: store i32 5,
  // CHECK: call spir_func void @fnc4smp(i32
  // CHECK-SAMPLER-TYPE: store %opencl.sampler_t { i32 5 }, %opencl.sampler_t* [[SMP_PTR]]
  // CHECK-SAMPLER-TYPE: call spir_func void @fnc4smp(%opencl.sampler_t* byval [[SMP_PTR]])

  fnc4smp(glb_smp);
  // CHECK: call spir_func void @fnc4smp(i32
  // CHECK-SAMPLER-TYPE: [[SMP:%[A-Za-z0-9_\.]+]] = load %opencl.sampler_t addrspace(2)* @glb_smp
  // CHECK-SAMPLER-TYPE: store %opencl.sampler_t [[SMP]], %opencl.sampler_t* [[TMP:%[A-Za-z0-9_\.]+]]
  // CHECK-SAMPLER-TYPE: call spir_func void @fnc4smp(%opencl.sampler_t* byval [[TMP]])
}

void __attribute__((overloadable)) bad1(image1d_t b, image2d_t c, image2d_t d) {}
// CHECK-LABEL: @{{_Z4bad111ocl_image1d11ocl_image2d11ocl_image2d|"\\01\?bad1@@YAXPAUocl_image1d@@PAUocl_image2d@@1@Z"}}
