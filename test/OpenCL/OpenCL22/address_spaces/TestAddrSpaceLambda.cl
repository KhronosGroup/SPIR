// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

auto gl = [](){};
kernel void worker2()
{
  auto pl = [](){};
  pl();
  gl();
}

template<typename T> 
auto foo2() {
  return [](const T&) { return 42; };
}

kernel void worker()
{
    auto gen_lambda = [](auto ptr){
    };
    
    gen_lambda(12);
	
	auto c = foo2<int>();
}


