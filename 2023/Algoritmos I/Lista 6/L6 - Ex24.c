/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include <math.h>



int main()
{
    int n;
    printf("Digite o número a ser elevado ao quadrado: ");
    scanf("%d", &n);
    printf("O quadrado de %d é %d = ", n, n*n);
    for(int i = 1; i<=n; i++){
        if(i!=n) printf("%d + ", 2*i-1);
        else printf("%d", 2*i-1);
    }
}


