#include <stdio.h>

void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main(int argc, char const *argv[])
{
    int nota_500 = 0, nota_150 = 0, nota_50 = 0, nota_20 = 0, nota_10 = 0, nota_5 = 0, nota_2 = 0, nota_1 = 0;
    int qnt_500, qnt_150, qnt_50, qnt_20, qnt_10, qnt_5, qnt_2, qnt_1;
    int opc = 0, opc_ger = 0;
    int valor_saque = 0, total_existente = 0, total_sacado = 0, total_cedulas = 0, verifica_saque = 0;
    int digito_1, digito_2, total, verifica, valida_verifica;
    int c1, c2, c3, c4, c5, c6;
    long long cpf_user, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11; 
    
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
    // 173600 - total_existente.
    total_existente = (500 * nota_500) + (150 * nota_150) + (50 * nota_50) + (20 * nota_20) + (10 * nota_10) + (5 * nota_5) + (2 * nota_2) + (1 * nota_1);
    // 25500 - total_cedulas
    total_cedulas = (nota_500 + nota_150 + nota_50 + nota_20 + nota_10 + nota_5 + nota_2 + nota_1);

    do
    {
        printf("\n\n---Bem vindo ao caixa eletronico!--\n");
        printf("1 - Saque\n");
        printf("2 - Gerente\n");
        printf("3 - Finalizar\n");
        printf("\nDigite o numero da opcao desejada: ");
        scanf("%d", &opc);
        flush_in();

        if (opc < 1 || opc > 3)
        {
            printf("\nOpcao inexistente, digite uma opcao valida.\n");
            opc = -1;
        }

        switch (opc)
        {
            case 1:
                cpf_user = d1 = d2 = d3 = d4 = d5 = d6 = d7 = d8 = d9 = d10 = d11 = 0;
                digito_1 = digito_2 = total = verifica = valida_verifica = 0;
                printf("\n");
                printf("OPCAO ESCOLHIDA: SAQUE\n");
                printf("\nINFORME SEU CPF: ");
                scanf("%lld", &cpf_user);
                flush_in();

                //VALIDAÇÃO DO CPF
                d11 = cpf_user % 10;
                d10 = (cpf_user / 10) % 10;
                d9 = (cpf_user / 100) % 10;
                d8 = (cpf_user / 1000) % 10;
                d7 = (cpf_user / 10000) % 10;
                d6 = (cpf_user / 100000) % 10;
                d5 = (cpf_user / 1000000) % 10;
                d4 = (cpf_user / 10000000) % 10;
                d3 = (cpf_user / 100000000) % 10;
                d2 = (cpf_user / 1000000000) % 10;
                d1 = cpf_user / 10000000000;

                if ((cpf_user == 11111111111) || (cpf_user == 22222222222) || (cpf_user == 33333333333) || (cpf_user == 44444444444) || (cpf_user == 55555555555) || (cpf_user == 66666666666) || (cpf_user == 77777777777) || (cpf_user == 88888888888) || (cpf_user == 99999999999))
                {
                    printf("\nCPF Invalido, tente novamente!\n");
                    opc = -1;
                    break;
                }
                else
                {   // Cálculo do dígito 1 
                    total += ((d1 * 10) + (d2 * 9) + (d3 * 8) + (d4 * 7) + (d5 * 6) + (d6 * 5) + (d7 * 4) + (d8 * 3) + (d9 * 2));
                    digito_1 = 11 - (total % 11);
                    if (digito_1 > 9)
                    {
                        digito_1 = 0;
                    }
                    // Cálculo do dígito 2 
                    total = 0;
                    total += ((d1 * 11) + (d2 * 10) + (d3 * 9) + (d4 * 8) + (d5 * 7) + (d6 * 6) + (d7 * 5) + (d8 * 4) + (d9 * 3) + (digito_1 * 2));
                    digito_2 = 11 - (total % 11);
                    if (digito_2 > 9)
                    {
                        digito_2 = 0;
                    }
                    verifica = (d10 * 10) + d11;
                    valida_verifica = (10 * digito_1) + digito_2;
                    if (verifica != valida_verifica)
                    {
                        printf("CPF Invalido, tente novamente!\n");
                        opc = -1;
                        break;
                    }
                    else
                    {
                        printf("Ola, cliente.\n");
                        printf("\nInsira o valor do saque desejado: ");
                        scanf("%d", &valor_saque);    
                        flush_in();
                        
                        // validação
                        if (valor_saque <= 0 )
                        {
                            do
                            {
                                printf("\nValor invalido, o valor do saque deve ser maior ou igual a 1 real.\n");
                                printf("\nInsira novamente o valor desejado: ");
                                scanf("%d", &valor_saque);
                            } while (valor_saque <= 0);
                        }
                        
                        // Melhor distribuição de cédulas
                        verifica_saque = valor_saque;
                        qnt_500 = qnt_150 = qnt_50 = qnt_20 = qnt_10 = qnt_5 = qnt_2 = qnt_1 = 0; 
                        while ((nota_500 > 0) && (verifica_saque >= 500))
                        {
                            nota_500 -= 1;
                            total_sacado += 500;
                            total_cedulas -= 1;
                            verifica_saque -= 500;
                            total_existente -= 500;
                            qnt_500 += 1;
                        }

                        while ((nota_150 > 0) && (verifica_saque >= 150))
                        {
                            nota_150 -= 1;
                            total_sacado += 150;
                            total_cedulas -= 1;
                            verifica_saque -= 150;
                            total_existente -= 150;
                            qnt_150 += 1;
                        }
                        
                        while ((nota_50 > 0) && (verifica_saque >= 50))
                        {
                            nota_50 -= 1;
                            total_sacado += 50;
                            total_cedulas -= 1;
                            verifica_saque -= 50;
                            total_existente -= 50;
                            qnt_50 += 1;
                        }

                        while ((nota_20 > 0) && (verifica_saque >= 20))
                        {
                            nota_20 -= 1;
                            total_sacado += 20;
                            total_cedulas -= 1;
                            verifica_saque -= 20;
                            total_existente -= 20;
                            qnt_20 += 1; 
                        }

                        while ((nota_10 > 0) && (verifica_saque >= 10))
                        {
                            nota_10 -= 1;
                            total_sacado += 10;
                            total_cedulas -= 1;
                            verifica_saque -= 10;
                            total_existente -= 10;
                            qnt_10 += 1;
                        }

                        while ((nota_5 > 0) && (verifica_saque >= 5))
                        {
                            nota_5 -= 1;
                            total_sacado += 5;
                            total_cedulas -= 1;
                            verifica_saque -= 5;
                            total_existente -= 5;
                            qnt_5 += 1;
                        }
                        
                        while ((nota_2 > 0) && (verifica_saque >= 2))
                        {
                            nota_2 -= 1;
                            total_sacado += 2;
                            total_cedulas -= 1;
                            verifica_saque -= 2;
                            total_existente -= 2;
                            qnt_2 += 1;
                        }
                        
                        while ((nota_1 > 0) && (verifica_saque >= 1))
                        {
                            nota_1 -= 1;
                            total_sacado += 1;
                            total_cedulas -= 1;
                            verifica_saque -= 1;
                            total_existente -= 1;
                            qnt_1 += 1;
                        }
                        
                        // Verificação da existência do valor solicitado no caixa
                        if (verifica_saque > 0)
                        {
                            valor_saque = valor_saque - verifica_saque;
                            printf("\nATENCAO\n");
                            printf("\nValor de R$ %d nao disponivel para saque.", verifica_saque);
                            printf("\nVerifique o abastecimento do caixa com o gerente!");
                        }
                        
                        // Separação dos digitos do valor de saque solicitado para informá-lo por extenso
                        c1 = c2 = c3 = c4 = c5 = c6 = 0;
                        c1 = (valor_saque % 10);  // Unidade
                        c2 = (valor_saque / 10) % 10;  // Dezena
                        c3 = (valor_saque / 100) % 10;  // Centena
                        c4 = (valor_saque / 1000) % 10;  // Milhar
                        c5 = (valor_saque / 10000) % 10;  // Dezena de milhar
                        c6 = (valor_saque / 100000) % 10;  // Centena de milhar
                        
                        if (valor_saque > 0) 
                        {
                            printf("\nOperacao realizado com sucesso!");
                            printf("\nCedulas utilizadas:\n");
                            if (qnt_500 > 1)
                            {
                                printf("%d cedulas de quinhentos reais.\n", qnt_500);
                            }
                            else if (qnt_500 == 1)
                            {
                                printf("%d cedula de quinhentos reais.\n", qnt_500);
                            }
                            if (qnt_150 > 1)
                            {
                                printf("%d cedulas de cento e cinquenta reais.\n", qnt_150);
                            }
                            else if (qnt_150 == 1)
                            {
                                printf("%d cedula de cento e cinquenta reais.\n", qnt_150);
                            }
                            if (qnt_50 > 1)
                            {
                                printf("%d cedulas de cinquenta reais.\n", qnt_50);
                            }
                            else if (qnt_50 == 1)
                            {
                                printf("%d cedula de cinquenta reais.\n", qnt_50);
                            }
                            if (qnt_20 > 1)
                            {
                                printf("%d cedulas de vinte reais.\n", qnt_20);
                            }
                            else if (qnt_20 == 1)
                            {
                                printf("%d cedula de vinte reais.\n", qnt_20);
                            }
                            if (qnt_10 > 1)
                            {
                                printf("%d cedulas de dez reais.\n", qnt_10);
                            }
                            else if (qnt_10 == 1)
                            {
                                printf("%d cedula de dez reais.\n", qnt_10);
                            }
                            if (qnt_5 > 1)
                            {
                                printf("%d cedulas de cinco reais.\n", qnt_5);
                            }
                            else if (qnt_5 == 1)
                            {
                                printf("%d cedula de cinco reais.\n", qnt_5);
                            }
                            if (qnt_2 > 1)
                            {
                                printf("%d cedulas de dois reais.\n", qnt_2);
                            }
                            else if (qnt_2 == 1)
                            {
                                printf("%d cedula de dois reais.\n", qnt_2);
                            }
                            if (qnt_1 > 1)
                            {
                                printf("%d cedulas de um real.\n", qnt_1);
                            }
                            else if (qnt_1 == 1)
                            {
                                printf("%d cedula de um real.\n", qnt_1);
                            }
                            printf("\nSaque solicitado no valor de ");

                        }
                        // Centena de milhar
                        if (c6 > 0)
                        {
                            if ((c5 == 0) && (c4 == 0))
                            {
                                printf("cem ");
                            }
                            else
                            {
                                printf("cento e ");
                            }
                        }
                        // Dezena de milhar
                        if (c5 > 0)
                        {   // Parte do milhar
                            if (c4 > 0)
                            {
                                switch (c5)
                                {
                                    case 1:
                                        if (c4 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c4 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c4 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c4 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c4 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else 
                                        {
                                            printf("dez");
                                        } 
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                }
                            }
                            else
                            {
                                switch (c5)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Milhar
                        if (c4 > 0)
                        {
                            if (c5 == 1)
                            {
                                switch (c4)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c5 != 1)  //(c4 > 0)
                            {
                                switch (c4)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        }
                        // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                        if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0 ) || (c4 > 0)))
                        {
                            printf("mil ");
                        }
                        if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0)|| (c1 > 0)))
                        {
                            printf("e ");
                        }
                        // Centena 
                        if (c3 > 0)
                        {
                            if ((c2 > 0) || (c1 > 0))
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cento e ");        
                                        break;
                                    case 2:
                                        printf("duzentos e ");
                                        break;
                                    case 3:
                                        printf("trezentos e ");
                                        break;
                                    case 4:
                                        printf("quatrocentos e ");
                                        break;
                                    case 5:
                                        printf("quinhentos e ");
                                        break;
                                    case 6:
                                        printf("seiscentos e ");
                                        break;
                                    case 7:
                                        printf("setecentos e ");
                                        break;
                                    case 8:
                                        printf("oitocentos e ");
                                        break;
                                    case 9:
                                        printf("novecentos e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cem ");
                                        break;
                                    case 2:
                                        printf("duzentos ");
                                        break;
                                    case 3:
                                        printf("trezentos ");
                                        break;
                                    case 4:
                                        printf("quatrocentos ");
                                        break;
                                    case 5:
                                        printf("quinhentos ");
                                        break;
                                    case 6:
                                        printf("seiscentos ");
                                        break;
                                    case 7:
                                        printf("setecentos ");
                                        break;
                                    case 8:
                                        printf("oitocentos ");
                                        break;
                                    case 9:
                                        printf("novecentos ");
                                        break;
                                }
                            }
                        }
                        // Dezena
                        if (c2 > 0)
                        {
                            if (c1 > 0)
                            {
                                switch (c2)
                                {
                                    case 1:
                                        if (c1 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c1 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c1 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c1 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c1 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else
                                        {
                                            printf("dez");
                                        }
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c2)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Unidade
                        if (c1 > 0)
                        {
                            if (c2 == 1)
                            {
                                switch (c1)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c2 != 1)
                            {
                                switch (c1)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        } 
                        if (valor_saque > 1) 
                        {
                            printf("reais.\n");
                        }
                        else if (valor_saque == 1)
                        {
                            printf("real.\n");
                        }
                        //volta ao menu
                        opc = -1;
                        break;
                    }
                }
            case 2:
                do
                {
                    printf("\n---Menu Gerente--\n");
                    printf("1 - Valor total sacado\n");
                    printf("2 - valor do saldo existente\n");
                    printf("3 - Quantidade de cédulas existentes\n");
                    printf("4 - Abastecer o caixa eletronico\n");
                    printf("5 - Voltar ao menu principal\n");
                    printf("\nDigite o numero da opcao desejada: ");
                    scanf("%d", &opc_ger);
                    flush_in();
                    
                    switch (opc_ger)
                    {
                    case 1:
                        c1 = c2 = c3 = c4 = c5 = c6 = 0;
                        c1 = (total_sacado % 10);  // Unidade
                        c2 = (total_sacado / 10) % 10;  // Dezena
                        c3 = (total_sacado / 100) % 10;  // Centena
                        c4 = (total_sacado / 1000) % 10;  // Milhar
                        c5 = (total_sacado / 10000) % 10;  // Dezena de milhar
                        c6 = (total_sacado / 100000) % 10;  // Centena de milhar
                        
                        printf("\n--------------------------------------------------------------------");
                        printf("\nO valor total sacado e: %d \n", total_sacado);
                        // Centena de milhar
                        if(total_sacado == 0){
                            printf("zero reais\n");
                        }
                        if (c6 > 0)
                        {
                            if ((c5 == 0) && (c4 == 0))
                            {
                                printf("cem ");
                            }
                            else
                            {
                                printf("cento e ");
                            }
                        }
                        // Dezena de milhar
                        if (c5 > 0)
                        {   // Parte do milhar
                            if (c4 > 0)
                            {
                                switch (c5)
                                {
                                    case 1:
                                        if (c4 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c4 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c4 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c4 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c4 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else 
                                        {
                                            printf("dez");
                                        } 
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                }
                            }
                            else
                            {
                                switch (c5)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Milhar
                        if (c4 > 0)
                        {
                            if (c5 == 1)
                            {
                                switch (c4)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c5 != 1)  //(c4 > 0)
                            {
                                switch (c4)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        }
                        // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                        if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0 ) || (c4 > 0)))
                        {
                            printf("mil ");
                        }
                        if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0)|| (c1 > 0)))
                        {
                            printf("e ");
                        }
                        // Centena 
                        if (c3 > 0)
                        {
                            if ((c2 > 0) || (c1 > 0))
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cento e ");        
                                        break;
                                    case 2:
                                        printf("duzentos e ");
                                        break;
                                    case 3:
                                        printf("trezentos e ");
                                        break;
                                    case 4:
                                        printf("quatrocentos e ");
                                        break;
                                    case 5:
                                        printf("quinhentos e ");
                                        break;
                                    case 6:
                                        printf("seiscentos e ");
                                        break;
                                    case 7:
                                        printf("setecentos e ");
                                        break;
                                    case 8:
                                        printf("oitocentos e ");
                                        break;
                                    case 9:
                                        printf("novecentos e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cem ");
                                        break;
                                    case 2:
                                        printf("duzentos ");
                                        break;
                                    case 3:
                                        printf("trezentos ");
                                        break;
                                    case 4:
                                        printf("quatrocentos ");
                                        break;
                                    case 5:
                                        printf("quinhentos ");
                                        break;
                                    case 6:
                                        printf("seiscentos ");
                                        break;
                                    case 7:
                                        printf("setecentos ");
                                        break;
                                    case 8:
                                        printf("oitocentos ");
                                        break;
                                    case 9:
                                        printf("novecentos ");
                                        break;
                                }
                            }
                        }
                        // Dezena
                        if (c2 > 0)
                        {
                            if (c1 > 0)
                            {
                                switch (c2)
                                {
                                    case 1:
                                        if (c1 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c1 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c1 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c1 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c1 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else
                                        {
                                            printf("dez");
                                        }
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c2)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Unidade
                        if (c1 > 0)
                        {
                            if (c2 == 1)
                            {
                                switch (c1)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c2 != 1)
                            {
                                switch (c1)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        } 
                        if (total_sacado > 1) 
                        {
                            printf("reais.\n");
                        }
                        else if (total_sacado == 1)
                        {
                            printf("real.\n");
                        }
                        printf("--------------------------------------------------------------------\n");
                        opc_ger = -1;
                        break;
                    case 2:
                        c1 = c2 = c3 = c4 = c5 = c6 = 0;
                        c1 = (total_existente % 10);  // Unidade
                        c2 = (total_existente / 10) % 10;  // Dezena
                        c3 = (total_existente / 100) % 10;  // Centena
                        c4 = (total_existente / 1000) % 10;  // Milhar
                        c5 = (total_existente / 10000) % 10;  // Dezena de milhar
                        c6 = (total_existente / 100000) % 10;  // Centena de milhar
                        printf("\n----------------------------------------------------------------------------");
                        printf("\nO valor existente no caixa e: %d\n", total_existente);
                        // Centena de milhar
                        if(total_existente == 0){
                            printf("zero reais\n");
                        }
                        if (c6 > 0)
                        {
                            if ((c5 == 0) && (c4 == 0))
                            {
                                printf("cem ");
                            }
                            else
                            {
                                printf("cento e ");
                            }
                        }
                        // Dezena de milhar
                        if (c5 > 0)
                        {   // Parte do milhar
                            if (c4 > 0)
                            {
                                switch (c5)
                                {
                                    case 1:
                                        if (c4 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c4 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c4 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c4 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c4 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else 
                                        {
                                            printf("dez");
                                        } 
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                }
                            }
                            else
                            {
                                switch (c5)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Milhar
                        if (c4 > 0)
                        {
                            if (c5 == 1)
                            {
                                switch (c4)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c5 != 1)  //(c4 > 0)
                            {
                                switch (c4)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        }
                        // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                        if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0 ) || (c4 > 0)))
                        {
                            printf("mil ");
                        }
                        if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0)|| (c1 > 0)))
                        {
                            printf("e ");
                        }
                        // Centena 
                        if (c3 > 0)
                        {
                            if ((c2 > 0) || (c1 > 0))
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cento e ");        
                                        break;
                                    case 2:
                                        printf("duzentos e ");
                                        break;
                                    case 3:
                                        printf("trezentos e ");
                                        break;
                                    case 4:
                                        printf("quatrocentos e ");
                                        break;
                                    case 5:
                                        printf("quinhentos e ");
                                        break;
                                    case 6:
                                        printf("seiscentos e ");
                                        break;
                                    case 7:
                                        printf("setecentos e ");
                                        break;
                                    case 8:
                                        printf("oitocentos e ");
                                        break;
                                    case 9:
                                        printf("novecentos e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cem ");
                                        break;
                                    case 2:
                                        printf("duzentos ");
                                        break;
                                    case 3:
                                        printf("trezentos ");
                                        break;
                                    case 4:
                                        printf("quatrocentos ");
                                        break;
                                    case 5:
                                        printf("quinhentos ");
                                        break;
                                    case 6:
                                        printf("seiscentos ");
                                        break;
                                    case 7:
                                        printf("setecentos ");
                                        break;
                                    case 8:
                                        printf("oitocentos ");
                                        break;
                                    case 9:
                                        printf("novecentos ");
                                        break;
                                }
                            }
                        }
                        // Dezena
                        if (c2 > 0)
                        {
                            if (c1 > 0)
                            {
                                switch (c2)
                                {
                                    case 1:
                                        if (c1 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c1 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c1 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c1 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c1 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else
                                        {
                                            printf("dez");
                                        }
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c2)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Unidade
                        if (c1 > 0)
                        {
                            if (c2 == 1)
                            {
                                switch (c1)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c2 != 1)
                            {
                                switch (c1)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        } 
                        if (total_existente > 1) 
                        {
                            printf("reais.\n");
                        }
                        else if (total_existente == 1)
                        {
                            printf("real.\n");
                        }
                        printf("----------------------------------------------------------------------------\n");
                        opc_ger = -1;
                        break;
                    case 3:
                        printf("\n--------------------------------------------------------------------------------------");
                        printf("\nO total de cedulas existente no caixa e: %d ", total_cedulas);
                        c1 = c2 = c3 = c4 = c5 = c6 = 0;
                        c1 = (total_cedulas % 10);  // Unidade
                        c2 = (total_cedulas / 10) % 10;  // Dezena
                        c3 = (total_cedulas / 100) % 10;  // Centena
                        c4 = (total_cedulas / 1000) % 10;  // Milhar
                        c5 = (total_cedulas / 10000) % 10;  // Dezena de milhar
                        c6 = (total_cedulas / 100000) % 10;  // Centena de milhar

                        // Centena de milhar
                        if(total_cedulas == 0){
                            printf("zero reais\n");
                        }
                        if (c6 > 0)
                        {
                            if ((c5 == 0) && (c4 == 0))
                            {
                                printf("cem ");
                            }
                            else
                            {
                                printf("cento e ");
                            }
                        }
                        // Dezena de milhar
                        if (c5 > 0)
                        {   // Parte do milhar
                            if (c4 > 0)
                            {
                                switch (c5)
                                {
                                    case 1:
                                        if (c4 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c4 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c4 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c4 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c4 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else 
                                        {
                                            printf("dez");
                                        } 
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                }
                            }
                            else
                            {
                                switch (c5)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Milhar
                        if (c4 > 0)
                        {
                            if (c5 == 1)
                            {
                                switch (c4)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c5 != 1)  //(c4 > 0)
                            {
                                switch (c4)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        }
                        // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                        if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0 ) || (c4 > 0)))
                        {
                            printf("mil ");
                        }
                        if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0)|| (c1 > 0)))
                        {
                            printf("e ");
                        }
                        // Centena 
                        if (c3 > 0)
                        {
                            if ((c2 > 0) || (c1 > 0))
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cento e ");        
                                        break;
                                    case 2:
                                        printf("duzentos e ");
                                        break;
                                    case 3:
                                        printf("trezentos e ");
                                        break;
                                    case 4:
                                        printf("quatrocentos e ");
                                        break;
                                    case 5:
                                        printf("quinhentos e ");
                                        break;
                                    case 6:
                                        printf("seiscentos e ");
                                        break;
                                    case 7:
                                        printf("setecentos e ");
                                        break;
                                    case 8:
                                        printf("oitocentos e ");
                                        break;
                                    case 9:
                                        printf("novecentos e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c3)
                                {
                                    case 1:
                                        printf("cem ");
                                        break;
                                    case 2:
                                        printf("duzentos ");
                                        break;
                                    case 3:
                                        printf("trezentos ");
                                        break;
                                    case 4:
                                        printf("quatrocentos ");
                                        break;
                                    case 5:
                                        printf("quinhentos ");
                                        break;
                                    case 6:
                                        printf("seiscentos ");
                                        break;
                                    case 7:
                                        printf("setecentos ");
                                        break;
                                    case 8:
                                        printf("oitocentos ");
                                        break;
                                    case 9:
                                        printf("novecentos ");
                                        break;
                                }
                            }
                        }
                        // Dezena
                        if (c2 > 0)
                        {
                            if (c1 > 0)
                            {
                                switch (c2)
                                {
                                    case 1:
                                        if (c1 == 1)
                                        {
                                            printf("onze ");
                                        }
                                        else if (c1 == 2)
                                        {
                                            printf("doze ");
                                        }
                                        else if (c1 == 3)
                                        {
                                            printf("treze ");
                                        }
                                        else if (c1 == 4)
                                        {
                                            printf("quatorze ");
                                        }
                                        else if (c1 == 5)
                                        {
                                            printf("quinze ");
                                        }
                                        else
                                        {
                                            printf("dez");
                                        }
                                        break;
                                    case 2:
                                        printf("vinte e ");
                                        break;
                                    case 3:
                                        printf("trinta e ");
                                        break;
                                    case 4:
                                        printf("quarenta e ");
                                        break;
                                    case 5:
                                        printf("cinquenta e ");
                                        break;
                                    case 6:
                                        printf("sessenta e ");
                                        break;
                                    case 7:
                                        printf("setenta e ");
                                        break;
                                    case 8:
                                        printf("oitenta e ");
                                        break;
                                    case 9:
                                        printf("noventa e ");
                                        break;
                                }
                            }
                            else
                            {
                                switch (c2)
                                {
                                    case 1:
                                        printf("dez ");
                                        break;
                                    case 2:
                                        printf("vinte ");
                                        break;
                                    case 3:
                                        printf("trinta ");
                                        break;
                                    case 4:
                                        printf("quarenta ");
                                        break;
                                    case 5:
                                        printf("cinquenta ");
                                        break;
                                    case 6:
                                        printf("sessenta ");
                                        break;
                                    case 7:
                                        printf("setenta ");
                                        break;
                                    case 8:
                                        printf("oitenta ");
                                        break;
                                    case 9:
                                        printf("noventa ");
                                        break;
                                }
                            }
                        }
                        // Unidade
                        if (c1 > 0)
                        {
                            if (c2 == 1)
                            {
                                switch (c1)
                                {
                                    case 6:
                                        printf("esseis ");
                                        break;
                                    case 7:
                                        printf("essete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("enove ");
                                        break;
                                }
                            }
                            else if (c2 != 1)
                            {
                                switch (c1)
                                {
                                    case 1:
                                        printf("um ");
                                        break;
                                    case 2:
                                        printf("dois ");
                                        break;
                                    case 3:
                                        printf("tres ");
                                        break;
                                    case 4:
                                        printf("quatro ");
                                        break;
                                    case 5:
                                        printf("cinco ");
                                        break;
                                    case 6:
                                        printf("seis ");
                                        break;
                                    case 7:
                                        printf("sete ");
                                        break;
                                    case 8:
                                        printf("oito ");
                                        break;
                                    case 9:
                                        printf("nove ");
                                        break;
                                }
                            }
                        } 
                        if (total_cedulas > 1) 
                        {
                            printf("reais.\n");
                        }
                        else if (total_cedulas == 1)
                        {
                            printf("real.\n");
                        }
                        printf("--------------------------------------------------------------------------------------\n");
                        printf("Notas de 1: %d", nota_1);
                        printf("\nNotas de 2: %d", nota_2);
                        printf("\nNotas de 5: %d", nota_5);
                        printf("\nNotas de 10: %d", nota_10);
                        printf("\nNotas de 20: %d", nota_20);
                        printf("\nNotas de 50: %d", nota_50);
                        printf("\nNotas de 150: %d", nota_150);
                        printf("\nNotas de 500: %d\n", nota_500);
                        printf("----------------------------------------------\n");
                        opc_ger = -1;
                        break;
                    case 4:
                        /* code */
                        break;
                        
                    default:
                        opc = -1;
                        break;
                    }

                } while (opc_ger < 1 || opc_ger > 5);
            case 3:
                printf("\nOperacao finalizada com sucesso!");
                break;
        }
    } while (opc < 1 || opc > 3);
    return 0;
}