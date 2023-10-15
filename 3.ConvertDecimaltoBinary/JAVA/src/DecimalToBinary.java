import java.util.Scanner;

public class DecimalToBinary {
    // Function to convert decimal to binary
    public static String decimalToBinary(int decimal) {
        StringBuilder binary = new StringBuilder();  // StringBuilder to build the binary representation

        if (decimal == 0) {
            // Special case for decimal number 0
            binary.append("0");  // Append "0" to the binary string
        } else {
            // Convert decimal to binary
            while (decimal > 0) {
                int remainder = decimal % 2;        // Get the remainder when dividing by 2
                binary.insert(0, remainder);       // Insert the remainder at the beginning of the binary string
                decimal /= 2;                     // Divide the decimal number by 2
            }
        }

        return binary.toString();  // Return the binary representation as a string
    }

    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);  // Create a new Scanner object to read user input
  
      try {
          System.out.print("Enter a decimal number: "); // prompt the user to enter a decimal number.
          int decimal = scanner.nextInt();  // Read the user input for a decimal number
  
          // Function decimalToBinary with the parameter decimal is called, and the return value is assigned to binary 
          String binary = decimalToBinary(decimal);
  
          System.out.println("Binary: " + binary);  // Print the binary representation
      } finally {
          scanner.close(); // Ensure the scanner is closed to release the associated resources.
      }
  }  
}
