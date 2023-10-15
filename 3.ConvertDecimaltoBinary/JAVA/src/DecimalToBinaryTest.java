public class DecimalToBinaryTest {

    boolean test(int input, String output) {
        String result = DecimalToBinary.decimalToBinary(input);
        return result.equals(output);
    }
}
