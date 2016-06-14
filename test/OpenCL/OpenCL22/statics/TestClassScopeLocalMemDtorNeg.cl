// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o -

#define LOCAL_MEM __local

#include "../opencl_def"

namespace Testers
{
    // explicitly defined defaulted default destructor; aggregate
    struct ExpDefDtorAggregate {
        int a;
        long b;

        ~ExpDefDtorAggregate() = default;
    };

    // explicitly defined defaulted default destructor; non-aggregate
    struct ExpDefDtorNonAggregate {
        int a;
    private:
        long b;

    public:
        ExpDefDtorNonAggregate() = default;
        ~ExpDefDtorNonAggregate() = default;
        void setB(long val) { b = val; }
    };

    // user defined defaulted default destructor; aggregate
    struct UserDtorAggregate {
        int a;
        long b;

        UserDtorAggregate() = default;
        ~UserDtorAggregate();
    };

    UserDtorAggregate::~UserDtorAggregate() = default;


    // user defined defaulted default destructor; non-aggregate
    struct UserDtorNonAggregate {
        int a;
    private:
        long b;

    public:
        UserDtorNonAggregate() = default;
        ~UserDtorNonAggregate();
        void setB(long val) { b = val; }
    };

    UserDtorNonAggregate::~UserDtorNonAggregate() = default;

    struct DerivedUserDtorNonAggregate : UserDtorNonAggregate {};

    struct CompositeUserDtorAggregate {
        UserDtorAggregate m;
    };

    using   TExpDefDtorNonAggregate = ExpDefDtorNonAggregate;
    typedef UserDtorAggregate         TUserDtorAggregate;
}

typedef Testers::TExpDefDtorNonAggregate TExpDefDtorNonAggregate;
using   TUserDtorAggregate             = Testers::TUserDtorAggregate;

typedef TExpDefDtorNonAggregate TExpDefDtorNonAggregate2[2];
typedef TUserDtorAggregate      TUserDtorAggregate2[2];

using TExpDefDtorNonAggregate22 = TExpDefDtorNonAggregate2[2];
using TUserDtorAggregate22      = TUserDtorAggregate2[2];

typedef LOCAL_MEM TExpDefDtorNonAggregate22 LTExpDefDtorNonAggregate22;
typedef LOCAL_MEM TUserDtorAggregate22      LTUserDtorAggregate22;
using TLTExpDefDtorNonAggregate22 = LTExpDefDtorNonAggregate22;
using TLTUserDtorAggregate22      = LTUserDtorAggregate22;


// Single
class WrapperClass1 {
public:
    static LOCAL_MEM Testers::ExpDefDtorAggregate         C1Type;
    static LOCAL_MEM Testers::ExpDefDtorNonAggregate      C2Type;
    static LOCAL_MEM Testers::UserDtorAggregate           C3Type;
    static LOCAL_MEM Testers::UserDtorNonAggregate        C4Type;
    static LOCAL_MEM Testers::DerivedUserDtorNonAggregate C5Type;
    static LOCAL_MEM Testers::CompositeUserDtorAggregate  C6Type;
};

LOCAL_MEM Testers::ExpDefDtorAggregate         WrapperClass1::C1Type;
LOCAL_MEM Testers::ExpDefDtorNonAggregate      WrapperClass1::C2Type;
LOCAL_MEM Testers::UserDtorAggregate           WrapperClass1::C3Type; // expected-error{{static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::UserDtorNonAggregate        WrapperClass1::C4Type; // expected-error{{static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::DerivedUserDtorNonAggregate WrapperClass1::C5Type; // expected-error{{static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::CompositeUserDtorAggregate  WrapperClass1::C6Type; // expected-error{{static data member with local storage (local address space) must have trivial destructor}}

// Arrays
struct WrapperClass2 {
    static LOCAL_MEM Testers::ExpDefDtorAggregate         C1ArrType[];
    static LOCAL_MEM Testers::ExpDefDtorNonAggregate      C2ArrType[];
    static LOCAL_MEM Testers::UserDtorAggregate           C3ArrType[];
    static LOCAL_MEM Testers::UserDtorNonAggregate        C4ArrType[];
    static LOCAL_MEM Testers::DerivedUserDtorNonAggregate C5ArrType[];
    static LOCAL_MEM Testers::CompositeUserDtorAggregate  C6ArrType[];
};

LOCAL_MEM Testers::ExpDefDtorAggregate         WrapperClass2::C1ArrType[3];
LOCAL_MEM Testers::ExpDefDtorNonAggregate      WrapperClass2::C2ArrType[3];
LOCAL_MEM Testers::UserDtorAggregate           WrapperClass2::C3ArrType[3]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::UserDtorNonAggregate        WrapperClass2::C4ArrType[3]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::DerivedUserDtorNonAggregate WrapperClass2::C5ArrType[3]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::CompositeUserDtorAggregate  WrapperClass2::C6ArrType[3]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}

struct WrapperClass3 {
    static LOCAL_MEM Testers::ExpDefDtorAggregate         C1ArrType[2][2];
    static LOCAL_MEM Testers::ExpDefDtorNonAggregate      C2ArrType[2][2];
    static LOCAL_MEM Testers::UserDtorAggregate           C3ArrType[2][2];
    static LOCAL_MEM Testers::UserDtorNonAggregate        C4ArrType[2][2];
    static LOCAL_MEM Testers::DerivedUserDtorNonAggregate C5ArrType[2][2];
    static LOCAL_MEM Testers::CompositeUserDtorAggregate  C6ArrType[2][2];
};

LOCAL_MEM Testers::ExpDefDtorAggregate         WrapperClass3::C1ArrType[2][2];
LOCAL_MEM Testers::ExpDefDtorNonAggregate      WrapperClass3::C2ArrType[2][2];
LOCAL_MEM Testers::UserDtorAggregate           WrapperClass3::C3ArrType[2][2]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::UserDtorNonAggregate        WrapperClass3::C4ArrType[2][2]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::DerivedUserDtorNonAggregate WrapperClass3::C5ArrType[2][2]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::CompositeUserDtorAggregate  WrapperClass3::C6ArrType[2][2]; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}

// Typedefs
namespace Helpers {
    template <typename T> struct TypedefDependantHelper { using Type = T; };
    template <typename T> struct TypedefLDependantHelper { using Type = LOCAL_MEM T; };
    template <typename T> using TypedefDep = typename TypedefDependantHelper<T>::Type;
    template <typename T> using TypedefLDep = LOCAL_MEM typename TypedefDependantHelper<T>::Type;
    template <typename T> using TypedefULDep = typename TypedefLDependantHelper<T>::Type;
}


struct WrapperClass4 {
    static LOCAL_MEM TExpDefDtorNonAggregate22 C2ArrSTType;
    static LOCAL_MEM TUserDtorAggregate22      C3ArrSTType;

    static LOCAL_MEM Helpers::TypedefDep<TExpDefDtorNonAggregate22> C2ArrTType;
    static LOCAL_MEM Helpers::TypedefDep<TUserDtorAggregate22>      C3ArrTType;

    static Helpers::TypedefLDep<TExpDefDtorNonAggregate22> C2ArrLTType;
    static Helpers::TypedefLDep<TUserDtorAggregate22>      C3ArrLTType;

    static Helpers::TypedefULDep<TExpDefDtorNonAggregate22> C2ArrULTType;
    static Helpers::TypedefULDep<TUserDtorAggregate22>      C3ArrULTType;

    static TLTExpDefDtorNonAggregate22 C2ArrTLTType;
    static TLTUserDtorAggregate22      C3ArrTLTType;
};

LOCAL_MEM TExpDefDtorNonAggregate22 WrapperClass4::C2ArrSTType;
LOCAL_MEM TUserDtorAggregate22      WrapperClass4::C3ArrSTType; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}

LOCAL_MEM Helpers::TypedefDep<TExpDefDtorNonAggregate22> WrapperClass4::C2ArrTType;
LOCAL_MEM Helpers::TypedefDep<TUserDtorAggregate22>      WrapperClass4::C3ArrTType; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}

Helpers::TypedefLDep<TExpDefDtorNonAggregate22> WrapperClass4::C2ArrLTType;
Helpers::TypedefLDep<TUserDtorAggregate22>      WrapperClass4::C3ArrLTType; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}

Helpers::TypedefULDep<TExpDefDtorNonAggregate22> WrapperClass4::C2ArrULTType;
Helpers::TypedefULDep<TUserDtorAggregate22>      WrapperClass4::C3ArrULTType; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}

TLTExpDefDtorNonAggregate22 WrapperClass4::C2ArrTLTType;
TLTUserDtorAggregate22      WrapperClass4::C3ArrTLTType; // expected-error{{elements of static data member with local storage (local address space) must have trivial destructor}}

// Type dependant entities
template <typename T> struct TypeDepClass1 {
    static LOCAL_MEM T TDepType1;
    static LOCAL_MEM T TDepArrType1[3];
};

template <typename T> LOCAL_MEM T TypeDepClass1<T>::TDepType1;
template <typename T> LOCAL_MEM T TypeDepClass1<T>::TDepArrType1[3];

template struct TypeDepClass1<Testers::ExpDefDtorAggregate>;
template struct TypeDepClass1<Testers::ExpDefDtorNonAggregate>;

template <typename T> struct TypeDepClass2 {
    static LOCAL_MEM T TDepType1;
    static LOCAL_MEM T TDepArrType1[3];
};

template <typename T> LOCAL_MEM T TypeDepClass2<T>::TDepType1;       // expected-error 4{{static data member with local storage (local address space) must have trivial destructor}}
template <typename T> LOCAL_MEM T TypeDepClass2<T>::TDepArrType1[3]; // expected-error 3{{elements of static data member with local storage (local address space) must have trivial destructor}}

template struct TypeDepClass2<Testers::UserDtorAggregate>;           // expected-note 2{{in instantiation of static data member}}
template struct TypeDepClass2<Testers::UserDtorNonAggregate>;        // expected-note 2{{in instantiation of static data member}}
template struct TypeDepClass2<Testers::DerivedUserDtorNonAggregate>; // expected-note 2{{in instantiation of static data member}}


kernel void worker() {
    auto v1 = TypeDepClass2<Testers::CompositeUserDtorAggregate>::TDepType1; // expected-note{{in instantiation of static data member}}
}