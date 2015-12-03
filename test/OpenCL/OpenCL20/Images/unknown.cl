// RUN: %clang_cc1 -O0 -cl-std=CL2.0  -fsyntax-only -verify %s
// expected-no-diagnostics
extern void myImageFunc(read_only image2d_t image);

void kernel k(image2d_t Img){
  myImageFunc(Img);
}
