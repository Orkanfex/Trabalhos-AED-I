#include <stdio.h>


void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main(int argc, char const *argv[])
{
    int nota_500, nota_150, nota_50, nota_20, nota_10, nota_5, nota_2, nota_1;
    int opc, opc_ger, cpf;
    int valor, total_exist, total_sac;

    opc = -1;
    opc_ger = -1;

    nota_500 = 100;
    nota_150 = 200; 
    nota_50 = 400;
    nota_20 = 800;
    nota_10 = 1600;
    nota_5 = 3200;
    nota_2 = 6400;
    nota_1 = 12800;
    
    total_exist = (500*nota_500) + (150*nota_150) + (50*nota_50) + (20*nota_20) + (10*nota_10) + (5*nota_5) + (2*nota_2) + (1*nota_1);

    total_sac = 0;

    do{
        printf("---Bem vindo ao caixa eletronico!--\n");
        printf("1-Saque\n");
        printf("2-gerente\n");
        printf("3-finalizar\n");
        scanf("%d", &opc);
        flush_in();

        if(opc<1 || opc>3){
            printf("Opcao inxistente, digite uma opção válida\n");
        }

        switch (opc)
        {
            case 1:
            printf("CPF: ");
            scanf("%d", &cpf);
            //VALIDAÇÃO DO CPF





            //será executado se o CPF for válido
            printf("Insira o valor desejado: ");
            scanf("%d", &valor);    
            flush_in();

            total_sac += valor;
            total_exist -= valor;

            //contagem de cedulas


            //volta ao menu
            opc = -1;

            break;
        case 2:
            do
            {
                printf("\n---Menu Gerente--\n");
                printf("1-Valor total sacado\n");
                printf("2-valor do saldo existente\n");
                printf("3-Quantidade de cédulas existentes\n");
                printf("4-Abastecer o caixa eletronico\n");
                printf("5-Voltar ao menu principal\n");
                scanf("%d", &opc_ger);
                flush_in();
                
                switch (opc_ger)
                {
                case 1:
                    printf("\n----------------------------");
                    printf("\nO valor total sacado e: %d\n", total_sac);
                    printf("----------------------------\n");
                    opc_ger = -1;
                    break;
                case 2:
                    printf("\n------------------------------------");
                    printf("\nO valor existente no caixa e: %d\n", total_exist);
                    printf("------------------------------------\n");
                    opc_ger = -1;
                    break;
                case 3:
                    /* code */
                    break;
                case 4:
                    /* code */
                    break;
                    
                default:
                    opc = -1;
                    break;
                }

            } while (opc_ger < 1 || opc_ger > 5);
        
            break;

        default:
            break;
        }

    }while(opc<1 || opc>3);
    
    
        
    return 0;
}
