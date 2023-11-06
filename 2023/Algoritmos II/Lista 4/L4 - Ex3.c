#include <stdio.h>

int min(int vetor[], int n)
{
    if (n == 1)
        return vetor[0];

    int aux = min(vetor, n - 1);
    if (vetor[n - 1] < aux)
        return vetor[n - 1];
    else
        return aux;
}

int main()
{
    int vetor[20], i, n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("vetor[%d] = ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\nMenor elemento do vetor: %d", min(vetor, n));
}
