
#include <stdio.h>
#include "sorting algs/generate_arrays.h"
#include "sorting algs/quick_sort.h"
#include "sorting algs/merge_sort.h"
#include "sorting algs/bubble_sort.h"
#include "sorting algs/bucket_sort.h"
#include "sorting algs/insertion_sort.h"
#include "sorting algs/selection_sort.h"
#include "sorting algs/shell_sort.h"

#define merge "merge_sort.txt"
#define bubble "bubble_sort.txt"
#define bucket "bucket_sort.txt"
#define insertion "insertion_sort.txt"
#define selection "selection_sort.txt"
#define shell "shell_sort.txt"
#define quick "quick_sort.txt"

int comps, trocas;
double secs;
int vet10[10], vet100[100], vet1000[1000], copia[1000];

void copiav(int dest[], int src[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

void main()
{
    int op;

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

    FILE *arq1, *arq2, *arq3, *arq4, *arq5, *arq6, *arq7;
    arq1 = fopen(quick, "w+");
    arq2 = fopen(merge, "w+");
    arq3 = fopen(insertion, "w+");
    arq4 = fopen(selection, "w+");
    arq5 = fopen(bubble, "w+");
    arq6 = fopen(bucket, "w+");
    arq7 = fopen(shell, "w+");
    for (int i = 0; i < 10; i++)
    {
        srand(i);
        copiav(copia, vet10, 10);
        quick_sort(copia, 0, 9, &comps, &trocas, &secs);
        fprintf(arq1, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet10, 10);
        merge_sort(copia, 0, 9, &comps, &trocas, &secs);
        fprintf(arq2, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet10, 10);
        insertion_sort(copia, 10, &comps, &trocas, &secs);
        fprintf(arq3, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet10, 10);
        selection_sort(copia, 10, &comps, &trocas, &secs);
        fprintf(arq4, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet10, 10);
        bubble_sort(copia, 10, &comps, &trocas, &secs);
        fprintf(arq5, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet10, 10);
        bucket_sort(copia, 10, &comps, &trocas, &secs);
        fprintf(arq6, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet10, 10);
        shell_sort(copia, 10, &comps, &trocas, &secs);
        fprintf(arq7, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
    }
    for (int i = 0; i < 10; i++)
    {

        srand(i);
        copiav(copia, vet100, 100);
        quick_sort(copia, 0, 99, &comps, &trocas, &secs);
        fprintf(arq1, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet100, 100);
        merge_sort(copia, 0, 99, &comps, &trocas, &secs);
        fprintf(arq2, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet100, 100);
        insertion_sort(copia, 100, &comps, &trocas, &secs);
        fprintf(arq3, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet100, 100);
        selection_sort(copia, 100, &comps, &trocas, &secs);
        fprintf(arq4, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet100, 100);
        bubble_sort(copia, 100, &comps, &trocas, &secs);
        fprintf(arq5, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet100, 100);
        bucket_sort(copia, 100, &comps, &trocas, &secs);
        fprintf(arq6, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet100, 100);
        shell_sort(copia, 100, &comps, &trocas, &secs);
        fprintf(arq7, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
    }
    for (int i = 0; i < 10; i++)
    {
        srand(i);
        copiav(copia, vet1000, 1000);
        quick_sort(copia, 0, 999, &comps, &trocas, &secs);
        fprintf(arq1, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet1000, 1000);
        merge_sort(copia, 0, 999, &comps, &trocas, &secs);
        fprintf(arq2, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet1000, 1000);
        insertion_sort(copia, 1000, &comps, &trocas, &secs);
        fprintf(arq3, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet1000, 1000);
        selection_sort(copia, 1000, &comps, &trocas, &secs);
        fprintf(arq4, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet1000, 1000);
        bubble_sort(copia, 1000, &comps, &trocas, &secs);
        fprintf(arq5, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet1000, 1000);
        bucket_sort(copia, 1000, &comps, &trocas, &secs);
        fprintf(arq6, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
        copiav(copia, vet1000, 1000);
        shell_sort(copia, 1000, &comps, &trocas, &secs);
        fprintf(arq7, "%d,%d,%.3f\n", comps, trocas, secs * 1000);
    }

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    fclose(arq4);
    fclose(arq5);
    fclose(arq6);
    fclose(arq7);
}
