#include "../include/ConvertStringToLowercaseTest.hpp"
#include "../include/ConvertStringToLowercase.hpp"
#include <iostream>

bool ConvertStringToLowercaseTester::test(const std::string& input, const std::string& expectedOutput) {
    ConvertStringToLowercase converter;
    std::string result = converter.convertToLowercase(input);
    
    // Compare the result with the expected output
    if (result != expectedOutput) {
        std::cout << "Test failed: Input: " << input << ", Expected Output: " << expectedOutput << ", Actual Output: " << result << std::endl;
        return false;
    }

    // Test passed
    return true;
}
