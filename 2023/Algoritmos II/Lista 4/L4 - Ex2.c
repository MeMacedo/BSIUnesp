#include <stdio.h>
#include <math.h>

void printa_pares(int n)
{
    if (n == 1)
    {
        printf("0");
        return;
    }

    if (n > 1)
    {
        printa_pares(n - 1);
    }

    printf(" %d", n * 2);
}

void main()
{
    int n;
    printf("Digite n para os n primeiros pares: ");
    scanf("%d", &n);

    printa_pares(n);
}
