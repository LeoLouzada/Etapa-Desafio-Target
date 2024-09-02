#include <stdio.h>
#include <stdlib.h>

int main() {

    double faturamentoSP = 67836.43;
    double faturamentoRJ = 36678.66;
    double faturamentoMG = 29229.88;
    double faturamentoES = 27165.48;
    double faturamentoOutros = 19849.53;

    double faturamentoTotal = faturamentoSP + faturamentoRJ + faturamentoMG + faturamentoES + faturamentoOutros;

    double percentualSP = (faturamentoSP / faturamentoTotal) * 100;
    double percentualRJ = (faturamentoRJ / faturamentoTotal) * 100;
    double percentualMG = (faturamentoMG / faturamentoTotal) * 100;
    double percentualES = (faturamentoES / faturamentoTotal) * 100;
    double percentualOutros = (faturamentoOutros / faturamentoTotal) * 100;

    printf("Percentual de representacao de cada estado:\n");
    printf("SP: %.2f%%\n", percentualSP);
    printf("RJ: %.2f%%\n", percentualRJ);
    printf("MG: %.2f%%\n", percentualMG);
    printf("ES: %.2f%%\n", percentualES);
    printf("Outros: %.2f%%\n", percentualOutros);

    return 0;
}
