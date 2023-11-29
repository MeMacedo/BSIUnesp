#include <stdio.h>
#include "FuncListaEncadeadas.h"

int main()
{
    int quant, num;

    no lista;
    printf("Cria lista vazia\n");
    criaLista(&lista);

    printf("Qual primeiro número da lista? ");
    scanf("%d", &num);

    incluiInicio(&lista, num);

    printf("Qual o último? Adicione um número maior que o primeiro");
    scanf("%d", &num);
    incluiFinal(&lista, num);
    imprimirLista(lista);
    printf("Quantos números a mais adicionar?");
    scanf("%d", &quant);
    for (int i = 0; i < quant; i++)
    {
        scanf("%d", &num);
        incluiOrdenado(&lista, num);
    }
    printf("Lista atual: ");
    imprimirLista(lista);

    printf("Outros testes: \n");
    printf("- Removendo o primeiro\n");
    removerPrimeiro(&lista);
    printf("- Removendo o último\n");
    removerUltimo(&lista);
    printf("- Imprimindo a lista\n");
    imprimirLista(lista);
    printf("- Busca\n");
    printf("    Digite um número para ser procurado: ");
    scanf("%d", &num);
    printf("    Encontrado na posição: %d\n", busca(lista, num));
    printf("- Quantidade de nós da lista: \n%d\n", contaNos(lista));
}
