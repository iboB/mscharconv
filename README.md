# mscharconv

`<charconv>` from [Microsoft STL](https://github.com/microsoft/STL), but multi-platform.

Tested with MSVC, gcc, and clang on Windows, Linux, and macOS (will likely work on other platforms supported by any of these compilers)

## Usage

The library is header only. You can clone the repo or copy the contents of the include directory in your project.

Alternatively you can use with CMake. The provided CMakeLists.txt defines an `INTERFACE` target `mscharconv` and its alias `msstl::charconv`.

To use the library in your code simply include `<msstl/charconv.hpp>` and use `to_chars` and `from_chars` from the namespace `msstl`.

C++17 or later is needed.

### Example

```c++
#include <msstl/charconv.hpp>
#include <iostream>
#include <string_view>

int main() {
    std::string_view pi_str = "3.14159 is pi";
    double pi;
    auto [p, ec] = msstl::from_chars(pi_str.data(), pi_str.data() + pi_str.length(), pi);
    if (ec != std::errc{}) {
        std::cerr << "Error converting \"" << pi_str << "\" to double\n";
        return 1;
    }
    std::cout << "Got double " << pi << ". The rest is \"" << p << "\".\n";

    return 0;
}
```

### Additional Utilities

An additional header `util.hpp` is provided with the library with non-standard util functions in namespace `msstl::util`. Note that `util.hpp` is **NOT** self contained. You must include it after including `charconv.hpp`.

The utility functions are:

* `bool from_string(std::string_view str, INTEGER& out, int base = 10);` - convert string to integral number with a given base. Will return `true` if the conversion is successful. The string must be an integer and nothing more. Even though `from_chars` supports inputs like `"123 and some text"` and will stop at the first non-integer character, `from_string` will consider this to be an invalid input and return false.
* `bool from_string(std::string_view str, FLOATING_POINT_NUM& out);` - convert a string to a floating point number. Return `true` is successful. Same restrictions as above apply.

### Advanced usage

For the basic usage of the library one needs to include `charconv.hpp` which is quite big. It contains a lot of code and huge helper arrays. If you include charconv in many places of your code, it may lead to long compilation times. The advanced usage of the library allows the functions to be compiled separately and only once per project. To enable this, instead of including `charconv.hpp` include `charconv_fwd.hpp` and in a single place of your code define `MSCHARCONV_IMPLEMENT` and then include `charconv.hpp`.

Additionally if you want to provide a shared library interface to the functions, define `MSCHARCONV_API` to your import/export symbols, before including `charconv_fwd.hpp`

## Development

The library is created by automatically converting headers from a clone of [Microsoft STL](https://github.com/microsoft/STL) with the Ruby script `convert-msstl-files.rb`. Additionally support functions and macros are provided in `charconv_impl.inl`.

## License

Copyright (c) Microsoft Corporation, Borislav Stanimirov, and contributors.

SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
