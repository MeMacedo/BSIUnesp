/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{
    int a, b, sum=0;
    
    do{
        printf("Digite a e b positivos\n");
        scanf("%d %d", &a, &b);
        if (a<b) {
            for (int i = a; i<=b; i++){
                sum+=a;
            }
            printf("A soma é %d\n", sum);
        }
        else {
            printf("Fim.");
        }
    } while(a<b);
}
