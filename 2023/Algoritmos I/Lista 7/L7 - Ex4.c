/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2, y1, y2, x_m, y_m;
    int meteor;
    int meteor_quant =0;
    int isIn = 0;
    int teste = 1;
    
    while(1){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        if(!(abs(x1)+abs(x2)+abs(y1)+abs(y2))) break;
        
        scanf("%d", &meteor);
        
        for(int i =0; i<meteor; i++){
            scanf("%d %d", &x_m, &y_m);
            isIn = (x_m<=x2 && x_m >= x1) && (y_m <= y1 && y_m>= y2);
            
            if(isIn) meteor_quant++;
        }
        
        
        printf("Teste %d\n%d\n", teste, meteor_quant);
        teste++;
        meteor_quant =0;
    }

    return 0;
}
