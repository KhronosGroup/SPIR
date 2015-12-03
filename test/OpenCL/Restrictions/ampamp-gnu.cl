// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only

kernel void foo(global int *in) {
  int a;
  void *p = &&a; // expected-error {{OpenCL does not support address of label ('&&') GNU extension}}

  void *hlbl_tbl[] = { &&label1 }; // expected-error {{OpenCL does not support address of label ('&&') GNU extension}}
label1:
  a = 0;
}
