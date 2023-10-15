public class DecimalToHexadecimalTest {

    boolean test(int input, String output) {
        String result = DecimalToHexadecimal.decimalToHexadecimal(input);
        return result.equals(output);
    }
}
