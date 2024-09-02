#include <stdio.h>
#include <stdlib.h>
#include <cJSON.h>

void calcularFaturamento(const char* jsonString) {
    cJSON *jsonArray = cJSON_Parse(jsonString);
    if (jsonArray == NULL) {
        printf("Erro ao analisar o JSON.\n");
        return;
    }

    int totalDias = cJSON_GetArraySize(jsonArray);
    double menorValor = -1, maiorValor = -1, soma = 0.0;
    int diasComFaturamento = 0, diasAcimaMedia = 0;

    // ITERA SOBRE CADA ELEMENTO DO ARRAY JSON
    for (int i = 0; i < totalDias; i++) {
        cJSON *dia = cJSON_GetArrayItem(jsonArray, i);
        cJSON *valor = cJSON_GetObjectItem(dia, "valor");

        if (valor->valuedouble > 0) {  // Ignora dias sem faturamento (valor = 0)
            if (menorValor == -1 || valor->valuedouble < menorValor) {
                menorValor = valor->valuedouble;
            }
            if (maiorValor == -1 || valor->valuedouble > maiorValor) {
                maiorValor = valor->valuedouble;
            }
            soma += valor->valuedouble;
            diasComFaturamento++;
        }
    }

    double mediaMensal = soma / diasComFaturamento;

    // CONTA OS DIAS COM FATURAMENTO ACIMA DA MEDIA
    for (int i = 0; i < totalDias; i++) {
        cJSON *dia = cJSON_GetArrayItem(jsonArray, i);
        cJSON *valor = cJSON_GetObjectItem(dia, "valor");

        if (valor->valuedouble > mediaMensal) {
            diasAcimaMedia++;
        }
    }

    printf("Menor valor de faturamento: %.2f\n", menorValor);
    printf("Maior valor de faturamento: %.2f\n", maiorValor);
    printf("Número de dias com faturamento acima da média: %d\n", diasAcimaMedia);

    cJSON_Delete(jsonArray);
}

int main() {

    FILE *arquivo = fopen("faturamento.json", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // CALCULA O TAMANHO DO ARQUIVO
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    // LE O CONTEUDO DO ARQUIVO
    char *jsonString = (char *)malloc(tamanhoArquivo + 1);
    fread(jsonString, 1, tamanhoArquivo, arquivo);
    jsonString[tamanhoArquivo] = '\0';

    fclose(arquivo);

    calcularFaturamento(jsonString);

    free(jsonString);
    return 0;
}
