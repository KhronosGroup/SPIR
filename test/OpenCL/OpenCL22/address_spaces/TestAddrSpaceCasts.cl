// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -fsyntax-only -pedantic -verify -emit-llvm -O0 -o /dev/null


__local int* srcPtr0;
kernel void worker()
{    
    __local int* srcPtr1;
	const __local int* srcPtr2;
	
	//c-style cast
    __local int *b0 = (__local int *)(srcPtr0);
	__local int *b1 = (__local int *)(srcPtr1);
	__local int *b2 = (__local int *)(srcPtr2);
	
	int *b3 = (__generic int *)(srcPtr0);
	int *b4 = (__generic int *)(srcPtr1);
	int *b5 = (__generic int *)(srcPtr2);
	
    int *b30 = (int *)(srcPtr0);
	int *b41 = (int *)(srcPtr1);
	int *b52 = (int *)(srcPtr2);
	
    int *b6 = (__global int *)(srcPtr0); // expected-error{{C-style cast from '__local int *' to '__global int *' casts away qualifiers}}
	int *b7 = (__global int *)(srcPtr1); // expected-error{{C-style cast from '__local int *' to '__global int *' casts away qualifiers}}
	int *b8 = (__global int *)(srcPtr2); // expected-error{{C-style cast from 'const __local int *' to '__global int *' casts away qualifiers}}
	
    long *b9 = (__generic long *)(srcPtr0);
	long *b10 = (__generic long *)(srcPtr1);
	long *b11 = (__generic long *)(srcPtr2);
	
	long *b90 = (long *)(srcPtr0);
	long *b100 = (long *)(srcPtr1);
	long *b110 = (long *)(srcPtr2);
	
    __local long *b91 = (__local long *)(srcPtr0);
	__local long *b101 = (__local long *)(srcPtr1);
	__local long *b111 = (__local long *)(srcPtr2);
	
	//reinterpret_cast
	__local int *c0 = reinterpret_cast<__local int *>(srcPtr0);
	__local int *c1 = reinterpret_cast<__local int *>(srcPtr1);
	__local int *c2 = reinterpret_cast<__local int *>(srcPtr2); // expected-error{{reinterpret_cast from 'const __local int *' to '__local int *' casts away qualifiers}}
	
	int *c3 = reinterpret_cast<__generic int *>(srcPtr0);
	int *c4 = reinterpret_cast<__generic int *>(srcPtr1);
	int *c5 = reinterpret_cast<__generic int *>(srcPtr2); // expected-error{{reinterpret_cast from 'const __local int *' to '__generic int *' casts away qualifiers}}

	int *c30 = reinterpret_cast<int *>(srcPtr0);
	int *c41 = reinterpret_cast<int *>(srcPtr1);
	int *c52 = reinterpret_cast<int *>(srcPtr2); // expected-error{{reinterpret_cast from 'const __local int *' to 'int *' casts away qualifiers}}
	
	int *c6 = reinterpret_cast<__global int *>(srcPtr0); // expected-error{{reinterpret_cast from '__local int *' to '__global int *' casts away qualifiers}}
	int *c7 = reinterpret_cast<__global int *>(srcPtr1); // expected-error{{reinterpret_cast from '__local int *' to '__global int *' casts away qualifiers}}
	int *c8 = reinterpret_cast<__global int *>(srcPtr2); // expected-error{{reinterpret_cast from 'const __local int *' to '__global int *' casts away qualifiers}}
	
    long *c9 = reinterpret_cast<__generic long *>(srcPtr0);
	long *c10 = reinterpret_cast<__generic long *>(srcPtr1);
	long *c11 = reinterpret_cast<__generic long *>(srcPtr2); // expected-error{{reinterpret_cast from 'const __local int *' to '__generic long *' casts away qualifiers}}
	
    long *c90 = reinterpret_cast<long *>(srcPtr0);
	long *c100 = reinterpret_cast<long *>(srcPtr1);
	long *c110 = reinterpret_cast<long *>(srcPtr2); // expected-error{{reinterpret_cast from 'const __local int *' to 'long *' casts away qualifiers}}
	
    __local long *c91 = reinterpret_cast<__local long *>(srcPtr0);
	__local long *c101 = reinterpret_cast<__local long *>(srcPtr1);
	__local long *c111 = reinterpret_cast<__local long *>(srcPtr2); // expected-error{{reinterpret_cast from 'const __local int *' to '__local long *' casts away qualifiers}}
	
	//static_cast
	__local int *d0 = static_cast<__local int *>(srcPtr0);
	__local int *d1 = static_cast<__local int *>(srcPtr1);
	__local int *d2 = static_cast<__local int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to '__local int *' is not allowed}}
	
	int *d3 = static_cast<__generic int *>(srcPtr0);
	int *d4 = static_cast<__generic int *>(srcPtr1);
	int *d5 = static_cast<__generic int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to '__generic int *' is not allowed}}
	
	int *d30 = static_cast<int *>(srcPtr0);
	int *d41 = static_cast<int *>(srcPtr1);
	int *d52 = static_cast<int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to 'int *' is not allowed}}
	
	__local int *d31 = static_cast<__local int *>(srcPtr0);
	__local int *d42 = static_cast<__local int *>(srcPtr1);
	__local int *d53 = static_cast<__local int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to '__local int *' is not allowed}}
	
	int *d6 = static_cast<__global int *>(srcPtr0); // expected-error{{static_cast from '__local int *' to '__global int *' is not allowed}}
	int *d7 = static_cast<__global int *>(srcPtr1); // expected-error{{static_cast from '__local int *' to '__global int *' is not allowed}}
	int *d8 = static_cast<__global int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to '__global int *' is not allowed}}
	
	long *d9 = static_cast<__generic long int *>(srcPtr0); // expected-error{{static_cast from '__local int *' to '__generic long *' is not allowed}}
	long *d10 = static_cast<__generic long int *>(srcPtr1); // expected-error{{static_cast from '__local int *' to '__generic long *' is not allowed}}
	long *d11 = static_cast<__generic long int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to '__generic long *' is not allowed}}
	
	long *d90 = static_cast<long int *>(srcPtr0); // expected-error{{static_cast from '__local int *' to 'long *' is not allowed}}
	long *d100 = static_cast<long int *>(srcPtr1); // expected-error{{static_cast from '__local int *' to 'long *' is not allowed}}
	long *d110 = static_cast<long int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to 'long *' is not allowed}}
	
	__local long *d91 = static_cast<__local long int *>(srcPtr0); // expected-error{{static_cast from '__local int *' to '__local long *' is not allowed}}
	__local long *d101 = static_cast<__local long int *>(srcPtr1); // expected-error{{static_cast from '__local int *' to '__local long *' is not allowed}}
	__local long *d111 = static_cast<__local long int *>(srcPtr2); // expected-error{{static_cast from 'const __local int *' to '__local long *' is not allowed}}
	
	//const_cast
	__local int *e0 = const_cast<__local int *>(srcPtr0);
	__local int *e1 = const_cast<__local int *>(srcPtr1);
	__local int *e2 = const_cast<__local int *>(srcPtr2);
	
	int *e3 = const_cast<__generic int *>(srcPtr0); // expected-error{{const_cast from '__local int *' to '__generic int *' is not allowed}}
	int *e4 = const_cast<__generic int *>(srcPtr1); // expected-error{{const_cast from '__local int *' to '__generic int *' is not allowed}}
	int *e5 = const_cast<__generic int *>(srcPtr2); // expected-error{{const_cast from 'const __local int *' to '__generic int *' is not allowed}}
	
	int *e30 = const_cast<int *>(srcPtr0); // expected-error{{const_cast from '__local int *' to 'int *' is not allowed}}
	int *e40 = const_cast<int *>(srcPtr1); // expected-error{{const_cast from '__local int *' to 'int *' is not allowed}}
	int *e50 = const_cast<int *>(srcPtr2); // expected-error{{const_cast from 'const __local int *' to 'int *' is not allowed}}
	
	int *e6 = const_cast<__global int *>(srcPtr0); // expected-error{{const_cast from '__local int *' to '__global int *' is not allowed}}
	int *e7 = const_cast<__global int *>(srcPtr1); // expected-error{{const_cast from '__local int *' to '__global int *' is not allowed}}
	int *e8 = const_cast<__global int *>(srcPtr2); // expected-error{{const_cast from 'const __local int *' to '__global int *' is not allowed}}
	
	long *e9 = const_cast<__generic long *>(srcPtr0); // expected-error{{const_cast from '__local int *' to '__generic long *' is not allowed}}
	long *e10 = const_cast<__generic long *>(srcPtr1); // expected-error{{const_cast from '__local int *' to '__generic long *' is not allowed}}
	long *e11 = const_cast<__generic long *>(srcPtr2); // expected-error{{const_cast from 'const __local int *' to '__generic long *' is not allowed}}
	
	long *e90 = const_cast<long *>(srcPtr0); // expected-error{{const_cast from '__local int *' to 'long *' is not allowed}}
	long *e100 = const_cast<long *>(srcPtr1); // expected-error{{const_cast from '__local int *' to 'long *' is not allowed}}
	long *e110 = const_cast<long *>(srcPtr2); // expected-error{{const_cast from 'const __local int *' to 'long *' is not allowed}}
	
	__local long *e91 = const_cast<__local  long *>(srcPtr0); // expected-error{{const_cast from '__local int *' to '__local long *' is not allowed}}
	__local long *e101 = const_cast<__local  long *>(srcPtr1); // expected-error{{const_cast from '__local int *' to '__local long *' is not allowed}}
	__local long *e111 = const_cast<__local  long *>(srcPtr2); // expected-error{{const_cast from 'const __local int *' to '__local long *' is not allowed}}
}
