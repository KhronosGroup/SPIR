// RUN: %clang_cc1 -O0 -cl-std=CL2.0  -fsyntax-only -verify %s
// TODO: This test is valid, but diagnostics is not implemented.
// XFAIL:*

void myImgFunction(read_only image2d_t, sampler_t);
void mySamplerlsessFunction(read_only image2d_t);

void kernel k(read_write image2d_t Img, sampler_t S) {
  myImgFunction(Img, S); // expected-error {{reading from an image declared with 'read_write' qualifier using a sampler is prohibited}}
  // This should be OK though.
  mySamplerlsessFunction(Img);
}
