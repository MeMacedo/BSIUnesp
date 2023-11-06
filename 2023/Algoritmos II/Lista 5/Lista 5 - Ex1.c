#include <stdio.h>
#include <math.h>

int buscaSequencial(int vetor[], int tam, int k)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == k)
            return ++cont;
        cont++;
    }

    return cont;
}

int buscaSequencialOrdenada(int vetor[], int tam, int k)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == k)
            return ++cont;
        else if (vetor[i] > k)
        {
            return ++cont;
        }

        cont++;
    }

    return cont;
}

int buscaBinaria(int vetor[], int tam, int k)
{

    int cont = 0, esq = 0, dir = tam - 1;
    if (esq > dir)
        return cont;

    while (dir >= esq)
    {
        cont++;
        int pos_meio = floor((dir + esq) / 2.0);
        int meio = vetor[pos_meio];
        if (k == meio)
        {
            break;
        }
        if (k < meio)
        {
            dir = pos_meio - 1;
            continue;
        }
        esq = pos_meio + 1;
    }

    return cont;
}

void comparaBuscas(int vetor[], int tam, int k)
{
    printf("Comparações em busca sequencial: %d\n", buscaSequencial(vetor, tam, k));

    printf("Comparações em busca sequencial ordenada: %d\n", buscaSequencialOrdenada(vetor, tam, k));
    printf("Comparações em busca binária: %d\n", buscaBinaria(vetor, tam, k));
}

int main()
{
    int vetor[50], k, tam;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    printf("Digite os elementos do vetor: ");

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o número a ser procurado: ");
    scanf("%d", &k);

    comparaBuscas(vetor, tam, k);
}
