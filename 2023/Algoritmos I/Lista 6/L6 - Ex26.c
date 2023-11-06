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
    printf("Digite o número pra saber se é triangular: ");
    scanf("%d", &n);
    
    for(int i = 1; i<n-1; i++){
        if(i*(i+1)*(i+2)==n) {printf("%d é triangular. %dx%dx%d=%d", n, i, i+1, i+2, n);
        return 0;}
    }
    printf("%d não é triangular", n);
}


