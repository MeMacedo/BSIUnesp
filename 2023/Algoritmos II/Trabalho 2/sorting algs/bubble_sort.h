#include <time.h>

struct timeval start, stop;
void bubble_sort(int vet[], int n, int *comps, int *trocas, double *secs)
{
    gettimeofday(&start, NULL);
    int i, j, houve_troca = 1;
    for (i = 0; i < n - 1 && houve_troca; i++)
    {
        houve_troca = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            (*comps)++;
            if (vet[j] > vet[j + 1])
            {
                troca(&vet[j], &vet[j + 1]);
                houve_troca = 1;
                (*trocas)++;
            }
        }
    }
    gettimeofday(&stop, NULL);
    (*secs) = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
}
