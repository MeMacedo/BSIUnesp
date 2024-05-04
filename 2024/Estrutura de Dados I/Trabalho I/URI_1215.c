#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct def_no
{
  char palavra[201];
  struct def_no *esq;
  struct def_no *dir;
} *no_arvore;

void insereArvore(no_arvore *arvore, char palavra[201])
{
  no_arvore p;
  if (*arvore != NULL)
  {
    int comp = strcmp((*arvore)->palavra, palavra);
    if (comp == 0)
      return;
    if (comp > 0)
      insereArvore(&((*arvore)->esq), palavra);
    else if (comp < 0)
      insereArvore(&((*arvore)->dir), palavra);
  }
  else
  {
    p = (no_arvore)malloc(sizeof(struct def_no));

    strcpy(p->palavra, palavra);
    p->esq = NULL;
    p->dir = NULL;
    *arvore = p;
  }
}

void printaArvore(no_arvore arvore)
{

  if (arvore != NULL)
  {
    printaArvore(arvore->esq);
    printf("%s\n", (arvore)->palavra);
    printaArvore(arvore->dir);
  }
}

void main()
{
  no_arvore dicionario;
  dicionario = NULL;

  char linha[201];

  while (fgets(linha, sizeof(linha) - 1, stdin) != NULL)
  {
    int tam = strlen(linha);
    if (!tam)
      continue;
    int i = 0;

    while (i < tam)
    {
      linha[i] = tolower(linha[i]);
      if (linha[i] < 'a' || linha[i] > 'z')
        linha[i] = 32;
      i++;
    }

    char *token = strtok(linha, " ");

    while (token != NULL)
    {
      if (strlen(token) != 0)
        insereArvore(&dicionario, token);
      token = strtok(NULL, " ");
    }
    fflush(stdin);
  }

  printaArvore(dicionario);
}
