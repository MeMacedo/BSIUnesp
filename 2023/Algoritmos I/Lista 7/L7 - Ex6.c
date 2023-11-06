/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int depositos,cofre1, cofre2;
    int difer =0;
    int teste =1;
    
    while(1){
        scanf("%d", &depositos);
        
        if(!depositos) break;
        
        
        printf("Teste %d\n", teste);
        
        for(int i =0; i<depositos; i++){
            scanf("%d %d", &cofre1, &cofre2);
            
            difer += cofre1-cofre2;
            printf("%d\n", difer);
        }
        
        teste++;
        difer =0;
    }

    return 0;
}
