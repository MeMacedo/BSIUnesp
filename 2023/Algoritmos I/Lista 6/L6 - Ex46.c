/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{       
    int pessoa1, pessoa2, dif;
    do{
        printf("Digite a idade em anos das duas pessoas: ");
        scanf("%d %d", &pessoa1, &pessoa2);
        if (pessoa1> pessoa2) dif = pessoa1-pessoa2;
        else dif = pessoa2 - pessoa1;
        if(pessoa1+pessoa2>0) {
            printf("A primeira pessoa tem %d meses ou %d dias ou %d horas ou %d minutos de idade\n", pessoa1*12, pessoa1*12*30, pessoa1*12*30*24, pessoa1*12*30*24*60);
            printf("A segunda pessoa tem %d meses ou %d dias ou %d horas ou %d minutos de idade\n", pessoa2*12, pessoa2*12*30, pessoa2*12*30*24, pessoa2*12*30*24*60);
            
            printf("A diferença de idade entre elas é %d meses ou %d dias ou %d horas ou %d minutos de idade\n", dif*12,dif*12*30, dif*12*30*24, dif*12*30*24*60);
        }
        
    } while(pessoa1+pessoa2>0);
    
    
    return 0;
}
