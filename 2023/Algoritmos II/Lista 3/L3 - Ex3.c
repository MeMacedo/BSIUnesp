#include <stdio.h>
#include <ctype.h>
#include <string.h>

int char_mais_freq(char *texto, int len)
{
    int freqs[36], pos = 0, max = 0;
    char charc;
    memset(freqs, 0, sizeof(freqs));

    for (int i = 0; i < len; i++)
    {

        charc = texto[i];
        if (isdigit(charc))
        {
            freqs[charc - 48] += 1;
        }
        else
        {
            freqs[tolower(charc) - 87] += 1;
        }
    }

    for (int i = 0; i < 36; i++)
    {
        if (freqs[i] > max)
        {
            pos = i;
            if (i > 9)
            {
                max = i + 87;
            }
            else
            {
                max = i + 48;
            }
        }
    }

    return max;
}

int main()
{
    FILE *arquivo;
    char texto[101];
    int quant_digit, quant_letra, mais_freq;

    arquivo = fopen("arquivo.txt", "r");

    if (!arquivo)
    {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    while (fgets(texto, 100, arquivo) != NULL)
    {
        quant_digit = 0;
        quant_letra = 0;

        printf("Linha de texto: %s", texto);

        for (int i = 0; i < strlen(texto); i++)
        {
            if (isdigit(texto[i]))
            {
                quant_digit++;
            }
            else if (isalpha(texto[i]))
            {
                quant_letra++;
            }
        }

        mais_freq = char_mais_freq(texto, strlen(texto));
        printf("Quant de digitos: %d, Quant de letras: %d, Caractere mais frequente: %c\n", quant_digit, quant_letra, mais_freq);
    }
}
