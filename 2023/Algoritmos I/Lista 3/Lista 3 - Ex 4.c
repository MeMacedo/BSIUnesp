/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{   
    
    int current_year;
    scanf("%d", &current_year);
    if(current_year%76)printf("%d", current_year+76-(current_year%76)+(1986%76));
    else printf("%d", current_year+76);
    
}   