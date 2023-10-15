import java.util.Scanner;

public class DecimalToHexadecimal {
    // Function to convert decimal to hexadecimal
    public static String decimalToHexadecimal(int decimal) {
        String hexadecimal = ""; // Initialize an empty string to store the hexadecimal representation.

        // Mapping of hexadecimal digits
        char[] hexDigits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        // Convert decimal to hexadecimal
        while (decimal > 0) {
            int remainder = decimal % 16; // Extract the remainder when dividing the decimal by 16.
            hexadecimal = hexDigits[remainder] + hexadecimal; // Append the corresponding hexadecimal digit to the front of the string.
            decimal /= 16; // Update the decimal number by dividing it by 16.
        }
        return hexadecimal; // Return the hexadecimal representation.
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a decimal number: ");
            int decimal = scanner.nextInt();
            String hexadecimal = decimalToHexadecimal(decimal);
            System.out.println("Hexadecimal: " + hexadecimal);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
