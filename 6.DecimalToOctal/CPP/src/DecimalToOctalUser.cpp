#include "../include/DecimalToOctal.hpp"

std::string DecimalToOctal::decimalToOctal(int decimal) {
    std::string octal = "";

    while (decimal > 0) {
        int remainder = decimal % 8;
        octal = std::to_string(remainder) + octal;
        decimal /= 8;
    }

    return octal;
}
