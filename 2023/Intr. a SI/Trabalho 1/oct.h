#include <stdlib.h>

void oct_to_dec(char num[10])
{
    int dec = 0;
    int octlen = strlen(num) - 1;
    int cota = octlen - 1;
    for (int i = 0; i < octlen; i++)
    {
        int quant = (int)num[i] - 48;
        dec += quant * pow(8, cota);
        cota--;
    }
    itoa(dec, num, 10);
}

char dec_to_oct(char num[10])
{
    char oct[10];
    long long deci = atoi(num);
    int i = 0;

    while (deci > 0)
    {
        itoa(deci % 8, &oct[i], 10);
        deci = deci / 8;
        i++;
    }

    strrev(oct);

    strcpy(num, oct);
}
