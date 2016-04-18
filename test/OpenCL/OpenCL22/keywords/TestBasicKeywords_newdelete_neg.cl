// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o -

#include "../opencl_def"

class Test
{
    int i;
};

class DeletedTest
{
    int i;
    void* operator new(size_t) = delete;
};

kernel void worker()
{
    Test* t = new Test; //expected-error {{no matching function for call to 'operator new'}}
    delete t; //expected-error {{no matching function for call to 'operator delete'}}
    
    DeletedTest* t2 = new DeletedTest; //expected-error {{call to deleted function 'operator new'}} expected-note@13{{candidate function has been explicitly deleted}}
    delete[] t2; //expected-error {{no matching function for call to 'operator delete[]'}}
}
