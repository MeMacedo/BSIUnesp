/* Trabalho em conjunto com Leonardo Vicentini, código dele*/

#include <stdio.h>
#include <math.h>

int main()
{

    int i, atual, meta, diaMes = 0, diasTotais = 0;
    double soma, media, ganho[30];
    scanf("%d %d", &atual, &meta);

    for (i = 0; i < 30; i++)
        scanf("%lg", &ganho[i]);

    while (atual < meta)
    {
        soma = 0;
        for (i = 0; i < 30; i++)
            soma += ganho[i];

        media = ceil(soma / 30.0);
        ganho[diaMes] = media;
        atual += media;

        diaMes++;
        if (diaMes == 30)
            diaMes = 0;

        diasTotais++;
    }

    printf("%d\n", diasTotais);

    return 0;
}
