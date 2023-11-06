/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    for(int i = 1; i<=6; i++){
        for(int j =1;j<=6;j++){
        if(i+j==7) printf("(%d %d)\n", i, j);}
    }
    return 0;
}
