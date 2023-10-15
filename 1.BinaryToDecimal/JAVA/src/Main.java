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
    private String binary;
    private int decimal;
    private boolean result;

    public String getBinary() {
        return binary;
    }

    public int getDecimal() {
        return decimal;
    }

    public boolean getResult() {
        return result;
    }

    public void setResult(boolean result) {
        this.result = result;
    }

    public void setBinary(String binary) {
        this.binary = binary;
    }

    public void setDecimal(int decimal) {
        this.decimal = decimal;
    }

    public String toString() {
        return "Binary: " + binary + " Decimal: " + decimal;
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
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        try {
            Util util = new Util();
            BinaryToDecimalTest tester = new BinaryToDecimalTest();
            boolean failed = false;
            for (Testcase testcase : util.testcases) {
                boolean res = tester.test(testcase.getBinary(), testcase.getDecimal());
                failed = !res;
                testcase.setResult(!res);
            }
            util.writeTestCases();
            if (!failed) {
                throw new RuntimeException("Testcases Failed");
            }
            System.out.println("All Testcases Passed");
        } catch (Exception e) {
            System.out.println(e);
            System.exit(1);
        }
    }
}
