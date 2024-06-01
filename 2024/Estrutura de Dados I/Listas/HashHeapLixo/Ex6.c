/*Desenvolva uma função para implementar o mÈtodo da dobra.*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>

int dobraHash(char *chave, int tamTabela)
{
    int valorChave = atoi(chave);

    do
    {
        int len = strlen(chave);
        char temp[1000] = {""};
        for (int i = 0; len / 2; i++)
        {
            temp[i] = (char)(((int)chave[i] + (int)chave[len - 1 - i]) % 10);
        }
        if (len % 2)
        {
            temp[(len / 2) + 1] = chave[len - 1];
            temp[(len / 2) + 2] = '\0';
        }
        else
        {
            temp[(len / 2) + 1] = '\0';
        }

        valorChave = atoi(temp);
        strcpy(chave, temp);
    } while (valorChave > tamTabela);

    return valorChave;
}

void main()
{
    printf("%d", dobraHash("71348790", 10));
}
