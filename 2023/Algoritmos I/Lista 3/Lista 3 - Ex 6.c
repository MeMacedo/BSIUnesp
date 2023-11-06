/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{   
    
    int x_m, y_m, x_r, y_r;
    scanf("%d %d %d %d", &x_m,&y_m, &x_r,&y_r);
    printf("%d", abs(x_m-x_r)+abs(y_m-y_r));
    
}   