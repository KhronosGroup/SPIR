// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

int count=0;
class O { // ...
public: 
  operator int(){ return ++iO; }
  O() : iO(count++) {}
  int iO;
};

void g(O a, O b) {
  int i = (a) ? 1+a : 0; 
}
