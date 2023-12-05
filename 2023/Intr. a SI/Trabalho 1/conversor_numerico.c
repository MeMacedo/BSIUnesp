#include <stdio.h>
#include <ctype.h>
#include "bin.h"
#include "hex.h"

// COMPILADOR GCC
// SO WINDOWS 10 PRO
// MELISSA MACEDO
// Meu compilador não tava suportando regex, então fiz a verificação com ifs mesmo

void getConversion(char, char);
int octTo(char);
int binTo(char);
int hexTo(char);
int isDec();

char num[10];

int main()
{
    char ini, fim, cont;
    printf("\nConversor numerico\n");
    do
    {
        fflush(stdin);
        printf("Em qual base está seu número?\n - B para binario\n - O para octal\n - D para decimal\n - H para hexadecimal\n");
        scanf("%c", &ini);
        fflush(stdin);

        printf("\nDigite seu número: ");
        fgets(num, 9, stdin);
        fflush(stdin);

        printf("Para qual base converter?\n - B para binario\n - O para octal\n - D para decimal\n - H para hexadecimal\n");
        scanf("%c", &fim);

        getConversion(ini, fim);

        fflush(stdin);
        printf("\nDeseja converter mais um numero? (S/N)");
        scanf("%c", &cont);

    } while (tolower(cont) == 's');
}

int decTo(char fim)
{
    if (!isDec())
    {
        printf("Seu numero nao eh decimal.\n");
        return 0;
    }
    if (fim == 'd')
        return 1;
    if (tolower(fim) == 'b')
        dec_to_bin(num);
    else if (tolower(fim) == 'h')
        dec_to_hex(num);
    else if (tolower(fim) == 'o')
        dec_to_oct(num);
    return 1;
}

int octTo(char fim)
{
    if (!isOct(num))
    {
        printf("Seu numero nao eh octal.\n");
        return 0;
    }
    if (fim == 'o')
        return 1;
    oct_to_dec(num);
    if (tolower(fim) == 'b')
        dec_to_bin(num);
    else if (tolower(fim) == 'h')
        dec_to_hex(num);
    return 1;
}

int hexTo(char fim)
{
    if (!isHex(num))
    {
        printf("Seu numero nao eh hexadecimal.\n");
        return 0;
    }
    if (fim == 'h')
        return 1;
    hex_to_dec(num);
    if (tolower(fim) == 'b')
        dec_to_bin(num);
    else if (tolower(fim) == 'o')
        dec_to_oct(num);
    return 1;
}

int binTo(char fim)
{
    if (!isBin(num))
    {
        printf("Seu numero nao eh binario.\n");
        return 0;
    }

    if (fim == 'b')
        return 1;
    bin_to_dec(num);
    if (tolower(fim) == 'h')
        dec_to_hex(num);
    else if (tolower(fim) == 'o')
        dec_to_oct(num);

    return 1;
}

void getConversion(char ini, char fim)
{
    int isConverted = 1;

    if (tolower(ini) == 'b')
        isConverted = binTo(fim);
    else if (tolower(ini) == 'h')
        isConverted = hexTo(fim);
    else if (tolower(ini) == 'o')
        isConverted = octTo(fim);
    else
        decTo(fim);
    if (isConverted)
        printf("Numero convertido: %s", num);
}

int isDec()
{
    for (int i = 0; i < strlen(num) - 1; i++)
    {
        if (!isdigit(num[i]))
            return 0;
    }
    return 1;
}
