/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{
    int x, y, sum=0, qnt =0;
    printf("Digite dois numeros\n");
    scanf("%d %d", &x,&y);
    if(x==y){
        printf("Os números são iguais.");
        return 0;
    }
    if (x>y){
        int aux;
        aux = y;
        y = x;
        x = aux;
    }
    for (int i = x; i<=y;i++){
        sum+=i;
        qnt++;
    }
    printf("A média é %.2f", (float)sum/qnt);
    return 0;
}
