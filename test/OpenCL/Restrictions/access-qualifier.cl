// RUN: %clang_cc1 -verify -pedantic -fsyntax-only -cl-std=CL1.2 %s
// RUN: %clang_cc1 -verify -pedantic -fsyntax-only -cl-std=CL2.0 %s
// expected-no-diagnostics

void myWrite(write_only image1d_t);
void myRead(read_only image1d_t);

typedef image1d_t img1d_ro_default;
kernel void k1(img1d_ro_default img) {
  myRead(img);
}

typedef write_only image1d_t img1d_wo;
kernel void k2(img1d_wo img) {
  myWrite(img);
}

typedef read_only image1d_t img1d_ro;
kernel void k3(img1d_ro img) {
  myRead(img);
}

#if __OPENCL_C_VERSION__ >= 200
void myReadWrite(read_write image1d_t);
void myPipeRead(read_only pipe int p);
void myPipeWrite(write_only pipe int p);

typedef read_write image1d_t img1d_rw;
kernel void k4(img1d_rw img) {
  myReadWrite(img);
}

#endif

