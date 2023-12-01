#include <sys/time.h>
#include "../sorting algs/generate_arrays.h"
#include "../sorting algs/quick_sort.h"
#include "../sorting algs/merge_sort.h"
#include "../sorting algs/bubble_sort.h"
#include "../sorting algs/bucket_sort.h"
#include "../sorting algs/insertion_sort.h"
#include "../sorting algs/selection_sort.h"
#include "../sorting algs/shell_sort.h"

int comps, trocas;
double secs;

void copiav(int dest[], int src[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

void show_quick_sort(int copia[], int vet10[10], int vet100[100], int vet1000[1000])
{
    printf("QUICK SORT\n");
    printf("    10 elementos\n");
    copiav(copia, vet10, 10);
    comps = trocas = secs = 0;
    quick_sort(copia, 0, 9, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    100 elementos\n");
    copiav(copia, vet100, 100);
    comps = trocas = secs = 0;
    quick_sort(copia, 0, 99, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    1000 elementos\n");
    copiav(copia, vet1000, 1000);
    comps = trocas = secs = 0;
    quick_sort(copia, 0, 999, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
};
void show_bubble_sort(int copia[], int vet10[10], int vet100[100], int vet1000[1000])
{
    printf("BUBBLE SORT\n");
    printf("    10 elementos\n");
    copiav(copia, vet10, 10);
    comps = trocas = secs = 0;
    bubble_sort(copia, 10, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    100 elementos\n");
    copiav(copia, vet100, 100);
    comps = trocas = secs = 0;
    bubble_sort(copia, 100, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    1000 elementos\n");
    copiav(copia, vet1000, 1000);
    comps = trocas = secs = 0;
    bubble_sort(copia, 1000, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
};
void show_bucket_sort(int copia[], int vet10[10], int vet100[100], int vet1000[1000])
{
    printf("\nBUCKET SORT\n"),
        printf("    10 elementos\n");
    copiav(copia, vet10, 10);
    comps = trocas = secs = 0;
    bucket_sort(copia, 10, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    100 elementos\n");
    copiav(copia, vet100, 100);
    comps = trocas = secs = 0;
    bucket_sort(copia, 100, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    1000 elementos\n");
    copiav(copia, vet1000, 1000);
    comps = trocas = secs = 0;
    bucket_sort(copia, 1000, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
};

void show_selection_sort(int copia[], int vet10[10], int vet100[100], int vet1000[1000])
{
    printf("SELECTION SORT\n");
    printf("    10 elementos\n");
    copiav(copia, vet10, 10);
    comps = trocas = secs = 0;
    selection_sort(copia, 10, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    100 elementos\n");
    copiav(copia, vet100, 100);
    comps = trocas = secs = 0;
    selection_sort(copia, 100, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    1000 elementos\n");
    copiav(copia, vet1000, 1000);
    comps = trocas = secs = 0;
    selection_sort(copia, 1000, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
}
void show_insertion_sort(int copia[], int vet10[10], int vet100[100], int vet1000[1000])
{
    printf("INSERCTION SORT\n");
    printf("    10 elementos\n");
    copiav(copia, vet10, 10);
    comps = trocas = secs = 0;
    insertion_sort(copia, 10, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    100 elementos\n");
    copiav(copia, vet100, 100);
    comps = trocas = secs = 0;
    insertion_sort(copia, 100, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    1000 elementos\n");
    copiav(copia, vet1000, 1000);
    comps = trocas = secs = 0;
    insertion_sort(copia, 1000, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
}

void show_merge_sort(int copia[], int vet10[10], int vet100[100], int vet1000[1000])
{
    printf("MERGE SORT\n");
    printf("    10 elementos\n");
    copiav(copia, vet10, 10);
    comps = trocas = secs = 0;
    merge_sort(copia, 0, 9, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    100 elementos\n");
    copiav(copia, vet100, 100);
    comps = trocas = secs = 0;
    merge_sort(copia, 0, 99, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    1000 elementos\n");
    copiav(copia, vet1000, 1000);
    comps = trocas = secs = 0;
    merge_sort(copia, 0, 999, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
}

void show_shell_sort(int copia[], int vet10[10], int vet100[100], int vet1000[1000])
{
    printf("SHELL SORT\n");
    printf("    10 elementos\n");
    copiav(copia, vet10, 10);
    comps = trocas = secs = 0;
    shell_sort(copia, 10, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    100 elementos\n");
    copiav(copia, vet100, 100);
    comps = trocas = secs = 0;
    shell_sort(copia, 100, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
    printf("    1000 elementos\n");
    copiav(copia, vet1000, 1000);
    comps = trocas = secs = 0;
    shell_sort(copia, 1000, &comps, &trocas, &secs);
    printf("    Comparacoes: %d  Trocas: %d  Milisecs:  %.3f\n", comps, trocas, secs*1000);
}
