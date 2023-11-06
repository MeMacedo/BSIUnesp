/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define I 500
#define J 500

int main()
{
    int m, n, last_zero, flag, num, line_first_zero;
    scanf("%d %d ", &m, &n);
    
    double matriz[I][J];
    
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            scanf(" %lf", &matriz[i][j]);
        }
    }
    
    last_zero = -1;
    
    for (int i = 0; i<m; i++){
        flag = 1;
        for (int j = 0; j<n; j++){
            if(flag && !matriz[i][j]) line_first_zero = j; else flag=0;
        }
        if(line_first_zero <=last_zero) {
            printf("N"); return 0;
        } else {
            last_zero = line_first_zero;
        }
    }
    
    printf("S");
    return 0;
}
