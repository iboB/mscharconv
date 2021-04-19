// Copyright (c) 2021 Borislav Stanimirov
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include "test_charconv.hpp"
#include <msstl/util.hpp>
#include "test.hpp"

void test_from_chars() {
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
}
