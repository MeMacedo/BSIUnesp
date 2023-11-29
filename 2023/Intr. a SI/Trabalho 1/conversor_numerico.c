#include <stdio.h>
#include <ctype.h>
#include "bin.h"
#include "hex.h"
#include "oct.h"

void getConversion(char, char);
void octTo(char);
void binTo(char);
void hexTo(char);

char num[10];

int main()
{
    char ini, fim, cont;
    printf("\nConversor númerico\n");
    do
    {
        fflush(stdin);
        printf("Em qual base está seu número?\n - B para binário\n - O para octal\n - D para decimal\n - H para hexadecimal\n");
        scanf("%c", &ini);
        fflush(stdin);

        printf("\nDigite seu número: ");
        fgets(num, 9, stdin);
        fflush(stdin);

        printf("Para qual base converter?\n - B para binário\n - O para octal\n - D para decimal\n - H para hexadecimal\n");
        scanf("%c", &fim);

        getConversion(ini, fim);

        fflush(stdin);
        printf("\nDeseja converter mais um número? (S/N)");
        scanf("%c", &cont);

    } while (tolower(cont) == 's');
}

void decTo(char fim)
{
    if (tolower(fim) == 'b')
        dec_to_bin(num);
    else if (tolower(fim) == 'h')
        dec_to_hex(num);
    else if (tolower(fim) == 'o')
        dec_to_oct(num);
}

void octTo(char fim)
{
    oct_to_dec(num);
    if (tolower(fim) == 'b')
        dec_to_bin(num);
    else if (tolower(fim) == 'h')
        dec_to_hex(num);
}

void hexTo(char fim)
{
    hex_to_dec(num);
    if (tolower(fim) == 'b')
        dec_to_bin(num);
    else if (tolower(fim) == 'o')
        dec_to_oct(num);
}

void binTo(char fim)
{
    bin_to_dec(num);
    if (tolower(fim) == 'h')
        dec_to_hex(num);
    else if (tolower(fim) == 'o')
        dec_to_oct(num);
}

void getConversion(char ini, char fim)
{
    if (ini == fim)
        printf("%s", num);
    if (tolower(ini) == 'b')
        binTo(fim);
    else if (tolower(ini) == 'h')
        hexTo(fim);
    else if (tolower(ini) == 'o')
        octTo(fim);
    else
        decTo(fim);
    printf("Número convertido: %s", num);
}
