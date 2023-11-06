/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(){
    int x_i = 0, y_i =0;
    int x_max, y_max, x_m, y_m, passos, min =0;
    
    scanf("%d %d", &x_max, &y_max);
    scanf("%d %d", &x_m, &y_m);
    scanf("%d", &passos);
    
    for(int i = 0; i<passos; i++){
        int passo;
        scanf("%d", &passo);
        switch(passo){
            case 1:
                x_i++; break;
            case 2:
                x_i--; break;
            case 3:
                y_i++; break;
            case 4:
                y_i--; break;
        }
        
        if((x_i<=(x_m+1)&&x_i>=(x_m-1))&&((y_i<=(y_m+1)&&y_i>=(y_m-1)))) min++; 
    }
    
    printf("%d", min);
}
