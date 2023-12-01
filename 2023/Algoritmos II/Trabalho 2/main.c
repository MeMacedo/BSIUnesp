#include <stdio.h>
#include <stdlib.h>
#include "io funcs/show_sort_alg.h"

int vet10[10], vet100[100], vet1000[1000], copia[1000];

int main()
{
    int op;
    char escolha;

    printf("----------ALGORITMOS DE ORDENACAO----------\n\n");
    do
    {

        printf("Escolha o tipo de vetor a ser gerado\n");
        printf("1 - Aleatorio\n");
        printf("2 - Crescente\n");
        printf("3 - Decrescente\n");
        printf("4 - Quase ordenado\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            vetor_aleatorio(vet1000, 1000);
            vetor_aleatorio(vet100, 100);
            vetor_aleatorio(vet10, 10);
            break;
        case 2:
            vetor_ordenado_cres(vet1000, 1000);
            vetor_ordenado_cres(vet100, 100);
            vetor_ordenado_cres(vet10, 10);
            break;
        case 3:
            vetor_ordenado_decres(vet1000, 1000);
            vetor_ordenado_decres(vet100, 100);
            vetor_ordenado_decres(vet10, 10);
            break;
        case 4:
            vetor_quase_ordenado(vet1000, 1000);
            vetor_quase_ordenado(vet100, 100);
            vetor_quase_ordenado(vet10, 10);
        }

        show_bucket_sort(copia, vet10, vet100, vet1000);
        show_bubble_sort(copia, vet10, vet100, vet1000);
        show_insertion_sort(copia, vet10, vet100, vet1000);
        show_merge_sort(copia, vet10, vet100, vet1000);
        show_quick_sort(copia, vet10, vet100, vet1000);
        show_selection_sort(copia, vet10, vet100, vet1000);
        show_shell_sort(copia, vet10, vet100, vet1000);

        fflush(stdin);
        printf("Deseja continuar? s/n \n");
        scanf("%c", &escolha);
    } while (escolha != 'n');
}
