// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 -cl-sampler-type i32 | FileCheck %s
// RUN: %clang_cc1 %s -emit-llvm -triple spir-unknown-unknown -o - -O0 | FileCheck -check-prefix CHECK-SAMPLER-TYPE %s

#define CLK_ADDRESS_CLAMP_TO_EDGE       2
#define CLK_NORMALIZED_COORDS_TRUE      1
#define CLK_FILTER_NEAREST              0x10
#define CLK_FILTER_LINEAR               0x20

constant sampler_t glb_smp = CLK_ADDRESS_CLAMP_TO_EDGE | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_LINEAR;;
// CHECK: constant i32 35
// CHECK-SAMPLER-TYPE: %spirv.ConstantSampler = type { i32, i32, i32 }
// CHECK-SAMPLER-TYPE: %spirv.Sampler = type opaque

// CHECK-SAMPLER-TYPE: [[glb_smp_init:@[-a-zA-Z$._][-a-zA-Z$._0-9]*]] = internal addrspace(2) constant %spirv.ConstantSampler { i32 1, i32 1, i32 1 }
// CHECK-SAMPLER-TYPE: @glb_smp = addrspace(2) constant %spirv.Sampler addrspace(2)* bitcast (%spirv.ConstantSampler addrspace(2)* [[glb_smp_init]] to %spirv.Sampler addrspace(2)*)
// CHECK-SAMPLER-TYPE: [[smp_init:@[-a-zA-Z$._][-a-zA-Z$._0-9]*]] = internal addrspace(2) constant %spirv.ConstantSampler { i32 1, i32 1, i32 0 }
// CHECK-SAMPLER-TYPE: [[smp_arg:@[-a-zA-Z$._][-a-zA-Z$._0-9]*]] = internal addrspace(2) constant %spirv.ConstantSampler { i32 1, i32 1, i32 0 }
// CHECK-SAMPLER-TYPE: [[glb_smp_arg:@[-a-zA-Z$._][-a-zA-Z$._0-9]*]] = internal addrspace(2) constant %spirv.ConstantSampler { i32 1, i32 1, i32 1 }

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
// CHECK-SAMPLER-TYPE: define spir_func void @fnc4smp(%spirv.Sampler addrspace(2)* %

kernel void foo(image1d_t img) {
// CHECK: define spir_kernel void @foo(%opencl.image1d_t {{.*}}*
// CHECK-SAMPLER-TYPE: define spir_kernel void @foo(%opencl.image1d_t {{.*}}*

  sampler_t smp = CLK_ADDRESS_CLAMP_TO_EDGE | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_NEAREST;
  // CHECK: alloca i32
  // CHECK-SAMPLER-TYPE: [[smp_ptr:%[A-Za-z0-9_\.]+]] = alloca %spirv.Sampler addrspace(2)*
  // CHECK-SAMPLER-TYPE: store %spirv.Sampler addrspace(2)* bitcast (%spirv.ConstantSampler addrspace(2)* [[smp_init]] to %spirv.Sampler addrspace(2)*), %spirv.Sampler addrspace(2)** [[smp_ptr]], align 4

  event_t evt;
  // CHECK: alloca %opencl.event_t*

  fnc4smp(smp);
  // CHECK: store i32 19,
  // CHECK: call spir_func void @fnc4smp(i32
  // CHECK-SAMPLER-TYPE: call spir_func void @fnc4smp(%spirv.Sampler addrspace(2)* bitcast (%spirv.ConstantSampler addrspace(2)* [[smp_arg]] to %spirv.Sampler addrspace(2)*))

  fnc4smp(glb_smp);
  // CHECK: call spir_func void @fnc4smp(i32
  // CHECK-SAMPLER-TYPE: call spir_func void @fnc4smp(%spirv.Sampler addrspace(2)* bitcast (%spirv.ConstantSampler addrspace(2)* [[glb_smp_arg]] to %spirv.Sampler addrspace(2)*))
}

void __attribute__((overloadable)) bad1(image1d_t b, image2d_t c, image2d_t d) {}
// CHECK-LABEL: @{{_Z4bad111ocl_image1d11ocl_image2d11ocl_image2d|"\\01\?bad1@@YAXPAUocl_image1d@@PAUocl_image2d@@1@Z"}}
