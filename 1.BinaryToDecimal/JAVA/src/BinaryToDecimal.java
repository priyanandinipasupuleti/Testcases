import java.util.Scanner;

public class BinaryToDecimal {

    
    // Function to convert binary digit to decimal value
    public static int binaryDigitToDecimal(char binaryDigit) {
        return binaryDigit - '0';
    }

    // Function to convert binary to decimal
    public static int binaryToDecimal(String binary) {
        if (binary == null) {
            return -1; // Handle the case where the binary string is null
        }

        int decimal = 0;
        int power = 0;

        // Convert binary to decimal
        for (int i = binary.length() - 1; i >= 0; i--) {
            int decimalValue = binaryDigitToDecimal(binary.charAt(i));

            if (decimalValue != 0 && decimalValue != 1) {
                return -1;
            }

            decimal += decimalValue * Math.pow(2, power);
            power++;
        }

        return decimal;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a binary number: ");
            String binary = scanner.nextLine();
            int decimal = binaryToDecimal(binary);

            if (decimal == -1) {
                System.out.println("Invalid binary number!");
            } else {
                System.out.println("Decimal: " + decimal);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
