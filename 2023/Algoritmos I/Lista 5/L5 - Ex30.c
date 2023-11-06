/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{

    float sum = 0.0;
    
    for (int i = 1; i<=50; i++)sum+=(2.0*i-1)/i;
    
    printf("Soma: %.2f", sum);
}


