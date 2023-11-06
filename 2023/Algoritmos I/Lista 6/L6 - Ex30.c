/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int n, i, j, num=0;
    
    printf("Digite a quantidade N e i,j: ");
    scanf("%d %d %d", &n, &i, &j);
    
    printf("Os %d múltiplos de %d, %d ou os dois são\n", n, i, j);
    
    while(n){
        if(!(num%i)||!(num%j)) {
            printf("%4d\n", num); 
            n--;
        }
        num++;
    };


    return 0;
}
