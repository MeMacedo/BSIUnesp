#include <stdio.h>
#include <math.h>

int soma_cubos(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    return pow(n, 3) + soma_cubos(n - 1);
}

void main()
{
    int n;
    printf("Digite n para a soma dos n primeiros cubos: ");
    scanf("%d", &n);

    printf("%d", soma_cubos(n));
}
