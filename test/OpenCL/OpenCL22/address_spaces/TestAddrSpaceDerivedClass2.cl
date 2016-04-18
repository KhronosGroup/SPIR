// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

struct A {
   ~A();
};

template <typename Ty>
struct B : public A {
   ~B () {  }
private:
     Ty* val;
};

template <typename Ty>
struct C : public A {
   C ();
   ~C ();
};

template <typename Ty>
struct D : public A {
     D () {}
   private:
     B<C<Ty> > blocks;
};

template class D<double>;
