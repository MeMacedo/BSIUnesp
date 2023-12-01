#include <time.h>
void insertion_sort(int vet[], int n, int *comps, int *trocas, int *clocks)
{
    clock_t start_t = clock();
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

    clock_t end_t = clock();
    (*clocks) = end_t - start_t;
}
