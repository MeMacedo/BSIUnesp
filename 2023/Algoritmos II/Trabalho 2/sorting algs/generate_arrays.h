#include <stdio.h>
#include <stdlib.h>

void vetor_aleatorio(int vet[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        vet[i] = rand() % (500);
}

void vet_bubble_sort(int vet[], int n)
{
    int i, j, houve_troca = 1;
    for (i = 0; i < n - 1 && houve_troca; i++)
    {
        houve_troca = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                troca(&vet[j], &vet[j + 1]);
                houve_troca = 1;
            }
        }
    }
}

void vet_bubble_sort_decres(int vet[], int n)
{
    int i, j, houve_troca = 1;
    for (i = 0; i < n - 1 && houve_troca; i++)
    {
        houve_troca = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (vet[j] < vet[j + 1])
            {
                troca(&vet[j], &vet[j + 1]);
                houve_troca = 1;
            }
        }
    }
}

void vetor_ordenado_cres(int vet[], int n)
{
    vetor_aleatorio(vet, n);
    vet_bubble_sort(vet, n);
}

void vetor_ordenado_decres(int vet[], int n)
{
    vetor_aleatorio(vet, n);
    vet_bubble_sort_decres(vet, n);
}

void vetor_quase_ordenado(int vet[], int n)
{
    vetor_aleatorio(vet, n);
    vetor_ordenado_cres(vet, n);
    int i, x = n > 50 ? n / 20 : 2;
    int pos1, pos2;
    for (i = 0; i < x; i++)
    {
        pos1 = rand() % n;
        pos2 = rand() % n;
        troca(&vet[pos1], &vet[pos2]);
    }
}
