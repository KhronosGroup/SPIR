// RUN: %clang_cc1 -fsyntax-only -cl-std=CL1.2 %s
// RUN: %clang_cc1 -fsyntax-only -cl-std=CL2.0 %s

__kernel void f__ro(__read_only image2d_t a) { }

__kernel void f__wo(__write_only image2d_t a) { }

#if __OPENCL_C_VERSION__ >= 200
__kernel void f__rw(__read_write image2d_t a) { }
#endif

__kernel void fro(read_only image2d_t a) { }

__kernel void fwo(write_only image2d_t a) { }

#if __OPENCL_C_VERSION__ >= 200
__kernel void frw(read_write image2d_t a) { }
#endif

