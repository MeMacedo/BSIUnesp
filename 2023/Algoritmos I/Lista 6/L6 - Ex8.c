/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int main() {
    
    printf("Fahrenheit    Celsius\n");
    
    for(int i = 50; i<=150; i+=5){
        printf("%10d %10d\n", i, 5*(i-32)/9);
    }
    
    
}
