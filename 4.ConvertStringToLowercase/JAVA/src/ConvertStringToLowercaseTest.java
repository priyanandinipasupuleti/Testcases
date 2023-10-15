

public class ConvertStringToLowercaseTest {

    boolean test(String input, String expectedOutput) {
        String result = ConvertStringToLowercase.toLowerCase(input);
        return result.equals(expectedOutput);
    }
}
