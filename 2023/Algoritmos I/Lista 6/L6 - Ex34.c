/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>
int main () {
    int n, i, j, impar, soma;   
 
    printf ("Quantidade de numeros que deseja calcular o seu cubo: ");
    scanf ("%d",&n);
    
	impar = 1;
	for (i=1; i<=n; i++){
	printf ("%d^3 = ", i);
	soma = 0;
	for (j=1; j<=i; j++){
	  soma += impar;
	  if(soma==i*i*i)printf("%d", impar);
	  else printf("%d + ", impar);
	  impar += 2;
	}
	printf (" = %d\n",soma);
	}
    
}    
