#pragma once

#include <system_error>

namespace msstl {

struct from_chars_result {
    const char* ptr;
    std::errc ec;
};

// defines to_chars_result and chars_format
#include "converted/xcharconv.h.inl"

to_chars_result to_chars(char* first, char* last, char val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, signed char val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, unsigned char val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, short val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, unsigned short val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, int val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, unsigned int val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, long val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, unsigned long val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, long long val, int base = 10) noexcept;
to_chars_result to_chars(char* first, char* last, unsigned long long val, int base = 10) noexcept;

to_chars_result to_chars(char* first, char* last, float val) noexcept;
to_chars_result to_chars(char* first, char* last, double val) noexcept;
to_chars_result to_chars(char* first, char* last, long double val) noexcept;
to_chars_result to_chars(char* first, char* last, float val, chars_format fmt) noexcept;
to_chars_result to_chars(char* first, char* last, double val, chars_format fmt) noexcept;
to_chars_result to_chars(char* first, char* last, long double val, chars_format fmt) noexcept;
to_chars_result to_chars(char* first, char* last, float val, chars_format fmt, int precision) noexcept;
to_chars_result to_chars(char* first, char* last, double val, chars_format fmt, int precision) noexcept;
to_chars_result to_chars(char* first, char* last, long double val, chars_format fmt, int precision) noexcept;

from_chars_result from_chars(const char* first, const char* last, char& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, signed char& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, unsigned char& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, short& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, unsigned short& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, int& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, unsigned int& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, long& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, unsigned long& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, long long& val, int base = 10) noexcept;
from_chars_result from_chars(const char* first, const char* last, unsigned long long& val, int base = 10) noexcept;

from_chars_result from_chars(const char* first, const char* last, float& val, chars_format fmt = chars_format::general) noexcept;
from_chars_result from_chars(const char* first, const char* last, double& val, chars_format fmt = chars_format::general) noexcept;
from_chars_result from_chars(const char* first, const char* last, long double& val, chars_format fmt = chars_format::general) noexcept;

}
