#include <stdio.h>
#include <stdlib.h>

void inverterString(char string[]){

    int primLetra = 0;
    int ultLetra = strlen(string) - 1;
    char aux;

    while(primLetra < ultLetra){

        aux = string[primLetra];
        string[primLetra] = string[ultLetra];
        string[ultLetra] = aux;

        primLetra++;
        ultLetra--;
    }
}

int main(){

    char string[100];

    printf("Digite a string que sera invertida: ");
    fgets(string, sizeof(string), stdin);

    // Remove o caractere de nova linha '\n' do final da string, se presente
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    inverterString(string);

    printf("\nString invertida: %s\n", string);

    return 0;
}

