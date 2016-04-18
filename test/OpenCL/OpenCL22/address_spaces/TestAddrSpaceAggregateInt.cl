// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify -emit-llvm -O0 -o /dev/null
// expected-no-diagnostics

struct Unit
{
  Unit() {}
  Unit(const Unit& v)  {}
};


struct Stuff
{
  Unit leafPos[1];
};


kernel void wn()
{
  Stuff a;
  Stuff b = a;
} 