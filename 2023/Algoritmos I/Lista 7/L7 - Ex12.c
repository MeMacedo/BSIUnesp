/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int cand, nota_min, nota1, nota2;
    int quant_cand = 0;
    
    scanf("%d %d", &cand, &nota_min);
    
    
    for(int i =0; i<cand; i++){
        scanf("%d %d", &nota1, &nota2);
            
        if(nota1+nota2>=nota_min) quant_cand++;
    }

    printf("%d", quant_cand);

    return 0;
}
