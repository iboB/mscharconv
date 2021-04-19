// Copyright (c) 2021 Borislav Stanimirov
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include "test_charconv.hpp"
#include "test.hpp"
#include <string>

namespace {
template <typename T>
std::string to_string(T t) {
    char buf[1024];
    auto ret = msstl::to_chars(buf, buf + sizeof(buf), t);
    if (ret.ec != std::errc{}) return {};
    return std::string(buf, ret.ptr);
}
}

void test_to_chars() {
    CHECK(to_string(char(5)) == "5");
    CHECK(to_string(42334) == "42334");
    CHECK(to_string(0xea7badf00dull) == "1007097344013");
    CHECK(to_string(3.1415f) == "3.1415");
    CHECK(to_string(1.233) == "1.233");
}
