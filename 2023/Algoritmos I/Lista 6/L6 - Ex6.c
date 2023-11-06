/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int main() {
    int m, n, x, y, soma = 0, x_max=-1, y_max=-1;
    
    scanf("%d %d", &m, &n);
    
    for(x=1; x<=m;x++){
        if(soma = 0) soma = x;
        for(y=1; y<=n;y++){
            if(x*y-x*x+y){
                x_max = x;
                y_max = y;
                soma = x*y-x*x+y;
            }
        }
    }
    
    printf("x: %d, y: %d, soma: %d", x_max,y_max, soma);
}
