#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo1, *arquivo2, *arquivo3;
    char endereco1[50], endereco2[50], linha[201];

    printf("EScreva o endereço do primeiro arquivo: ");

    scanf("%s", endereco1);

    printf("EScreva o endereço do segundo arquivo: ");

    scanf("%s", endereco2);

    arquivo3 = fopen("arquivo_final.txt", "w");
    if (!arquivo3)
    {
        printf("Erro na abertura do arquivo-destino");
        return 1;
    }

    arquivo1 = fopen(endereco1, "r");

    if (!arquivo1)
    {
        printf("Erro na abertura do primeiro arquivo");
        return 1;
    }

    while (fgets(linha, 200, arquivo1) != NULL)
    {
        fputs(linha, arquivo3);
    }

    fclose(arquivo1);

    arquivo2 = fopen(endereco2, "r");

    if (!arquivo2)
    {
        printf("Erro na abertura do segundo arquivo");
        return 1;
    }

    while (fgets(linha, 200, arquivo2) != NULL)
    {
        fputs(linha, arquivo3);
    }

    fclose(arquivo2);

    fclose(arquivo3);
}
