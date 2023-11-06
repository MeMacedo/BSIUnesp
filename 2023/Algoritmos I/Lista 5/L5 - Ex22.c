/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{
    int qnt = 0,sum =0;
    for(int i = 3; i<=700;i+=3){
        sum+=i;
        qnt++;
    }
    printf("A soma é igual a %d e a quantidade somada foi %d", sum, qnt);
}


