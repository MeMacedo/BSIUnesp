/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int min_18 = 0,max_80 = 0,qnt_players = 11*5;
    float sum_height = 0;
    for (int i =0; i<5; i++){
        int j = 0;
        int sum_age = 0;
        printf("Digite a idade, o peso e a altura dos 11 jogadores do time %d\n", i);
        int idade;
        float peso, altura;
        while(j<5){
            scanf("%d %f %f", &idade, &peso, &altura);
            sum_height+=altura;
            sum_age +=idade;
            if(idade<18) min_18++;
            if(peso>80) max_80++;
            j++;
        }
        printf("A media de idade do time %d é %.2f\n", i, sum_age/11.0);
        sum_age=0;
    }
    
    printf("A quantidade de jogadores menores de 18 é %d\n", min_18);
    
    printf("A media de altura do campeonato é %.2f\n", sum_height/qnt_players);
    
    printf("A porcentagem de atletas com peso maior que 80 do campeonato é %.2f\n", max_80*100.0/qnt_players);

    return 0;
}
