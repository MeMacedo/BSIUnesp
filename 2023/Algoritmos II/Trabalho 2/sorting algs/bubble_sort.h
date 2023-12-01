#include <time.h>

void bubble_sort(int vet[], int n, int *comps, int *trocas, int *clocks)
{
    clock_t start_t = clock();
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
    clock_t end_t = clock();
    (*clocks) = end_t - start_t;
}
