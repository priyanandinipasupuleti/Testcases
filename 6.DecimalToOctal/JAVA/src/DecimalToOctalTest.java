public class DecimalToOctalTest {

    boolean test(int input, String output) {
        String result = DecimalToOctal.decimalToOctal(input);
        return result.equals(output);
    }
}
