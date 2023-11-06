/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    int x, par;
    
    double erro_atual, erro_menor = -1;
    
    do{ 
        printf("Digite um inteiro maior que 0: ");
        scanf("%d", &x);
        for(int i = 0; i<=x;i+=2){
            erro_atual = fabs(pow(x,0.5)-i);
            if(erro_atual<erro_menor || erro_menor==-1){
                erro_menor = erro_atual;
                par = i;
            }
        }
        printf("%d\n", par);erro_menor=-1;
    } while (x>0);

    return 0;
}
