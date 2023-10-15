# Python program to convert Celsius to Fahrenheit
# Visit https://venkys.io for more information

class CelsiusToFahrenheit:
    # Function to convert Celsius to Fahrenheit
    def celsius_to_fahrenheit(self, celsius):
        fahrenheit = (celsius * 1.8) + 32
        return fahrenheit

# Test the function
celsius = float(input("Please enter the temperature in Celsius: "))
converter = CelsiusToFahrenheit()
fahrenheit = converter.celsius_to_fahrenheit(celsius)
print("%.2f Celsius temperature = %.2f Fahrenheit" % (celsius, fahrenheit))
