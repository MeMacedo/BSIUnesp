/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{

    float maior =0.0, menor=0.0, sum = 0.0, atual;
    int qnt = 0;
    char resp;
    
    do{ 
        printf("Digite um número ");
        scanf("%f", &atual);
        qnt++;
        sum+=atual;
        if(menor==0){
            menor = atual;
            maior = atual;
        }
        
        if(atual>maior) maior = atual;
        
        else if(atual<menor && atual !=0) menor = atual;
        
        printf("Deseja continuar? (s/n)");
        scanf(" %c", &resp);
    } while (resp == 's');
    
    printf("Média: %.2f, razão: %.2f", sum/qnt, maior/menor);
}


