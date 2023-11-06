#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include <string.h>

typedef struct
{
    char nome[30];
    int idade;
    char email[30];
} Pessoa;

int main()
{
    FILE *arquivo;
    Pessoa pessoa;
    char idade[3];

    arquivo = fopen("teste.bin", "wb");
    if (!arquivo)
    {
        printf("Erro");
        return 1;
    }

    printf("\n\nNome: ");
    fgets(pessoa.nome, 30, stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = 0;
    printf("\nIdade: ");
    fgets(idade, 3, stdin);
    pessoa.idade = atoi(idade);
    fflush(stdin);
    printf("\nE-mail: ");
    fgets(pessoa.email, 30, stdin);

    fwrite(&pessoa, sizeof(pessoa), 1, arquivo);

    fclose(arquivo);

    if ((arquivo = fopen("teste.bin", "rb")) == NULL)
    {
        printf("\nErro");
        return 1;
    }

    if (fread(&pessoa, sizeof(pessoa), 1, arquivo))
    {
        printf("\n%s %d anos E-mail:%s", pessoa.nome, pessoa.idade, pessoa.email);
    }
    fclose(arquivo);

    return 0;
}
