#include <cassert>
#include <cstring>

namespace msstl {

namespace impl {

using ulong32 = std::conditional_t<sizeof(unsigned long) == 4, unsigned long, uint32_t>;

#if INTPTR_MAX == INT64_MAX
#   define MSCHARCONV_64_BIT
#endif

inline void ms_verify_range(const char* first, const char* last) { assert(first <= last); }

template <class To, class From>
To bit_cast(const From& val) noexcept {
#ifdef _MSC_VER
    return __builtin_bit_cast(To, val);
#else
    To to;
    std::memcpy(&to, &val, sizeof(To));
    return to;
#endif
}

#include "converted/m_floating_type_traits.inl"
#include "converted/xbit_ops.h.inl"
#include "converted/xcharconv_ryu_tables.h.inl"
#include "converted/xcharconv_ryu.h.inl"
#include "converted/charconv.inl"

} // namespace impl

inline to_chars_result to_chars(char* first, char* last, const char val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, signed char val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, unsigned char val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, short val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, unsigned short val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, int val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, unsigned int val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, long val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, unsigned long val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, long long val, int base) noexcept { return impl::to_chars(first, last, val, base); }
inline to_chars_result to_chars(char* first, char* last, unsigned long long val, int base) noexcept { return impl::to_chars(first, last, val, base); }

inline to_chars_result to_chars(char* first, char* last, float val) noexcept { return impl::to_chars(first, last, val); }
inline to_chars_result to_chars(char* first, char* last, double val) noexcept { return impl::to_chars(first, last, val); }
inline to_chars_result to_chars(char* first, char* last, long double val) noexcept { return impl::to_chars(first, last, val); }
inline to_chars_result to_chars(char* first, char* last, float val, chars_format fmt) noexcept { return impl::to_chars(first, last, val, fmt); }
inline to_chars_result to_chars(char* first, char* last, double val, chars_format fmt) noexcept { return impl::to_chars(first, last, val, fmt); }
inline to_chars_result to_chars(char* first, char* last, long double val, chars_format fmt) noexcept { return impl::to_chars(first, last, val, fmt); }
inline to_chars_result to_chars(char* first, char* last, float val, chars_format fmt, int precision) noexcept { return impl::to_chars(first, last, val, fmt, precision); }
inline to_chars_result to_chars(char* first, char* last, double val, chars_format fmt, int precision) noexcept { return impl::to_chars(first, last, val, fmt, precision); }
inline to_chars_result to_chars(char* first, char* last, long double val, chars_format fmt, int precision) noexcept { return impl::to_chars(first, last, val, fmt, precision); }


inline from_chars_result from_chars(const char* first, const char* last, char& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, signed char& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, unsigned char& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, short& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, unsigned short& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, int& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, unsigned int& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, long& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, unsigned long& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, long long& val, int base) noexcept { return impl::from_chars(first, last, val, base); }
inline from_chars_result from_chars(const char* first, const char* last, unsigned long long& val, int base) noexcept { return impl::from_chars(first, last, val, base); }

inline from_chars_result from_chars(const char* first, const char* last, float& val, chars_format fmt) noexcept { return impl::from_chars(first, last, val, fmt); }
inline from_chars_result from_chars(const char* first, const char* last, double& val, chars_format fmt) noexcept { return impl::from_chars(first, last, val, fmt); }
inline from_chars_result from_chars(const char* first, const char* last, long double& val, chars_format fmt) noexcept { return impl::from_chars(first, last, val, fmt); }


} // namespace msstl
