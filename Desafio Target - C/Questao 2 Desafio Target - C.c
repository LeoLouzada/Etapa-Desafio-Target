#include <stdio.h>
#include <stdlib.h>

int pertenceFibonacci(int numero){

    int primNum = 0;
    int segNum = 1;
    int proxNum = 0;

    if(numero == 0 || numero == 1){
        return 1; // RETORNA VERDADEIRO, POIS O NUMERO FAZ PARTE DA SEQUENCIA
    }

    while(proxNum < numero){
        proxNum = primNum + segNum; // CALCULA O PROXIMO VALOR DA SEQUENCIA
        primNum = segNum; // O PRIMEIRO VALOR VAI RECEBER O VALOR DA FRENTE
        segNum = proxNum; // O PRIMEIRO VALOR VAI RECEBER O VALOR DA FRENTE
    }

    if(proxNum == numero){
        return 1; // RETORNA VERDADEIRO, POIS O NUMERO FAZ PARTE DA SEQUENCIA
    }else{
        return 0; // RETORNA FALSO, POIS O NUMERO NAO FAZ PARTE DA SEQUENCIA
    }
}

int main() {

    int numero;

    printf("Digite o numero para realizar a verificacao: ");
    scanf("%d", &numero);

    if(pertenceFibonacci(numero)){
        printf("%d faz parte da sequencia de Fibonacci!\n", numero);
    }else{
        printf("%d nao faz parte da sequencia de Fibonacci!\n", numero);
    }

    return 0;
}

