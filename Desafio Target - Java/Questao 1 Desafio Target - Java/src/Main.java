public class Main {
    public static void main(String[] args) {

        int indice = 13;  // Valor do índice
        int soma = 0;     // Variável para armazenar a soma
        int k = 0;        // Variável de controle

        // Laço para somar os números de 1 até o valor do índice
        while (k < indice) {
            k = k + 1;    // Incrementa o valor de k
            soma = soma + k;  // Adiciona k à soma
        }

        // Imprime o resultado da soma
        System.out.println(soma);
    }
}