#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    int num;
    struct reg *prox;
} *no;

void criaLista(no *lista)
{
    *lista = NULL;
    printf("Lista criada\n");
}

void imprimirLista(no lista)
{
    no p = lista;
    while (p)
    {
        printf("%d ", p->num);
        p = p->prox;
    }
    printf("\n");
}

int contaNos(no lista)
{
    int nos = 0;
    no p = lista;
    while (p)
    {
        nos++;
        p = p->prox;
    }
    return nos;
}

// INCLUSÕES
void incluiInicio(no *lista, int num)
{
    no p = (no)malloc(sizeof(struct reg));
    p->num = num;
    p->prox = *lista;
    *lista = p;
}

void incluiFinal(no *lista, int num)
{
    no p = (no)malloc(sizeof(struct reg));
    p->num = num;
    p->prox = NULL;
    if (*lista == NULL)
    {
        *lista = p;
    }
    else
    {
        no q = *lista;
        while (q->prox)
        {
            q = q->prox;
        }
        q->prox = p;
    }
}

void incluiOrdenado(no *lista, int num)
{

    no p = (no)malloc(sizeof(struct reg));
    p->num = num;
    if (!(*lista))
    {
        *lista = p;
        (*lista)->prox = NULL;
    }
    else if ((*lista)->num > num)
    {
        p->prox = *lista;
        *lista = p;
    }
    else
    {
        no r, q;
        r = *lista;
        q = r->prox;
        while (q != NULL && q->num < num)
        {
            r = q;
            q = q->prox;
        }
        r->prox = p;
        p->prox = q;
    }
}

// REMOÇÕES

void removerPrimeiro(no *lista)
{
    if (!*lista)
    {
        printf("Lista vazia, não há primeiro item");
        return;
    }
    no p = *lista;
    *lista = (*lista)->prox;
    free(p);
}

void removerUltimo(no *lista)
{
    no p = *lista;
    if (!*lista)
    {
        printf("Lista vazia, não há último item");
        return;
    }

    if ((*lista)->prox == NULL)
    {
        *lista = NULL;
        return;
    }
    no q;
    while (p->prox)
    {
        q = p;
        p = p->prox;
    }
    free(p);
    q->prox = NULL;
}

int removeDeterm(no *lista, int num)
{
    no p = *lista;
    no q = NULL;

    while (p)
    {
        if (p->num == num)
        {
            if (q)
                q->prox = p->prox;
            else
                (*lista) = p->prox;
            free(p);
            return 1;
        }
        q = p;
        p = p->prox;
    }
    return 0;
}

void removerLista(no *lista)
{
    no p = *lista, q;
    while (p)
    {
        q = p;
        p = p->prox;
        free(q);
    }
    *lista = NULL;
}

// BUSCAS
int buscaKesimo(no lista, int index)
{
    int k = 0;
    no p = lista;
    while (p != NULL && k < index)
    {
        p = p->prox;
    }

    return p->num;
}

int busca(no lista, int num)
{
    no p = lista;
    int pos = 0;
    while (p)
    {
        if (p->num == num)
            return pos;
        p = p->prox;
        pos++;
    }

    return -1;
}
