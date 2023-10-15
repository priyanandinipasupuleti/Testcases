#include "../include/ConvertStringToLowercase.hpp"
#include <cctype>

std::string ConvertStringToLowercase::convertToLowercase(const std::string& str) {
    std::string lowercaseStr;
    for (char c : str) {
        lowercaseStr += std::tolower(c);
    }
    return lowercaseStr;
}
