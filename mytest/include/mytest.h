#ifndef MYTEST_H_
#define MYTEST_H_

#include <iostream>
#include <string>

namespace mytest {
void make_test(const std::string &name, void (*new_test)());

// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define MYTEST_INTERNAL_TEST_CASE(class_name, name) \
    namespace {                                     \
    struct class_name {                             \
        static void test();                         \
        class_name() {                              \
            mytest::make_test(name, test);          \
        }                                           \
    } class_name##object;                           \
    }                                               \
    void class_name ::test()

// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define MYTEST_INTERNAL_TEST_CASE2(line, name) \
    MYTEST_INTERNAL_TEST_CASE(mytest_test_class_##line, name)
// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define MYTEST_INTERNAL_TEST_CASE1(line, name) \
    MYTEST_INTERNAL_TEST_CASE2(line, name)
// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define TEST_CASE(name) MYTEST_INTERNAL_TEST_CASE1(__LINE__, name)

int run_tests();
void check_expression(const std::string &file,
                      int line,
                      const std::string &exp,
                      bool res,
                      const std::string &mes = "");

// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define CHECK(expr) mytest::check_expression(__FILE__, __LINE__, #expr, expr)
// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define CHECK_MESSAGE(expr, mes) \
    mytest::check_expression(__FILE__, __LINE__, #expr, expr, mes)

}  // namespace mytest

#endif  // MYTEST_H_
