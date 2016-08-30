// RUN: %clang_cc1 -verify -pedantic -fsyntax-only -cl-std=CL1.2 %s
// RUN: %clang_cc1 -verify -pedantic -fsyntax-only -cl-std=CL2.0 %s

typedef int Int;
typedef read_only int IntRO; // expected-error {{access qualifier can only be used for pipe and image type}}

void myWrite(write_only image1d_t);
void myRead(read_only image1d_t);
#if __OPENCL_C_VERSION__ < 200
void myReadWrite(read_write image1d_t); // expected-error {{image type cannot be used with the __read_write access qualifer which is reserved for future use by OpenCL 1.2}}
#endif

typedef image1d_t img1d_ro_default;
typedef read_only image1d_t img1d_ro;
typedef write_only image1d_t img1d_wo;

kernel void k1(img1d_ro_default img_ro_default,
               img1d_wo img_wo,
               img1d_ro img_ro) {
  myWrite(img_ro_default); // expected-error {{passing 'img1d_ro_default' (aka '__read_only image1d_t') to parameter of incompatible type '__write_only image1d_t'}}
  // expected-note@7 {{passing argument to parameter here}}
  myRead(img_wo);  // expected-error {{passing 'img1d_wo' (aka '__write_only image1d_t') to parameter of incompatible type '__read_only image1d_t'}}
  // expected-note@8 {{passing argument to parameter here}}
  myWrite(img_ro); // expected-error {{passing 'img1d_ro' (aka '__read_only image1d_t') to parameter of incompatible type '__write_only image1d_t'}}
  // expected-note@7 {{passing argument to parameter here}}
}

kernel void k2(write_only img1d_ro_default img){} // expected-error {{multiple access qualifiers}}
// expected-note@13 {{previously declared 'read_only' here}}
kernel void k3(write_only img1d_ro img){} // expected-error {{multiple access qualifiers}}
// expected-note@14 {{previously declared 'read_only' here}}
kernel void k4(read_only img1d_wo img){} // expected-error {{multiple access qualifiers}}
// expected-note@15 {{previously declared 'write_only' here}}
kernel void k5(read_only int i){} // expected-error {{access qualifier can only be used for pipe and image type}}
kernel void k6(read_only Int img){} // expected-error {{access qualifier can only be used for pipe and image type}}
kernel void k7(read_only write_only image1d_t i){} // expected-error {{multiple access qualifiers}}
kernel void k8(read_only read_only image1d_t i){} // expected-warning {{duplicate 'read_only' declaration specifier}}
kernel void k9(read_only img1d_ro_default i){} // expected-warning {{duplicate 'read_only' declaration specifier}}
// expected-note@13 {{previously declared 'read_only' here}}
kernel void k10(__read_only img1d_ro i){} // expected-warning {{duplicate '__read_only' declaration specifier}}
// expected-note@14 {{previously declared 'read_only' here}}
kernel void k11(write_only write_only image1d_t i){} // expected-warning {{duplicate 'write_only' declaration specifier}}
kernel void k12(write_only img1d_wo i){} // expected-warning {{duplicate 'write_only' declaration specifier}}
// expected-note@15 {{previously declared 'write_only' here}}

#if __OPENCL_C_VERSION__ >= 200
void myReadWrite(read_write image1d_t);
typedef read_write image1d_t img1d_rw;
kernel void k13(img1d_ro img_r, img1d_wo img_w) {
  myReadWrite(img_r); // expected-error {{passing 'img1d_ro' (aka '__read_only image1d_t') to parameter of incompatible type '__read_write image1d_t'}}
  // expected-note@47 {{passing argument to parameter here}}
  myReadWrite(img_w); // expected-error {{passing 'img1d_wo' (aka '__write_only image1d_t') to parameter of incompatible type '__read_write image1d_t'}}
  // expected-note@47 {{passing argument to parameter here}}
}
kernel void k14(read_write img1d_rw i){} // expected-warning {{duplicate 'read_write' declaration specifier}}
// expected-note@48 {{previously declared 'read_write' here}}

#endif
