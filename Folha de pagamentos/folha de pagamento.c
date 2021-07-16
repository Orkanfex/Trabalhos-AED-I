/*
Trabalho 1 - Folha de pagamentos
Alunos:
Henrique Gettner de Oliveira RGM: 45767
Henrique Apolinário Iwamizu Tada RGM: 43927
Leandro Madeira de Oliveira RGM: 45280
Guilherme Garcia Gloor RGM: 45535
Felipe Echeverria Vilhalva RGM: 45611
João Paulo Ishii Marcon RGM: 45276
*/
#include <stdio.h>

int main() {

    int num, divisor;
    float soma;

    printf("Informe a quantidade de funcionarios: ");
    scanf("%d", &num);
    if (num <= 0 || num > 10000) {
        do {
            printf("Informe a quantidade correta de funcionarios: ");
            scanf("%d", &num);
            if(num <= 0 || num > 10000) {
                printf("\nvalor invalido! Digite outro valor!");
            }
        } while (num <= 0 || num > 10000);
    }
    if (num > 0 && num <= 10000) {
        soma = 0;  
        for (divisor = 1; divisor < num; divisor++) {
            soma = soma + divisor;
        }
    }
    printf("soma: %.2f", soma);
    return 0;
}