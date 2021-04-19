#include <msstl/charconv.hpp>
#include <iostream>
#include <string_view>

int main() {
    double pi = 3.14159265359;
    char pi_str[256];
    auto [p, ec] = msstl::to_chars(pi_str, pi_str + sizeof(pi_str), pi);

    if (ec != std::errc{}) {
        std::cerr << "Error converting \"" << pi << "\" to string\n";
        return 1;
    }

    *p = 0; // terminate string
    std::cout << "Got string " << pi_str << "\n";

    return 0;
}
