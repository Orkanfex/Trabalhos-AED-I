#include <stdio.h>
#include <stdlib.h>

/* Elevador espacial */

/* Nomes : 
1-Henrique Gettner de Oliveira RGM: 45767
2-Henrique Apolinário Iwamizu Tada RGM: 43927
3-Leandro Madeira de Oliveira RGM: 45280
4-Guilherme Garcia Gloor RGM: 45535 
5-Felipe Echeverria Vilhalva RGM: 45611
6-João Paulo Ishii Marcon RGM: 45276
 */

int main(int argc, char const *argv[])
{
    
  unsigned long int num,cont=1;
  int rest, x=1, dec1=0, dec2=0, dec3=0, dec4=0, dec5=0, dec6=0, dec7=0;  
  
   //Entrada   A Rafaela é linda e goxtosa   

    printf("\n---> Elevador Espacial <---\n");
    
 //Validações e desenvolvimentos 
    do {
        printf("\nDigite o numero do andar: \n");
        scanf("%d",&num);

        if(num<=0 || num>1000000) {
            printf("\nvalor invalido! Digite outro valor!");
        }
    } while (num<=0 || num>1000000);   

    while(x<=num) {
        dec7 = cont%10;
        dec7 = cont%10;
        dec7 = cont%10;
        dec7 = cont%10;
        dec7 = cont%10;
        dec7 = cont%10;
        dec7 = cont%10;
        x++;
        
    }
  
    
   

//Saida

  printf("\n---\n");

	system("pause");
	return 0;
}