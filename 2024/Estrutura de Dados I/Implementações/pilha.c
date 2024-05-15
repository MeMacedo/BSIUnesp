#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int pilhaLen;
    int num;
    struct pilha *anterior;
} *Pilha;

int pop(Pilha *p)
{
    if (*p != NULL)
    {
        Pilha topo = (Pilha *)malloc(sizeof(Pilha)), temp;
        topo->pilhaLen = (*p)->pilhaLen - 1;
        temp = *p;
        *p = topo;
        int popped = temp->num;
        free(temp);
        return popped;
    }
    return NULL;
}

void push(Pilha *p, int num)
{
    Pilha topo = (Pilha *)malloc(sizeof(Pilha));
    topo->num = num;
    if (*p != NULL)
    {
        topo->pilhaLen = (*p)->pilhaLen + 1;
    }
    else
    {
        topo->pilhaLen = 1;
    }
    topo->anterior = *p;
    *p = topo;
}

int isEmpty(Pilha p)
{
    return p->pilhaLen == 0;
}

int top(Pilha p)
{

    return p->num;
}

void main() {}
