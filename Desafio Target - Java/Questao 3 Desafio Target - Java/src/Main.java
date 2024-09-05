public class Main {

    public static void main(String[] args) {
        // Valores fornecidos no JSON
        double[] valores = {
                31490.7866, 37277.9400, 37708.4303, 0.0000, 0.0000,
                17934.2269, 0.0000, 6965.1262, 24390.9374, 14279.6481,
                0.0000, 0.0000, 39807.6622, 27261.6304, 39775.6434,
                29797.6232, 17216.5017, 0.0000, 0.0000, 12974.2000,
                28490.9861, 8748.0937, 8889.0023, 17767.5583, 0.0000,
                0.0000, 3071.3283, 48275.2994, 10299.6761, 39874.1073
        };

        double menor = Double.MAX_VALUE;
        double maior = Double.MIN_VALUE;
        double soma = 0.0;
        int diasComFaturamento = 0;

        for (double valor : valores) {
            if (valor > 0) {  // Considera apenas dias com faturamento positivo
                if (valor < menor) menor = valor;
                if (valor > maior) maior = valor;
                soma += valor;
                diasComFaturamento++;
            }
        }

        double media = soma / diasComFaturamento;

        int diasAcimaMedia = 0;
        for (double valor : valores) {
            if (valor > media) {
                diasAcimaMedia++;
            }
        }

        System.out.printf("Menor valor de faturamento: %.2f%n", menor);
        System.out.printf("Maior valor de faturamento: %.2f%n", maior);
        System.out.printf("Numero de dias com faturamento acima da media mensal: %d%n", diasAcimaMedia);
    }
}
