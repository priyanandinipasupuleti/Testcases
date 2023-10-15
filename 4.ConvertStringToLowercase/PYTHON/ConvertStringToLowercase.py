# Python program to convert a string to lowercase
# Visit https://venkys.io for more information

class ConvertStringToLowercase:
    def convert_to_lowercase(self, input_string):
        result = ''
        for char in input_string:
            if 'A' <= char <= 'Z':
                result += chr(ord(char) + 32)
            else:
                result += char
        return result

# Input from the user
input_string = input("Please enter a string: ")

# Create an instance of the ConvertStringToLowercase class
converter = ConvertStringToLowercase()

# Call the function to convert the string to lowercase
lowercase_string = converter.convert_to_lowercase(input_string)

# Display the original and converted strings
print("\nOriginal: ", input_string)
print("Converted: ", lowercase_string)
