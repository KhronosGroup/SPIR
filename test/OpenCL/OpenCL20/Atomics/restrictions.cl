// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -fsyntax-only -verify  %s

extern void f_atomici(atomic_int);
extern void f_atomicPi(atomic_int*);

#define ATOMIC_VAR_INIT(X) X

void test_atomic_arithmetics() {

  atomic_int ai = 0; // expected-error {{initialization of atomic variables is restricted to variables in global address space}}
  static global atomic_int gi = ATOMIC_VAR_INIT(42);
  atomic_int ai2;

  ai2 + 2;         // expected-error {{invalid operands to binary expression (atomic_int and int)}}
  2 + ai2;         // expected-error {{invalid operands to binary expression (int and atomic_int)}}
  ai2 + ai2;       // expected-error {{invalid operands to binary expression (atomic_int and atomic_int}}

  ai2 * 2;         // expected-error {{invalid operands to binary expression (atomic_int and int)}}
  2 * ai2;         // expected-error {{invalid operands to binary expression (int and atomic_int)}}
  ai2 * ai2;       // expected-error {{invalid operands to binary expression (atomic_int and atomic_int)}}

  ai2 - 2;         // expected-error {{invalid operands to binary expression (atomic_int and int)}}
  2 - ai2;         // expected-error {{invalid operands to binary expression (int and atomic_int)}}
  ai2 - ai2;       // expected-error {{invalid operands to binary expression (atomic_int and atomic_int)}}

  ai2 / 2;         // expected-error {{invalid operands to binary expression (atomic_int and int)}}
  2 / ai2;         // expected-error {{invalid operands to binary expression (int and atomic_int)}}
  ai2 / ai2;       // expected-error {{invalid operands to binary expression (atomic_int and atomic_int)}}

  ai2++;           // expected-error {{invalid argument type atomic_int to unary expression}}
  ++ai2;           // expected-error {{invalid argument type atomic_int to unary expression}}
  ai2--;           // expected-error {{invalid argument type atomic_int to unary expression}}
  --ai2;           // expected-error {{invalid argument type atomic_int to unary expression}}
}

void test_atomic_ref_operations() {
  atomic_int *P = 0;
  // We allow atomic deref, although its useless.
  f_atomici(P[0]);
  f_atomici(*P);
}

// This should compile OK.
void test_legal_subscript() {
  atomic_int arr[2];
  atomic_int *P = &arr[0];
  f_atomicPi(&arr[0]);
}

// This should compile OK.
global atomic_int a = 0;

kernel void test_global_assignment(global atomic_int *PI) {
  a = *PI; // expected-error {{atomic variables can only be assigned to compile time constants, in their definition statement}}
}

void test_assignment(atomic_int *PI) {
  atomic_int AI = *PI; // expected-error {{initialization of atomic variables is restricted to variables in global address space}}
}
