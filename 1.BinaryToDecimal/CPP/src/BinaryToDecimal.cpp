#include "../include/BinaryToDecimal.hpp"

#include <string>
#include <cmath>

int BinaryToDecimal::binarydigitToDecimal(char binaryDigit) {
    return binaryDigit - '0';
}

int BinaryToDecimal::binaryToDecimal(std::string binary) {
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; i--) {
        int decimalValue = binarydigitToDecimal(binary[i]);

        if (decimalValue != 0 && decimalValue != 1) {
            return -1;
        }

        decimal += decimalValue * std::pow(2, power);
        power++;
    }

    return decimal;
}
