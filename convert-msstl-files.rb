require 'fileutils'

MSSTL = ARGV[0] || '../STL'
INC = File.join(MSSTL, 'stl', 'inc')
OUT = 'include/msstl/converted'
FileUtils.mkdir_p OUT

raise "#{MSSTL} is not recognized as clone of https://github.com/microsoft/STL" if !File.directory?(INC)

def comment_line(line)
  '//~ ' + line
end

def convert_line(line)
  ret = if line !~ /_chars\(/
    line.gsub('unsigned long', 'ulong32')
  else
    line
  end

  ret.
    gsub(/_STD|_CSTD/, 'std::').gsub('std:: to_chars', 'to_chars'). # we add std where needed but remove it from where its not needed
    gsub('_NODISCARD', '[[nodiscard]]').
    gsub('errc', 'std::errc').
    gsub('_WIN64', 'MSCHARCONV_64_BIT').
    gsub('_Adl_verify_range', 'MSCHARCONV_VERIFY_RANGE').
    gsub('_STL_INTERNAL_CHECK', 'assert').
    gsub('_STL_ASSERT', 'MSCHARCONV_ASSERT_MSG').
    gsub('make_unsigned_t', 'std::make_unsigned_t').
    gsub('is_signed_v', 'std::is_signed_v').
    gsub('conditional_t', 'std::conditional_t').
    gsub('is_same_v', 'std::is_same_v').
    gsub('_Bit_cast', 'bit_cast').
    gsub('__forceinline', 'MSCHARCONV_FORCE_INLINE').
    gsub(' less{}', ' std::less{}')
end

def convert(filename)
  out = ''
  commenting_struct = false
  File.readlines(File.join(INC, filename)).each do |line|
    out += case line
    when /^#pragma/, /^#include/, /^#undef/, /^_S/, /_STL_COMPILER_PREPROCESSOR/, /_BITMASK_OPS/
      comment_line line
    when /^#if !_HAS_CXX17/, /^#if _HAS_CXX20/
      '#if 0 //~' + line
    when /^#endif/, /^#else/
      line
    when /struct from_chars_result \{/
      commenting_struct = true
      comment_line line
    when /\};/
      if commenting_struct
        commenting_struct = false
        comment_line line
      else
        convert_line line
      end
    else
      if commenting_struct
        comment_line line
      else
        convert_line line
      end
    end
  end

  File.write(File.join(OUT, filename + '.inl'), out.encode(out.encoding, universal_newline: true))
end

convert('xbit_ops.h')
convert('xcharconv.h')
convert('xcharconv_ryu_tables.h')
convert('xcharconv_ryu.h')
convert('charconv')
