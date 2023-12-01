

#include <time.h>

struct timeval start, stop;
void merge(int v[], int left, int middle, int right, int *comps, int *trocas, double *secs)
{
    int helper[1000], i, j, k;
    for (int i = left; i <= right; i++)
    {
        helper[i] = v[i];
    }

    i = left;
    j = middle + 1;
    k = left;
    while (i <= middle && j <= right)
    {
        (*comps)++;
        (*trocas)++;
        if (helper[i] <= helper[j])
        {
            v[k] = helper[i];
            i++;
        }
        else
        {
            v[k] = helper[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        (*trocas)++;
        v[k] = helper[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        (*trocas)++;
        v[k] = helper[j];
        j++;
        k++;
    }
}

void merge_sort(int v[], int left, int right, int *comps, int *trocas, double *secs)
{
    gettimeofday(&start, NULL);
    if (left >= right)
        return;
    int middle = (left + right) / 2;
    merge_sort(v, left, middle, comps, trocas, secs);
    merge_sort(v, middle + 1, right, comps, trocas, secs);
    merge(v, left, middle, right, comps, trocas, secs);
    gettimeofday(&stop, NULL);
    (*secs) = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
}
