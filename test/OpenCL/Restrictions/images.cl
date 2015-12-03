// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only

void myWrite(write_only image2d_t);
void myRead (read_only image2d_t);
void myReadWrite (read_write image2d_t);
void myIndifferent (image2d_t);


kernel void k1 (read_only image2d_t img) {
  myWrite(img); // expected-error {{passing ''read_only'' to ''write_only'' mismatch access qualifiers}}
}

kernel void k2 (write_only image2d_t img) {
  myRead(img); // expected-error {{passing ''write_only'' to ''read_only'' mismatch access qualifiers}}
}

// Should be all OK.
kernel void k3 (read_write image2d_t img) {
  myRead(img);  // read_write > read_only
  myWrite(img); // read_write > write_only
  myReadWrite(img); //read_write = read_write
}

// Legal to path everything to an 'indifferent' function.
kernel void k4(read_write image2d_t i1, read_only image2d_t i2,
               write_only image2d_t i3) {
  myIndifferent(i1);
  myIndifferent(i2);
  myIndifferent(i3);
}
