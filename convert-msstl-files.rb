MSSTL = ARGV[0] || '../STL'
INC = File.join(MSSTL, 'stl', 'inc')

raise "#{MSSTL} is not recognized as clone of https://github.com/microsoft/STL" if !File.directory?(INC)

def comment(line)
  '//~ ' + line
end

def convert(source, target)
  out = ''
  File.readlines(File.join(INC, source)).each do |line|
    out += case line
    when /^#pragma/, /^#include/, /^#undef/, /^_S/
      comment line
    else
      line
    end
  end

  puts out
end

convert('xcharconv.h', 'xcharconv.h.inl')
