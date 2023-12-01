
struct timeval start, stop;
void shell_sort(int vet[], int n, int *comps, int *trocas, double *secs)
{
    gettimeofday(&start, NULL);
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
    gettimeofday(&stop, NULL);
    (*secs) = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
}
