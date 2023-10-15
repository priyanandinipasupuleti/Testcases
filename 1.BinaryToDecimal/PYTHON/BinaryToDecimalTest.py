from BinaryToDecimal import BinaryToDecimal

class BinaryToDecimalTest:
    def __init__(self):
        self.converter = BinaryToDecimal()
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(self.config.get('testcasesFile'))

    def test(self, input, expected_output):
        # Convert the input to decimal using the BinaryToDecimal class
        result = self.converter.binary_to_decimal(input)

        # Compare the result to the expected output
        return result == expected_output
