#include <stdio.h>
#include <conio.h>
#define M 10
#define N 10

void scanea_matriz(float matriz[M][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }
}

void printa_matriz(float matriz[M][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void troca_linha(float matriz[M][N], int l1, int l2)
{
    float aux;
    for (int i = 0; i < N; i++)
    {
        aux = matriz[l1][i];
        matriz[l1][i] = matriz[l2][i];
        matriz[l2][i] = aux;
    }
}

void troca_coluna(float matriz[M][N], int c1, int c2)
{
    float aux;
    for (int i = 0; i < M; i++)
    {
        aux = matriz[i][c1];
        matriz[i][c1] = matriz[i][c2];
        matriz[i][c2] = aux;
    }
}

void troca_diagonais(float matriz[M][N], int m, int n)
{
    if (m != n)
    {
        printf("Não é possível trocar diagonais de matrizes não-quadradas.\n");
        return;
    }

    float aux;
    int dif = m - 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                continue;
            aux = matriz[i][j];
            matriz[i][j] = matriz[i][dif];
            matriz[i][dif] = aux;
        }
        dif--;
    }
}

int e_igual(float matriz[M][N], float matriz2[M][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matriz[i][j] != matriz2[i][j])
                return 0;
        }
    }
    return 1;
}

void e_simetrica(float matriz[M][N], int m, int n)
{
    if (m != n)
        return;
    float matriz2[M][N];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz2[j][i] = matriz[i][j];
        }
    }
    printf("Transposta\n");
    printa_matriz(matriz2, m, n);

    if (e_igual(matriz, matriz2, m, n))
        printf("É simétrica");
    else
        printf("Não é simétrica");
}

float soma_diagonal(float matriz[M][N], int m, int n, int princ)
{
    float soma = 0;
    int dif = n - 1;
    if (princ)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    soma += matriz[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    soma += matriz[i][dif];
                    dif--;
                }
            }
        }
    }

    return soma;
}

float soma_coluna(float matriz[M][N], int m, int coluna)
{
    float soma = 0;
    for (int i = 0; i < m; i++)
    {
        soma += matriz[i][coluna];
    }
    return soma;
}

float soma_linha(float linha[M], int n)
{
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += linha[i];
    }
    return soma;
}

void e_quadr_magico(float matriz[M][N], int m, int n)
{
    int soma, soma_atual;

    if (m != n)
    {
        printf("Não é possível fazer a operação para matrizes não-quadradas.\n");
        return;
    }

    soma = soma_linha(matriz[0], n);

    for (int i = 1; i < m; i++)
    {
        soma_atual = soma_linha(matriz[i], n);
        if (soma != soma_atual)
        {
            printf("A matriz não é um quadrado mágico");
            return;
        }
    }

    for (int j = 0; j < n; j++)
    {
        soma_atual = soma_coluna(matriz, n, j);
        if (soma != soma_atual)
        {
            printf("A matriz não é um quadrado mágico");
            return;
        }
    }

    for (int h = 0; h < 2; h++)
    {
        soma_atual = soma_diagonal(matriz, n, m, h);
        if (soma != soma_atual)
        {
            printf("A matriz não é um quadrado mágico");
            return;
        }
    }

    printf("A matriz é um quadrado mágico");
    return;
}

int linha_so_tem_um(float linha[N], int n)
{
    int achou_um = 1;
    for (int i = 0; i < n; i++)
    {
        if (!linha[i])
            continue;
        else if (linha[i] == 1 && achou_um)
            achou_um = 0;
        else if (linha[i] == 1 && !achou_um)
            return 0;
        else if (linha[i] > 1)
            return 0;
    }
    return 1;
}

int coluna_so_tem_um(float matriz[M][N], int m, int coluna)
{
    int achou_um = 1;
    for (int i = 0; i < m; i++)
    {
        if (!matriz[i][coluna])
            continue;
        else if (matriz[i][coluna] == 1 && achou_um)
            achou_um = 0;
        else if (matriz[i][coluna] == 1 && !achou_um)
            return 0;
        else if (matriz[i][coluna] != 1)
            return 0;
    }
    return 1;
}

void e_de_permut(float matriz[M][N], int m, int n)
{

    if (m != n)
    {
        printf("Não é possível fazer a operação para matrizes não-quadradas.\n");
        return;
    }

    for (int i = 1; i < m; i++)
    {
        if (!linha_so_tem_um(matriz[i], n))
        {
            printf("A matriz não é de permutação");
            return;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (!coluna_so_tem_um(matriz, m, j))
        {
            printf("A matriz não é de permutação");
            return;
        }
    }

    printf("A matriz é de permutação");
    return;
}

void e_quadr_latino(float matriz[M][N], int m, int n)
{
    if (m != n)
    {
        printf("Não é possível fazer a operação para matrizes não-quadradas.\n");
        return;
    }

    int achou = 0;
    float cont = 1;

    for (int i = 0; i < m; i++)
    {
        achou = 0;
        for (int j = 0; j < n; j++)
        {
            if (matriz[i][j] == cont)
            {
                if (achou)
                {
                    printf("A matriz não é quadrado latino");
                    return;
                }
                else
                    achou = 1;
            }
            if (matriz[i][j] > m + 1 || matriz[i][j] < 1)
            {
                printf("A matriz não é quadrado latino");
                return;
            }
        }
        cont++;
        if (!achou)
        {
            printf("A matriz não é quadrado latino");
            return;
        }
    }

    cont = 1;

    for (int i = 0; i < m; i++)
    {
        achou = 0;
        for (int j = 0; j < n; j++)
        {
            if (matriz[j][i] == cont)
            {
                if (achou)
                {
                    printf("A matriz não é quadrado latino");
                    return;
                }
                else
                    achou = 1;
            }
            if (matriz[j][i] > m + 1 || matriz[i][j] < 1)
            {
                printf("A matriz não é quadrado latino");
                return;
            }
        }
        cont++;
        if (!achou)
        {
            printf("A matriz não é quadrado latino");
            return;
        }
    }

    printf("A matriz é quadrado latino");
}

int main()
{
    int m, n, c;

    float matriz[M][N];

    printf("Digite dois números inteiros para as dimensões da matriz: \n");
    scanf("%d %d", &m, &n);

    printf("Digite as entradas da sua matriz: \n");

    scanea_matriz(matriz, m, n);

    printf("O que deseja fazer? Use as setas do teclado para escolher\n"
           "Seta para cima para printar a matriz\n"
           "Seta para direta para trocar uma linha da matriz por outra\n"
           "Seta para esquerda para trocar uma coluna por outra\n"
           "Seta para baixo para trocar a diagonal principal pela secundária\n"
           "Qualquer outra tecla para mais opções\n");

    c = getch();
    if (c == 0 || c == 0xE0)
        c = getch();

    switch (c)
    {
    case 72:
        printa_matriz(matriz, m, n);
        return 1;
    case 80:
        troca_diagonais(matriz, m, n);
        return 1;
    case 77:
        int l1, l2;
        printf("Digite o valor das linhas a trocar: ");
        scanf("%d %d", &l1, &l2);
        troca_linha(matriz, l1, l2);
        return 1;
    case 75:
        int c1, c2;
        printf("Digite o valor das colunas a trocar: ");
        scanf("%d %d", &c1, &c2);
        troca_coluna(matriz, c1, c2);
        return 1;
    default:
        printf("Use as setas do teclado para escolher\n"
               "Seta para cima para verificar se a matriz é simétrica\n"
               "Seta para direta para verificar se a matriz é quadrado latino\n"
               "Seta para esquerda para verificar se a matriz é quadrado mágico\n"
               "Seta para baixo para verificar se a matriz de permutação\n"
               "Esc para sair\n");

        break;
    }

    c = getch();
    if (c == 0 || c == 0xE0)
        c = getch();

    switch (c)
    {
    case 72:
        e_simetrica(matriz, m, n);
        return 1;
    case 80:
        e_de_permut(matriz, m, n);
        return 1;
    case 77:
        int l1, l2;

        e_quadr_latino(matriz, m, n);
        return 1;
    case 75:
        e_quadr_magico(matriz, m, n);
        return 1;
    case 27:
        printf("Tchauzinho!");
        return 1;
    default:
        printf("Tecla não fazia parte das opções. Cancelando programa.");
        break;
    }

    return 0;
}
