//RUN: %clang_cc1 -O0 -cl-std=CL2.0 -fsyntax-only -verify %s

extern int counter();

kernel void B (global int *x) {
  __attribute__((opencl_unroll_hint(42)))
  if (x[0])                             // expected-error {{OpenCL only supports opencl_unroll_hint on for, while, and do statements}}
    x[0] = 15;
}

kernel void C (global int *x) {
  int I = 3;
  __attribute__((opencl_unroll_hint(I))) // expected-error {{opencl_unroll_hint attribute requires an integer constant}}
  while (I--)
    x[I] = I;
}

kernel void D (global int *x) {
  int i;

  __attribute__((opencl_unroll_hint))
  do {
    i = counter();
    x[i] = i;
  } while(i);
}

kernel void E() {
  __attribute__((opencl_unroll_hint(-2))) // expected-error {{opencl_unroll_hint requires a positive integral compile time constant expression}}
  for(int i=0; i<100; i++);
}
