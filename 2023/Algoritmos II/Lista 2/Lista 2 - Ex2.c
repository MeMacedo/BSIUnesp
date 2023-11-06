#include <stdio.h>

int main()
{
    int quant;
    int num;
    char buffer;
    FILE *odd;
    FILE *even;

    printf("Quant. de números: ");
    scanf("%d", &quant);
    printf("\n");

    odd = fopen("odd.bin", "wb");
    even = fopen("even.bin", "wb");

    if (!odd || !even)
    {
        printf("Erro");
        return 1;
    }

    printf("Escreva os números: ");
    while (quant--)
    {
        scanf("%d%c", &num, &buffer);
        if (num % 2 == 0)
        {
            fwrite(&num, sizeof(num), 1, even);
        }
        else
        {

            fwrite(&num, sizeof(num), 1, odd);
        }
    }

    printf("\n");
    fclose(odd);
    fclose(even);

    printf("Números pares: ");
    even = fopen("even.bin", "rb");
    if (!even)
    {
        printf("Erro");
        return 1;
    }
    while (fread(&num, sizeof(num), 1, even))
    {
        printf("%d ", num);
    }

    printf("\n");
    fclose(even);

    printf("Números impares: ");
    odd = fopen("odd.bin", "rb");
    if (!odd)
    {
        printf("Erro");
        return 1;
    }
    while (fread(&num, sizeof(num), 1, odd))
    {
        printf("%d ", num);
    }

    printf("\n");
    fclose(even);
}
