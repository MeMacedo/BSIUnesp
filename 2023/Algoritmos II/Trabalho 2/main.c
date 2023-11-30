
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int comps, trocas, tempo;

// sorts
void troca(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bucket_sort(int vet[], int n)
{
    // melissa
}

void selection_sort(int vet[], int n)
{
    int i, j, min_ind;
    for (i = 0; i < n - 1; i++)
    {
        min_ind = i;
        for (j = i + 1; j < n; j++)
        {
            comps++;
            if (vet[j] < vet[min_ind])
                min_ind = j;
        }
        if (min_ind != i)
        {
            troca(&vet[min_ind], &vet[i]);
            trocas++;
        }
    }
}

void bubble_sort(int vet[], int n)
{
    int i, j, houve_troca = 1;
    for (i = 0; i < n - 1 && houve_troca; i++)
    {
        houve_troca = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            comps++;
            if (vet[j] > vet[j + 1])
            {
                troca(&vet[j], &vet[j + 1]);
                houve_troca = 1;
                trocas++;
            }
        }
    }
}

void insertion_sort(int vet[], int n)
{
    int i, j, aux;
    for (i = 1; i < n; i++)
    {
        aux = vet[i];
        for (j = i - 1; j >= 0 && aux < vet[j]; j--)
        {
            vet[j + 1] = vet[j];
            comps++;
            trocas++;
        }
        if (j >= 0)
            comps++;
        vet[j + 1] = aux;
    }
}

void shell_sort(int vet[], int n)
{
    int i, j, k, aux;
    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            aux = vet[i];
            for (j = i - k; j >= 0 && aux < vet[j]; j -= k)
            {
                vet[j + k] = vet[j];
                comps++;
                trocas++;
            }
            if (j >= 0)
                comps++;
            vet[j + k] = aux;
        }
    }
}

void merge(int v[], int left, int middle, int right)
{
    int helper[MAX], i, j, k;
    for (int i = left; i <= right; i++)
    {
        helper[i] = v[i];
    }

    i = left;
    j = middle + 1;
    k = left;
    while (i <= middle && j <= right)
    {
        comps++;
        trocas++;
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
        trocas++;
        v[k] = helper[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        trocas++;
        v[k] = helper[j];
        j++;
        k++;
    }
}

void merge_sort(int v[], int left, int right)
{
    if (left >= right)
        return;
    int middle = (left + right) / 2;
    merge_sort(v, left, middle);
    merge_sort(v, middle + 1, right);
    merge(v, left, middle, right);
}

int partition(int v[], int left, int right)
{
    int pivot = v[left];
    int i = left;
    int j;

    for (j = left + 1; j <= right; j++)
    {
        comps++;
        if (v[j] <= pivot)
        {
            i += 1;
            trocas++;
            troca(&v[i], &v[j]);
        }
    }
    trocas++;
    troca(&v[left], &v[i]);

    return i;
}

void quick_sort(int v[], int left, int right)
{
    if (left < right)
    {
        int index_pivot = partition(v, left, right);
        quick_sort(v, left, index_pivot - 1);
        quick_sort(v, index_pivot + 1, right);
    }
}

// vetores
void copiav(int dest[], int src[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

void vetor_aleatorio(int vet[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        vet[i] = rand() % (n * 5);
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

int main()
{
    int op;
    char escolha;
    int vet10[10], vet100[100], vet1000[1000], copia[1000];

    printf("----------ALGORITMOS DE ORDENACAO----------\n\n");
    do
    {
        printf("Escolha o tipo de vetor a ser gerado\n");
        printf("1 - Aleatorio\n");
        printf("2 - Crescente\n");
        printf("3 - Decrescente\n");
        printf("4 - Quase ordenado\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            vetor_aleatorio(vet1000, 1000);
            vetor_aleatorio(vet100, 100);
            vetor_aleatorio(vet10, 10);
            break;
        case 2:
            vetor_ordenado_cres(vet1000, 1000);
            vetor_ordenado_cres(vet100, 100);
            vetor_ordenado_cres(vet10, 10);
            break;
        case 3:
            vetor_ordenado_decres(vet1000, 1000);
            vetor_ordenado_decres(vet100, 100);
            vetor_ordenado_decres(vet10, 10);
            break;
        case 4:
            vetor_quase_ordenado(vet1000, 1000);
            vetor_quase_ordenado(vet100, 100);
            vetor_quase_ordenado(vet10, 10);
        }

        printf("BUCKET SORT\n"),
            printf("    10 elementos\n");
        copiav(copia, vet10, 10);
        comps = trocas = tempo = 0;
        bucket_sort(copia, 10);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    100 elementos\n");
        copiav(copia, vet100, 100);
        comps = trocas = tempo = 0;
        bucket_sort(copia, 100);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    1000 elementos\n");
        copiav(copia, vet1000, 1000);
        comps = trocas = tempo = 0;
        bucket_sort(copia, 1000);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");

        printf("SELECTION SORT\n");
        printf("    10 elementos\n");
        copiav(copia, vet10, 10);
        comps = trocas = tempo = 0;
        selection_sort(copia, 10);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    100 elementos\n");
        copiav(copia, vet100, 100);
        comps = trocas = tempo = 0;
        selection_sort(copia, 100);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    1000 elementos\n");
        copiav(copia, vet1000, 1000);
        comps = trocas = tempo = 0;
        selection_sort(copia, 1000);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");

        printf("BUBBLE SORT\n");
        printf("    10 elementos\n");
        copiav(copia, vet10, 10);
        comps = trocas = tempo = 0;
        bubble_sort(copia, 10);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    100 elementos\n");
        copiav(copia, vet100, 100);
        comps = trocas = tempo = 0;
        bubble_sort(copia, 100);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    1000 elementos\n");
        copiav(copia, vet1000, 1000);
        comps = trocas = tempo = 0;
        bubble_sort(copia, 1000);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");

        printf("INSERCTION SORT\n");
        printf("    10 elementos\n");
        copiav(copia, vet10, 10);
        comps = trocas = tempo = 0;
        insertion_sort(copia, 10);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    100 elementos\n");
        copiav(copia, vet100, 100);
        comps = trocas = tempo = 0;
        insertion_sort(copia, 100);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    1000 elementos\n");
        copiav(copia, vet1000, 1000);
        comps = trocas = tempo = 0;
        insertion_sort(copia, 1000);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");

        printf("SHELL SORT\n");
        printf("    10 elementos\n");
        copiav(copia, vet10, 10);
        comps = trocas = tempo = 0;
        shell_sort(copia, 10);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    100 elementos\n");
        copiav(copia, vet100, 100);
        comps = trocas = tempo = 0;
        shell_sort(copia, 100);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    1000 elementos\n");
        copiav(copia, vet1000, 1000);
        comps = trocas = tempo = 0;
        shell_sort(copia, 1000);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");

        printf("MERGE SORT\n");
        printf("    10 elementos\n");
        copiav(copia, vet10, 10);
        comps = trocas = tempo = 0;
        merge_sort(copia, 0, 9);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    100 elementos\n");
        copiav(copia, vet100, 100);
        comps = trocas = tempo = 0;
        merge_sort(copia, 0, 99);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    1000 elementos\n");
        copiav(copia, vet1000, 1000);
        comps = trocas = tempo = 0;
        merge_sort(copia, 0, 999);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");

        printf("QUICK SORT\n");
        printf("    10 elementos\n");
        copiav(copia, vet10, 10);
        comps = trocas = tempo = 0;
        quick_sort(copia, 0, 9);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    100 elementos\n");
        copiav(copia, vet100, 100);
        comps = trocas = tempo = 0;
        quick_sort(copia, 0, 99);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");
        printf("    1000 elementos\n");
        copiav(copia, vet1000, 1000);
        comps = trocas = tempo = 0;
        quick_sort(copia, 0, 999);
        printf("    Comparacoes: %d  Trocas: %d  Tempo:  %d\n");

        fflush(stdin);
        printf("Deseja continuar? s/n \n");
        scanf("%c", &escolha);
    } while (escolha != 'n');
}
