#include "../include/DecimalToOctal.hpp"  // Include the header file for DecimalToOctal

// Function to convert decimal to octal
std::string DecimalToOctal::decimalToOctal(int decimal) {
    std::string octal = "";  // Initialize an empty string variable named octal to store the octal representation.

    // Convert decimal to octal
    while (decimal > 0) {
        int remainder = decimal % 8;  // Calculate the remainder when decimal is divided by 8
        octal = std::to_string(remainder) + octal;  // Convert the remainder to a string and prepend it to the octal string
        decimal /= 8;  // Update decimal by dividing it by 8.
    }

    return octal;  // Return the octal representation as the result of the DecimalToOctal::decimalToOctal function.
}
