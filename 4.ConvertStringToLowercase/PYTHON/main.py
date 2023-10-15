from ConvertStringToLowercase import ConvertStringToLowercase
import json
import os

class Util:
    @staticmethod
    def read_json(file_path):
        with open(file_path, 'r') as file:
            return json.load(file)

    @staticmethod
    def write_json(file_path, data):
        with open(file_path, 'w') as file:
            json.dump(data, file, indent=4)

class ConvertStringToLowercaseTest:
    def __init__(self):
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(self.config.get('testcasesFile'))

    def test(self, input_string, expected_output):
        # Test the ConvertStringToLowercase class here
        converter = ConvertStringToLowercase()
        result = converter.convert_to_lowercase(input_string)
        return result == expected_output

def main():
    tester = ConvertStringToLowercaseTest()
    testcases_json = tester.testcases

    for testcase in testcases_json:
        res = tester.test(testcase['input'], testcase['output'])
        testcase["result"] = "fail" if not res else "pass"

    # Update the result in python_result.json
    tester.util.write_json(tester.config.get('PythonResultFile'), testcases_json)

    if "fail" in [testcase["result"] for testcase in testcases_json]:
        raise Exception("Testcases failed")
    print("All testcases passed")

if __name__ == "__main__":
    main()
