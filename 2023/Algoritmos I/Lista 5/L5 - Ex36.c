/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{

    float sum = 0.0;
    int num = 1;
    
    for (int i = 15; i>=1; i--){
        float mult;
        if(i%2)mult=1.0;else mult=-1.0;
        sum+=mult*num/(i*i);
        num*=2;
    }
    
    printf("Soma: %.2f", sum);
}


