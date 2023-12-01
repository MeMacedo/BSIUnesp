#include "troca.h"
#include <time.h>

int partition(int v[], int left, int right, int *comps, int *trocas, int *clocks)

{
    int pivot = v[left];
    int i = left;
    int j;

    for (j = left + 1; j <= right; j++)
    {
        (*comps)++;
        if (v[j] <= pivot)
        {
            i += 1;
            (*trocas)++;
            troca(&v[i], &v[j]);
        }
    }
    (*trocas)++;
    troca(&v[left], &v[i]);

    return i;
}

void quick_sort(int v[], int left, int right, int *comps, int *trocas, int *clocks)

{
    clock_t start_t = clock();
    if (left < right)
    {
        int index_pivot = partition(v, left, right, comps, trocas, clocks);
        quick_sort(v, left, index_pivot - 1, comps, trocas, clocks);
        quick_sort(v, index_pivot + 1, right, comps, trocas, clocks);
    }

    clock_t end_t = clock();
    (*clocks) = end_t - start_t;
}
