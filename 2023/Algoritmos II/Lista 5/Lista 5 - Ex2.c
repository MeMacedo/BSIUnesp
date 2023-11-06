#include <stdio.h>
#include <math.h>

int buscaSequencial(int vetor[], int tam, int k)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == k)
        {
            printf("O número %d foi encontrado.\n\n", k);
            return ++cont;
        }
        cont++;
    }
    printf("O número %d não foi encontrado.\n\n", k);
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
    printf("Comparações em busca binária: %d\n\n", buscaBinaria(vetor, tam, k));
}

int main()
{
    int vetor[100000], quant, tam, k;
    FILE *dados;

    dados = fopen("dados.txt", "r");

    if (!dados)
    {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    fscanf(dados, "%d %d", &tam, &quant);

    for (int i = 0; i < tam; i++)
    {
        fscanf(dados, "%d", &vetor[i]);
    }

    printf("%d %d", vetor[0], vetor[1]);

    while (quant--)
    {
        fscanf(dados, "%d", &k);
        comparaBuscas(vetor, tam, k);
    }
}
