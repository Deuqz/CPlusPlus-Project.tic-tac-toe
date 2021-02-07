#include "mytest.h"

TEST_CASE("Demo2.cpp test case 1") {
    CHECK(2 * 2 == 4), CHECK(true);
}

TEST_CASE("Demo2.cpp test case 2") {
    CHECK(true), CHECK(2 * 2 == 5);
}

TEST_CASE("Demo2.cpp test case with multiple failures and messages") {
    CHECK_MESSAGE(2 * 2 == 4, "demo2-msg1");
    CHECK_MESSAGE(2 * 2 == 5, "demo2-msg2");
    CHECK(true), CHECK(2 * 2 == 4);
    CHECK(2 * 2 == 5), CHECK(true);
}
