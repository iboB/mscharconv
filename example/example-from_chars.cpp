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
