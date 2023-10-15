#include "../include/json.hpp"
#include "../include/BinaryToDecimal.hpp"
#include "../include/BinaryToDecimalTest.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unistd.h> 

using json = nlohmann::json;

class Config {
public:
    std::string testcasesFile;
    std::string CppResultFile;
};

class TestCase {
public:
    std::string input;
    int output;
    bool result;

    void to_json(json& j) {
        j = json{{"input", input}, {"output", output}, {"result", result}};
    }
};

json serialize(std::vector<TestCase> testcases) {
    json outputJson = json::array();
    for (TestCase testcase : testcases) {
        json j;
        testcase.to_json(j);
        outputJson.push_back(j);
    }
    return outputJson;
}

class Util {
public:
    std::vector<TestCase> testcases;
    Config config;

    Util() {
        config = readConfig();
        testcases = readTestcases();
    }

    Config readConfig() {
        std::ifstream configFile;
        configFile.open("../../conf/config.json");
        json configJson;
        configFile >> configJson;
        configFile.close();
        Config config;
        config.testcasesFile = configJson["testcasesFile"];
        config.CppResultFile = configJson["CppResultFile"];
        return config;
    }

    std::vector<TestCase> readTestcases() {
        std::ifstream testcaseFile;
        testcaseFile.open("../../" + config.testcasesFile);
        json j;
        testcaseFile >> j;
        testcaseFile.close();
        std::vector<TestCase> testcases;
        for (int i = 0; i < j.size(); i++) {
            TestCase testcase;
            testcase.input = j[i]["input"].get<std::string>();
            testcase.output = j[i]["output"].get<int>();
            testcases.push_back(testcase);
        }
        return testcases;
    }

    void writeResult() {
        std::ofstream resultFile;
        resultFile.open("../../" + config.CppResultFile);
        json j = serialize(testcases);
        resultFile << j.dump(2);
        resultFile.close();
    }
};

int main() {
    Util util;
    BinaryToDecimalTester tester;
    std::vector<TestCase>& testcases = util.testcases;
    bool failed = false;

    // Create a vector of pairs to hold the test cases
    std::vector<std::pair<std::string, int>> testCases;

    for (const TestCase& testcase : testcases) {
        // Add each test case to the vector of pairs
        testCases.emplace_back(testcase.input, testcase.output);
    }

    // Call the test method with the vector of test cases
    bool res = tester.test(testCases);

    failed = !res;

    for (std::size_t i = 0; i < testcases.size(); ++i) {
        // Update the result in the original TestCase object
        testcases[i].result = testCases[i].second == 1; // You can use a suitable condition here
    }

    util.writeResult();

    if (failed) {
        throw std::runtime_error("Some test cases failed");
    }

    std::cout << "All test cases passed" << std::endl;

    return 0;
}

