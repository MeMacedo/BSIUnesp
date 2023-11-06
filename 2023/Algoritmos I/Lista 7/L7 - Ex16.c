/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int navio_x, navio_y, navio_z,cont_x, cont_y, cont_z;
    
    
    scanf("%d %d %d", &cont_x, &cont_y, &cont_z);
    scanf("%d %d %d", &navio_x, &navio_y, &navio_z);
    

    printf("%d", (navio_x/cont_x)*(navio_y/cont_y)*(navio_z/cont_z));

    return 0;
}
