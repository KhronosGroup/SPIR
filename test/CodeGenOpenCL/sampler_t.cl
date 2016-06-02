// RUN: %clang_cc1 %s -emit-spirv -triple spir-unknown-unknown -O0 -o %t.spv
// RUN: llvm-spirv -to-text %t.spv -o - | FileCheck %s

typedef int int2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));
#define const_func __attribute__((const))
float4 __attribute__((overloadable)) const_func read_imagef(__read_only image2d_t image, sampler_t sampler, int2 coord);

#define CLK_ADDRESS_NONE                0
#define CLK_ADDRESS_CLAMP_TO_EDGE       2
#define CLK_ADDRESS_CLAMP               4
#define CLK_ADDRESS_REPEAT              6
#define CLK_ADDRESS_MIRRORED_REPEAT     8
#define CLK_NORMALIZED_COORDS_FALSE     0
#define CLK_NORMALIZED_COORDS_TRUE      1
#define CLK_FILTER_NEAREST              0x10
#define CLK_FILTER_LINEAR               0x20

// CHECK: [[None:0]]
// CHECK: [[ClampToEdge:1]]
// CHECK: [[Clamp:2]]
// CHECK: [[Repeat:3]]
// CHECK: [[MirroredRepeat:4]]

// CHECK: [[NonNormalized:0]]
// CHECK: [[Normalized:1]]

// CHECK: [[Nearest:0]]
// CHECK: [[Linear:1]]

// CHECK: TypeInt [[TypeInt:[0-9]+]] 32 0
// CHECK: Constant [[TypeInt]] [[global_constant_int:[0-9]+]] 16
// CHECK: TypeSampler [[TypeSampler:[0-9]+]]
// CHECK: TypePointer [[TypeSamplerPtr_Constant:[0-9]+]] 0 [[TypeSampler]]
// CHECK: TypeImage [[TypeImage:[0-9]+]]
// CHECK: TypeSampledImage [[TypeSampledImage:[0-9]+]] [[TypeImage]]

// CHECK: ConstantSampler [[TypeSampler]] [[global_const_sampler_INIT:[0-9]+]] [[Clamp]] [[Normalized]] [[Linear]]
// CHECK: ConstantSampler [[TypeSampler]] [[global_constant_sampler_INIT:[0-9]+]] [[Repeat]] [[NonNormalized]] [[Linear]]

// CHECK: ConstantSampler [[TypeSampler]] [[read_imagef_literal_arg:[0-9]+]] [[Repeat]] [[NonNormalized]] [[Linear]]

// CHECK: ConstantSampler [[TypeSampler]] [[const_sampler_INIT:[0-9]+]] [[Repeat]] [[Normalized]] [[Nearest]]
// CHECK: ConstantSampler [[TypeSampler]] [[constant_sampler_INIT:[0-9]+]] [[Clamp]] [[Normalized]] [[Nearest]]
// CHECK: ConstantSampler [[TypeSampler]] [[constant_sampler_init_by_const_int_INIT:[0-9]+]] [[Clamp]] [[Normalized]] [[Linear]]

// CHECK: ConstantSampler [[TypeSampler]] [[init_by_const_int_INIT:[0-9]+]] [[Clamp]] [[Normalized]] [[Linear]]
// CHECK: ConstantSampler [[TypeSampler]] [[init_by_constant_int_INIT:[0-9]+]] [[MirroredRepeat]] [[Normalized]] [[Linear]]
// CHECK: ConstantSampler [[TypeSampler]] [[init_by_literal_int_INIT:[0-9]+]] [[Clamp]] [[NonNormalized]] [[Linear]]

// CHECK: ConstantSampler [[TypeSampler]] [[global_const_sampler_INIT2:[0-9]+]] [[Clamp]] [[Normalized]] [[Linear]]
// CHECK: ConstantSampler [[TypeSampler]] [[global_constant_sampler_INIT2:[0-9]+]] [[Repeat]] [[NonNormalized]] [[Linear]]
// CHECK: ConstantSampler [[TypeSampler]] [[global_constant_int_INIT:[0-9]+]] [[None]] [[NonNormalized]] [[Nearest]]

// CHECK: ConstantSampler [[TypeSampler]] [[const_sampler_INIT2:[0-9]+]] [[Repeat]] [[Normalized]] [[Nearest]]
// CHECK: ConstantSampler [[TypeSampler]] [[constant_sampler_INIT2:[0-9]+]] [[Clamp]] [[Normalized]] [[Nearest]]


// CHECK: ConstantSampler [[TypeSampler]] [[init_by_literal_int_INIT2:[0-9]+]] [[Clamp]] [[NonNormalized]] [[Linear]]

// CHECK: ConstantSampler [[TypeSampler]] [[const_int_INIT2:[0-9]+]] [[Clamp]] [[Normalized]] [[Linear]]
// CHECK: ConstantSampler [[TypeSampler]] [[constant_int_INIT2:[0-9]+]] [[MirroredRepeat]] [[Normalized]] [[Linear]]
// CHECK: ConstantSampler [[TypeSampler]] [[literal_int_INIT:[0-9]+]] [[Repeat]] [[Normalized]] [[Linear]]

const sampler_t global_const_sampler = CLK_ADDRESS_CLAMP | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_LINEAR;
// CHECK: Variable [[TypeSamplerPtr_Constant]] [[global_const_sampler:[0-9]+]] 0 [[global_const_sampler_INIT]]

constant sampler_t global_constant_sampler = CLK_ADDRESS_REPEAT | CLK_NORMALIZED_COORDS_FALSE | CLK_FILTER_LINEAR;
// CHECK: Variable [[TypeSamplerPtr_Constant]] [[global_constant_sampler:[0-9]+]] 0 [[global_constant_sampler_INIT]]

// CHECK: Variable [[TypeSamplerPtr_Constant]] [[constant_sampler_init_by_const_int:[0-9]+]] 0 [[constant_sampler_init_by_const_int_INIT]]

__constant int global_constant_int = CLK_ADDRESS_NONE | CLK_NORMALIZED_COORDS_FALSE | CLK_FILTER_NEAREST;

void foofoo(sampler_t sampler){}
// CHECK: Function {{[0-9]+}} [[foofoo:[0-9]+]]
// CHECK: FunctionParameter [[TypeSampler]]

void foo(sampler_t sampler) {
// CHECK: Function {{[0-9]+}} [[foo:[0-9]+]]
// CHECK: FunctionParameter [[TypeSampler]] [[sampler_fun_arg:[0-9]+]]

  foofoo(sampler);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foofoo]] [[sampler_fun_arg]]
}

__kernel void bar(sampler_t sampler_kernel_arg, image2d_t image) {
// CHECK: Function
// CHECK: FunctionParameter [[TypeSampler]] [[sampler_kernel_arg:[0-9]+]]
// CHECK: FunctionParameter [[TypeImage]] [[image:[0-9]+]]

    float4 a = read_imagef(image, sampler_kernel_arg, (int2)(1,2));
// CHECK: SampledImage [[TypeSampledImage]] [[SampledImage:[0-9]+]] [[image]] [[sampler_kernel_arg]]
// CHECK: ImageSampleExplicitLod {{[0-9]+}} {{[0-9]+}} [[SampledImage]]

    float4 b = read_imagef(image, CLK_ADDRESS_REPEAT | CLK_NORMALIZED_COORDS_FALSE | CLK_FILTER_LINEAR, (int2)(1,2));
// CHECK: SampledImage [[TypeSampledImage]] [[SampledImage:[0-9]+]] [[image]] [[read_imagef_literal_arg]]
// CHECK: ImageSampleExplicitLod {{[0-9]+}} {{[0-9]+}} [[SampledImage]]

       const int const_int    = CLK_ADDRESS_CLAMP | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_LINEAR;
    constant int constant_int = CLK_ADDRESS_MIRRORED_REPEAT | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_LINEAR;

       const sampler_t const_sampler = CLK_ADDRESS_REPEAT | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_NEAREST;
  __constant sampler_t constant_sampler = CLK_ADDRESS_CLAMP | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_NEAREST;
    constant sampler_t constant_sampler_init_by_const_int = const_int;

    sampler_t init_by_const_int = const_int;
    sampler_t init_by_constant_int = constant_int;
    sampler_t init_by_literal_int = CLK_ADDRESS_CLAMP | CLK_NORMALIZED_COORDS_FALSE | CLK_FILTER_LINEAR;

    foo(sampler_kernel_arg);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[sampler_kernel_arg]]

    foo(global_const_sampler);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[global_const_sampler_INIT2]]
    foo(global_constant_sampler);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[global_constant_sampler_INIT2]]
    foo(global_constant_int);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[global_constant_int_INIT]]

    foo(const_sampler);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[const_sampler_INIT2]]
    foo(constant_sampler);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[constant_sampler_INIT2]]
    foo(constant_sampler_init_by_const_int);
// CHECK: Load [[TypeSampler]] [[const_int_INIT:[0-9]+]] [[constant_sampler_init_by_const_int]] 
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[const_int_INIT]]

    foo(init_by_const_int);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[init_by_const_int_INIT]]
    foo(init_by_constant_int);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[init_by_constant_int_INIT]]
    foo(init_by_literal_int);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[init_by_literal_int_INIT2]]

    foo(const_int);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[const_int_INIT2]]
    foo(constant_int);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[constant_int_INIT2]]
    foo(CLK_ADDRESS_REPEAT | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_LINEAR);
// CHECK: FunctionCall {{[0-9]+}} {{[0-9]+}} [[foo]] [[literal_int_INIT]]
}
