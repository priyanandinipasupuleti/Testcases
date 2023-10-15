#include "../include/json.hpp"
#include "../include/CelsiusToFahrenheit.hpp"
#include "../include/CelsiusToFahrenheitTest.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using json = nlohmann::json;

class Config {
public:
    std::string testcasesFile;
    std::string CppResultFile;
};

class TestCase {
public:
    double input;  // Changed to double for Celsius temperature
    double output; // Changed to double for Fahrenheit temperature
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
            testcase.input = j[i]["input"].get<double>(); // Changed to double for Celsius temperature
            testcase.output = j[i]["output"].get<double>(); // Changed to double for Fahrenheit temperature
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
    CelsiusToFahrenheitTester tester;
    std::vector<TestCase>& testcases = util.testcases;
    bool failed = false;
    for (TestCase& testcase : testcases) {
        bool res = tester.test(testcase.input, testcase.output);
        failed = !res;
        testcase.result = res;
    }
    util.writeResult();
    if (failed) {
        throw std::runtime_error("Some test cases failed");
    }
    std::cout << "All test cases passed" << std::endl;
    return 0;
}
