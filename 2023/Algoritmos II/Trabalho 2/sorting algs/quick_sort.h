#include "troca.h"
#include <time.h>

struct timeval start, stop;

int partition(int v[], int left, int right, int *comps, int *trocas, double *secs)

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

void quick_sort(int v[], int left, int right, int *comps, int *trocas, double *secs)

{
    gettimeofday(&start, NULL);
    if (left < right)
    {
        int index_pivot = partition(v, left, right, comps, trocas, secs);
        quick_sort(v, left, index_pivot - 1, comps, trocas, secs);
        quick_sort(v, index_pivot + 1, right, comps, trocas, secs);
    }
    gettimeofday(&stop, NULL);
    (*secs) = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
}
