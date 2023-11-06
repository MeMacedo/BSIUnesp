/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{       

    int ano, mes, dia, v, g,f, n,ds;

    printf("Escreva uma data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    if(mes<=2){
        f=mes+13;
        g=ano-1;
    }
    else {
        f=mes+1;g=ano;}
    
    n = (int)(365.25*g)+(int)(30.6*f)+dia-621049;
    
    if(n<36523) v =2;
    else if (n>=73048) v=0;
    else v=1;
    
    ds = round((n/7.0 - n/7)*7 + v + 1);
    
    switch(ds){
        case 1:
        printf("Domingo");
        break;
        case 2:
        printf("Segunda");
        break;
        case 3:
        printf("Terça");
        break;
        case 4:
        printf("Quarta");
        break;
        case 5:
        printf("Quinta");
        break;
        case 6:
        printf("Sexta");
        break;
        case 7:
        printf("Sabado");
        break;
    }
    
    return 0;
}
