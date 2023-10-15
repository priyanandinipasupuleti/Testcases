# Python program to convert decimal to hexadecimal

class DecimalToHexadecimal:
    # Function to convert decimal to hexadecimal
    def decimal_to_hexadecimal(self, decimal):
        # Initialize an empty string to store the hexadecimal representation.
        hexadecimal = ""

        # Mapping of hexadecimal digits
        hex_digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']

        # Convert decimal to hexadecimal
        while decimal > 0:
            remainder = decimal % 16  # Extract the remainder when dividing the decimal by 16.
            hexadecimal = hex_digits[remainder] + hexadecimal  # Append the corresponding hexadecimal digit to the front of the string.
            decimal //= 16  # Update the decimal number by dividing it by 16.

        return hexadecimal  # Return the hexadecimal representation.

# Test the function
decimal = int(input("Enter a decimal number: "))
converter = DecimalToHexadecimal()
hexadecimal = converter.decimal_to_hexadecimal(decimal)
print("Hexadecimal:", hexadecimal)
