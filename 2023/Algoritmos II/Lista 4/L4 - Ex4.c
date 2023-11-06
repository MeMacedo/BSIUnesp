#include <stdio.h>

int tetranacci(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return 0;
    if (n == 4)
        return 1;
    return tetranacci(n - 4) + tetranacci(n - 3) + tetranacci(n - 2) + tetranacci(n - 1);
}

int main()
{
    int n;
    printf("Digite n para o n-ésimo termo de tetranacci: ");
    scanf("%d", &n);
    printf("\nN-ésimo termo de tetranacci = %d", tetranacci(n));
}
