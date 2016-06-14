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
LOCAL_MEM Testers::ExpDefDtorAggregate         C1Type;
LOCAL_MEM Testers::ExpDefDtorNonAggregate      C2Type;
LOCAL_MEM Testers::UserDtorAggregate           C3Type; // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::UserDtorNonAggregate        C4Type; // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::DerivedUserDtorNonAggregate C5Type; // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::CompositeUserDtorAggregate  C6Type; // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}

// Arrays
LOCAL_MEM Testers::ExpDefDtorAggregate         C1ArrType1[3];
LOCAL_MEM Testers::ExpDefDtorNonAggregate      C2ArrType1[3];
LOCAL_MEM Testers::UserDtorAggregate           C3ArrType1[3]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::UserDtorNonAggregate        C4ArrType1[3]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::DerivedUserDtorNonAggregate C5ArrType1[3]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::CompositeUserDtorAggregate  C6ArrType1[3]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}

LOCAL_MEM Testers::ExpDefDtorAggregate         C1ArrType2[2][2];
LOCAL_MEM Testers::ExpDefDtorNonAggregate      C2ArrType2[2][2];
LOCAL_MEM Testers::UserDtorAggregate           C3ArrType2[2][2]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::UserDtorNonAggregate        C4ArrType2[2][2]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::DerivedUserDtorNonAggregate C5ArrType2[2][2]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}
LOCAL_MEM Testers::CompositeUserDtorAggregate  C6ArrType2[2][2]; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}

// Typedefs
LOCAL_MEM TExpDefDtorNonAggregate22 C2ArrTType;
LOCAL_MEM TUserDtorAggregate22      C3ArrTType; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}

TLTExpDefDtorNonAggregate22 C2ArrTLTType;
TLTUserDtorAggregate22      C3ArrTLTType; // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}

// Template variables
template <typename T> LOCAL_MEM T TemplateVarType1;
template <typename T> T           TemplateVarType2;

template <> LOCAL_MEM Testers::ExpDefDtorAggregate         TemplateVarType1<Testers::ExpDefDtorAggregate>;
template <> LOCAL_MEM Testers::ExpDefDtorNonAggregate      TemplateVarType1<Testers::ExpDefDtorNonAggregate>;
template <> LOCAL_MEM Testers::UserDtorAggregate           TemplateVarType1<Testers::UserDtorAggregate>;           // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}
template <> LOCAL_MEM Testers::UserDtorNonAggregate        TemplateVarType1<Testers::UserDtorNonAggregate>;        // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}
template <> LOCAL_MEM Testers::DerivedUserDtorNonAggregate TemplateVarType1<Testers::DerivedUserDtorNonAggregate>; // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}
template <> LOCAL_MEM Testers::CompositeUserDtorAggregate  TemplateVarType1<Testers::CompositeUserDtorAggregate>;  // expected-error{{program-scope variable with local storage (local address space) must have trivial destructor}}

template <> TLTExpDefDtorNonAggregate22 TemplateVarType2<TLTExpDefDtorNonAggregate22>;
template <> TLTUserDtorAggregate22      TemplateVarType2<TLTUserDtorAggregate22>;      // expected-error{{elements of program-scope variable with local storage (local address space) must have trivial destructor}}