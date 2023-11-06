#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isVowel(char ch)
{
    int c = toupper(ch);

    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main()
{
    int vog = 0, cons = 0;
    FILE *arquivo;
    char letra;

    arquivo = fopen("arquivo.txt", "a+");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo");
        return 1;
    }

    while ((letra = getc(arquivo)) != EOF)
    {

        if (isVowel(letra))
        {
            vog++;
        }
        else
        {
            cons++;
        }
    }
    fclose(arquivo);

    printf("Quantidade de vogais do arquivo: %d\n", vog);

    printf("Quantidade de consoantes do arquivo: %d", cons);

    return 0;
}
