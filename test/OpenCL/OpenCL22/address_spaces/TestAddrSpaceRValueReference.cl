// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

template< class T > struct remove_generic { typedef T type; };

template< class T > struct remove_generic<__generic T> { typedef T type; };

template <class T> struct remove_generic;

template <class K> struct remove_reference;

template <class I>
using remove_reference_t = typename remove_reference<I>::type;

template <class T>
using remove_generic_t = typename remove_generic<T>::type;

template <class G>
struct remove_reference { typedef G type; };

template <class C>
struct remove_reference<C&> { typedef C type; };

template <class A>
struct remove_reference<A&&> { typedef A type; };

template <typename F>
void level2(F && t)
{
    remove_generic_t<remove_reference_t<F>> a;
}

template <typename M>
void level1(M t)
{
	level2(t);
}

kernel void worker( )
{
    int a = 12;    
    level1(a);
}
