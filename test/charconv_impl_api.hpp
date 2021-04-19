// Copyright (c) 2021 Borislav Stanimirov
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#pragma once

#if defined(_WIN32)
#   define SYMBOL_EXPORT __declspec(dllexport)
#   define SYMBOL_IMPORT __declspec(dllimport)
#else
#   define SYMBOL_EXPORT __attribute__((__visibility__("default")))
#   define SYMBOL_IMPORT
#endif

#if MSCHARCONV_SHARED
#   if defined(MSCHARCONV_IMPLEMENT)
#       define MSCHARCONV_API SYMBOL_EXPORT
#   else
#       define MSCHARCONV_API SYMBOL_IMPORT
#   endif
#endif
