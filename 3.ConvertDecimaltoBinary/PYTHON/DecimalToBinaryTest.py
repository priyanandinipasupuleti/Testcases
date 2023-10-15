from DecimalToBinary import DecimalToBinary  # Import the DecimalToBinary class from your implementation.

class DecimalToBinaryTest:
    def __init__(self):
        self.converter = DecimalToBinary()
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(self.config.get('testcasesFile'))

    def test(self, input, expected_output):
        # Convert the input to binary using the DecimalToBinary class
        result = self.converter.decimal_to_binary(input)

        # Compare the result to the expected output
        return result == expected_output

# Example usage
if __name__ == "__main__":
    test_instance = DecimalToBinaryTest()

    for testcase in test_instance.testcases:
        input_decimal = testcase["input"]
        expected_binary = testcase["output"]

        result = test_instance.test(input_decimal, expected_binary)
        if result:
            print(f"Test Passed: Decimal {input_decimal} converted to Binary {expected_binary}")
        else:
            print(f"Test Failed: Decimal {input_decimal} did not convert to Binary {expected_binary}")
