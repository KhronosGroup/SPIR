// RUN: %clang_cc1 -verify -pedantic -fsyntax-only -cl-std=CL1.2 %s
// RUN: %clang_cc1 -verify -pedantic -fsyntax-only -cl-std=CL2.0 %s

typedef image1d_t img1d_ro_default; // expected-note {{previously declared 'read_only' here}}

typedef write_only image1d_t img1d_wo; // expected-note {{previously declared 'write_only' here}}
typedef read_only image1d_t img1d_ro;

#if __OPENCL_C_VERSION__ >= 200
typedef read_write image1d_t img1d_rw;
#endif

#if __OPENCL_C_VERSION__ >= 200
typedef pipe int pipe_ro; // expected-note {{previously declared 'read_only' here}}
typedef write_only pipe int pipe_wo; // expected-note {{previously declared 'read_only' here}}
#endif

typedef int Int;
typedef read_only int IntRO; // expected-error {{access qualifier can only be used for pipe and image type}}


void myWrite(write_only image1d_t); // expected-note {{passing argument to parameter here}} expected-note {{passing argument to parameter here}}
void myRead(read_only image1d_t); // expected-note {{passing argument to parameter here}}

#if __OPENCL_C_VERSION__ >= 200
void myReadWrite(read_write image1d_t);
#else
void myReadWrite(read_write image1d_t); // expected-error {{image type cannot be used with the __read_write access qualifer which is reserved for future use by OpenCL 1.2}}
#endif

#if __OPENCL_C_VERSION__ >= 200
void myPipeRead(read_only pipe int p);
void myPipeWrite(write_only pipe int p);
#endif


kernel void k1(img1d_wo img) {
  myRead(img); // expected-error {{passing 'img1d_wo' (aka '__write_only image1d_t') to parameter of incompatible type '__read_only image1d_t'}}
}

kernel void k2(img1d_ro img) {
  myWrite(img); // expected-error {{passing 'img1d_ro' (aka '__read_only image1d_t') to parameter of incompatible type '__write_only image1d_t'}}
}

kernel void k3(img1d_wo img) {
  myWrite(img);
}

#if __OPENCL_C_VERSION__ >= 200
kernel void k4(img1d_rw img) {
  myReadWrite(img);
}
#endif

kernel void k5(img1d_ro_default img) {
  myWrite(img); // expected-error {{passing 'img1d_ro_default' (aka '__read_only image1d_t') to parameter of incompatible type '__write_only image1d_t'}}
}

kernel void k6(img1d_ro img) {
  myRead(img);
}

kernel void k7(read_only img1d_wo img){} // expected-error {{multiple access qualifiers}}

kernel void k8(write_only img1d_ro_default img){} // expected-error {{multiple access qualifiers}}

kernel void k9(read_only int i){} // expected-error {{access qualifier can only be used for pipe and image type}}

kernel void k10(read_only Int img){} // expected-error {{access qualifier can only be used for pipe and image type}}

kernel void k11(read_only write_only image1d_t i){} // expected-error {{multiple access qualifiers}}

kernel void k12(read_only read_only image1d_t i){} // expected-warning {{duplicate 'read_only' declaration specifier}}

#if __OPENCL_C_VERSION__ >= 200
kernel void k13(read_write pipe int i){} // expected-error {{read_write access qualifier can't be specified for pipes}}
#else
kernel void k13(__read_write image1d_t i){} // expected-error {{image type cannot be used with the __read_write access qualifer which is reserved for future use by OpenCL 1.2}}
#endif


#if __OPENCL_C_VERSION__ >= 200
kernel void k14(write_only pipe_ro p) {} // expected-error {{multiple access qualifiers}}
kernel void k15(read_only pipe_wo p) {} // expected-error {{multiple access qualifiers}}

kernel void k16(pipe_ro p) {
  myPipeRead(p);
}

kernel void k17(pipe_wo p) {
  myPipeWrite(p);
}
#endif

