void shell_sort(int vet[], int n, int *comps, int *trocas, int *clocks)
{
    clock_t start_t = clock();
    int i, j, k, aux;
    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            aux = vet[i];
            for (j = i - k; j >= 0 && aux < vet[j]; j -= k)
            {
                vet[j + k] = vet[j];
                (*comps)++;
                (*trocas)++;
            }
            if (j >= 0)
                (*comps)++;
            vet[j + k] = aux;
        }
    }

    clock_t end_t = clock();
    (*clocks) = end_t - start_t;
}
