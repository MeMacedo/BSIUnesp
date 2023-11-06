/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    char resp;
    int sum_lamp =0;
    int sum_pot = 0;
    
    do{
        
        printf("Digite o comodo, a classe, a largura e o comprimento dele: ");
        char comodo[10];
        int classe, largura, comprimento;
        
        scanf("%s %d %d %d", &comodo, &classe, &largura, &comprimento);
        
        int area, potencia;
        
        switch (classe){
            case 1:
                potencia = 15;
                break;
            case 3:
                potencia = 20;
                break;
            default:
            potencia = 18;
            break;
        }
        
        area = largura*comprimento;
        sum_pot+=area*potencia;
        
        sum_lamp += ceil(area*potencia/60);
        
        printf("A area da(o) %s é %d, sua potencia é %d e precisa de %f lampadas\n", comodo,area, potencia, ceil(area*potencia/60));
        
        printf("Tem mais um comodo? ");
        scanf(" %c", &resp);
        
    
    } while(resp=='s');
    
    printf("O total de lampadas e potencia é %d e %d", sum_lamp, sum_pot);
    
}


