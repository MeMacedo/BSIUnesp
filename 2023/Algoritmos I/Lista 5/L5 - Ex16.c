/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{
    for (float x=1;x<=10;x++){
        float h = x*x-16;
        float f;
        if(h>=0)f=h;else f=1;
        float g;
        if(f==0)g=x*x+16; else g =0;
        printf("Soma = %.2f\n", f+g);
    }
}


