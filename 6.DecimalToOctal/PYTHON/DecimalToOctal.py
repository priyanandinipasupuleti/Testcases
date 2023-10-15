# Python program to convert decimal to octal
# Visit https://venkys.io for more information

class DecimalToOctal:
    # Function to convert decimal to octal
    def decimal_to_octal(self, decimal):
        # Initialize an empty string to store the octal representation.
        octal = ""

        # Convert decimal to octal
        while decimal > 0:
            remainder = decimal % 8  # Calculate the remainder when decimal is divided by 8.
            octal = str(remainder) + octal  # Insert the remainder at the beginning of the octal string.
            decimal //= 8  # Update decimal by dividing it by 8.

        return octal  # Return the octal representation.

# Test the function
decimal = int(input("Enter a decimal number: "))
converter = DecimalToOctal()
octal = converter.decimal_to_octal(decimal)
print("Octal:", octal)
