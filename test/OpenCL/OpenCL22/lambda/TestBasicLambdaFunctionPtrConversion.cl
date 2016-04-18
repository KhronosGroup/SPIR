// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null

void f(int a)
{
    auto l = a? [](){}: [](){}; //expected-error{{incompatible operand types}}* 
    auto l2 = a? [](int a){}: [](auto a){}; //expected-error{{incompatible operand types}}* 
}
