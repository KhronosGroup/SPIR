// XFAIL: *
// temporary disabled
// RUN: %clang_cc1 -verify %s

kernel void no_ptrptr(global int **i) { } // expected-error{{kernel parameter cannot be declared as a pointer to a pointer}}

kernel int bar()  { // expected-error {{kernel must have void return type}}
  return 6;
}

kernel void main() { // expected-error {{kernel cannot be called 'main'}}

}

int main() { // expected-error {{function cannot be called 'main'}}
  return 0;
}
