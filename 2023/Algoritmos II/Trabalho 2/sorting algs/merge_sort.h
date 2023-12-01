

#include <time.h>
void merge(int v[], int left, int middle, int right, int *comps, int *trocas, int *clocks)
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

void merge_sort(int v[], int left, int right, int *comps, int *trocas, int *clocks)
{
    clock_t start_t = clock();
    if (left >= right)
        return;
    int middle = (left + right) / 2;
    merge_sort(v, left, middle, comps, trocas, clocks);
    merge_sort(v, middle + 1, right, comps, trocas, clocks);
    merge(v, left, middle, right, comps, trocas, clocks);

    clock_t end_t = clock();
    (*clocks) = end_t - start_t;
}
