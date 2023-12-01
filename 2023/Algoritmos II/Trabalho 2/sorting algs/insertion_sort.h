#include <time.h>
struct timeval start, stop;
void insertion_sort(int vet[], int n,int *comps, int *trocas, double *secs)
{
    gettimeofday(&start, NULL);
    int i, j, aux;
    for (i = 1; i < n; i++)
    {
        aux = vet[i];
        for (j = i - 1; j >= 0 && aux < vet[j]; j--)
        {
            vet[j + 1] = vet[j];
            (*comps)++;
            (*trocas)++;
        }
        if (j >= 0)
            (*comps)++;
        vet[j + 1] = aux;
    }
    gettimeofday(&stop, NULL);
    (*secs) = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
}
