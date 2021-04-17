// Copyright (c) 2021 Borislav Stanimirov
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// The purpose of this test is to check that the library can be built on
// various platforms with various compilers.
// Complete unit testing of the code is part of the microsoft/STL project
// at https://github.com/microsoft/STL

#include <msstl/charconv.hpp>
#include <msstl/util.hpp>

#include <iostream>
#include <string>

int performed = 0;
int failed = 0;

template <typename F>
bool approx(F a, F b) {
    return std::abs(a - b) < F(1e-5);
}

void check(bool val, const char* check, const char* file, int line) {
    ++performed;
    if (val) return;
    std::cerr << file << ':' << line << " `" << check << "` FAILED!\n";
    ++failed;
}

#define CHECK(x) check(x, #x, __FILE__, __LINE__)

template <typename T>
std::string to_string(T t) {
    char buf[1024];
    auto ret = msstl::to_chars(buf, buf + sizeof(buf), t);
    if (ret.ec != std::errc{}) return {};
    return std::string(buf, ret.ptr);
}

int main() {

    CHECK(to_string(char(5)) == "5");
    CHECK(to_string(42334) == "42334");
    CHECK(to_string(0xea7badf00dull) == "1007097344013");
    CHECK(to_string(3.1415f) == "3.1415");
    CHECK(to_string(1.233) == "1.233");

    using msstl::util::from_string;
    short s;
    CHECK(!from_string("asd", s));
    CHECK(!from_string("666s", s));
    CHECK(from_string("123", s));
    CHECK(s == 123);

    int i;
    CHECK(from_string("badf00d", i, 16));
    CHECK(i == 0xbadf00d);

    float f;
    CHECK(from_string("0.3", f));
    CHECK(approx(f, 0.3f));
    double d;
    CHECK(from_string("1.23e1", d));
    CHECK(approx(d, 12.3));

    std::cout << "Ran " << performed << " tests:\n\t" << (performed - failed) << " passed\n\t" << failed << " failed\n";

    return failed != 0;
}
