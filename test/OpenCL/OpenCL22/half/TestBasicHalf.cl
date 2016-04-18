// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
#ifdef cl_khr_fp16
// expected-no-diagnostics
#endif

#pragma OPENCL EXTENSION cl_khr_fp16: disable
#pragma OPENCL EXTENSION cl_khr_fp64: disable

#ifdef cl_khr_fp16
    #pragma OPENCL EXTENSION cl_khr_fp16: enable
#endif

#ifdef cl_khr_fp64
    #pragma OPENCL EXTENSION cl_khr_fp64: enable
#endif

half func0() { return 0.0h; }
half* func1(half *ptr) { return ptr; }
half& func2(half &ref) { return ref; }

kernel void w(half arg0, int arg1, __global half *arg2, __global half &arg3)
{
  half v0 = 0.0h;
  float f1 = 1.0f;
  v0 = arg1? 1.0h: 2.0h;
	
  half *ptr0 = &v0;
  half v1 = *ptr0;
  half v2 = ptr0[0];
  half v3 = func0();
  half *ptr1 = func1(&v3);
  half &ref0 = v3;
  half &ref1 = func2(v3);
  
#ifdef cl_khr_fp16
  float f0 = v0;
  v0 = f1;
  bool b0 = v0;
  bool b1 = false;
  v0 = b1;
  int i0 = v0;
  int i1 = 1;
  v0 = i1;
 
#ifdef cl_khr_fp64
  double d0 = v0;
  double d1 = 0.1;
  v0 = d1;
  v0 = 2.0;
#endif

  v0 += 1.0h;
  v0 -= 1.0h;
  v0 *= 1.0h;
  v0 /= 1.0h;
  v0 = v0 + 1.0h;
  v0 = v0 - 1.0h;
  v0 = v0 * 1.0h;
  v0 = v0 / 1.0h;
  v0 = 2.0f;
  v0 = 2.0;
  v0 = -v0;
  v0 = !v0;

  if(v0) { }
  if(!v0) { }
  if(v0 && v1) { }
  if(v0 || v1) { }  
  if(v1 == v2) { }
  if(v1 != v2) { }
  if(v1 < v2) { }
  if(v1 > v2) { }
  if(v1 <= v2) { }
  if(v1 >= v2) { }

#else
  float f0 = v0; //expected-error{{conversion from 'half' to 'float' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 = f1; //expected-error{{conversion from 'float' to 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  //expected-error@TestBasicHalf.cl:* {{assigning to 'half' from incompatible type 'float'}}
  bool b0 = v0; //expected-error{{conversion from 'half' to 'bool' type is not allowed if cl_khr_fp16 extension is not supported}}
  bool b1;
  v0 = b1; //expected-error{{conversion from 'bool' to 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  //expected-error@TestBasicHalf.cl:* {{assigning to 'half' from incompatible type 'bool'}}
  int i0 = v0; //expected-error{{conversion from 'half' to 'int' type is not allowed if cl_khr_fp16 extension is not supported}}
  int i1;
  v0 = i1; //expected-error{{conversion from 'int' to 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  //expected-error@TestBasicHalf.cl:* {{assigning to 'half' from incompatible type 'int'}}

#ifdef cl_khr_fp64
  double d0 = v0; //expected-error{{conversion from 'half' to 'double' type is not allowed if cl_khr_fp16 extension is not supported}}
  double d1;
  v0 = d1;  //expected-error{{conversion from 'double' to 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  //expected-error@TestBasicHalf.cl:* {{assigning to 'half' from incompatible type 'double'}}
  v0 = 2.0; //expected-error{{conversion from 'double' to 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  //expected-error@TestBasicHalf.cl:* {{assigning to 'half' from incompatible type 'double'}}
#endif

  v0 += 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 -= 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 *= 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 /= 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 = v0 + 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 = v0 - 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 = v0 * 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 = v0 / 1.0h; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 = 2.0f; //expected-error{{conversion from 'float' to 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  //expected-error@TestBasicHalf.cl:* {{assigning to 'half' from incompatible type 'float'}}
  v0 = -v0; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  v0 = !v0; //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}

  if(v0) { } //expected-error{{conversion from 'half' to 'bool' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(!v0) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v0 && v1) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v0 || v1) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v1 == v2) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v1 != v2) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v1 < v2) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v1 > v2) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v1 <= v2) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}
  if(v1 >= v2) { } //expected-error{{operator on 'half' type is not allowed if cl_khr_fp16 extension is not supported}}  
#endif
}
