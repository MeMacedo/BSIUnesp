/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include <math.h>

int main()
{
    float preco_ingr=5, receita=600, gasto_ingr=200.0/120, lucro_max=0, preco_max;
    int quant_ingr=120, quant_max; 
    printf("Preço\t\tIngressos\tReceita\t\tLucro\n"); 
    while(preco_ingr>=1){ 
    receita=preco_ingr*quant_ingr;  
    printf("R$%.2f",preco_ingr); 
    printf("\t\t %d",quant_ingr); 
    printf("\t\t R$%.2f",receita); 
    printf("\t R$%.2f\n",receita-gasto_ingr*quant_ingr); 
    
    if(receita-gasto_ingr*quant_ingr>lucro_max){
        lucro_max = receita-gasto_ingr*quant_ingr;
        quant_max = quant_ingr;
        preco_max=preco_ingr;
    }
    
    quant_ingr=quant_ingr+26; 
    preco_ingr=preco_ingr-0.5; 
    }
    
    printf("\nPreço: %.2f\nQuantidade: %d\nLucro máximo: %.2f\n", preco_max, quant_max, lucro_max);
}


