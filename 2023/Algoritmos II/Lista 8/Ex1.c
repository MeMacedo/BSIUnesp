
#include <stdio.h>

// Visto que o ponteiro p aponta para o endereço de i e o ponteiro q aponta para
//  o endereço de p, temos:
// p = &i ==> *p == i
// q = &p ==> *q == p && **q == *(*q) == *p == i
// Logo, **q == i == 7. Daí, c == 12

int main()
{
    int i = 7, j = 5;
    int *p;
    int **q;
    p = &i;
    q = &p;
    int c = **q + j;
}
