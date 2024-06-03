/*Desenvolva um programa que implemente as operaÁıes de inserÁ„o, busca e remoÁ„o de
elementos em uma tabela hashing utilizando encadeamento interno para tratamento das
colisıes. Considere chaves do tipo numÈrico e tabela com tamanho M.*/

#include <stdio.h>

#define MAX 1000

typedef struct ent
{
    int valor;
    struct ent *seguinte;
} *entrada;

typedef struct tab
{
    entrada tabela[MAX];
} tabela;

int divInteira(int valor, int tamTabela)
{
    return valor % tamTabela;
}

entrada procuraTabela(tabela tab, int valor, int tamTabela)
{
    int chave = divInteira(valor, tamTabela);

    if (tab.tabela[chave] == NULL)
    {
        printf("O valor não está presente na tabela");
    }
    else
    {
        entrada p = tab.tabela[chave];
        do
        {
            if (p->valor == valor)
            {
                return p;
            }
            p = p->seguinte;
        } while (p != NULL);
    }
    printf("O valor não está presente na tabela");
    return NULL;
};

void insereTabela(tabela tab, int valor, int tamTabela)
{
    int chave = divInteira(valor, tamTabela);

    entrada q = (entrada)malloc(sizeof(entrada));
    q->valor = valor;

    if (tab.tabela[chave] == NULL)
    {
        tab.tabela[chave] = q;
    }
    else
    {
        entrada p = tab.tabela[chave]->seguinte;
        while (p != NULL)
        {
            p = p->seguinte;
        }
        p->seguinte = q;
    }
}

void removeTabela(tabela tab, int valor, int tamTabela)
{
    int chave = divInteira(valor, tamTabela);

    if (tab.tabela[chave] == NULL)
    {
        printf("O valor não está presente na tabela");
    }
    else
    {
        entrada p = tab.tabela[chave];
        if (p->valor == valor)
        {
            tab.tabela[chave] = p->seguinte;
            free(p);
        }
        else
        {
            do
            {
                entrada q = p;
                p = q->seguinte;
                if (p->valor == valor)
                {
                    q->seguinte = p->seguinte;
                    free(p);
                }
            } while (p != NULL);
        }
    }

    printf("O valor não está presente na tabela");
    return NULL;
}

void main()
{
    int tamTabela;

    scanf("%d", &tamTabela);
    tabela tab;
}
