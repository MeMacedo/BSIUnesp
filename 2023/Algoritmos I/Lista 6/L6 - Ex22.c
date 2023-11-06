/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{       
    int num1, num2, soma, cota;
    
    printf("Digite dois números inteiros entre 100 e 999: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\t\t\t\t%d\t%d\t%d\n", num1/100, num1%100/10, num1%100%10);
    
    printf("\t\tx\t\t%d\t%d\t%d\n", num2/100, num2%100/10, num2%100%10);
    
    int n[3] = {num1/100, num1%100/10, num1%100%10};

    int v[3] = {num2/100, num2%100/10, num2%100%10};
    
    
    for(int i =2; i>=0;i--){
        if(i==1) 
        soma = (n[0]*v[i]*100+n[1]*v[i]*10+n[2]*v[i])*10;
        else if(i==0) soma = (n[0]*v[i]*100+n[1]*v[i]*10+n[2]*v[i])*100;
        else soma = n[0]*v[i]*100+n[1]*v[i]*10+n[2]*v[i];
        if(soma<=999) {printf("\t\t\t\t");cota=100;}
        else if (soma<= 9999) { printf("\t\t\t"); cota = 1000;}
        else if (soma<= 99999) {printf("\t\t"); cota =10000;}
        else if (soma<= 999999) { printf("\t");cota =100000;}
        while(soma > 10){
            printf("%d\t", soma/cota);
            soma = soma%cota;
            cota = cota/10;
        }
        
        printf("%d\n", soma);
        
        
    }
    
    printf("\t-----------------------------------------------\n");
    
    int total = num1*num2;
    
    if(total<=999) {printf("\t\t\t\t");cota=100;}
    else if (total<= 9999) { printf("\t\t\t"); cota = 1000;}
    else if (total<= 99999) {printf("\t\t"); cota =10000;}
    else if (total<= 999999) { printf("\t");cota = 100000;}
    else if (total<= 9999999) { cota = 1000000;}
    
    while(total > 10){
            printf("%d\t", total/cota);
            total = total%cota;
            cota = cota/10;
    }
    
    printf("%d\n", total);
    
    return 0;
}
