#include <stdio.h>
#include <stdlib.h>

void scanElements(int v[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

int main()
{

    int n;

    printf("Digite a quantidade de números do vetor: ");
    scanf("%d", &n);

    int *v;
    v = (int *)malloc(n * sizeof(int));

    scanElements(v, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}
