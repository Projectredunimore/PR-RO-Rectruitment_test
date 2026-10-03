// mini_test.hpp — header-only micro test framework (no external dependencies).
// DO NOT modify this file.
//
// Usage:
//   TEST_CASE("test name") { CHECK(a == b); CHECK_NEAR(x, 1.0, 1e-9); }
//   int main() { return mini_test::run_all(); }
#pragma once

#include <cmath>
#include <cstddef>
#include <exception>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace mini_test {

struct Failure {
    std::string message;
};

struct TestCase {
    std::string name;
    std::function<void()> fn;
};

inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> tests;
    return tests;
}

struct Registrar {
    Registrar(const char* name, std::function<void()> fn) { registry().push_back({name, std::move(fn)}); }
};

template <typename T>
std::string to_str(const T& v) {
    std::ostringstream os;
    os << v;
    return os.str();
}

template <typename T>
std::string to_str(const std::vector<T>& v) {
    std::ostringstream os;
    os << "{";
    for (std::size_t i = 0; i < v.size(); ++i) os << (i ? ", " : "") << v[i];
    os << "}";
    return os.str();
}

inline void fail(const std::string& what, const char* file, int line) {
    std::ostringstream os;
    os << file << ":" << line << ": " << what;
    throw Failure{os.str()};
}

inline int run_all() {
    int passed = 0, failed = 0;
    for (const auto& t : registry()) {
        try {
            t.fn();
            ++passed;
            std::cout << "[  PASS  ] " << t.name << "\n";
        } catch (const Failure& f) {
            ++failed;
            std::cout << "[  FAIL  ] " << t.name << "\n           " << f.message << "\n";
        } catch (const std::exception& e) {
            ++failed;
            std::cout << "[  FAIL  ] " << t.name << "\n           unexpected exception: " << e.what() << "\n";
        } catch (...) {
            ++failed;
            std::cout << "[  FAIL  ] " << t.name << "\n           unknown exception\n";
        }
    }
    std::cout << "\n" << passed << "/" << (passed + failed) << " tests passed\n";
    return failed == 0 ? 0 : 1;
}

}  // namespace mini_test

#define MT_CONCAT_(a, b) a##b
#define MT_CONCAT(a, b) MT_CONCAT_(a, b)

#define TEST_CASE(name)                                                                    \
    static void MT_CONCAT(mt_test_fn_, __LINE__)();                                        \
    static mini_test::Registrar MT_CONCAT(mt_registrar_, __LINE__)(name, &MT_CONCAT(mt_test_fn_, __LINE__)); \
    static void MT_CONCAT(mt_test_fn_, __LINE__)()

#define CHECK(cond) \
    do { if (!(cond)) mini_test::fail("CHECK(" #cond ") failed", __FILE__, __LINE__); } while (0)

#define CHECK_EQ(actual, expected)                                                               \
    do {                                                                                         \
        const auto& mt_a = (actual);                                                             \
        const auto& mt_e = (expected);                                                           \
        if (!(mt_a == mt_e))                                                                     \
            mini_test::fail("CHECK_EQ(" #actual ", " #expected ")\n           actual:   " +      \
                                mini_test::to_str(mt_a) + "\n           expected: " +            \
                                mini_test::to_str(mt_e), __FILE__, __LINE__);                    \
    } while (0)

#define CHECK_NEAR(actual, expected, tol)                                                        \
    do {                                                                                         \
        const double mt_a = (actual), mt_e = (expected);                                         \
        if (!(std::fabs(mt_a - mt_e) <= (tol)))                                                  \
            mini_test::fail("CHECK_NEAR(" #actual ", " #expected ") got " +                      \
                                mini_test::to_str(mt_a) + ", expected " + mini_test::to_str(mt_e), \
                            __FILE__, __LINE__);                                                 \
    } while (0)

#define CHECK_VEC_NEAR(actual, expected, tol)                                                    \
    do {                                                                                         \
        const auto& mt_a = (actual);                                                             \
        const auto& mt_e = (expected);                                                           \
        bool mt_ok = mt_a.size() == mt_e.size();                                                 \
        for (std::size_t mt_i = 0; mt_ok && mt_i < mt_a.size(); ++mt_i)                          \
            mt_ok = std::fabs(mt_a[mt_i] - mt_e[mt_i]) <= (tol);                                 \
        if (!mt_ok)                                                                              \
            mini_test::fail("CHECK_VEC_NEAR(" #actual ", " #expected ")\n           actual:   " + \
                                mini_test::to_str(mt_a) + "\n           expected: " +            \
                                mini_test::to_str(mt_e), __FILE__, __LINE__);                    \
    } while (0)

#define CHECK_THROWS_AS(expr, ExceptionType)                                                     \
    do {                                                                                         \
        bool mt_thrown = false;                                                                  \
        try { (void)(expr); } catch (const ExceptionType&) { mt_thrown = true; }                 \
        if (!mt_thrown)                                                                          \
            mini_test::fail("CHECK_THROWS_AS(" #expr ", " #ExceptionType "): no exception "      \
                            "of the expected type", __FILE__, __LINE__);                         \
    } while (0)
