#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void bin_to_dec(char num[10])
{
    int dec = 0;
    int binlen = strlen(num) - 1;
    int cota = binlen - 1;
    for (int i = 0; i < binlen; i++)
    {
        int quant = (int)num[i] - 48;
        dec += quant * pow(2, cota);
        cota--;
    }
    itoa(dec, num, 10);
}

void dec_to_bin(char num[10])
{

    char bin[10];
    int deci = atoi(num);
    int i = 0;

    while (deci > 0)
    {
        itoa(deci % 2, &bin[i], 10);
        deci = deci / 2;
        i++;
    }

    strrev(bin);

    strcpy(num, bin);
}

int isBin(char num[10])
{
    for (int i = 0; i < strlen(num) - 1; i++)
    {
        if (num[i] != '1' && num[i] != '0')
            return 0;
    }
    return 1;
}
