/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{
    char ch;
    printf("\nDigite um caracter: ");
    scanf("%c",&ch);
    printf("\nCaracter anterior: %c, caracter seguinte: %c", ch-1, ch+1);
    return 0;
}


