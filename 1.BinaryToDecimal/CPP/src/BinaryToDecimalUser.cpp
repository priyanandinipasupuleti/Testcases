#include "../include/BinaryToDecimal.hpp"
#include <iostream> // Include the <iostream> header for cout and cin

int main() {
    BinaryToDecimal btd;
    std::string binary;

    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    int decimal = btd.binaryToDecimal(binary);

    if (decimal == -1) {
        std::cout << "Invalid binary number!" << std::endl;
    } else {
        std::cout << "Decimal: " << decimal << std::endl;
    }

    return 0;
}
