// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o -

#define LOCAL_MEM __local

#include "../opencl_def"

namespace Testers
{
    // implicitly defined defaulted default constructor; aggregate
    struct Aggregate {
        int a;
        float b;
    };

    // implicitly defined defaulted default constructor; non-aggregate
    struct NonAggregate {
        int a;
    private:
        float b;

    public:
        void setB(float val) { b = val; }
    };

    // explicitly defined defaulted default constructor; aggregate
    struct ExpDefCtorAggregate {
        int a;
        long b;

        ExpDefCtorAggregate() = default;
    };

    // explicitly defined defaulted default constructor; non-aggregate
    struct ExpDefCtorNonAggregate {
        int a;
    private:
        long b;

    public:
        ExpDefCtorNonAggregate() = default;
        void setB(long val) { b = val; }
    };

    // user defined defaulted default constructor; non-aggregate
    struct UserCtorNonAggregate {
        int a;
        long b;

        UserCtorNonAggregate();
    };

    UserCtorNonAggregate::UserCtorNonAggregate() = default;

    // user defined defaulted default constructor; non-aggregate
    struct UserConstexprCtorNonAggregate {
        int a;
        long b;

        constexpr UserConstexprCtorNonAggregate() : a(), b() {}
    };

    // no default constructor; non-aggregate
    struct NonCtorNonAggregate {
        int a;
        int b;

        NonCtorNonAggregate(int a) : a(a), b(a) {}
    };

    // NOTE: Class derived from aggregate is not aggregate (aggregate cannot have base classes).
    struct DerivedAggregate : Aggregate {
        int c;
    };

    struct DerivedUserCtorNonAggregate : UserCtorNonAggregate {};

    struct CompositeUserCtorNonAggregate {
        UserCtorNonAggregate m;
    };

    struct AggregateLRef1 {
        const int & m;
    };

    struct AggregateRRef1 {
        int && m;
    };

    struct AggregateLRef2 {
        const Aggregate & m;
    };

    struct AggregateRRef2 {
        Aggregate && m;
    };

    struct LAggregateLRef1 {
        LOCAL_MEM const int & m;
    };

    struct LAggregateRRef1 {
        LOCAL_MEM int && m;
    };

    struct LAggregateLRef2 {
        LOCAL_MEM const Aggregate & m;
    };

    struct LAggregateRRef2 {
        LOCAL_MEM Aggregate && m;
    };

    using TAggregate    = Aggregate;
    using TNonAggregate = NonAggregate;
    typedef UserCtorNonAggregate TUserCtorNonAggregate;
    typedef int2 TInt2;
}

using TAggregate    = Testers::TAggregate;
using TNonAggregate = Testers::TNonAggregate;
typedef Testers::TUserCtorNonAggregate TUserCtorNonAggregate;
typedef Testers::TInt2 TInt2;

using TAggregateA2 = TAggregate[2];
typedef TNonAggregate TNonAggregateA2[2];
using TUserCtorNonAggregateA2 = TUserCtorNonAggregate[2];
typedef TInt2 TInt2A2[2];

using TAggregateA22 = TAggregateA2[2];
typedef TNonAggregateA2 TNonAggregateA22[2];
using TUserCtorNonAggregateA22 = TUserCtorNonAggregateA2[2];
typedef TInt2A2 TInt2A22[2];

typedef LOCAL_MEM TAggregateA22 LTAggregateA22;
using TLTAggregateA22 = LTAggregateA22;

int UserFunc();


// Single
LOCAL_MEM int TrivialType1;
LOCAL_MEM int TrivialType2{};                 // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType3 = {};              // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType4A = int();          // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType4B = UserFunc();     // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType5(1234);             // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType6{1234};             // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType7 = {1234};          // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType8 = int(1234);       // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialType9A = 1234;           // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM const int TrivialType9B = 1234;     // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM constexpr int TrivialType9C = 1234; // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

LOCAL_MEM float2 TrivialVecType1;
LOCAL_MEM float2 TrivialVecType2{};                // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecType3 = {};             // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecType4 = float2();       // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecType5(12, 34);          // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecType6{12, 34};          // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecType7 = {12, 34};       // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecType8 = float2(12, 34); // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecType9 = 1234;           // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

LOCAL_MEM Testers::Aggregate C1Type1;
LOCAL_MEM Testers::Aggregate C1Type2{};                            // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1Type3 = {};                         // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1Type4 = Testers::Aggregate();       // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1Type6{12, 34};                      // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1Type7 = {12, 34};                   // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1Type8 = Testers::Aggregate{12, 34}; // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonAggregate C2Type1;
LOCAL_MEM Testers::NonAggregate C2Type2{};                         // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonAggregate C2Type3 = {};                      // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonAggregate C2Type4 = Testers::NonAggregate(); // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorAggregate C3Type1;
LOCAL_MEM Testers::ExpDefCtorAggregate C3Type2{};                                      // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3Type3 = {};                                   // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3Type4 = Testers::ExpDefCtorAggregate();       // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3Type6{12, 34};                                // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3Type7 = {12, 34};                             // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3Type8 = Testers::ExpDefCtorAggregate{12, 34}; // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type1;
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type2{};                                   // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type3 = {};                                // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type4 = Testers::ExpDefCtorNonAggregate(); // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::UserCtorNonAggregate C5Type1A;                                  // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserCtorNonAggregate C5Type1B;                            // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5Type2{};                                 // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5Type3 = {};                              // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5Type4 = Testers::UserCtorNonAggregate(); // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type1A;                                           // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserConstexprCtorNonAggregate C6Type1B;                                     // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate C6Type1C;                                 // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type2{};                                          // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type3 = {};                                       // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type4 = Testers::UserConstexprCtorNonAggregate(); // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonCtorNonAggregate C7Type5(1234);                                 // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7Type6{1234};                                 // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7Type7 = {1234};                              // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7Type8 = Testers::NonCtorNonAggregate(1234);  // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7Type9 = 1234;                                // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7Type10 = Testers::NonCtorNonAggregate{1234}; // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::DerivedAggregate C8Type1;
LOCAL_MEM Testers::DerivedAggregate C8Type2{};                                   // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedAggregate C8Type3 = {};                                // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedAggregate C8Type4 = Testers::DerivedAggregate();       // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type1;                                          // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type2{};                                        // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type3 = {};                                     // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type4 = Testers::DerivedUserCtorNonAggregate(); // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type1;                                            // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type2{};                                          // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type3 = {};                                       // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type4 = Testers::CompositeUserCtorNonAggregate(); // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Arrays
LOCAL_MEM int TrivialArrType1[2];
LOCAL_MEM int TrivialArrType2[2]{};                   // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialArrType3[2] = {};                // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialArrType6[2]{1234};               // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialArrType7A[2] = {1234};           // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM const int TrivialArrType7B[2] = {1234};     // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM constexpr int TrivialArrType7C[2] = {1234}; // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

LOCAL_MEM float2 TrivialVecArrType1[3];
LOCAL_MEM float2 TrivialVecArrType2[3]{};          // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecArrType3[3] = {};       // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecArrType6[3]{12, 34};    // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecArrType7[3] = {12, 34}; // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

LOCAL_MEM Testers::Aggregate C1ArrType1[2][4][6];
LOCAL_MEM Testers::Aggregate C1ArrType2[2][4][6]{};                // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1ArrType3[2][4][6] = {};             // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1ArrType6[2][4][6]{{{{12, 34}}}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1ArrType7[2][4][6] = {{{{12, 34}}}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonAggregate C2ArrType1[2][4];
LOCAL_MEM Testers::NonAggregate C2ArrType2[2][4]{};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonAggregate C2ArrType3[2][4] = {}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType1[4];
LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType2[4]{};            // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType3[4] = {};         // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType6[4]{{12, 34}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType7[4] = {{12, 34}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorNonAggregate C4ArrType1[3][6];
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4ArrType2[3][6]{};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4ArrType3[3][6] = {}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::UserCtorNonAggregate C5ArrType1A[4];       // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserCtorNonAggregate C5ArrType1B[4]; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5ArrType2[4]{};      // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5ArrType3[4] = {};   // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6ArrType1A[3];           // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserConstexprCtorNonAggregate C6ArrType1B[3];     // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate C6ArrType1C[3]; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6ArrType2[3]{};          // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6ArrType3[3] = {};       // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonCtorNonAggregate C7ArrType6[1][1]{{Testers::NonCtorNonAggregate{1234}}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7ArrType7[1][1] = {{Testers::NonCtorNonAggregate{1234}}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::DerivedAggregate C8ArrType1[2];
LOCAL_MEM Testers::DerivedAggregate C8ArrType2[2]{};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedAggregate C8ArrType3[2] = {}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9ArrType1[4];      // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9ArrType2[4]{};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9ArrType3[4] = {}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10ArrType1[5];      // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10ArrType2[5]{};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10ArrType3[5] = {}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Auto-sized arrays
LOCAL_MEM int TrivialUArrType6[]{1234};       // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialUArrType7[] = {1234};    // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

LOCAL_MEM float2 TrivialVecUArrType6[]{12, 34};          // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecUArrType7[] = {12, 34};       // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

LOCAL_MEM Testers::Aggregate C1UArrType6[][4][6]{{{{12, 34}}}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1UArrType7[][4][6] = {{{{12, 34}}}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorAggregate C3UArrType6[]{{12, 34}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3UArrType7[] = {{12, 34}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonCtorNonAggregate C6UArrType6[][1]{{Testers::NonCtorNonAggregate{1234}}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C6UArrType7[][1] = {{Testers::NonCtorNonAggregate{1234}}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Typedefs
LOCAL_MEM TInt2A22 TrivialVecArrTType1;
LOCAL_MEM TInt2A22 TrivialVecArrTType2{};            // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM TInt2A22 TrivialVecArrTType3 = {};         // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM TInt2A22 TrivialVecArrTType6{{12, 34}};    // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
LOCAL_MEM TInt2A22 TrivialVecArrTType7 = {{12, 34}}; // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

LOCAL_MEM TAggregateA22 C1ArrTType1;
LOCAL_MEM TAggregateA22 C1ArrTType2{};              // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TAggregateA22 C1ArrTType3 = {};           // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TAggregateA22 C1ArrTType6{{{12, 34}}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TAggregateA22 C1ArrTType7 = {{{12, 34}}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM TNonAggregateA22 C2ArrTType1;
LOCAL_MEM TNonAggregateA22 C2ArrTType2{};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TNonAggregateA22 C2ArrTType3 = {}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM TUserCtorNonAggregateA22 C5ArrTType1;      // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TUserCtorNonAggregateA22 C5ArrTType2{};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TUserCtorNonAggregateA22 C5ArrTType3 = {}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

TLTAggregateA22 C1ArrTLTType1;
TLTAggregateA22 C1ArrTLTType2{};              // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
TLTAggregateA22 C1ArrTLTType3 = {};           // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
TLTAggregateA22 C1ArrTLTType6{{{12, 34}}};    // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
TLTAggregateA22 C1ArrTLTType7 = {{{12, 34}}}; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Template variables
template <typename T> LOCAL_MEM T TemplateVarType1;
template <typename T> LOCAL_MEM T TemplateVarType2;
template <typename T> LOCAL_MEM T TemplateVarType3;
template <typename T> LOCAL_MEM T TemplateVarType4{}; // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

template <> LOCAL_MEM int TemplateVarType1<int>;
template <> LOCAL_MEM int TemplateVarType2<int>{};      // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
template <> LOCAL_MEM int TemplateVarType3<int> = 1234; // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}

template <> LOCAL_MEM Testers::Aggregate TemplateVarType1<Testers::Aggregate>;
template <> LOCAL_MEM Testers::UserCtorNonAggregate TemplateVarType1<Testers::UserCtorNonAggregate>;                         // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
template <> LOCAL_MEM Testers::DerivedUserCtorNonAggregate TemplateVarType1<Testers::DerivedUserCtorNonAggregate>;           // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
template <> LOCAL_MEM Testers::CompositeUserCtorNonAggregate TemplateVarType1<Testers::CompositeUserCtorNonAggregate[2]>[2]; // expected-error{{elements of program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

template LOCAL_MEM float TemplateVarType1<float>;
template LOCAL_MEM int2 TemplateVarType1<int2>;
template LOCAL_MEM Testers::Aggregate TemplateVarType2<Testers::Aggregate>;
// NOTE: Treated as external in clang (and ignored - why?), because TemplateVarType2 is treated as declaration.
template LOCAL_MEM Testers::UserCtorNonAggregate TemplateVarType2<Testers::UserCtorNonAggregate>;                   // expected-error 0-1{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
template LOCAL_MEM Testers::CompositeUserCtorNonAggregate TemplateVarType2<Testers::CompositeUserCtorNonAggregate>; // expected-error 0-1{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Life-time extended temporary variables (program-scope, lvalue reference)
const int &                          LExtTmpL1A = 1;
LOCAL_MEM const int &                LExtTmpL1B = 1;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const float3 &                       LExtTmpL2A = {};
LOCAL_MEM const float3 &             LExtTmpL2B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const Testers::Aggregate &           LExtTmpL3A = {};
LOCAL_MEM const Testers::Aggregate & LExtTmpL3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
const TInt2A22 &                     LExtTmpL4A = {};
LOCAL_MEM const TInt2A22 &           LExtTmpL4B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

const Testers::Aggregate           (& LExtTmpL5A)[] = {{}};
LOCAL_MEM const Testers::Aggregate (& LExtTmpL5B)[] = {{}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Life-time extended temporary variables (program-scope, rvalue reference)
int &&                          LExtTmpR1A = 1;
LOCAL_MEM int &&                LExtTmpR1B = 1;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
float3 &&                       LExtTmpR2A = {};
LOCAL_MEM float3 &&             LExtTmpR2B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
Testers::Aggregate &&           LExtTmpR3A = {};
LOCAL_MEM Testers::Aggregate && LExtTmpR3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
TInt2A22 &&                     LExtTmpR4A = {};
LOCAL_MEM TInt2A22 &&           LExtTmpR4B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

Testers::Aggregate           (&& LExtTmpR5A)[] = {{}};
LOCAL_MEM Testers::Aggregate (&& LExtTmpR5B)[] = {{}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}


// Life-time extended temporary variables (program-scope, nested)
const Testers::AggregateLRef1 &  LExtTmpN1A = {{}};
const Testers::LAggregateLRef1 & LExtTmpN1B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const Testers::AggregateRRef1 &  LExtTmpN2A = {{}};
const Testers::LAggregateRRef1 & LExtTmpN2B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
Testers::AggregateLRef1 &&       LExtTmpN3A = {{}};
Testers::LAggregateLRef1 &&      LExtTmpN3B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
Testers::AggregateRRef1 &&       LExtTmpN4A = {{}};
Testers::LAggregateRRef1 &&      LExtTmpN4B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const Testers::AggregateLRef2 &  LExtTmpN5A = {{}};
const Testers::LAggregateLRef2 & LExtTmpN5B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
const Testers::AggregateRRef2 &  LExtTmpN6A = {{}};
const Testers::LAggregateRRef2 & LExtTmpN6B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
Testers::AggregateLRef2 &&       LExtTmpN7A = {{}};
Testers::LAggregateLRef2 &&      LExtTmpN7B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
Testers::AggregateRRef2 &&       LExtTmpN8A = {{}};
Testers::LAggregateRRef2 &&      LExtTmpN8B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}


// Life-time extended temporary variables (program-scope, template variables, lvalue reference)
template <typename T> LOCAL_MEM const T & TemplateLVarType1 = {};   // expected-error 3{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}} expected-note 0-2{{declared here}}
template <typename T> LOCAL_MEM const T & TemplateLVarType2 = 1234; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}} expected-note 0-1{{declared here}}

template <> LOCAL_MEM const int & TemplateLVarType1<int> = {};   // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
template <> LOCAL_MEM const int & TemplateLVarType2<int> = 1234; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

template LOCAL_MEM const float & TemplateLVarType1<float>; // expected-note{{in instantiation of variable template}}
template LOCAL_MEM const long & TemplateLVarType1<long>;   // expected-note{{in instantiation of variable template}}
template LOCAL_MEM const short & TemplateLVarType2<short>; // expected-note{{in instantiation of variable template}}

// Life-time extended temporary variables (program-scope, template variables, rvalue reference)
template <typename T> LOCAL_MEM T && TemplateRVarType1 = {};   // expected-error 2{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}} expected-note 0-2{{declared here}}
template <typename T> LOCAL_MEM T && TemplateRVarType2 = 1234; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}} expected-note 0-1{{declared here}}

template <> LOCAL_MEM int && TemplateRVarType1<int> = {};   // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
template <> LOCAL_MEM int && TemplateRVarType2<int> = 1234; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

template LOCAL_MEM float && TemplateRVarType1<float>; // expected-note{{in instantiation of variable template}}
template LOCAL_MEM long && TemplateRVarType1<long>;   // expected-note{{in instantiation of variable template}}
template LOCAL_MEM short && TemplateRVarType2<short>; // expected-note{{in instantiation of variable template}}


kernel void worker() {
    // NOTE: Treated as external in clang, because TemplateVarType3 is treated as declaration.
    auto v1 = TemplateVarType3<Testers::DerivedAggregate>;
    auto v2 = TemplateVarType3<Testers::DerivedUserCtorNonAggregate>; // expected-error 0-1{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // Life-time extended temporary variables (local-scope, lvalue reference)
    const int &                          LLExtTmpL1A = 1;
    LOCAL_MEM const int &                LLExtTmpL1B = 1;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    const float3 &                       LLExtTmpL2A = {};
    LOCAL_MEM const float3 &             LLExtTmpL2B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    const Testers::Aggregate &           LLExtTmpL3A = {};
    LOCAL_MEM const Testers::Aggregate & LLExtTmpL3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    const TInt2A22 &                     LLExtTmpL4A = {};
    LOCAL_MEM const TInt2A22 &           LLExtTmpL4B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    const Testers::Aggregate           (& LLExtTmpL5A)[] = {{}};
    LOCAL_MEM const Testers::Aggregate (& LLExtTmpL5B)[] = {{}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // Life-time extended temporary variables (local-scope, rvalue reference)
    int &&                          LLExtTmpR1A = 1;
    LOCAL_MEM int &&                LLExtTmpR1B = 1;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    float3 &&                       LLExtTmpR2A = {};
    LOCAL_MEM float3 &&             LLExtTmpR2B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    Testers::Aggregate &&           LLExtTmpR3A = {};
    LOCAL_MEM Testers::Aggregate && LLExtTmpR3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    TInt2A22 &&                     LLExtTmpR4A = {};
    LOCAL_MEM TInt2A22 &&           LLExtTmpR4B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    Testers::Aggregate           (&& LLExtTmpR5A)[] = {{}};
    LOCAL_MEM Testers::Aggregate (&& LLExtTmpR5B)[] = {{}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}


    // Life-time extended temporary variables (local-scope, nested)
    const Testers::AggregateLRef1 &  LLExtTmpN1A = {{}};
    const Testers::LAggregateLRef1 & LLExtTmpN1B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    const Testers::AggregateRRef1 &  LLExtTmpN2A = {{}};
    const Testers::LAggregateRRef1 & LLExtTmpN2B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    Testers::AggregateLRef1 &&       LLExtTmpN3A = {{}};
    Testers::LAggregateLRef1 &&      LLExtTmpN3B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    Testers::AggregateRRef1 &&       LLExtTmpN4A = {{}};
    Testers::LAggregateRRef1 &&      LLExtTmpN4B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    const Testers::AggregateLRef2 &  LLExtTmpN5A = {{}};
    const Testers::LAggregateLRef2 & LLExtTmpN5B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    const Testers::AggregateRRef2 &  LLExtTmpN6A = {{}};
    const Testers::LAggregateRRef2 & LLExtTmpN6B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    Testers::AggregateLRef2 &&       LLExtTmpN7A = {{}};
    Testers::LAggregateLRef2 &&      LLExtTmpN7B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    Testers::AggregateRRef2 &&       LLExtTmpN8A = {{}};
    Testers::LAggregateRRef2 &&      LLExtTmpN8B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    auto v3 = TemplateLVarType1<ulong>; // expected-note{{in instantiation of variable template}}
}
