#include <stdio.h>
#include <stdlib.h>

int main() {
    // Array de faturamento diário (valores fornecidos pelo JSON)
    double faturamento[] = {31490.7866, 37277.9400, 37708.4303, 0.0000, 0.0000,
                17934.2269, 0.0000, 6965.1262, 24390.9374, 14279.6481,
                0.0000, 0.0000, 39807.6622, 27261.6304, 39775.6434,
                29797.6232, 17216.5017, 0.0000, 0.0000, 12974.2000,
                28490.9861, 8748.0937, 8889.0023, 17767.5583, 0.0000,
                0.0000, 3071.3283, 48275.2994, 10299.6761, 39874.1073};

    int n = sizeof(faturamento) / sizeof(faturamento[0]);
    double menor = 0, maior = 0, soma = 0;
    int diasComFaturamento = 0;

    for (int i = 0; i < n; i++) {
        if (faturamento[i] > 0.0) {
            menor = maior = faturamento[i];
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (faturamento[i] > 0.0) {
            if (faturamento[i] < menor) menor = faturamento[i];
            if (faturamento[i] > maior) maior = faturamento[i];
            soma += faturamento[i];
            diasComFaturamento++;
        }
    }

    double media = soma / diasComFaturamento;

    int diasAcimaMedia = 0;
    for (int i = 0; i < n; i++) {
        if (faturamento[i] > media) {
            diasAcimaMedia++;
        }
    }

    printf("Media: %.2lf\n", media);
    printf("Menor valor de faturamento: %.2f\n", menor);
    printf("Maior valor de faturamento: %.2f\n", maior);
    printf("Numero de dias com faturamento acima da media mensal: %d\n", diasAcimaMedia);

    return 0;
}
