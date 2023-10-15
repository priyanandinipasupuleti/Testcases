from BinaryToDecimal import BinaryToDecimal
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

class BinaryToDecimalTest:
    def __init__(self):
        self.util = Util()
        self.config = self.util.read_json('conf/config.json')
        self.testcases = self.util.read_json(os.path.join('resources', 'testcases.json'))
        self.converter = BinaryToDecimal()

    def test(self, input, expected_output):
        result = self.converter.binary_to_decimal(int(input))
        return result == expected_output

def main():
    tester = BinaryToDecimalTest()
    testcasesJson = tester.testcases

    for testcase in testcasesJson:
        res = tester.test(testcase['input'], testcase['output'])
        testcase["result"] = "fail" if not res else "pass"

    # Update the result in python_result.json
    tester.util.write_json(tester.config.get('PythonResultFile'), testcasesJson)

    if "fail" in [testcase["result"] for testcase in testcasesJson]:
        raise Exception("Testcases failed")
    print("All testcases passed")

if __name__ == "__main__":
    main()
