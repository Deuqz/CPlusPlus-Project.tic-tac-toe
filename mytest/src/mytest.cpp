#include "mytest.h"
#include <string>
#include <vector>

namespace mytest {
namespace {
// File-local declarations and definitions.
int failed_tests = 0;
bool fail = false;
struct Test {
    std::string name;
    void (*func)();
};
std::vector<Test> &tests() {
    static std::vector<Test> v;
    return v;
}

}  // namespace

void make_test(const std::string &name, void (*new_test)()) {
    tests().push_back({name, new_test});
}

int run_tests() {
    for (const Test &cur_test : tests()) {
        std::cerr << "Running \"" << cur_test.name << "\"...\n";
        cur_test.func();
        if (fail) {
            ++failed_tests;
            fail = false;
        }
    }
    std::cerr << "===== Tests passed: " << tests().size() - failed_tests << "/"
              << tests().size() << " =====\n";
    return failed_tests == 0 ? 0 : 1;
}

void check_expression(const std::string &file,
                      int line,
                      const std::string &exp,
                      bool res,
                      const std::string &mes) {
    if (!res) {
        fail = true;
        std::cerr << "CHECK(" << exp << ") at " << file << ":" << line
                  << " failed!\n";
    }
    if (!mes.empty() && !res) {
        std::cerr << "    message: " << mes << "\n";
    }
}

// Externally visible declarations and definitions.
}  // namespace mytest
