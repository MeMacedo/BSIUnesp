#include <stdio.h>

int sub_digitos(int n, int k)
{
    int quant;
    if (n == 0)
    {
        return 0;
    }

    quant = (n % 10) == k;
    return quant + sub_digitos(n / 10, k);
}
int main()
{
    int numero;
    int k;
    printf("Digite um número natural n: ");
    scanf("%d", &numero);
    printf("Digite um inteiro k para ser encontrado em n: ");
    scanf("%d", &k);

    printf("Vezes que n aparece: %d", sub_digitos(numero, k));
    return 0;
}
