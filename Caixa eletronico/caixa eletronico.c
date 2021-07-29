#include <stdio.h>


void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main(int argc, char const *argv[])
{
    int nota_500, nota_150, nota_50, nota_20, nota_10, nota_5, nota_2, nota_1;
    int opc, cpf;
    float valor;

    nota_500 = 100;
    nota_150 = 200; 
    nota_50 = 400;
    nota_20 = 800;
    nota_10 = 1600;
    nota_5 = 3200;
    nota_2 = 6400;
    nota_1 = 12800;
    
    total = (500*nota_500) + (150*nota_150) + (50*nota_50) + (20*nota_20) + (10*nota_10) + (5*nota_5) + (2*nota_2) + (1*nota_1);

    do{
        printf("---Bem vindo ao caixa eletronico!--\n");
        printf("1-Saque\n");
        printf("2-gerente\n");
        printf("3-finalizar\n");
        scanf("%d", &opc);
        flush_in();

        if(opc<1 || opc>3){
            printf("Opcao inxistente, digite uma opção válida\n")
        }

    }while(opc!=1 || opc!=2 || opc!=3)
    
    switch (opc)
    {
    case 1:
        printf("CPF: ");
        scanf("%d", &cpf);
        //VALIDAÇÃO DO CPF





        //será executado se o CPF for válido
        printf("Insira o valor desejado: ");
        scanf("%f", &valor);    
        flush_in();

        
        break;
    case 2:

        break;
    case 3:

        break;

    default:
        break;
    }
        
    return 0;
}
