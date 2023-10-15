from DecimalToOctal import DecimalToOctal

class DecimalToOctalTest:
    def __init__(self):
        self.converter = DecimalToOctal()
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(self.config.get('testcasesFile'))

    def test(self, input, expected_output):
        # Convert the input to octal using the DecimalToOctal class
        result = self.converter.decimal_to_octal(input)

        # Compare the result to the expected output
        return result == expected_output