from CelsiusToFahrenheit import CelsiusToFahrenheit

class CelsiusToFahrenheitTest:
    def __init__(self):
        self.converter = CelsiusToFahrenheit()
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(self.config.get('testcasesFile'))

    def test(self, input, expected_output):
        # Convert the input from Celsius to Fahrenheit using the CelsiusToFahrenheit class
        result = self.converter.celsius_to_fahrenheit(input)

        # Compare the result to the expected output
        return result == expected_output
