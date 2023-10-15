#include "../include/DecimalToOctalTest.hpp"
#include "../include/DecimalToOctal.hpp"

bool DecimalToOctalTester::test(int decimal, const std::string& expectedOctal) {
    // Create an instance of the DecimalToOctal class
    DecimalToOctal converter;
    
    // Call the decimalToOctal function with the provided decimal input
    std::string result = converter.decimalToOctal(decimal);

    // Check if the result matches the expectedOctal
    return (result == expectedOctal);
}
