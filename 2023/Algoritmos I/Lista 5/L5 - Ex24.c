/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{

    int maior =0, menor=0, atual;
    
    do{
        printf("Digite um número ");
        scanf("%d", &atual);
        if(menor==0){
            menor = atual;
            maior = atual;
        }
        
        if(atual>maior) maior = atual;
        
        else if(atual<menor && atual !=0) menor = atual;
        
    } while (atual > 0);
    
    printf("Maior: %d\nMenor: %d", maior, menor);
}


