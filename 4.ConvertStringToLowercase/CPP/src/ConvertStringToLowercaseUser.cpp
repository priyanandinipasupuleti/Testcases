#include "../include/ConvertStringToLowercase.hpp"
#include <iostream>

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    ConvertStringToLowercase converter; // Create an instance of the conversion class

    std::string lowercaseStr = converter.convertToLowercase(str); // Use the conversion function
    std::cout << "Lowercase string: " << lowercaseStr << std::endl;

    return 0;
}
