#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define N 100

void random(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % N;
    }
};

void cresc(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
}

void desc(int v[], int n)
{
    for (int i = n - 1, cont = 0; i > -1; i--, cont++)
    {
        v[cont] = i;
    }
}

void quas(int v[], int n)
{
    cresc(v, n);
    int quant = rand() % n, aux, pos1 = rand() % n, pos2 = pos1 + 1;

    for (int i = 0; i < quant && i < n / 2; i++)
    {

        aux = v[pos1];
        v[pos1] = v[pos2];
        v[pos2] = aux;
        pos1 = rand() % n;
        pos2 = pos1 + 1;
    }
}

int main()
{
    int n, opt, v[N];

    srand(time(NULL));

    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &n);

    printf("Digite o número para escolher a ordenação do vetor: ");
    printf("-- Completamente aleatório (1)");
    printf("-- Ordenado em ordem crescente (2)");
    printf("-- Ordenado em ordem decrescente (3)");
    printf("-- Quase ordenado em ordem crescente (4)");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        random(v, n);
        break;
    case 2:
        cresc(v, n);
        break;
    case 3:
        desc(v, n);
        break;
    case 4:
        quas(v, n);
        break;
    default:
        printf("Não é uma opção válida.");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}
