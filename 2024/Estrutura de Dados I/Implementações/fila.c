#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int num;
    struct fila *prox;
} *Fila;

int dequeue(Fila *inicio, Fila *final)
{
    int popped;
    Fila temp;
    if (*inicio == *final)
    {
        popped = (*inicio)->num;
        temp = *inicio;
        *inicio = NULL;
        free(temp);
        temp = *final;
        *final = NULL;
        free(temp);
        return popped;
    }

    if (*inicio != NULL)
    {
        temp = *inicio;
        *inicio = (*inicio)->prox;
        popped = temp->num;
        free(temp);
        return popped;
    }
    return NULL;
}

void queue(Fila *inicio, Fila *final, int num)
{
    Fila ultimo = (Fila *)malloc(sizeof(Fila));
    ultimo->num = num;
    if (*final != NULL)
    {
        (*final)->prox = ultimo;
    }
    else
    {
        *inicio = ultimo;
        *final = ultimo;
    }
}

int isEmpty(Fila inicio)
{
    return (inicio) != NULL;
}

void main() {}
