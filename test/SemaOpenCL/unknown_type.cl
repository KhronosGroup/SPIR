// RUN: %clang_cc1 -cl-std=CL1.1 -fsyntax-only -verify %s
typedef double double2 __attribute__((ext_vector_type(2)));   // expected-error {{use of type 'double' requires cl_khr_fp64 extension to be enabled}}
typedef double double16 __attribute__((ext_vector_type(16))); // expected-error {{use of type 'double' requires cl_khr_fp64 extension to be enabled}}
#pragma OPENCL EXTENSION all : disable
void foo()
{
    (double)(3.14); // expected-error {{use of type 'double' requires cl_khr_fp64 extension to be enabled}}
    (double2)(1.0, 3.14); // expected-error {{use of type 'double2' (vector of 2 'double' values) requires cl_khr_fp64 extension to be enabled}}
    (double16)(123455.134,123455.134,2.0,-12345.032,-12345.032,1.0,1.0,2.0,2.0,0.0,0.0,0.0,-1.23,-1.23,1.0,123455.134); // expected-error {{use of type 'double16' (vector of 16 'double' values) requires cl_khr_fp64 extension to be enabled}}
}
