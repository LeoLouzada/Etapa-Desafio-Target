import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite uma string para inverter: ");
        String input = scanner.nextLine();

        scanner.close();

        String invertida = "";

        for (int i = input.length() - 1; i >= 0; i--) {
            invertida += input.charAt(i);
        }
        
        System.out.println("String invertida: " + invertida);
    }
}