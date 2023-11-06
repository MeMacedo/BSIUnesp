#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char nomes[1000][50];
int quant = 0;

int upperSearch(char nome[50])
{
    int l = 0, r = quant - 1;

    while (l < r)
    {
        int m = (l + r) / 2;
        char aux_nome[50];
        int nome_len = strlen(nome);
        strcpy(aux_nome, nomes[m]);
        aux_nome[nome_len - 1] = '\0';
        int comp = strcmp(nome, aux_nome);
        if (comp >= 0)
        {
            l = m + 1;
        }
        else
            r = m;
    }
    return r;
}

int lowerSearch(char nome[50])
{
    int l = 0, r = quant - 1;
    int lower = 0;
    while (l < r)
    {
        int m = (l + r) / 2;
        int comp = strcmp(nome, nomes[m]);
        if (comp > 0)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return l;
}

void search()
{
    char opt;
    printf("Deseja consultar um nome? (s/n): ");
    opt = fgetc(stdin);
    char nome[50];
    int upperbound, lowerbound;

    if (tolower(opt) == 's')
    {
        do
        {
            printf("Digite o nome: ");
            fflush(stdin);
            fgets(nome, 49, stdin);

            lowerbound = lowerSearch(nome);

            upperbound = upperSearch(nome);

            for (int i = lowerbound; i < upperbound; i++)
            {
                printf("%s", nomes[i]);
            }

            printf("Deseja consultar mais um? (s/n): ");
            opt = fgetc(stdin);

        } while (tolower(opt) == 's');
    }
}

int main()
{

    char nome[50];
    int i = 0;

    FILE *arquivo;

    arquivo = fopen("nomes.txt", "r");

    while (fgets(nome, 49, arquivo))
    {
        strcpy(nomes[i], nome);
        i++;
    }
    quant = i;

    fclose(arquivo);

    search();
}
