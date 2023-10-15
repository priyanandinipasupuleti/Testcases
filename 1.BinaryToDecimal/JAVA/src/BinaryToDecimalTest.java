public class BinaryToDecimalTest {

    boolean test(String binary, int expectedDecimal) {
        int result = BinaryToDecimal.binaryToDecimal(binary);
        return result == expectedDecimal;
    }
}
