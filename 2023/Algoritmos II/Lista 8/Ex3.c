#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buscaBinaria(int vetor[], int tam, int k)
{

    int achou = 0, esq = 0, dir = tam - 1;
    if (esq > dir)
        return achou;

    while (dir >= esq)
    {
        int pos_meio = floor((dir + esq) / 2.0);
        int meio = vetor[pos_meio];
        if (k == meio)
        {
            achou = 1;
            break;
        }
        if (k < meio)
        {
            dir = pos_meio - 1;
            continue;
        }
        esq = pos_meio + 1;
    }

    return achou;
}

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd)
{

    *qtd = n1 + n2;
    int *x3;
    x3 = (int *)malloc(*qtd * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        x3[i] = x1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        if (buscaBinaria(x1, n2, x2[i]))
            *qtd = *qtd - 1;
        else
            x3[n1 - 1 + i] = x2[i];
    }

    return x3;
}

int main()
{
    int x1[5] = {1, 3, 5, 6, 7}, x2[5] = {1, 3, 4, 6, 8}, n1 = 5, n2 = 5;
    int *qtd, *x3;

    x3 = uniao(x1, x2, n1, n2, qtd);

    printf("Quantidade de números em x3: %d\n", *qtd);
    printf("x3: {");
    for (int i = 0; i < 7; i++)
    {
        }
    printf("}");
}
