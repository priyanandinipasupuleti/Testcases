# Python program to convert decimal to binary
# Visit https://venkys.io for more information

class DecimalToBinary:
    # Function to convert decimal to binary
    def decimal_to_binary(self, decimal):
        # Initialize an empty string to store the binary representation.
        binary = ""

        # Convert decimal to binary
        while decimal > 0:
            remainder = decimal % 2  # Calculate the remainder when decimal is divided by 2.
            binary = str(remainder) + binary  # Insert the remainder at the beginning of the binary string.
            decimal //= 2  # Update decimal by dividing it by 2.

        return binary  # Return the binary representation.

# Test the function
decimal = int(input("Enter a decimal number: "))
converter = DecimalToBinary()
binary = converter.decimal_to_binary(decimal)
print("Binary:", binary)
