from ConvertStringToLowercase import convert_to_lowercase
  # Replace 'YourUtilModule' with the actual module where Util is defined

class ConvertStringToLowercaseTest:
    def __init__(self):
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(self.config.get('testcasesFile'))

    def test(self, input_string, expected_output):
        # Convert the input string to lowercase using the convert_to_lowercase function
        result = convert_to_lowercase(input_string)

        # Compare the result to the expected output
        return result == expected_output
