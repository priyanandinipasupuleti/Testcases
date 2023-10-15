

import java.util.Scanner;

public class DecimalToOctal {
    // Function to convert decimal to octal
    public static String decimalToOctal(int decimal) {
        StringBuilder octal = new StringBuilder(); // This creates a StringBuilder object to build the octal representation.

        // Convert decimal to octal
        while (decimal > 0) { // This loop continues as long as the decimal number is greater than zero.
            int remainder = decimal % 8; // Calculate the remainder when decimal is divided by 8
            octal.insert(0, remainder); // Insert the remainder at the beginning of the octal string using the insert method of StringBuilder
            decimal /= 8; // Update decimal by dividing it by 8.
        }
        return octal.toString(); // Return the octal representation as a string.
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a decimal number: ");
            int decimal = scanner.nextInt();
            String octal = decimalToOctal(decimal);
            System.out.println("Octal: " + octal);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
