#ifndef BINARYTODECIMAL_HPP
#define BINARYTODECIMAL_HPP

#include <string>
#include <vector>

class BinaryToDecimal {
private:
    int binarydigitToDecimal(char binaryDigit);

public:
    int binaryToDecimal(std::string binary);
};

#endif
