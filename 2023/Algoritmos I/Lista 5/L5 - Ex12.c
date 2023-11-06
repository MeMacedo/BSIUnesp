/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{
    int linhas = 5;
    int ast = 1;
    for (int i=linhas; i>0; i--){
        for(int j = 1; j<=i;j++){
            printf("   ");
        }
        for(int j = 1; j<=ast;j++){
            printf("%%  ");
            if(ast==j){
                printf("\n");
            }
        }
        ast+=2;
    }
    return 0;
}


