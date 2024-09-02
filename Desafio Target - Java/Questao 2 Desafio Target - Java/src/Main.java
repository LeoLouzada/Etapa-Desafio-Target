import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Informe um numero: ");
        int number = scanner.nextInt();

        boolean isFibonacci = false;

        if (number >= 0) {

            int num1 = 5 * number * number + 4;
            int num2 = 5 * number * number - 4;

            int sqrt1 = (int) Math.sqrt(num1);
            int sqrt2 = (int) Math.sqrt(num2);

            if (sqrt1 * sqrt1 == num1 || sqrt2 * sqrt2 == num2) {
                isFibonacci = true;
            }
        }

        if (isFibonacci) {
            System.out.println(number + " pertence a sequencia de Fibonacci.");
        } else {
            System.out.println(number + " nao pertence a sequencia de Fibonacci.");
        }

        scanner.close();
    }
}