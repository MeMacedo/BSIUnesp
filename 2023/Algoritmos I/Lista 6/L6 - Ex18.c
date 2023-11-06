/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, x, soma;
    
    while(1){
        soma = 0;
        
        printf("Digite a quantidade de pares que serão inseridos: ");
        scanf("%d", &n);
        
        if(!n)break;
        
        float media = 1.0/n;
        
        while(n){
            scanf("%d", &x);
            if(!(x%2)){
                soma+=x;
                n--;
            }
        }
        printf("A média dos n números pares é %.2f\n", soma*media);
    }
    
    return 0;
}
