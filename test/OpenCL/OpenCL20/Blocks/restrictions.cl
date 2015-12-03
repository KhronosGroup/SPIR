// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -fsyntax-only -verify %s

extern int random();

int (^BlkVariadic)(int, ...) = ^int(int I, ...) { // expected-error {{Invalid block prototype, variadic arguments are not allowed}}
   return 0;
};

typedef int (^BlkInt)(int);

void f1() {
  BlkInt B1 = ^int(int I) {return 1;};
  BlkInt B2 = ^int(int I) {return 2;};
  BlkInt Arr[] = {B1, B2}; // expected-error {{Array of block is invalid in OpenCL}}
}

void f2(BlkInt *BlockPtr) {
  BlkInt B = ^int(int I) {return 1;};
  BlkInt *P = &B; // expected-error {{invalid argument type 'BlkInt' (aka 'int (^)(int)') to unary expression}}
  B = *BlockPtr;  // expected-error {{dereferencing pointer of type '__generic BlkInt *' (aka 'int (^__generic *)(int)') is not allowed}}
}

int f3() {
  BlkInt B1 = ^int(int I) {return 1;};
  BlkInt B2 = ^int(int I) {return 2;};
  int R = random();
  return (R % 2) ? B1(R)  // expected-error {{blocks cannot be used as expressions in ternary expressions}}
                 : B2(R); // expected-error {{blocks cannot be used as expressions in ternary expressions}}
}
