#include "../include/DecimalToBinary.hpp"



std::string DecimalToBinary::decimalToBinary(int decimal) {
    std::string binary;

    if (decimal == 0) {
        binary = "0";
    } else {
        while (decimal > 0) {
            int remainder = decimal % 2;
            binary = std::to_string(remainder) + binary;
            decimal /= 2;
        }
    }

    return binary;
}
