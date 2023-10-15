
#include "../include/CelsiusToFahrenheit.hpp"
#include "../include/CelsiusToFahrenheitTest.hpp"

bool CelsiusToFahrenheitTester::test(float celsius, float expectedFahrenheit) {
    // Create an instance of CelsiusToFahrenheit
    CelsiusToFahrenheit ctf;

    // Calculate the actual Fahrenheit value
    float actualFahrenheit = ctf.convert(celsius);

    // Compare the actual and expected values
    // You may want to add a tolerance for floating-point comparisons
    // For example: if (abs(actualFahrenheit - expectedFahrenheit) < tolerance)
    return actualFahrenheit == expectedFahrenheit;
}
