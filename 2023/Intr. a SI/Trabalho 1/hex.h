#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void hex_to_dec(char num[10])
{
    int dec = 0;
    int hexlen = strlen(num) - 1;
    int cota = hexlen - 1;
    for (int i = 0; i < hexlen; i++)
    {
        int quant = (int)num[i] - 48;
        dec += quant * pow(16, cota);
        cota--;
    }
    itoa(dec, num, 10);
}

void dec_to_hex(char num[10])
{
    char hex[10];
    long long deci = atoi(num);
    int i = 0;
    while (deci > 0)
    {
        itoa(deci % 16, &hex[i], 16); // fazer conversão
        deci = deci / 16;
        i++;
    }
    strrev(hex);
    strcpy(num, hex);
}

int charToInt(char num)
{
    switch (num)
    {
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        return atoi(&num);
    }
}

int isHex(char num[10])
{
    for (int i = 0; i < strlen(num) - 1; i++)
    {
        if (!isdigit(num[i]) && tolower(num[i]) != 'a' && tolower(num[i]) != 'b' && tolower(num[i]) != 'c' && tolower(num[i]) != 'd' && tolower(num[i]) != 'e' && tolower(num[i]) != 'f')
            return 0;
    }
    return 1;
}
