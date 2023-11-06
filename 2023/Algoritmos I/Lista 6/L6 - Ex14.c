/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    int qnt_contri, num_dep;
    
    double renda, cpf, imposto, sal_min;
    
    printf("Digite a quantidade de contribuintes e o valor atual do SM: ");
    scanf("%d %lf", &qnt_contri, &sal_min);
    
    for(int i = 0; i< qnt_contri; i++){
        imposto = 0;
        printf("Insira o CPF, número de dependentes e renda do contribuinte %d: ", i+1);
        scanf("%lf %d %lf", &cpf, &num_dep, &renda);
        
        
        
        if(renda>=2*sal_min&&renda<3*sal_min)imposto += renda*0.05;
        else if (renda>=3*sal_min && renda<5*sal_min) imposto += renda*0.1;
        else if (renda>=5*sal_min && renda<7*sal_min) imposto += renda*0.15;
        else if (renda>=7*sal_min) imposto += renda*0.2;
        
        
        
        imposto += 0.05*num_dep*sal_min;
        
    
        
        printf("O valor do imposto do contribuinte %d é %lf\n", i+1, imposto);
    }
    

    return 0;
}
