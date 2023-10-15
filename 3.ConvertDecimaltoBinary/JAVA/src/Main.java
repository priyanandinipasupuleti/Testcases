import java.io.*;
import com.google.gson.Gson;
import com.google.gson.stream.JsonReader;

class Config {
    private String testcasesFile;
    private String JavaResultFile;

    String getTestCaseFile() {
        return this.testcasesFile;
    }

    String getOutputFile() {
        return this.JavaResultFile;
    }

    public void setTestCaseFile(String testcasesFile) {
        this.testcasesFile = testcasesFile;
    }

    public void setJavaResultFile(String javaResultFile) {
        JavaResultFile = javaResultFile;
    }
}

class Testcase {
    private int input;
    private String output;
    private boolean result;

    public int getInput() {
        return input;
    }

    public String getOutput() {
        return output;
    }

    public boolean getResult() {
        return result;
    }

    public void setResult(boolean result) {
        this.result = result;
    }

    public void setInput(int input) {
        this.input = input;
    }

    public void setOutput(String output) {
        this.output = output;
    }

    public String toString() {
        return "Input: " + input + " Output: " + output;
    }
}

class Util {
    Testcase[] testcases;
    Config config;
    Gson gson;

    Util() {
        this.gson = new Gson();
        this.config = readConfig();
        this.testcases = readTestcases();
    }

    private Config readConfig() {
        Config config = null;
        try {
            File file = new File("../../conf/config.json");
            JsonReader r = new JsonReader(new FileReader(file.getAbsolutePath()));
            config = gson.fromJson(r, Config.class);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return config;
    }

    private Testcase[] readTestcases() {
        Testcase[] testcases = null;
        try {
            File file = new File("../../" + config.getTestCaseFile());
            JsonReader reader = new JsonReader(new FileReader(file.getAbsolutePath()));
            testcases = gson.fromJson(reader, Testcase[].class);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return testcases;
    }

    public void writeTestCases() {
        try {
            File file = new File("../../" + config.getOutputFile());
            String json = gson.toJson(testcases);
            FileWriter writer = new FileWriter(file.getAbsolutePath());
            writer.write(json);
            writer.close();
            return;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        try {
            Util util = new Util();
            DecimalToBinaryTest tester = new DecimalToBinaryTest();
            boolean failed = false;
            for (Testcase testcase : util.testcases) {
                boolean res = tester.test(testcase.getInput(), testcase.getOutput());
                failed = !res;
                testcase.setResult(res);
            }
            util.writeTestCases();
            if (failed)
                throw new RuntimeException("Testcases Failed");
            System.out.println("All Testcases Passed");
        } catch (Exception e) {
            System.out.println(e);
            System.exit(1);
        }
    }
}
