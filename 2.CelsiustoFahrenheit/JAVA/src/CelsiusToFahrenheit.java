import java.util.Scanner;

public class CelsiusToFahrenheit {
    // Function to convert Celsius to Fahrenheit
    public static double celsiusToFahrenheit(double celsius) {
        return (celsius * 9 / 5) + 32;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Please enter the temperature in Celsius: ");
            double celsius = scanner.nextDouble();
            double fahrenheit = celsiusToFahrenheit(celsius);
            System.out.printf("%.2f Celsius temperature = %.2f Fahrenheit%n", celsius, fahrenheit);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
