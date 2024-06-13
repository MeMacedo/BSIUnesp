
#include <stdio.h>
#define MAX 50

typedef struct
{
    int vetor[MAX];
    int tamanho;
} Heap;

void insereHeap(int valor, Heap *heap)
{
    int filho = (*heap).tamanho - 1;
    (*heap).vetor[filho] = valor;
    int pai = (filho - 1) / 2;
    (*heap).tamanho++;
    while (pai > 0 && (*heap).vetor[pai] < valor)
    {

        (*heap).vetor[filho] = (*heap).vetor[pai];
        filho = pai;
        pai = (pai - 1) / 2;
    }
    (*heap).vetor[pai] = valor;
}

int removeHeap(Heap *heap)
{
    if ((*heap).tamanho == 0)
        return NULL;

    int max = (*heap).vetor[0];
    (*heap).vetor[0] = (*heap).vetor[((*heap).tamanho) - 1];
    (*heap).tamanho--;

    int indexAtual = 0;
    int indexFilho = 1;
    int x = (*heap).vetor[0];
    while (indexFilho < (*heap).tamanho)
    {
        if (indexFilho < (*heap).tamanho - 1 && (*heap).vetor[indexFilho] < (*heap).vetor[indexFilho + 1])
        {
            indexFilho++;
        }

        if (x < (*heap).vetor[indexFilho])
        {
            (*heap).vetor[indexAtual] = (*heap).vetor[indexFilho];
            indexAtual = indexFilho;
            indexFilho = 2 * indexFilho + 1;
        }
        else
            break;
    }
    (*heap).vetor[indexAtual] = x;
    return max;
}

void criaHeap() {}

void main()
{
}

void desce(Heap *heap, int indexAtual){
    
    int indexFilho = 2*indexAtual+1;
    int x = (*heap).vetor[indexAtual];
    while (indexFilho < (*heap).tamanho)
    {
        if (indexFilho < (*heap).tamanho - 1 && (*heap).vetor[indexFilho] < (*heap).vetor[indexFilho + 1])
        {
            indexFilho++;
        }

        if (x < (*heap).vetor[indexFilho])
        {
            (*heap).vetor[indexAtual] = (*heap).vetor[indexFilho];
            indexAtual = indexFilho;
            indexFilho = 2 * indexFilho + 1;
        }
        else
            break;
    }
    (*heap).vetor[indexAtual] = x;
}

void heapSort(int array[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }

    int temp;
    for (int i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}
