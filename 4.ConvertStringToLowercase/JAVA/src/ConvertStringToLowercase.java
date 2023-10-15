import java.util.Scanner;
public class ConvertStringToLowercase {
    // Function to convert a string to lowercase
    public static String toLowerCase(String input) {
        StringBuilder result = new StringBuilder();
        for (char ch : input.toCharArray()) {
            if (ch >= 'A' && ch <= 'Z') {
                result.append((char) (ch + 32));
            } else {
                result.append(ch);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the string to convert to lowercase: ");
            String input = scanner.nextLine();
            String lowercase = toLowerCase(input);
            System.out.println("Lowercase: " + lowercase);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
