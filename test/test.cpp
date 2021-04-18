// Copyright (c) 2021 Borislav Stanimirov
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include "test.hpp"

int performed = 0;
int failed = 0;

void test_to_chars();
void test_from_chars();

int main() {
    test_to_chars();
    test_from_chars();

    std::cout << "Ran " << performed << " tests:\n\t" << (performed - failed) << " passed\n\t" << failed << " failed\n";

    return failed != 0;
}
