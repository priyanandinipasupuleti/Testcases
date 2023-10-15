#include "../include/BinaryToDecimal.hpp"
#include "../include/BinaryToDecimalTest.hpp"

bool BinaryToDecimalTester::test(const std::vector<std::pair<std::string, int>>& testCases) {
    BinaryToDecimal btd;
    
    for (const auto& testCase : testCases) {
        const std::string& binary = testCase.first;
        int expectedDecimal = testCase.second;
        
        int result = btd.binaryToDecimal(binary);
        
        if (result != expectedDecimal) {
            return false;
        }
    }
    
    return true;
}
