// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only -cl-std=CL2.0

// TODO: remove the note from diagnostics???
void myWrite(write_only image2d_t); // expected-note {{passing argument to parameter here}}
void myRead (read_only image2d_t); // expected-note {{passing argument to parameter here}}
void myReadWrite (read_write image2d_t);
void myIndifferent (image2d_t);


kernel void k1 (read_only image2d_t img) {
  myWrite(img); // expected-error {{passing '__read_only image2d_t' to parameter of incompatible type '__write_only image2d_t'}}
}

kernel void k2 (write_only image2d_t img) {
  myRead(img); // expected-error {{'__write_only image2d_t' to parameter of incompatible type '__read_only image2d_t'}}
}
