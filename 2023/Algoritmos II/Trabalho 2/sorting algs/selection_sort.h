

struct timeval start, stop;
void selection_sort(int vet[], int n, int *comps, int *trocas, double *secs)
{
    gettimeofday(&start, NULL);
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
    gettimeofday(&stop, NULL);
    (*secs) = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
}
