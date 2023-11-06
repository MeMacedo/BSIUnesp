#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *notas;
    float nota1, nota2;
    char nome[51];
    int quant;

    notas = fopen("notas.txt", "r");

    if (!notas)
    {
        printf("Erro ao abrir arquivo de notas");
        return 1;
    }

    quant = getc(notas) - 48;
    getc(notas);

    while (quant--)
    {
        fgets(nome, 50, notas);
        fscanf(notas, "%f %f ", &nota1, &nota2);
        if ((nota1 + nota2) / 2 < 5.0)
            printf("%s", nome);
        }
}
