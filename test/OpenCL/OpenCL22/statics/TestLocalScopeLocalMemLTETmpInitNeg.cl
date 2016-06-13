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


kernel void worker_l() {
    // Life-time extended temporary variables (local-/kernel-scope, lvalue reference)
    const int &                            LExtTmpL1A = 1;
    LOCAL_MEM const int &                  LExtTmpL1B = 2;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM const int &           LExtTmpL1C = 3;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr const int &        LExtTmpL1D = 4;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr const int & LExtTmpL1E = 5;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    const float3 &                            LExtTmpL2A = {1, 2, 3};
    LOCAL_MEM const float3 &                  LExtTmpL2B = {1, 2, 3}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM const float3 &           LExtTmpL2C = {};        // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr const float3 &        LExtTmpL2D = float3();  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr const float3 & LExtTmpL2E = 5;         // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    const Testers::Aggregate &                            LExtTmpL3A = {};
    LOCAL_MEM const Testers::Aggregate &                  LExtTmpL3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::Aggregate &           LExtTmpL3C = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::Aggregate &        LExtTmpL3D = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::Aggregate & LExtTmpL3E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Non-aggregate with trivial default constructor and destructor is default-initialized when
    //       brace-or-equal init is used (so no init takes place and cases B., C. are allowed).
    //       Copy initializer causes value-initialization so it is forbidden (case D.).
    const Testers::NonAggregate &           LExtTmpL4A = {};
    LOCAL_MEM const Testers::NonAggregate & LExtTmpL4B{};
    LOCAL_MEM const Testers::NonAggregate & LExtTmpL4C = {};
    LOCAL_MEM const Testers::NonAggregate & LExtTmpL4D = Testers::NonAggregate(); // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::ExpDefCtorAggregate &                            LExtTmpL5A = {};
    LOCAL_MEM const Testers::ExpDefCtorAggregate &                  LExtTmpL5B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::ExpDefCtorAggregate &           LExtTmpL5C = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::ExpDefCtorAggregate &        LExtTmpL5D = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::ExpDefCtorAggregate & LExtTmpL5E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::ExpDefCtorNonAggregate &           LExtTmpL6A = {};
    LOCAL_MEM const Testers::ExpDefCtorNonAggregate & LExtTmpL6B{};
    LOCAL_MEM const Testers::ExpDefCtorNonAggregate & LExtTmpL6C = {};
    LOCAL_MEM const Testers::ExpDefCtorNonAggregate & LExtTmpL6D = Testers::ExpDefCtorNonAggregate(); // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::UserCtorNonAggregate &                            LExtTmpL7A = {};
    LOCAL_MEM const Testers::UserCtorNonAggregate &                  LExtTmpL7B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::UserCtorNonAggregate &           LExtTmpL7C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::UserCtorNonAggregate &        LExtTmpL7D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::UserCtorNonAggregate & LExtTmpL7E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::UserConstexprCtorNonAggregate &                            LExtTmpL8A = {};
    LOCAL_MEM const Testers::UserConstexprCtorNonAggregate &                  LExtTmpL8B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::UserConstexprCtorNonAggregate &           LExtTmpL8C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::UserConstexprCtorNonAggregate &        LExtTmpL8D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::UserConstexprCtorNonAggregate & LExtTmpL8E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::NonCtorNonAggregate &                            LExtTmpL9A = {1};
    LOCAL_MEM const Testers::NonCtorNonAggregate &                  LExtTmpL9B = {1}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::NonCtorNonAggregate &           LExtTmpL9C{1};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::NonCtorNonAggregate &        LExtTmpL9D{1};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::NonCtorNonAggregate & LExtTmpL9E = {1}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Class derived from aggregate is not aggregate (aggregate cannot have base classes).
    //       It will behave as non-aggregate class with trivial default constructor and destructor.
    const Testers::DerivedAggregate &                  LExtTmpL10A = {};
    LOCAL_MEM const Testers::DerivedAggregate &        LExtTmpL10B = {};
    static LOCAL_MEM const Testers::DerivedAggregate & LExtTmpL10C{};

    const Testers::DerivedUserCtorNonAggregate &                            LExtTmpL11A = {};
    LOCAL_MEM const Testers::DerivedUserCtorNonAggregate &                  LExtTmpL11B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::DerivedUserCtorNonAggregate &           LExtTmpL11C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::DerivedUserCtorNonAggregate &        LExtTmpL11D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::DerivedUserCtorNonAggregate & LExtTmpL11E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::CompositeUserCtorNonAggregate &                            LExtTmpL12A = {};
    LOCAL_MEM const Testers::CompositeUserCtorNonAggregate &                  LExtTmpL12B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::CompositeUserCtorNonAggregate &           LExtTmpL12C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::CompositeUserCtorNonAggregate &        LExtTmpL12D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::CompositeUserCtorNonAggregate & LExtTmpL12E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
}

kernel void worker_la() {
    // Life-time extended temporary variables (local-/kernel-scope, lvalue reference)
    const int                            (& LExtTmpL1A)[2] = {};
    LOCAL_MEM const int                  (& LExtTmpL1B)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM const int           (& LExtTmpL1C)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr const int        (& LExtTmpL1D)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr const int (& LExtTmpL1E)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    const float3                            (& LExtTmpL2A)[2][2] = {};
    LOCAL_MEM const float3                  (& LExtTmpL2B)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM const float3           (& LExtTmpL2C)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr const float3        (& LExtTmpL2D)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr const float3 (& LExtTmpL2E)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    const Testers::Aggregate                            (& LExtTmpL3A)[3][2][1] = {};
    LOCAL_MEM const Testers::Aggregate                  (& LExtTmpL3B)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::Aggregate           (& LExtTmpL3C)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::Aggregate        (& LExtTmpL3D)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::Aggregate (& LExtTmpL3E)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Array is always aggregate (the elements are copy-initialized or value-initialized).
    const Testers::NonAggregate           (& LExtTmpL4A)[1] = {};
    LOCAL_MEM const Testers::NonAggregate (& LExtTmpL4B)[1]{};                           // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM const Testers::NonAggregate (& LExtTmpL4C)[1] = {};                        // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM const Testers::NonAggregate (& LExtTmpL4D)[1] = {Testers::NonAggregate()}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::ExpDefCtorAggregate                            (& LExtTmpL5A)[2][1] = {};
    LOCAL_MEM const Testers::ExpDefCtorAggregate                  (& LExtTmpL5B)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::ExpDefCtorAggregate           (& LExtTmpL5C)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::ExpDefCtorAggregate        (& LExtTmpL5D)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::ExpDefCtorAggregate (& LExtTmpL5E)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::ExpDefCtorNonAggregate           (& LExtTmpL6A)[4] = {};
    LOCAL_MEM const Testers::ExpDefCtorNonAggregate (& LExtTmpL6B)[4]{};                                     // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM const Testers::ExpDefCtorNonAggregate (& LExtTmpL6C)[4] = {};                                  // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM const Testers::ExpDefCtorNonAggregate (& LExtTmpL6D)[4] = {Testers::ExpDefCtorNonAggregate()}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::UserCtorNonAggregate                             (& LExtTmpL7A)[3][2] = {};
    LOCAL_MEM const Testers::UserCtorNonAggregate                   (& LExtTmpL7B)[3][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::UserCtorNonAggregate            (& LExtTmpL7C)[3][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::UserCtorNonAggregate         (& LExtTmpL7D)[3][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::UserCtorNonAggregate  (& LExtTmpL7E)[3][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::UserConstexprCtorNonAggregate                             (& LExtTmpL8A)[1][1] = {};
    LOCAL_MEM const Testers::UserConstexprCtorNonAggregate                   (& LExtTmpL8B)[1][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::UserConstexprCtorNonAggregate            (& LExtTmpL8C)[1][1]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::UserConstexprCtorNonAggregate         (& LExtTmpL8D)[1][1]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::UserConstexprCtorNonAggregate  (& LExtTmpL8E)[1][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::NonCtorNonAggregate                             (& LExtTmpL9A)[1][1][1] = {{{1}}};
    LOCAL_MEM const Testers::NonCtorNonAggregate                   (& LExtTmpL9B)[1][1][1] = {{{1}}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::NonCtorNonAggregate            (& LExtTmpL9C)[1][1][1]{{{1}}};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::NonCtorNonAggregate         (& LExtTmpL9D)[1][1][1]{{{1}}};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::NonCtorNonAggregate  (& LExtTmpL9E)[1][1][1] = {{{1}}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Class derived from aggregate is not aggregate (aggregate cannot have base classes).
    //       It will behave as non-aggregate class with trivial default constructor and destructor.
    const Testers::DerivedAggregate                   (& LExtTmpL10A)[2][2] = {};
    LOCAL_MEM const Testers::DerivedAggregate         (& LExtTmpL10B)[2][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::DerivedAggregate  (& LExtTmpL10C)[2][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::DerivedUserCtorNonAggregate                             (& LExtTmpL11A)[2][2] = {};
    LOCAL_MEM const Testers::DerivedUserCtorNonAggregate                   (& LExtTmpL11B)[2][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::DerivedUserCtorNonAggregate            (& LExtTmpL11C)[2][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::DerivedUserCtorNonAggregate         (& LExtTmpL11D)[2][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::DerivedUserCtorNonAggregate  (& LExtTmpL11E)[2][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    const Testers::CompositeUserCtorNonAggregate                             (& LExtTmpL12A)[4][2] = {};
    LOCAL_MEM const Testers::CompositeUserCtorNonAggregate                   (& LExtTmpL12B)[4][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM const Testers::CompositeUserCtorNonAggregate            (& LExtTmpL12C)[4][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr const Testers::CompositeUserCtorNonAggregate         (& LExtTmpL12D)[4][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr const Testers::CompositeUserCtorNonAggregate  (& LExtTmpL12E)[4][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
}

kernel void worker_r() {
    // Life-time extended temporary variables (local-/kernel-scope, rvalue reference)
    int &&                            LExtTmpR1A = 1;
    LOCAL_MEM int &&                  LExtTmpR1B = 2;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM int &&           LExtTmpR1C = 3;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr int &&        LExtTmpR1D = 4;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr int && LExtTmpR1E = 5;  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    float3 &&                            LExtTmpR2A = {1, 2, 3};
    LOCAL_MEM float3 &&                  LExtTmpR2B = {1, 2, 3}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM float3 &&           LExtTmpR2C = {};        // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr float3 &&        LExtTmpR2D = float3();  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr float3 && LExtTmpR2E = 5;         // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    Testers::Aggregate &&                            LExtTmpR3A = {};
    LOCAL_MEM Testers::Aggregate &&                  LExtTmpR3B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::Aggregate &&           LExtTmpR3C = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::Aggregate &&        LExtTmpR3D = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::Aggregate && LExtTmpR3E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Non-aggregate with trivial default constructor and destructor is default-initialized when
    //       brace-or-equal init is used (so no init takes place and cases B., C. are allowed).
    //       Copy initializer causes value-initialization so it is forbidden (case D.).
    Testers::NonAggregate &&           LExtTmpR4A = {};
    LOCAL_MEM Testers::NonAggregate && LExtTmpR4B{};
    LOCAL_MEM Testers::NonAggregate && LExtTmpR4C = {};
    LOCAL_MEM Testers::NonAggregate && LExtTmpR4D = Testers::NonAggregate(); // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::ExpDefCtorAggregate &&                            LExtTmpR5A = {};
    LOCAL_MEM Testers::ExpDefCtorAggregate &&                  LExtTmpR5B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::ExpDefCtorAggregate &&           LExtTmpR5C = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::ExpDefCtorAggregate &&        LExtTmpR5D = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::ExpDefCtorAggregate && LExtTmpR5E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::ExpDefCtorNonAggregate &&           LExtTmpR6A = {};
    LOCAL_MEM Testers::ExpDefCtorNonAggregate && LExtTmpR6B{};
    LOCAL_MEM Testers::ExpDefCtorNonAggregate && LExtTmpR6C = {};
    LOCAL_MEM Testers::ExpDefCtorNonAggregate && LExtTmpR6D = Testers::ExpDefCtorNonAggregate(); // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::UserCtorNonAggregate &&                            LExtTmpR7A = {};
    LOCAL_MEM Testers::UserCtorNonAggregate &&                  LExtTmpR7B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::UserCtorNonAggregate &&           LExtTmpR7C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::UserCtorNonAggregate &&        LExtTmpR7D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::UserCtorNonAggregate && LExtTmpR7E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::UserConstexprCtorNonAggregate &&                            LExtTmpR8A = {};
    LOCAL_MEM Testers::UserConstexprCtorNonAggregate &&                  LExtTmpR8B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate &&           LExtTmpR8C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate &&        LExtTmpR8D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate && LExtTmpR8E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::NonCtorNonAggregate &&                            LExtTmpR9A = {1};
    LOCAL_MEM Testers::NonCtorNonAggregate &&                  LExtTmpR9B = {1}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::NonCtorNonAggregate &&           LExtTmpR9C{1};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::NonCtorNonAggregate &&        LExtTmpR9D{1};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::NonCtorNonAggregate && LExtTmpR9E = {1}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Class derived from aggregate is not aggregate (aggregate cannot have base classes).
    //       It will behave as non-aggregate class with trivial default constructor and destructor.
    Testers::DerivedAggregate &&                  LExtTmpR10A = {};
    LOCAL_MEM Testers::DerivedAggregate &&        LExtTmpR10B = {};
    static LOCAL_MEM Testers::DerivedAggregate && LExtTmpR10C{};

    Testers::DerivedUserCtorNonAggregate &&                            LExtTmpR11A = {};
    LOCAL_MEM Testers::DerivedUserCtorNonAggregate &&                  LExtTmpR11B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate &&           LExtTmpR11C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::DerivedUserCtorNonAggregate &&        LExtTmpR11D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::DerivedUserCtorNonAggregate && LExtTmpR11E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::CompositeUserCtorNonAggregate &&                            LExtTmpR12A = {};
    LOCAL_MEM Testers::CompositeUserCtorNonAggregate &&                  LExtTmpR12B = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate &&           LExtTmpR12C{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::CompositeUserCtorNonAggregate &&        LExtTmpR12D{};    // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::CompositeUserCtorNonAggregate && LExtTmpR12E = {}; // expected-error{{lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
}

kernel void worker_ra() {
    // Life-time extended temporary variables (local-/kernel-scope, rvalue reference)
    int                            (&& LExtTmpL1A)[2] = {};
    LOCAL_MEM int                  (&& LExtTmpL1B)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM int           (&& LExtTmpL1C)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr int        (&& LExtTmpL1D)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr int (&& LExtTmpL1E)[2] = {};  // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    float3                            (&& LExtTmpL2A)[2][2] = {};
    LOCAL_MEM float3                  (&& LExtTmpL2B)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM float3           (&& LExtTmpL2C)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    LOCAL_MEM constexpr float3        (&& LExtTmpL2D)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}
    static LOCAL_MEM constexpr float3 (&& LExtTmpL2E)[2][2] = {}; // expected-error{{initialization of lifetime-extended temporary variable with local storage (local address space) is forbidden}}

    Testers::Aggregate                            (&& LExtTmpL3A)[3][2][1] = {};
    LOCAL_MEM Testers::Aggregate                  (&& LExtTmpL3B)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::Aggregate           (&& LExtTmpL3C)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::Aggregate        (&& LExtTmpL3D)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::Aggregate (&& LExtTmpL3E)[3][2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Array is always aggregate (the elements are copy-initialized or value-initialized).
    Testers::NonAggregate           (&& LExtTmpL4A)[1] = {};
    LOCAL_MEM Testers::NonAggregate (&& LExtTmpL4B)[1]{};                           // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM Testers::NonAggregate (&& LExtTmpL4C)[1] = {};                        // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM Testers::NonAggregate (&& LExtTmpL4D)[1] = {Testers::NonAggregate()}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::ExpDefCtorAggregate                            (&& LExtTmpL5A)[2][1] = {};
    LOCAL_MEM Testers::ExpDefCtorAggregate                  (&& LExtTmpL5B)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::ExpDefCtorAggregate           (&& LExtTmpL5C)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::ExpDefCtorAggregate        (&& LExtTmpL5D)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::ExpDefCtorAggregate (&& LExtTmpL5E)[2][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::ExpDefCtorNonAggregate           (&& LExtTmpL6A)[4] = {};
    LOCAL_MEM Testers::ExpDefCtorNonAggregate (&& LExtTmpL6B)[4]{};                                     // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM Testers::ExpDefCtorNonAggregate (&& LExtTmpL6C)[4] = {};                                  // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM Testers::ExpDefCtorNonAggregate (&& LExtTmpL6D)[4] = {Testers::ExpDefCtorNonAggregate()}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::UserCtorNonAggregate                             (&& LExtTmpL7A)[3][2] = {};
    LOCAL_MEM Testers::UserCtorNonAggregate                   (&& LExtTmpL7B)[3][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::UserCtorNonAggregate            (&& LExtTmpL7C)[3][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::UserCtorNonAggregate         (&& LExtTmpL7D)[3][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::UserCtorNonAggregate  (&& LExtTmpL7E)[3][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::UserConstexprCtorNonAggregate                             (&& LExtTmpL8A)[1][1] = {};
    LOCAL_MEM Testers::UserConstexprCtorNonAggregate                   (&& LExtTmpL8B)[1][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::UserConstexprCtorNonAggregate            (&& LExtTmpL8C)[1][1]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate         (&& LExtTmpL8D)[1][1]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::UserConstexprCtorNonAggregate  (&& LExtTmpL8E)[1][1] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::NonCtorNonAggregate                             (&& LExtTmpL9A)[1][1][1] = {{{1}}};
    LOCAL_MEM Testers::NonCtorNonAggregate                   (&& LExtTmpL9B)[1][1][1] = {{{1}}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::NonCtorNonAggregate            (&& LExtTmpL9C)[1][1][1]{{{1}}};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::NonCtorNonAggregate         (&& LExtTmpL9D)[1][1][1]{{{1}}};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::NonCtorNonAggregate  (&& LExtTmpL9E)[1][1][1] = {{{1}}}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    // NOTE: Class derived from aggregate is not aggregate (aggregate cannot have base classes).
    //       It will behave as non-aggregate class with trivial default constructor and destructor.
    Testers::DerivedAggregate                   (&& LExtTmpL10A)[2][2] = {};
    LOCAL_MEM Testers::DerivedAggregate         (&& LExtTmpL10B)[2][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::DerivedAggregate  (&& LExtTmpL10C)[2][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::DerivedUserCtorNonAggregate                             (&& LExtTmpL11A)[2][2] = {};
    LOCAL_MEM Testers::DerivedUserCtorNonAggregate                   (&& LExtTmpL11B)[2][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::DerivedUserCtorNonAggregate            (&& LExtTmpL11C)[2][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::DerivedUserCtorNonAggregate         (&& LExtTmpL11D)[2][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::DerivedUserCtorNonAggregate  (&& LExtTmpL11E)[2][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}

    Testers::CompositeUserCtorNonAggregate                             (&& LExtTmpL12A)[4][2] = {};
    LOCAL_MEM Testers::CompositeUserCtorNonAggregate                   (&& LExtTmpL12B)[4][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM Testers::CompositeUserCtorNonAggregate            (&& LExtTmpL12C)[4][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    LOCAL_MEM constexpr Testers::CompositeUserCtorNonAggregate         (&& LExtTmpL12D)[4][2]{};    // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
    static LOCAL_MEM constexpr Testers::CompositeUserCtorNonAggregate  (&& LExtTmpL12E)[4][2] = {}; // expected-error{{elements of lifetime-extended temporary variable with local storage (local address space) must be default-initialized with trivial default constructor}}
}
