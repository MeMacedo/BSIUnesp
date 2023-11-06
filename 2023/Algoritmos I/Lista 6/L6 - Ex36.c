/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{       
    float a, b, c;
    char opcao;
    printf("Digite T para aréa do triangulo, P para paralelepipedo, Q para quadrado e D para diagonal: ");
    scanf("%c", &opcao);
    
    switch(opcao){
        case 'T':
            do {
                printf("Digite dois lados: ");
                scanf("%f %f", &a, &b );
            } while(a<=0 || b<=0);
            printf("Perdão, não sei calcular a área de um tringulo só com dois lados :(");
            break;
        case 'P':
            do {
                printf("Digite três lados: ");
                scanf("%f %f %f", &a, &b, &c);
            } while(a<=0 || b<=0 || c<=0);
            printf("A área do paralelepipedo é %.2f", 2*a*b+2*a*c+2*b*c);
            break;
        case 'Q':
            do {
                printf("Digite dois lados: ");
                scanf("%f %f", &a, &b );
            } while(a<=0 || b<=0);
            printf("A área do quadrado é %.2f", a*b);
            break;
        case 'D':
            do {
                printf("Digite três lados: ");
                scanf("%f %f %f", &a, &b, &c);
            } while(a<=0 || b<=0 || c<=0);
            scanf("%f %f %f", &a, &b, &c);
            printf("A tamanho da diagonal é %.2f", pow(a*a+b*b+c*c, 0.5));
            break;
    }
    
    return 0;
}
