public class CelsiusToFahrenheitTest {

    boolean test(double input, double expectedOutput) {
        double result = CelsiusToFahrenheit.celsiusToFahrenheit(input);
        return Math.abs(result - expectedOutput) < 0.01; // Allowing for a small difference due to double precision.
    }
}
