/*9. Considere o mÈtodo de TransformaÁ„o da raiz. Elabore uma rotina que recebe como
par‚metro a chave, a base e o tamanho da tabela e retorne o endereço da chave na tabela.*/

#include <stdlib.h>
#include <stdio.h>

int transfRaiz(int valor, int tamTabela, int base)
{
    char temp[1000];
    itoa(valor, temp, base);
    return atoi(temp) % tamTabela;
}

void main()
{

    printf("%d", transfRaiz(345, 100, 9));
}
