
#define BUCKET_SIZE 500
#define BUCKETS 10
#define MAX = 500;

typedef struct
{
    int head;
    int bucket[BUCKET_SIZE];
} bucket;

void bucket_sort(int vet[], int n, int *comps, int *trocas, int *clocks)
{

    clock_t start_t = clock();
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
            if (vet[i] >= j * BUCKET_SIZE)
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
            bubble_sort(b[i].bucket, b[i].head, comps, trocas, clocks);

    int i = 0;
    for (int j = 0; j < BUCKETS; j++)
    {
        for (int k = 0; k < b[j].head; k++)
        {
            (*trocas)++;
            vet[i] = b[j].bucket[k];
            i++;
        }
    }

    clock_t end_t = clock();
    (*clocks) = end_t - start_t;
}
