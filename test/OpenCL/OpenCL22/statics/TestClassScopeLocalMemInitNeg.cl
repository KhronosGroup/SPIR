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


// Single
struct TrivialTypeClass1 {
    static LOCAL_MEM int TrivialType1;
    static LOCAL_MEM int TrivialType2;
    static LOCAL_MEM int TrivialType3;
    static LOCAL_MEM int TrivialType4;
    static LOCAL_MEM int TrivialType5;
    static LOCAL_MEM int TrivialType6;
    static LOCAL_MEM int TrivialType7;
    static LOCAL_MEM int TrivialType8;
    static LOCAL_MEM int TrivialType9A;
    static LOCAL_MEM const int TrivialType9B;
    static LOCAL_MEM const int TrivialType9C = 1234;     // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr int TrivialType9D = 1234; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
};

LOCAL_MEM int TrivialTypeClass1::TrivialType1;
LOCAL_MEM int TrivialTypeClass1::TrivialType2{};             // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialTypeClass1::TrivialType3 = {};          // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialTypeClass1::TrivialType4 = int();       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialTypeClass1::TrivialType5(1234);         // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialTypeClass1::TrivialType6{1234};         // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialTypeClass1::TrivialType7 = {1234};      // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialTypeClass1::TrivialType8 = int(1234);   // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialTypeClass1::TrivialType9A = 1234;       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM const int TrivialTypeClass1::TrivialType9B = 1234; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

template <typename T> class TrivialTypeClass2 {
public:
    static LOCAL_MEM T TrivialType1;
    static LOCAL_MEM T TrivialType2;
    static LOCAL_MEM T TrivialType3;
    static LOCAL_MEM T TrivialType4;
    static LOCAL_MEM T TrivialType5;
    static LOCAL_MEM T TrivialType6;
    static LOCAL_MEM T TrivialType7;
    static LOCAL_MEM T TrivialType8;
    static LOCAL_MEM T TrivialType9A;
    static LOCAL_MEM const T TrivialType9B;
    static LOCAL_MEM const T TrivialType9C = 1234;     // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr T TrivialType9D = 1234; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
};

template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType1;
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType2{};             // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType3 = {};          // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType4 = int();       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType5(1234);         // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType6{1234};         // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType7 = {1234};      // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType8 = int(1234);   // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialTypeClass2<T>::TrivialType9A = 1234;       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM const T TrivialTypeClass2<T>::TrivialType9B = 1234; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

struct TrivialVecTypeClass1 {
    static LOCAL_MEM float2 TrivialVecType1;
    static LOCAL_MEM float2 TrivialVecType2;
    static LOCAL_MEM float2 TrivialVecType3;
    static LOCAL_MEM float2 TrivialVecType4;
    static LOCAL_MEM float2 TrivialVecType5;
    static LOCAL_MEM float2 TrivialVecType6;
    static LOCAL_MEM float2 TrivialVecType7;
    static LOCAL_MEM float2 TrivialVecType8;
    static LOCAL_MEM float2 TrivialVecType9;
};

LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType1;
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType2{};                // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType3 = {};             // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType4 = float2();       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType5(12, 34);          // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType6{12, 34};          // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType7 = {12, 34};       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType8 = float2(12, 34); // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecTypeClass1::TrivialVecType9 = 1234;           // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

struct C1TypeClass1 {
    static LOCAL_MEM Testers::Aggregate C1Type1A;
    static LOCAL_MEM const Testers::Aggregate C1Type1B{}; // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::Aggregate C1Type2;
    static LOCAL_MEM Testers::Aggregate C1Type3;
    static LOCAL_MEM Testers::Aggregate C1Type4;
    static LOCAL_MEM Testers::Aggregate C1Type6;
    static LOCAL_MEM Testers::Aggregate C1Type7;
    static LOCAL_MEM Testers::Aggregate C1Type8;
};

LOCAL_MEM Testers::Aggregate C1TypeClass1::C1Type1A;
LOCAL_MEM Testers::Aggregate C1TypeClass1::C1Type2{};                            // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1TypeClass1::C1Type3 = {};                         // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1TypeClass1::C1Type4 = Testers::Aggregate();       // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1TypeClass1::C1Type6{12, 34};                      // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1TypeClass1::C1Type7 = {12, 34};                   // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1TypeClass1::C1Type8 = Testers::Aggregate{12, 34}; // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C2TypeClass1 {
    static LOCAL_MEM Testers::NonAggregate C2Type1;
    static LOCAL_MEM Testers::NonAggregate C2Type2;
    static LOCAL_MEM Testers::NonAggregate C2Type3;
    static LOCAL_MEM Testers::NonAggregate C2Type4;
};

LOCAL_MEM Testers::NonAggregate C2TypeClass1::C2Type1;
LOCAL_MEM Testers::NonAggregate C2TypeClass1::C2Type2{};                         // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonAggregate C2TypeClass1::C2Type3 = {};                      // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonAggregate C2TypeClass1::C2Type4 = Testers::NonAggregate(); // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C3TypeClass1 {
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3Type1;
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3Type2;
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3Type3;
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3Type4;
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3Type6;
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3Type7;
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3Type8;
};

LOCAL_MEM Testers::ExpDefCtorAggregate C3TypeClass1::C3Type1;
LOCAL_MEM Testers::ExpDefCtorAggregate C3TypeClass1::C3Type2{};                                      // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3TypeClass1::C3Type3 = {};                                   // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3TypeClass1::C3Type4 = Testers::ExpDefCtorAggregate();       // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3TypeClass1::C3Type6{12, 34};                                // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3TypeClass1::C3Type7 = {12, 34};                             // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C3TypeClass1::C3Type8 = Testers::ExpDefCtorAggregate{12, 34}; // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C4TypeClass1 {
    static LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type1;
    static LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type2;
    static LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type3;
    static LOCAL_MEM Testers::ExpDefCtorNonAggregate C4Type4;
};

LOCAL_MEM Testers::ExpDefCtorNonAggregate C4TypeClass1::C4Type1;
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4TypeClass1::C4Type2{};                                   // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4TypeClass1::C4Type3 = {};                                // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorNonAggregate C4TypeClass1::C4Type4 = Testers::ExpDefCtorNonAggregate(); // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C5TypeClass1 {
    static LOCAL_MEM Testers::UserCtorNonAggregate C5Type1A;
    static LOCAL_MEM const Testers::UserCtorNonAggregate C5Type1B;
    static LOCAL_MEM Testers::UserCtorNonAggregate C5Type2;
    static LOCAL_MEM Testers::UserCtorNonAggregate C5Type3;
    static LOCAL_MEM Testers::UserCtorNonAggregate C5Type4;
};

LOCAL_MEM Testers::UserCtorNonAggregate C5TypeClass1::C5Type1A;                                  // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserCtorNonAggregate C5TypeClass1::C5Type1B;                            // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5TypeClass1::C5Type2{};                                 // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5TypeClass1::C5Type3 = {};                              // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C5TypeClass1::C5Type4 = Testers::UserCtorNonAggregate(); // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C6TypeClass1 {
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type1A;
    static LOCAL_MEM const Testers::UserConstexprCtorNonAggregate C6Type1B;
    static LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate C6Type1C{}; // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type2;
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type3;
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6Type4;
};

LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6TypeClass1::C6Type1A;                                           // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserConstexprCtorNonAggregate C6TypeClass1::C6Type1B;                                     // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6TypeClass1::C6Type2{};                                          // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6TypeClass1::C6Type3 = {};                                       // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6TypeClass1::C6Type4 = Testers::UserConstexprCtorNonAggregate(); // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C7TypeClass1 {
    static LOCAL_MEM Testers::NonCtorNonAggregate C7Type5;
    static LOCAL_MEM Testers::NonCtorNonAggregate C7Type6;
    static LOCAL_MEM Testers::NonCtorNonAggregate C7Type7;
    static LOCAL_MEM Testers::NonCtorNonAggregate C7Type8;
    static LOCAL_MEM Testers::NonCtorNonAggregate C7Type9;
    static LOCAL_MEM Testers::NonCtorNonAggregate C7Type10;
};

LOCAL_MEM Testers::NonCtorNonAggregate C7TypeClass1::C7Type5(1234);                                 // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7TypeClass1::C7Type6{1234};                                 // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7TypeClass1::C7Type7 = {1234};                              // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7TypeClass1::C7Type8 = Testers::NonCtorNonAggregate(1234);  // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7TypeClass1::C7Type9 = 1234;                                // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C7TypeClass1::C7Type10 = Testers::NonCtorNonAggregate{1234}; // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C8TypeClass1 {
    static LOCAL_MEM Testers::DerivedAggregate C8Type1;
    static LOCAL_MEM Testers::DerivedAggregate C8Type2;
    static LOCAL_MEM Testers::DerivedAggregate C8Type3;
    static LOCAL_MEM Testers::DerivedAggregate C8Type4;
};

LOCAL_MEM Testers::DerivedAggregate C8TypeClass1::C8Type1;
LOCAL_MEM Testers::DerivedAggregate C8TypeClass1::C8Type2{};                             // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedAggregate C8TypeClass1::C8Type3 = {};                          // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedAggregate C8TypeClass1::C8Type4 = Testers::DerivedAggregate(); // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C9TypeClass1 {
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type1;
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type2;
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type3;
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9Type4;
};

LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9TypeClass1::C9Type1;                                          // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9TypeClass1::C9Type2{};                                        // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9TypeClass1::C9Type3 = {};                                     // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9TypeClass1::C9Type4 = Testers::DerivedUserCtorNonAggregate(); // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct C10TypeClass1 {
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type1;
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type2;
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type3;
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10Type4;
};

LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10TypeClass1::C10Type1;                                            // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10TypeClass1::C10Type2{};                                          // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10TypeClass1::C10Type3 = {};                                       // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10TypeClass1::C10Type4 = Testers::CompositeUserCtorNonAggregate(); // expected-error{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

// Arrays
class TrivialArrClass1 {
public:
    static LOCAL_MEM int TrivialArrType1[2];
    static LOCAL_MEM int TrivialArrType2[2];
    static LOCAL_MEM int TrivialArrType3[2];
    static LOCAL_MEM int TrivialArrType6[2];
    static LOCAL_MEM int TrivialArrType7A[2];
    static LOCAL_MEM const int TrivialArrType7B[2];
    static LOCAL_MEM const int TrivialArrType7C[2] = {1234};     // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr int TrivialArrType7D[2] = {1234}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
};

LOCAL_MEM int TrivialArrClass1::TrivialArrType1[2];
LOCAL_MEM int TrivialArrClass1::TrivialArrType2[2]{};                   // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialArrClass1::TrivialArrType3[2] = {};                // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialArrClass1::TrivialArrType6[2]{1234};               // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int TrivialArrClass1::TrivialArrType7A[2] = {1234};           // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM const int TrivialArrClass1::TrivialArrType7B[2] = {1234};     // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

template <typename T> struct TrivialArrClass2 {
    static LOCAL_MEM T TrivialArrType1[2];
    static LOCAL_MEM T TrivialArrType2[2];
    static LOCAL_MEM T TrivialArrType3[2];
    static LOCAL_MEM T TrivialArrType6[2];
    static LOCAL_MEM T TrivialArrType7A[2];
    static LOCAL_MEM const T TrivialArrType7B[2];
    static LOCAL_MEM const T TrivialArrType7C[2] = {1234};     // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr T TrivialArrType7D[2] = {1234}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
};

template <typename T> LOCAL_MEM T TrivialArrClass2<T>::TrivialArrType1[2];
template <typename T> LOCAL_MEM T TrivialArrClass2<T>::TrivialArrType2[2]{};                   // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialArrClass2<T>::TrivialArrType3[2] = {};                // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialArrClass2<T>::TrivialArrType6[2]{1234};               // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T TrivialArrClass2<T>::TrivialArrType7A[2] = {1234};           // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM const T TrivialArrClass2<T>::TrivialArrType7B[2] = {1234};     // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

struct TrivialVecArrClass1 {
    static LOCAL_MEM float2 TrivialVecArrType1[3];
    static LOCAL_MEM float2 TrivialVecArrType2[3];
    static LOCAL_MEM float2 TrivialVecArrType3[3];
    static LOCAL_MEM float2 TrivialVecArrType6[3];
    static LOCAL_MEM float2 TrivialVecArrType7[3];
};

LOCAL_MEM float2 TrivialVecArrClass1::TrivialVecArrType1[3];
LOCAL_MEM float2 TrivialVecArrClass1::TrivialVecArrType2[3]{};          // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecArrClass1::TrivialVecArrType3[3] = {};       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecArrClass1::TrivialVecArrType6[3]{12, 34};    // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 TrivialVecArrClass1::TrivialVecArrType7[3] = {12, 34}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

struct C1_10TypeArrClass1 {
    static LOCAL_MEM float2 TrivialVecArrType1[3];
    static LOCAL_MEM float2 TrivialVecArrType2[3];
    static LOCAL_MEM float2 TrivialVecArrType3[3];
    static LOCAL_MEM float2 TrivialVecArrType6[3];
    static LOCAL_MEM float2 TrivialVecArrType7[3];

    static LOCAL_MEM Testers::Aggregate C1ArrType1[2][4][6];
    static LOCAL_MEM Testers::Aggregate C1ArrType2[2][4][6];
    static LOCAL_MEM Testers::Aggregate C1ArrType3[2][4][6];
    static LOCAL_MEM Testers::Aggregate C1ArrType6[2][4][6];
    static LOCAL_MEM Testers::Aggregate C1ArrType7[2][4][6];

    static LOCAL_MEM Testers::NonAggregate C2ArrType1[2][4];
    static LOCAL_MEM Testers::NonAggregate C2ArrType2[2][4];
    static LOCAL_MEM Testers::NonAggregate C2ArrType3[2][4];

    static LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType1[4];
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType2[4];
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType3[4];
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType6[4];
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3ArrType7[4];

    static LOCAL_MEM Testers::ExpDefCtorNonAggregate C4ArrType1[3][6];
    static LOCAL_MEM Testers::ExpDefCtorNonAggregate C4ArrType2[3][6];
    static LOCAL_MEM Testers::ExpDefCtorNonAggregate C4ArrType3[3][6];

    static LOCAL_MEM Testers::UserCtorNonAggregate C5ArrType1A[4];
    static LOCAL_MEM const Testers::UserCtorNonAggregate C5ArrType1B[4];
    static LOCAL_MEM Testers::UserCtorNonAggregate C5ArrType2[4];
    static LOCAL_MEM Testers::UserCtorNonAggregate C5ArrType3[4];

    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6ArrType1A[3];
    static LOCAL_MEM const Testers::UserConstexprCtorNonAggregate C6ArrType1B[3];
    static LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate C6ArrType1C[3]{}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6ArrType2[3];
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate C6ArrType3[3];

    static LOCAL_MEM Testers::NonCtorNonAggregate C7ArrType6[1][1];
    static LOCAL_MEM Testers::NonCtorNonAggregate C7ArrType7[1][1];

    static LOCAL_MEM Testers::DerivedAggregate C8ArrType1[2];
    static LOCAL_MEM Testers::DerivedAggregate C8ArrType2[2];
    static LOCAL_MEM Testers::DerivedAggregate C8ArrType3[2];

    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9ArrType1[4];
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9ArrType2[4];
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate C9ArrType3[4];

    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10ArrType1[5];
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10ArrType2[5];
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate C10ArrType3[5];
};

LOCAL_MEM float2 C1_10TypeArrClass1::TrivialVecArrType1[3];
LOCAL_MEM float2 C1_10TypeArrClass1::TrivialVecArrType2[3]{};          // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 C1_10TypeArrClass1::TrivialVecArrType3[3] = {};       // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 C1_10TypeArrClass1::TrivialVecArrType6[3]{12, 34};    // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 C1_10TypeArrClass1::TrivialVecArrType7[3] = {12, 34}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

LOCAL_MEM Testers::Aggregate C1_10TypeArrClass1::C1ArrType1[2][4][6];
LOCAL_MEM Testers::Aggregate C1_10TypeArrClass1::C1ArrType2[2][4][6]{};                // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1_10TypeArrClass1::C1ArrType3[2][4][6] = {};             // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1_10TypeArrClass1::C1ArrType6[2][4][6]{{{{12, 34}}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate C1_10TypeArrClass1::C1ArrType7[2][4][6] = {{{{12, 34}}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonAggregate C1_10TypeArrClass1::C2ArrType1[2][4];
LOCAL_MEM Testers::NonAggregate C1_10TypeArrClass1::C2ArrType2[2][4]{};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonAggregate C1_10TypeArrClass1::C2ArrType3[2][4] = {}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorAggregate C1_10TypeArrClass1::C3ArrType1[4];
LOCAL_MEM Testers::ExpDefCtorAggregate C1_10TypeArrClass1::C3ArrType2[4]{};            // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C1_10TypeArrClass1::C3ArrType3[4] = {};         // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C1_10TypeArrClass1::C3ArrType6[4]{{12, 34}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate C1_10TypeArrClass1::C3ArrType7[4] = {{12, 34}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorNonAggregate C1_10TypeArrClass1::C4ArrType1[3][6];
LOCAL_MEM Testers::ExpDefCtorNonAggregate C1_10TypeArrClass1::C4ArrType2[3][6]{};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorNonAggregate C1_10TypeArrClass1::C4ArrType3[3][6] = {}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::UserCtorNonAggregate C1_10TypeArrClass1::C5ArrType1A[4];       // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserCtorNonAggregate C1_10TypeArrClass1::C5ArrType1B[4]; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C1_10TypeArrClass1::C5ArrType2[4]{};      // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserCtorNonAggregate C1_10TypeArrClass1::C5ArrType3[4] = {};   // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::UserConstexprCtorNonAggregate C1_10TypeArrClass1::C6ArrType1A[3];       // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM const Testers::UserConstexprCtorNonAggregate C1_10TypeArrClass1::C6ArrType1B[3]; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C1_10TypeArrClass1::C6ArrType2[3]{};      // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::UserConstexprCtorNonAggregate C1_10TypeArrClass1::C6ArrType3[3] = {};   // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonCtorNonAggregate C1_10TypeArrClass1::C7ArrType6[1][1]{{Testers::NonCtorNonAggregate{1234}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate C1_10TypeArrClass1::C7ArrType7[1][1] = {{Testers::NonCtorNonAggregate{1234}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::DerivedAggregate C1_10TypeArrClass1::C8ArrType1[2];
LOCAL_MEM Testers::DerivedAggregate C1_10TypeArrClass1::C8ArrType2[2]{};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedAggregate C1_10TypeArrClass1::C8ArrType3[2] = {}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::DerivedUserCtorNonAggregate C1_10TypeArrClass1::C9ArrType1[4];      // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C1_10TypeArrClass1::C9ArrType2[4]{};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::DerivedUserCtorNonAggregate C1_10TypeArrClass1::C9ArrType3[4] = {}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::CompositeUserCtorNonAggregate C1_10TypeArrClass1::C10ArrType1[5];      // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C1_10TypeArrClass1::C10ArrType2[5]{};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::CompositeUserCtorNonAggregate C1_10TypeArrClass1::C10ArrType3[5] = {}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

struct UArrClass1 {
    static LOCAL_MEM int TrivialUArrType6[];
    static LOCAL_MEM int TrivialUArrType7[];

    static LOCAL_MEM float2 TrivialVecUArrType6[];
    static LOCAL_MEM float2 TrivialVecUArrType7[];

    static LOCAL_MEM Testers::Aggregate C1UArrType6[][4][6];
    static LOCAL_MEM Testers::Aggregate C1UArrType7[][4][6];

    static LOCAL_MEM Testers::ExpDefCtorAggregate C3UArrType6[];
    static LOCAL_MEM Testers::ExpDefCtorAggregate C3UArrType7[];

    static LOCAL_MEM Testers::NonCtorNonAggregate C6UArrType6[][1];
    static LOCAL_MEM Testers::NonCtorNonAggregate C6UArrType7[][1];
};

// Auto-sized arrays
LOCAL_MEM int UArrClass1::TrivialUArrType6[]{1234};    // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM int UArrClass1::TrivialUArrType7[2] = {1234}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

LOCAL_MEM float2 UArrClass1::TrivialVecUArrType6[]{12, 34};    // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM float2 UArrClass1::TrivialVecUArrType7[] = {12, 34}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

LOCAL_MEM Testers::Aggregate UArrClass1::C1UArrType6[][4][6]{{{{12, 34}}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::Aggregate UArrClass1::C1UArrType7[][4][6] = {{{{12, 34}}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::ExpDefCtorAggregate UArrClass1::C3UArrType6[]{{12, 34}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::ExpDefCtorAggregate UArrClass1::C3UArrType7[] = {{12, 34}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM Testers::NonCtorNonAggregate UArrClass1::C6UArrType6[][1]{{Testers::NonCtorNonAggregate{1234}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Testers::NonCtorNonAggregate UArrClass1::C6UArrType7[][1] = {{Testers::NonCtorNonAggregate{1234}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

// Typedefs
namespace Helpers {
    template <typename T> struct TypedefDependantHelper { using Type = T; };
    template <typename T> struct TypedefLDependantHelper { using Type = LOCAL_MEM T; };
    template <typename T> using TypedefDep = typename TypedefDependantHelper<T>::Type;
    template <typename T> using TypedefLDep = LOCAL_MEM typename TypedefDependantHelper<T>::Type;
    template <typename T> using TypedefULDep = typename TypedefLDependantHelper<T>::Type;
}

struct TypedefClass1 {
    using TTInt2A22 = TInt2A22;

    static LOCAL_MEM TTInt2A22 TrivialVecArrTType1;
    static LOCAL_MEM TTInt2A22 TrivialVecArrTType2;
    static LOCAL_MEM TTInt2A22 TrivialVecArrTType3;
    static LOCAL_MEM TTInt2A22 TrivialVecArrTType6;
    static LOCAL_MEM TTInt2A22 TrivialVecArrTType7;

    static LOCAL_MEM Helpers::TypedefDep<TAggregateA22> C1ArrTType1;
    static LOCAL_MEM Helpers::TypedefDep<TAggregateA22> C1ArrTType2;
    static LOCAL_MEM Helpers::TypedefDep<TAggregateA22> C1ArrTType3;
    static LOCAL_MEM Helpers::TypedefDep<TAggregateA22> C1ArrTType6;
    static LOCAL_MEM Helpers::TypedefDep<TAggregateA22> C1ArrTType7;

    static Helpers::TypedefLDep<TAggregateA22> C1ArrLTType1;
    static Helpers::TypedefLDep<TAggregateA22> C1ArrLTType2;
    static Helpers::TypedefLDep<TAggregateA22> C1ArrLTType3;
    static Helpers::TypedefLDep<TAggregateA22> C1ArrLTType6;
    static Helpers::TypedefLDep<TAggregateA22> C1ArrLTType7;

    static Helpers::TypedefULDep<TAggregateA22> C1ArrULTType1;
    static Helpers::TypedefULDep<TAggregateA22> C1ArrULTType2;
    static Helpers::TypedefULDep<TAggregateA22> C1ArrULTType3;
    static Helpers::TypedefULDep<TAggregateA22> C1ArrULTType6;
    static Helpers::TypedefULDep<TAggregateA22> C1ArrULTType7;

    static LOCAL_MEM TNonAggregateA22 C2ArrTType1;
    static LOCAL_MEM TNonAggregateA22 C2ArrTType2;
    static LOCAL_MEM TNonAggregateA22 C2ArrTType3;

    static LOCAL_MEM TUserCtorNonAggregateA22 C5ArrTType1;
    static LOCAL_MEM TUserCtorNonAggregateA22 C5ArrTType2;
    static LOCAL_MEM TUserCtorNonAggregateA22 C5ArrTType3;

    static TLTAggregateA22 C1ArrTLTType1;
    static TLTAggregateA22 C1ArrTLTType2;
    static TLTAggregateA22 C1ArrTLTType3;
    static TLTAggregateA22 C1ArrTLTType6;
    static TLTAggregateA22 C1ArrTLTType7;
};

LOCAL_MEM TypedefClass1::TTInt2A22 TypedefClass1::TrivialVecArrTType1;
LOCAL_MEM TypedefClass1::TTInt2A22 TypedefClass1::TrivialVecArrTType2{};            // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM TypedefClass1::TTInt2A22 TypedefClass1::TrivialVecArrTType3 = {};         // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM TypedefClass1::TTInt2A22 TypedefClass1::TrivialVecArrTType6{{12, 34}};    // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
LOCAL_MEM TypedefClass1::TTInt2A22 TypedefClass1::TrivialVecArrTType7 = {{12, 34}}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

LOCAL_MEM Helpers::TypedefDep<TAggregateA22> TypedefClass1::C1ArrTType1;
LOCAL_MEM Helpers::TypedefDep<TAggregateA22> TypedefClass1::C1ArrTType2{};              // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Helpers::TypedefDep<TAggregateA22> TypedefClass1::C1ArrTType3 = {};           // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Helpers::TypedefDep<TAggregateA22> TypedefClass1::C1ArrTType6{{{12, 34}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM Helpers::TypedefDep<TAggregateA22> TypedefClass1::C1ArrTType7 = {{{12, 34}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

Helpers::TypedefLDep<TAggregateA22> TypedefClass1::C1ArrLTType1;
Helpers::TypedefLDep<TAggregateA22> TypedefClass1::C1ArrLTType2{};              // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
Helpers::TypedefLDep<TAggregateA22> TypedefClass1::C1ArrLTType3 = {};           // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
Helpers::TypedefLDep<TAggregateA22> TypedefClass1::C1ArrLTType6{{{12, 34}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
Helpers::TypedefLDep<TAggregateA22> TypedefClass1::C1ArrLTType7 = {{{12, 34}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

Helpers::TypedefULDep<TAggregateA22> TypedefClass1::C1ArrULTType1;
Helpers::TypedefULDep<TAggregateA22> TypedefClass1::C1ArrULTType2{};              // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
Helpers::TypedefULDep<TAggregateA22> TypedefClass1::C1ArrULTType3 = {};           // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
Helpers::TypedefULDep<TAggregateA22> TypedefClass1::C1ArrULTType6{{{12, 34}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
Helpers::TypedefULDep<TAggregateA22> TypedefClass1::C1ArrULTType7 = {{{12, 34}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM TNonAggregateA22 TypedefClass1::C2ArrTType1;
LOCAL_MEM TNonAggregateA22 TypedefClass1::C2ArrTType2{};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TNonAggregateA22 TypedefClass1::C2ArrTType3 = {}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

LOCAL_MEM TUserCtorNonAggregateA22 TypedefClass1::C5ArrTType1;      // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TUserCtorNonAggregateA22 TypedefClass1::C5ArrTType2{};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
LOCAL_MEM TUserCtorNonAggregateA22 TypedefClass1::C5ArrTType3 = {}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

TLTAggregateA22 TypedefClass1::C1ArrTLTType1;
TLTAggregateA22 TypedefClass1::C1ArrTLTType2{};              // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
TLTAggregateA22 TypedefClass1::C1ArrTLTType3 = {};           // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
TLTAggregateA22 TypedefClass1::C1ArrTLTType6{{{12, 34}}};    // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
TLTAggregateA22 TypedefClass1::C1ArrTLTType7 = {{{12, 34}}}; // expected-error{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

// Template variables
struct TemplateVarClass1 {
    template <typename T> static LOCAL_MEM T TemplateVarType1;
    template <typename T> static LOCAL_MEM T TemplateVarType2;
    template <typename T> static LOCAL_MEM T TemplateVarType3;
    template <typename T> static LOCAL_MEM T TemplateVarType4{}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
};

template <> LOCAL_MEM int TemplateVarClass1::TemplateVarType1<int>;
template <> LOCAL_MEM int TemplateVarClass1::TemplateVarType2<int>{};      // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <> LOCAL_MEM int TemplateVarClass1::TemplateVarType3<int> = 1234; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

// NOTE: Treated as external in clang (and ignored - why?), because TemplateVarType1<> is treated as declaration of specialization (not definition).
template <> LOCAL_MEM Testers::Aggregate TemplateVarClass1::TemplateVarType1<Testers::Aggregate>;
template <> LOCAL_MEM Testers::UserCtorNonAggregate TemplateVarClass1::TemplateVarType1<Testers::UserCtorNonAggregate>;                         // expected-error 0-1{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
template <> LOCAL_MEM Testers::DerivedUserCtorNonAggregate TemplateVarClass1::TemplateVarType1<Testers::DerivedUserCtorNonAggregate>;           // expected-error 0-1{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
template <> LOCAL_MEM Testers::CompositeUserCtorNonAggregate TemplateVarClass1::TemplateVarType1<Testers::CompositeUserCtorNonAggregate[2]>[2]; // expected-error 0-1{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

// Type dependant entities
template <typename T> struct TypeDepClass1 {
    static LOCAL_MEM T TDepType1;
    static LOCAL_MEM T TDepArrType1[3];
    static LOCAL_MEM T TDepUArrType1[];
    template <typename U> static LOCAL_MEM decltype(U(), T()) TDepTemplateVarType1;
};

template <typename T> LOCAL_MEM T TypeDepClass1<T>::TDepType1;
template <typename T> LOCAL_MEM T TypeDepClass1<T>::TDepArrType1[3];
template <typename T> LOCAL_MEM T TypeDepClass1<T>::TDepUArrType1[]{};                                                    // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}
template <typename T> template <typename U> static LOCAL_MEM decltype(U(), T()) TypeDepClass1<T>::TDepTemplateVarType1{}; // expected-error{{initialization of static data member with local storage (local address space) is forbidden}}

template struct TypeDepClass1<Testers::Aggregate>;
template struct TypeDepClass1<int>;

template <typename T> struct TypeDepClass2 {
    static LOCAL_MEM T TDepType1;
    static LOCAL_MEM T TDepArrType1[3];
};

template <typename T> LOCAL_MEM T TypeDepClass2<T>::TDepType1;       // expected-error 4{{static data member with local storage (local address space) must be default-initialized with trivial default constructor}}
template <typename T> LOCAL_MEM T TypeDepClass2<T>::TDepArrType1[3]; // expected-error 3{{elements of static data member with local storage (local address space) must be default-initialized with trivial default constructor}}

template struct TypeDepClass2<Testers::UserCtorNonAggregate>;          // expected-note 2{{in instantiation of static data member}}
template struct TypeDepClass2<Testers::DerivedUserCtorNonAggregate>;   // expected-note 2{{in instantiation of static data member}}
template struct TypeDepClass2<Testers::CompositeUserCtorNonAggregate>; // expected-note 2{{in instantiation of static data member}}

// Life-time extended temporary variables (class-scope).
struct LExtClass1 {
    static const int &                          LExtTmpL1A;
    static LOCAL_MEM const int &                LExtTmpL1B;
    static const float3 &                       LExtTmpL2A;
    static LOCAL_MEM const float3 &             LExtTmpL2B;
    static const Testers::Aggregate &           LExtTmpL3A;
    static LOCAL_MEM const Testers::Aggregate & LExtTmpL3B;
    static const TInt2A22 &                     LExtTmpL4A;
    static LOCAL_MEM const TInt2A22 &           LExtTmpL4B;

    static const Testers::Aggregate           (& LExtTmpL5A)[];
    static LOCAL_MEM const Testers::Aggregate (& LExtTmpL5B)[];

    static int &&                          LExtTmpR1A;
    static LOCAL_MEM int &&                LExtTmpR1B;
    static float3 &&                       LExtTmpR2A;
    static LOCAL_MEM float3 &&             LExtTmpR2B;
    static Testers::Aggregate &&           LExtTmpR3A;
    static LOCAL_MEM Testers::Aggregate && LExtTmpR3B;
    static TInt2A22 &&                     LExtTmpR4A;
    static LOCAL_MEM TInt2A22 &&           LExtTmpR4B;

    static Testers::Aggregate           (&& LExtTmpR5A)[];
    static LOCAL_MEM Testers::Aggregate (&& LExtTmpR5B)[];

    static const Testers::AggregateLRef1 &  LExtTmpN1A;
    static const Testers::LAggregateLRef1 & LExtTmpN1B;
    static const Testers::AggregateRRef1 &  LExtTmpN2A;
    static const Testers::LAggregateRRef1 & LExtTmpN2B;
    static Testers::AggregateLRef1 &&       LExtTmpN3A;
    static Testers::LAggregateLRef1 &&      LExtTmpN3B;
    static Testers::AggregateRRef1 &&       LExtTmpN4A;
    static Testers::LAggregateRRef1 &&      LExtTmpN4B;
    static const Testers::AggregateLRef2 &  LExtTmpN5A;
    static const Testers::LAggregateLRef2 & LExtTmpN5B;
    static const Testers::AggregateRRef2 &  LExtTmpN6A;
    static const Testers::LAggregateRRef2 & LExtTmpN6B;
    static Testers::AggregateLRef2 &&       LExtTmpN7A;
    static Testers::LAggregateLRef2 &&      LExtTmpN7B;
    static Testers::AggregateRRef2 &&       LExtTmpN8A;
    static Testers::LAggregateRRef2 &&      LExtTmpN8B;
};

// Life-time extended temporary variables (class-scope, lvalue reference)
const int &                          LExtClass1::LExtTmpL1A = 1;
LOCAL_MEM const int &                LExtClass1::LExtTmpL1B = 1;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const float3 &                       LExtClass1::LExtTmpL2A = {};
LOCAL_MEM const float3 &             LExtClass1::LExtTmpL2B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const Testers::Aggregate &           LExtClass1::LExtTmpL3A = {};
LOCAL_MEM const Testers::Aggregate & LExtClass1::LExtTmpL3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
const TInt2A22 &                     LExtClass1::LExtTmpL4A = {};
LOCAL_MEM const TInt2A22 &           LExtClass1::LExtTmpL4B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

const Testers::Aggregate           (& LExtClass1::LExtTmpL5A)[] = {{}};
LOCAL_MEM const Testers::Aggregate (& LExtClass1::LExtTmpL5B)[] = {{}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Life-time extended temporary variables (class-scope, rvalue reference)
int &&                          LExtClass1::LExtTmpR1A = 1;
LOCAL_MEM int &&                LExtClass1::LExtTmpR1B = 1;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
float3 &&                       LExtClass1::LExtTmpR2A = {};
LOCAL_MEM float3 &&             LExtClass1::LExtTmpR2B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
Testers::Aggregate &&           LExtClass1::LExtTmpR3A = {};
LOCAL_MEM Testers::Aggregate && LExtClass1::LExtTmpR3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
TInt2A22 &&                     LExtClass1::LExtTmpR4A = {};
LOCAL_MEM TInt2A22 &&           LExtClass1::LExtTmpR4B = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

Testers::Aggregate           (&& LExtClass1::LExtTmpR5A)[] = {{}};
LOCAL_MEM Testers::Aggregate (&& LExtClass1::LExtTmpR5B)[] = {{}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Life-time extended temporary variables (class-scope, nested)
const Testers::AggregateLRef1 &  LExtClass1::LExtTmpN1A = {{}};
const Testers::LAggregateLRef1 & LExtClass1::LExtTmpN1B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const Testers::AggregateRRef1 &  LExtClass1::LExtTmpN2A = {{}};
const Testers::LAggregateRRef1 & LExtClass1::LExtTmpN2B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
Testers::AggregateLRef1 &&       LExtClass1::LExtTmpN3A = {{}};
Testers::LAggregateLRef1 &&      LExtClass1::LExtTmpN3B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
Testers::AggregateRRef1 &&       LExtClass1::LExtTmpN4A = {{}};
Testers::LAggregateRRef1 &&      LExtClass1::LExtTmpN4B = {{}}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
const Testers::AggregateLRef2 &  LExtClass1::LExtTmpN5A = {{}};
const Testers::LAggregateLRef2 & LExtClass1::LExtTmpN5B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
const Testers::AggregateRRef2 &  LExtClass1::LExtTmpN6A = {{}};
const Testers::LAggregateRRef2 & LExtClass1::LExtTmpN6B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
Testers::AggregateLRef2 &&       LExtClass1::LExtTmpN7A = {{}};
Testers::LAggregateLRef2 &&      LExtClass1::LExtTmpN7B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
Testers::AggregateRRef2 &&       LExtClass1::LExtTmpN8A = {{}};
Testers::LAggregateRRef2 &&      LExtClass1::LExtTmpN8B = {{}}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

// Life-time extended temporary variables (class-scope, init list + brace elision)
Testers::AggregateLRef1  LExtAggInitList1[] = {1, 2, 3}; // expected-warning 3{{suggest braces}}
Testers::LAggregateLRef1 LExtAggInitList2[] = {1, 2, 3}; // expected-error 3{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}} // expected-warning 3{{suggest braces}}
Testers::AggregateRRef1  LExtAggInitList3[] = {1, 2, 3}; // expected-warning 3{{suggest braces}}
Testers::LAggregateRRef1 LExtAggInitList4[] = {1, 2, 3}; // expected-error 3{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}} // expected-warning 3{{suggest braces}}

// Type-dependant life-extended temporary variables
template <typename T> struct LExtDepClass1 {
    static LOCAL_MEM const T & LExtTmpL1;
    static LOCAL_MEM T &&      LExtTmpR1;
};

template <typename T> LOCAL_MEM const T & LExtDepClass1<T>::LExtTmpL1 = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
template <typename T> LOCAL_MEM T &&      LExtDepClass1<T>::LExtTmpR1 = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}


kernel void worker() {
    // NOTE: Treated as external in clang, because TemplateVarType3 is treated as declaration.
    auto v1 = TemplateVarClass1::TemplateVarType3<Testers::DerivedAggregate>;
    auto v2 = TemplateVarClass1::TemplateVarType3<Testers::DerivedUserCtorNonAggregate>; // expected-error 0-1{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    auto v3 = TypeDepClass2<Testers::NonAggregate>::TDepType1;
    auto v4 = TypeDepClass2<Testers::UserConstexprCtorNonAggregate>::TDepType1; // expected-note{{in instantiation of static data member}}

    auto v5 = LExtDepClass1<int>::LExtTmpL1; // expected-note{{in instantiation of static data member}}
    auto v6 = LExtDepClass1<int>::LExtTmpR1; // expected-note{{in instantiation of static data member}}
}