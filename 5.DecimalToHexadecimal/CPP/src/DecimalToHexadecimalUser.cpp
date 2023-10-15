#include "../include/DecimalToHexadecimal.hpp"  // Include the header file for DecimalToHexadecimal class

std::string DecimalToHexadecimal::decimalToHexadecimal(int decimal) {
    std::string hexadecimal = ""; // Initialize an empty string to store the hexadecimal representation.
    
    // Mapping of hexadecimal digits
    char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    // Convert decimal to hexadecimal
    while (decimal > 0) { // Loop until the decimal number becomes 0.
        int remainder = decimal % 16; // Extract the remainder when dividing the decimal number by 16
        hexadecimal = hexDigits[remainder] + hexadecimal; // Append the corresponding hexadecimal digit to the front of the hexadecimal string
        decimal /= 16; // Update the decimal number by dividing it by 16.
    }
    
    return hexadecimal; // Return the hexadecimal string as the result of the function.
}
