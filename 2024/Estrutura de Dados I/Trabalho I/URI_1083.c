#include <stdio.h>
#include <string.h>
#include <ctype.h>

char operadores[] = "|.<>=#+-*/^";
char operandos[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int lexicalError(char *ent)
{
    for (int i = 0; ent[i] != '\0'; i++)
    {
        if (strchr(operadores, ent[i]) == NULL && strchr(operandos, ent[i]) == NULL && ent[i] != '(' && ent[i] != ')')
            return 1;
    }

    return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '>' || c == '<' || c == '=' || c == '#' || c == '.' || c == '|')
        return 1;
    else
        return 0;
}

int isOperand(char c)
{
    if (isalnum(c))
        return 1;
    else
        return 0;
}

int syntaxError(char *ent)
{
    char pilha[1000];
    int pilhaLen = 0;
    int entLen = strlen(ent);

    if (strlen(ent) == 1 && ent[0] == '(')
        return 1;

    int i = 0;
    while (i < entLen)
    {
        if (ent[i] == '(' && ent[i + 1] == ')')
            return 0;
        if (ent[i] == '(')
        {
            pilha[pilhaLen] = ent[i];
            pilhaLen++;
        }
        if (ent[i] == ')')
        {
            if (pilhaLen)
            {
                pilhaLen--;
            }
            else
            {
                return 1;
            }
        }
        if (i < entLen - 1)
        {
            if (isOperator(ent[i]) && isOperator(ent[i + 1]))
                return 1;
            if (isOperand(ent[i]) && isOperand(ent[i + 1]))
                return 1;
        }
        i++;
    }

    if (pilhaLen > 0)
        return 1;

    return 0;
}

int precedencia(char c)
{
    switch (c)
    {
    case '|':
        return 1;
    case '.':
        return 2;
    case '<':
    case '>':
    case '=':
    case '#':
        return 3;
    case '+':
    case '-':
        return 4;
    case '*':
    case '/':
        return 5;
    case '^':
        return 6;
    default:
        return 0;
    }
}

void toPosFixa(char *entrada)
{
    char posfixa[1000], pilhaAux[1000];
    int topo = -1, pos = 0, len = strlen(entrada);

    for (int i = 0; i < len; i++)
    {
        if (isOperand(entrada[i]))
        {
            posfixa[pos] = entrada[i];
            pos++;
        }
        else if (isOperator(entrada[i]))
        {
            while (topo >= 0 && pilhaAux[topo] != '(' && (precedencia(pilhaAux[topo]) >= precedencia(entrada[i])))
            {
                posfixa[pos] = pilhaAux[topo];
                pos++;
                topo--;
            }
            topo++;
            pilhaAux[topo] = entrada[i];
        }
        else if (entrada[i] == '(')
        {
            topo++;
            pilhaAux[topo] = entrada[i];
        }
        else if (entrada[i] == ')')
        {
            while (topo >= 0 && pilhaAux[topo] != '(')
            {
                posfixa[pos] = pilhaAux[topo];
                pos++;
                topo--;
            }
            topo--;
        }
    }

    while (topo >= 0)
    {
        posfixa[pos] = pilhaAux[topo];
        pos++;
        topo--;
    }

    posfixa[pos] = '\0';

    printf("%s\n", posfixa);
}

int main()
{
    char entrada[1000];
    while (scanf("%s", entrada) != EOF)
    {

        if (lexicalError(entrada))
            printf("Lexical Error!\n");
        else if (syntaxError(entrada))
            printf("Syntax Error!\n");
        else
            toPosFixa(entrada);
    }

    return 0;
}
