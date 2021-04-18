// Copyright (c) 2021 Borislav Stanimirov
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#pragma once
#include <iostream>
#include <cmath>

// a bare bones unit testing library

extern int performed;
extern int failed;

template <typename F>
bool approx(F a, F b) {
    return std::abs(a - b) < F(1e-5);
}

inline void check(bool val, const char* check, const char* file, int line) {
    ++performed;
    if (val) return;
    std::cerr << file << ':' << line << " `" << check << "` FAILED!\n";
    ++failed;
}

#define CHECK(x) check(x, #x, __FILE__, __LINE__)
