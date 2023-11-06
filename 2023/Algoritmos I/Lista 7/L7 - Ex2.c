/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
  int teste = 1;
  while (1) {
      int partidas;
      scanf("%d", &partidas);
      if (!partidas) break;

      printf("Teste %d\n", teste);

      int melhor_soma_saldo = -1;
      int melhor_ini, melhor_final;
      int ini = 1, soma_atual = 0;
      int favor, contra;
      
      for (int partida = 1 ; partida <= partidas; partida ++){
          scanf("%d %d", &favor, &contra);
          soma_atual += favor - contra;
          if (soma_atual < 0) {
              ini = partida + 1;
              soma_atual = 0;
          }
          else if (soma_atual > 0 && (soma_atual > melhor_soma_saldo || (soma_atual == melhor_soma_saldo && partida-ini >= melhor_final-melhor_ini))){
              melhor_soma_saldo = soma_atual;
              melhor_ini = ini;
              melhor_final = partida;
            }
        }

     
      if (melhor_soma_saldo == -1) printf("nenhum\n");
      else{
        printf("%d %d\n", melhor_ini, melhor_final);
     }
      teste ++;
    }
}
