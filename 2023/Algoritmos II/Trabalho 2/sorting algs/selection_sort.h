

void selection_sort(int vet[], int n, int *comps, int *trocas, int *clocks)
{
    clock_t start_t = clock();
    int i, j, min_ind;
    for (i = 0; i < n - 1; i++)
    {
        min_ind = i;
        for (j = i + 1; j < n; j++)
        {
            (*comps)++;
            if (vet[j] < vet[min_ind])
                min_ind = j;
        }
        if (min_ind != i)
        {
            troca(&vet[min_ind], &vet[i]);
            (*trocas)++;
        }
    }

    clock_t end_t = clock();
    (*clocks) = end_t - start_t;
}
