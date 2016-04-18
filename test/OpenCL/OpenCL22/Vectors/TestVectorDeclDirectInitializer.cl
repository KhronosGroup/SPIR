// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp64-enable -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -cl-fp16-enable -cl-fp64-enable -emit-llvm -o -
// expected-no-diagnostics

#include "../opencl_def"

#ifdef cl_khr_fp16
    #pragma OPENCL EXTENSION cl_khr_fp16: enable
#endif

namespace
{
    // Tester for usage of implicit conversion operator.
    template <typename destType_>
        class ConversionOpTester
    {
        destType_ _val;

    public:
        ConversionOpTester(const destType_& val)
            : _val(val) {}
        // Do simple copy for move. It is for testing reference binding only.
        ConversionOpTester(destType_&& val)
            : _val(val) {}

        operator destType_() // TODO: Change to auto does not work. Why?
        {
            return _val;
        }
    };

    // Tester for parameter pack expansions.
    template <typename vecType_, typename elemType_, elemType_ ... elems_>
        class ExpansionInClassSimpleTester
    {
        vecType_ _member;
        vecType_ _initMember = vecType_(elems_ ...);

    public:
        // Initialization with pack expansion of old style compile-time variable (value-dependant value).
        // TODO: Should `static const vecType` be allowed? Is vector of integrals an integral literal type?
        //static const vecType_ OldStyleCTVar = vecType_(elems_ ...);
        // Initialization with pack expansion of old style compile-time variable (value-dependant value).
        static constexpr vecType_ NewStyleCTVar = vecType_(elems_ ...);

        // Initialization in .ctor initialization list (from class pack).
        constexpr ExpansionInClassSimpleTester() : _member(elems_ ...)
        {
            // Initialization of local (from class pack).
            vecType_ local1(elems_ ...);
            vecType_ local2 = vecType_(elems_ ...);
        }

        template <elemType_ ... funElems_> void Fun01()
        {
            // Initialization of local (from function pack).
            vecType_ local1(funElems_ ...);
            vecType_ local2 = vecType_(funElems_ ...);
        }

        vecType_ Fun10()
        {
            // Initialization by function-style initializer and binding to return (from class pack).
            return vecType_(elems_ ...);
        }

        template <elemType_ ... funElems_> vecType_ Fun11()
        {
            // Initialization by function-style initializer and binding to return (from function pack).
            return vecType_(funElems_ ...);
        }

        template <typename ... funElemTypes_>
            vecType_ Fun12(funElemTypes_ ... funElems)
        {
            // Initialization by function-style initializer and binding to return (from function arguments).
            return vecType_(funElems ...);
        }

        // Initialization in .ctor initialization list (from function arguments).
        template <typename ... ctorElemTypes_>
            ExpansionInClassSimpleTester(ctorElemTypes_ ... ctorElems) : _member(ctorElems ...)
        {
            // Initialization of local (from function arguments).
            vecType_ local1(ctorElems ...);
            vecType_ local2 = vecType_(ctorElems ...);
        }

        const vecType_& GetMember() const
        {
            return _member;
        }
    };
}


kernel void worker_literals()
{
    // Initialization by scalar components (all, literal).
    const bool3             vec01 (false, true, false);                                         // no narrowing
    const volatile bool4    vec02 (false, false, true, true);                                   // no narrowing
    volatile uchar2         vec03 (100, 150);                                                   // integer narrowing (no truncation)

    short8   vec04 (10000, -9999, 9998, -9997, 9996, -9995, 9994, -9993);                       // integer narrowing (no truncation)
    int4     vec05 (4, 3, 2, 1);                                                                // no narrowing
    long16   vec06 (100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85);           // no narrowing
    float8   vec07 (4.1f, 4.2f, 5.5f, -1, 0.0f, 1, 7.0f, 8.0f);                                 // integer-fp conversion (no precision loss)
#ifdef cl_khr_fp16
    half3    vec08 (static_cast<half>(1.0f), static_cast<half>(2.0f), static_cast<half>(3.0f)); // no narrowing
#endif
#ifdef cl_khr_fp64
    double4  vec09 (-1.0, -2.0, -3.0, -4.0);                                                    // no narrowing
#endif

    // Initialization by scalar component (single, literal).
    bool8    vec10 (true);                       // no narrowing
    char4    vec11 (11);                         // integer narrowing (no truncation)
    ushort3  vec12 (1125);                       // integer narrowing (no truncation)
    uint2    vec13 (2987654321);                 // no narrowing
    ulong8   vec14 (1020304050607080);           // no narrowing
    float4   vec15 (-6.25e-18f);                 // no narrowing
#ifdef cl_khr_fp16
    half8    vec16 (static_cast<half>(13.75f));  // no narrowing
#endif
#ifdef cl_khr_fp64
    double8  vec17 (-9.92135e109);               // no narrowing
#endif

    // Initialization by scalar/vector components (splat, literal scalar & vector variable).
    bool16   vec18 (true, vec01, vec02, true, true, vec01, vec01);   // no narrowing
    int8     vec19 (vec05, -1, 1, 2, 3);                             // no narrowing

    // Initialization by scalar/vector components (splat, literal scalar & vector variable).
    float16  vec20 (1, -2, 3U, 4.0f, false, vec07, 6.0f, 7, 8L);     // integer-fp conversion (no precision loss)
}


kernel void worker_variables()
{
    const bool          sv01 = false;
    const volatile char sv02 = 1;
    volatile uchar      sv03 = 2;

    short  sv04 = 3;
    ushort sv05 = 4;
    int    sv06 = 5;
    uint   sv07 = 6;
    long   sv08 = 7;
    ulong  sv09 = 8;
#ifdef cl_khr_fp16
    half   sv10 = static_cast<half>(9);
#endif
    float  sv11 = 10.0f;
#ifdef cl_khr_fp64
    double sv12 = 11.0;
#endif

    // Initialization by scalar components (all, variables).
    int8     vec01 (sv01, sv02, sv03, sv04, sv05, sv04, sv03, sv02);   // no narrowing
    float4   vec02 (sv01, sv02, sv03, sv05);                           // integer-fp conversion (no precision loss)
#ifdef cl_khr_fp16
    half4    vec03 (sv01, sv02, sv03, sv05);                           // integer-fp conversion (possible precision loss)
#endif

    // Initialization by scalar components (all, variables & prvalues from implicit operators).
    long8   vec04 (sv08, ConversionOpTester<long>(10), sv08, sv08,                   // no narrowing
                   ConversionOpTester<long>(11), sv08, sv08,
                   ConversionOpTester<volatile long>(12));
    int3    vec05 (ConversionOpTester<long>(10), 11L, static_cast<ulong>(12));       // integer narrowing (possible truncation)
    float2  vec06 (ConversionOpTester<long>(120), ConversionOpTester<uchar>(110));   // integer-fp conversion (possible precision loss)
    float4  vec07 (sv11, ConversionOpTester<ulong>(210), sv06,                       // integer-fp conversion (possible precision loss)
                   ConversionOpTester<ushort>(220));
#ifdef cl_khr_fp16
    float4  vec08 (sv10, ConversionOpTester<float>(210), sv06,                       // integer-fp conversion (possible precision loss)
                   ConversionOpTester<ushort>(220));
#endif
#ifdef cl_khr_fp64
    double4  vec09 (sv12, ConversionOpTester<float>(210), sv06,                       // integer-fp conversion (possible precision loss)
                    ConversionOpTester<ushort>(220));
#endif
}


void TestTempBindFun01(long3);
void TestTempBindFun02(const bool8&);
void TestTempBindFun03(float16&&);

template <typename t1_, typename t2_, typename t3_>
    struct TestTempBindCtors
{
    TestTempBindCtors(t1_);
    TestTempBindCtors(const t2_&);
    TestTempBindCtors(t3_&&);
};


kernel void worker_func_style_temporary()
{
    bool   sv01 = false;
    char   sv02 = 1;
    uchar  sv03 = 2;
    short  sv04 = 3;
    ushort sv05 = 4;
    int    sv06 = 5;
    uint   sv07 = 6;
    long   sv08 = 7;
    ulong  sv09 = 8;
#ifdef cl_khr_fp16
    half   sv10 = static_cast<half>(9);
#endif
    float  sv11 = 10.0f;
#ifdef cl_khr_fp64
    double sv12 = 11.0;
#endif

    // Function-style (temporary) initialization by scalar components (all).
    int2   vec01 = int2(1, 2);                                          // no narrowing
    float4 vec02 = float4(10, 20, 30.3f, 40UL);                         // integer-fp conversion (no precision loss)
    float8 vec03 = float8(sv04, sv01, -3.1f, sv05, 20U, sv11,           // integer-fp conversion (possible precision loss)
                          ConversionOpTester<long>(120), float(10.0f));

    // Function-style (temporary) initialization by scalar/vector components (splat).
    auto   vec04 = int16(vec01, 1, 2U, 'A', sv08, vec01, int3(3, 2, 1), // integer narrowing & fp-integer conversion (possible precision loss/truncation)
                         ConversionOpTester<long>(-5), int4(-6));
    auto   vec05 = int16(vec01, 1, 2U, 'A', sv08, vec01, int3{3, 2, 1}, // integer narrowing & fp-integer conversion (possible precision loss/truncation)
                         ConversionOpTester<long>(-5), int4{-6});
    // TODO: [WIP] Needs fixing handling conversion operators to vector types when specified in vector init list.
    //auto   vec06 = int16(vec01, sv03, 2U, 'A', sv08, vec01, int4(3),    // integer narrowing & fp-integer conversion (possible precision loss/truncation)
    //                     ConversionOpTester<int4>(int4(9, 8, 7, 6)));

    // Function-style (temporary) initialization by scalar/vector components (splat) with binding to function argument.
    TestTempBindFun01(long3(long2(1, 2), ConversionOpTester<float>(-6.0f)));
    TestTempBindFun02(bool8(1, 0, 1, 2, -10, 0, false, true));
    TestTempBindFun03(float16(12345));

    // Function-style (temporary) initialization by scalar/vector components (splat) with binding to function argument.
    using TestTempBindCtors01 = TestTempBindCtors<ulong2, float3, uchar3>;
    TestTempBindCtors01 tester01(ulong2(1, 2.0f));
    TestTempBindCtors01 tester02(float3(1, sv06, sv11));
    TestTempBindCtors01 tester03(uchar3(sv01, uchar4(sv11, sv09, 10, 11).xz));

    // Function-style (temporary) initialization by scalar/vector components (splat) with binding reference.
    const float4& vec07 = float4(1, 2, float2(3, 4));
    long3&&       vec08 = long3(-1);
    const int2&   vec09 = int2();
}


kernel void worker_param_pack_expansion()
{
    bool sv01 = false;

    // TODO: [WIP] `static const vecType` should be allowed when vecType is literal fundamental integral type
    //              which we assume is true when element type is integral.
    // Expansion to full list of scalars.
    //auto vec01 = ExpansionInClassSimpleTester<int4, int, 1, 2, 3, 4>::OldStyleCTVar;                         // no narrowing (literals)
    //auto vec02 = ExpansionInClassSimpleTester<int4, long, 1, 2, 3, 4>::OldStyleCTVar;                        // integer narrowing (literals)
    auto vec03 = ExpansionInClassSimpleTester<int8, int, 11, 12, 13, 14, 15, 16, 17, 18>::NewStyleCTVar;     // no narrowing (literals)
    auto vec04 = ExpansionInClassSimpleTester<int8, ulong, 11, 12, 13, 14, 15, 16, 17, 18>::NewStyleCTVar;   // integer narrowing (literals)
    ExpansionInClassSimpleTester<bool3, bool, true, false, true> tester01;                                   // no narrowing
    tester01.Fun01<false, false, true>();                                                                    // no narrowing
    ExpansionInClassSimpleTester<bool4, int, 0, 0, 1, 2> tester02;                                           // integer narrowing (literals)
    tester02.Fun01<3, 2, 1, 0>();                                                                            // integer narrowing (literals)
    ExpansionInClassSimpleTester<float3, uint, 1, 2, 3> tester03(31.0f, 32.0f, 33.0f);                       // no narrowing
    // TODO: [WIP] Needs spec clarification on non-pointer use of half when cl_khr_fp16 and decision of scope of use as storage type without fp16 extension.
    //       If latter will be relaxed the ifdef will be removed.
#ifdef cl_khr_fp16
    //ExpansionInClassSimpleTester<float3, uint, 1, 2, 3> tester04(static_cast<half>(1.0f), 2.0f, 3.0f);       // no narrowing
#endif
    ExpansionInClassSimpleTester<short3, uint, 1, 2, 3> tester05(1L, 1UL, -1);                               // integer narrowing (variables)
#ifdef cl_khr_fp64
    ExpansionInClassSimpleTester<float4, uint, 1, 2, 3, 4> tester06a(1U, -2, 3.0, true);                     // integer-fp conversion & possible fp narrowing (variables)
#endif
    ExpansionInClassSimpleTester<float4, uint, 1, 2, 3, 4> tester06(1U, -2, 3.0f, true);                     // integer-fp conversion (variables)
    auto vec05 = tester06.Fun10();                                                                           // integer-fp conversion
    auto vec06 = tester06.Fun11<10, 11, 12, 13>();                                                           // integer-fp conversion
    auto vec07 = tester06.Fun12(1U, -2, 3.0, true);                                                          // integer-fp conversion & possible fp narrowing (variables)

    // Expansion to single scalar.
    //auto vec08 = ExpansionInClassSimpleTester<uint4, uint, 41>::OldStyleCTVar;   // no narrowing
    auto vec09 = ExpansionInClassSimpleTester<uint3, uint, 51>::NewStyleCTVar;   // no narrowing
    ExpansionInClassSimpleTester<int8, short, -1234> tester07;                   // no narrowing
    ExpansionInClassSimpleTester<ushort4, uint, 123> tester08;                   // narrowing (literals).
    ExpansionInClassSimpleTester<float2, int, 12> tester09;                      // integer-fp conversion (literals)
    tester09.Fun01<11>();                                                        // integer-fp conversion (literals)
    ExpansionInClassSimpleTester<int3, long, 1> tester10;                        // integer narrowing (literals)
    tester10.Fun01<2345678>();                                                   // integer narrowing (literals)
    ExpansionInClassSimpleTester<short3, uint, 1, 2, 3> tester11(1L);            // integer narrowing (variables)
    ExpansionInClassSimpleTester<short3, uint, 1, 2, 3> tester12(1UL);           // integer narrowing (variables)
    ExpansionInClassSimpleTester<short3, uint, 1, 2, 3> tester13(-1);            // integer narrowing (variables)
    ExpansionInClassSimpleTester<float4, uint, 1, 2, 3, 4> tester14(1U);         // integer-fp conversion & fp narrowing (variables)
    ExpansionInClassSimpleTester<float4, uint, 1, 2, 3, 4> tester15(-2);         // integer-fp conversion & fp narrowing (variables)
    ExpansionInClassSimpleTester<float4, uint, 1, 2, 3, 4> tester16(3.0);        // fp narrowing (variables)
    ExpansionInClassSimpleTester<float4, uint, 1, 2, 3, 4> tester17(true);       // integer-fp conversion & possible fp narrowing (variables)
    auto vec10 = tester10.Fun10();                                               // integer narrowing (literals)
    auto vec11 = tester10.Fun11<-10>();                                          // integer narrowing (literals)
    auto vec12 = tester10.Fun12(1UL);                                            // integer narrowing (variables)

    // Expansion to empty pack.
    //auto vec13 = ExpansionInClassSimpleTester<uint16, uint>::OldStyleCTVar;
    auto vec14 = ExpansionInClassSimpleTester<uint8, uint>::NewStyleCTVar;
    ExpansionInClassSimpleTester<int3, short> tester18;
    tester18.Fun01<>();
    auto tester19 = ExpansionInClassSimpleTester<short3, uint, 1, 2, 3>();
    auto vec15 = tester10.Fun10();
    auto vec16 = tester10.Fun11<>();
    auto vec17 = tester10.Fun12();

    // Expansion to mixed scalar/vector.
    ExpansionInClassSimpleTester<float8, uint, 1> tester20(tester03.GetMember().y, sv01, tester06.GetMember().ba, float2(1,2).yyxy);
    //ExpansionInClassSimpleTester<float8, uint, 1> tester21(sv01, 12, float4(1, 2, 3, 4), ConversionOpTester<float2>(float2(10, 20.0f)));
}
