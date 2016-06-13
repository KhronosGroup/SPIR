// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify

__constant int a = 1;
int b = 2;
__constant int c = b; // expected-error{{variable 'c' in the constant address space must be initialized by a constant expression}}
//expected-note@TestAddrSpaceQualConstantNeg.cl:* {{read of non-const variable}}*
//expected-note@TestAddrSpaceQualConstantNeg.cl:* {{declared here}}*


kernel void worker_constant_assign()
{
    a = 2; // expected-error{{read-only variable is not assignable}}
}

