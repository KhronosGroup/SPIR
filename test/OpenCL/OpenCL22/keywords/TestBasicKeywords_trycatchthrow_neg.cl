// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o -

void error(int);

kernel void worker()
{
    try { //expected-error {{cannot use 'try' with exceptions disabled}}
        throw 0; //expected-error {{cannot use 'throw' with exceptions disabled}}
    } catch (int i) {
        error(i);
    }
}