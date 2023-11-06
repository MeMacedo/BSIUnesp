/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    float alc, gaso, r_a, r_g;
    
    scanf("%f %f %f %f", &alc, &gaso, &r_a, &r_g);
    
    if (alc*(r_g/r_a) < gaso){
        printf("A");
        return 0;
    }

    printf("G");
    return 0;
}
