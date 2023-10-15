from DecimalToHexadecimal import DecimalToHexadecimal
from Util import Util  # Import the Util class from your utility module

class DecimalToHexadecimalTest:
    def __init__(self):
        self.converter = DecimalToHexadecimal()
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(self.config.get('testcasesFile'))

    def test(self, input, expected_output):
        # Convert the input to hexadecimal using the DecimalToHexadecimal class
        result = self.converter.decimal_to_hexadecimal(input)

        # Compare the result to the expected output
        return result == expected_output

    def run_tests(self):
        for test_case in self.testcases:
            test_input = test_case['input']
            expected_output = test_case['output']
            test_result = self.test(test_input, expected_output)

            if test_result:
                print(f"Test passed for input {test_input}.")
            else:
                print(f"Test failed for input {test_input}. Expected: {expected_output}, Got: {self.converter.decimal_to_hexadecimal(test_input)}")

if __name__ == "__main__":
    test_instance = DecimalToHexadecimalTest()
    test_instance.run_tests()
