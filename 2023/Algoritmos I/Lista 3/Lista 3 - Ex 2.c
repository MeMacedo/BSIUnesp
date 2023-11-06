/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int hanoi(int i){
    if(i==1){
        return 1;
    } else if(!i){
        return 0;
    } else {
        return 2*hanoi(i-1)+1;
    }
}

int main()
{   
    
    int itera = 1;
    int teste = 0;
    int testes[30];
    
    while(itera){
        int quant_discos;
        scanf("%d", &quant_discos);
        if (!quant_discos){
            itera = 0;
            continue;
        }
        testes[teste] = quant_discos;
        teste++;
    }
    
    for (int i=0; i<=teste-1; i++){
        printf("Teste %d\n%d\n\n", i+1, hanoi(testes[i]));
    }
}