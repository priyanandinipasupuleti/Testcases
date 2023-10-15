#include "../include/DecimalToBinary.hpp"
#include "../include/DecimalToBinaryTest.hpp"



bool DecimalToBinaryTester::test(int decimal, const std::string& expectedBinary) {
    DecimalToBinary converter;
    std::string binary = converter.decimalToBinary(decimal);

    return binary == expectedBinary;
}
