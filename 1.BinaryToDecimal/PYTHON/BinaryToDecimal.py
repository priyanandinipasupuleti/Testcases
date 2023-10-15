# Python program to convert binary to decimal
# Visit https://venkys.io for more information

class BinaryToDecimal:
    # Function to convert binary to decimal
    def binary_to_decimal(self, binary):
        # Initialize decimal and i to 0
        decimal, i = 0, 0

        # Convert binary to decimal
        while binary != 0:
            dec = binary % 10
            decimal = decimal + dec * 2**i
            binary = binary // 10
            i += 1

        return decimal

# Test the function
binary = int(input("Enter a binary number: "))
converter = BinaryToDecimal()
decimal = converter.binary_to_decimal(binary)
print("Decimal:", decimal)
