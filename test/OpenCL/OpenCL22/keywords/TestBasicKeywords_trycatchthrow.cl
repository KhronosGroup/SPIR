// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o -

#define try bool __error = false; do //expected-warning{{keyword is hidden by macro definition}}
#define throw __error = true; break; //expected-warning{{keyword is hidden by macro definition}}
#define catch(x) while (false); if (__error) //expected-warning{{keyword is hidden by macro definition}}

void error_hnd();

kernel void worker()
{
    try {
        int i = 1;
        throw;
    } catch (...) {
        error_hnd();
    }
}
