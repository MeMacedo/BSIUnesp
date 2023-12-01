
#define BUCKET_SIZE 500
#define BUCKETS 10
#define MAX 50

struct timeval start, stop;
typedef struct
{
    int head;
    int bucket[BUCKET_SIZE];
} bucket;

void bucket_sort(int vet[], int n, int *comps, int *trocas, double *secs)
{

    gettimeofday(&start, NULL);
    bucket b[BUCKETS];
    for (int i = 0; i < BUCKETS; i++)
    {
        b[i].head = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int j = BUCKETS - 1;
        while (j >= 0)
        {
            (*comps)++;
            if (vet[i] >= j * MAX)
            {
                b[j].bucket[b[j].head] = vet[i];
                (b[j].head)++;
                break;
            }
            j--;
        }
    }

    for (int i = 0; i < BUCKETS; i++)
        if (b[i].head)
            bubble_sort(b[i].bucket, b[i].head, comps, trocas, secs);

    int i = 0;
    while (i < n)
    {
        for (int j = 0; j < BUCKETS; j++)
        {
            for (int k = 0; k < b[j].head; k++)
            {
                (*trocas)++;
                vet[i] = b[j].bucket[k];
                i++;
            }
        }
    }
    gettimeofday(&stop, NULL);
    (*secs) = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
}
