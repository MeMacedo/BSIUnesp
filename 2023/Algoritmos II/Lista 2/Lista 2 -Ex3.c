#include <stdio.h>

#define arquivo "estoque.bin"

typedef struct
{
    int codigo;
    char descr[20];
    int quant;
    double preco;
    int existe;
} Item;

void consultaEstoque()
{
    FILE *estoque;
    Item item;
    int cod;

    estoque = fopen(arquivo, "rb");

    if (!estoque)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    printf("Digite o numero do produto procurado: ");
    scanf("%d", &cod);

    int achou = 0;
    while (fread(&item, sizeof(item), 1, estoque))
    {
        if (item.existe && item.codigo == cod)
        {
            printf("Nome do item: %s\n", item.descr);
            printf("Código: %d\n", item.codigo);
            printf("Preço: %3.2f\n", item.preco);
            printf("Quantidade: %d\n", item.quant);
            achou = 1;
            break;
        }
    }
    if (!achou)
        printf("Produto não encontrado.\n");

    fclose(estoque);
}

int consultaNumero(int cod)
{
    FILE *estoque;

    Item item;
    int achou = 0;
    estoque = fopen(arquivo, "rb");

    if (!estoque)
    {
        return 0;
    }

    while (fread(&item, sizeof(item), 1, estoque))
    {
        if (item.existe && item.codigo == cod)
        {
            achou = 1;
        }
    }

    return achou;
}

void adicionaItem()
{
    FILE *estoque;
    Item item;
    char cont;
    estoque = fopen(arquivo, "ab");

    if (!estoque)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    do
    {
        printf("Nome do item: ");
        scanf("%s", &item.descr);
        printf("Código: ");
        scanf("%d", &item.codigo);
        printf("Preço: ");
        scanf("%f", &item.preco);
        printf("Quantidade: ");
        scanf("%d", &item.quant);

        if (consultaNumero(item.codigo))
        {
            printf("Código de item já utilizado.Escolha outra código\n");
        }
        else
        {
            fwrite(&item, sizeof(item), 1, estoque);
            printf("Item adicionado ao estoque.\n");
        }

        printf("Deseja adicionar mais um produto? (s/n)? ");
        do
        {
            cont = getch();
        } while (toupper(cont) != 'S' && toupper(cont) != 'N');
    } while (cont == 's' || cont == 'S');
    fclose(estoque);
}

void alteraItem()
{
    FILE *estoque;
    Item item;
    int cod;
    int achou = 0;
    estoque = fopen(arquivo, "r+b");

    if (!estoque)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    printf("Digite o código do item que procura: ");
    scanf("%d", &cod);

    while (fread(&item, sizeof(item), 1, estoque))
    {
        if (item.existe && item.codigo == cod)
        {
            achou = 1;
            printf("Infos atuais do item:\n");
            printf("Nome do item: %s\n", item.descr);
            printf("Código: %d\n", item.codigo);
            printf("Preço: %3.2f\n", item.preco);
            printf("Quantidade: %d\n", item.quant);

            printf("Adicione as infos novas: \n");
            printf("Nome do item: ");
            scanf("%s", &item.descr);
            printf("Código: ");
            scanf("%d", &item.codigo);
            printf("Preço: ");
            scanf("%f", &item.preco);
            printf("Quantidade: ");
            scanf("%d", &item.quant);

            item.existe = 1;

            if (consultaNumero(item.codigo))
            {
                printf("Código de item já utilizado.Escolha outra código\n");
            }
            else
            {
                fseek(estoque, -sizeof(item), SEEK_CUR);
                fwrite(&item, sizeof(item), 1, estoque);
                printf("Item alterado no estoque.\n");
            }
            break;
        }
    }

    if (!achou)
        printf("Item não encontrado\n");

    fclose(estoque);
}

void removeItem()
{
    FILE *estoque;
    Item item;
    int cod;
    int achou = 0;
    estoque = fopen(arquivo, "r+b");

    if (!estoque)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    printf("Digite o código do item que quer excluir: ");
    scanf("%d", &cod);

    while (fread(&item, sizeof(item), 1, estoque))
    {
        if (item.existe && item.codigo == cod)
        {
            achou = 1;
            item.existe = 0;
            fseek(estoque, -sizeof(item), SEEK_CUR);
            fwrite(&item, sizeof(item), 1, estoque);

            printf("Item excluído do estoque.\n");
            break;
        }
    }
    if (!achou)
        printf("Item não encontrado\n");

    fclose(estoque);
}

void removeTudo()
{
    FILE *atual, *novo;
    Item item;

    atual = fopen(arquivo, "rb");
    novo = fopen("temp.bin", "wb");

    if (!atual || !novo)
    {
        printf("Erro na remoção física");
    }

    while (fread(&item, sizeof(item), 1, atual))
    {
        if (item.existe)
        {
            fwrite(&item, sizeof(item), 1, novo);
        }
    }

    fclose(novo);
    fclose(atual);
    remove(arquivo);

    rename("temp.bin", arquivo);

    printf("Remoção física realizada");
    return;
}

void opcoes(char *opt)
{
    printf("\nO que deseja fazer?:");
    printf("\n 1 - Consultar estoque");
    printf("\n 2 - Adicionar estoque");
    printf("\n 3 - Alterar registro");
    printf("\n 4 - Remover item do estoque");
    printf("\n 5 - Sair\n");
    do
    {
        *opt = getch();
    } while (*opt < '1' || *opt > '5');
    printf("---------------------------------------------------------\n");
}

int main()
{

    Item item;
    char opt;

    do
    {
        opcoes(&opt);
        switch (opt)
        {
        case '1':
            consultaEstoque();
            break;
        case '2':
            adicionaItem();
            break;
        case '3':
            alteraItem();
            break;
        case '4':
            removeItem();
            break;
        case '5':
            break;
        default:
            printf("\nSelecione uma opção válida\n");
        }
    } while (opt != '5');
    removeTudo();
}
