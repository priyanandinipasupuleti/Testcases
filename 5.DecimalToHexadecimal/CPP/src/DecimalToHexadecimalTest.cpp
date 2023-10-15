#include "../include/DecimalToHexadecimalTest.hpp"  // Include the header file for DecimalToHexadecimalTest class
#include "../include/DecimalToHexadecimal.hpp"  // Include the header file for DecimalToHexadecimal class

bool DecimalToHexadecimalTester::test(int decimal, const std::string& expectedHexadecimal) {
    DecimalToHexadecimal dth;  // Create an instance of the DecimalToHexadecimal class
    std::string result = dth.decimalToHexadecimal(decimal);  // Call the decimalToHexadecimal method

    // Compare the result with the expected hexadecimal string
    if (result != expectedHexadecimal) {
        return false;  // Return false if the result does not match the expected value
    }

    return true;  // Return true if the test passes
}
