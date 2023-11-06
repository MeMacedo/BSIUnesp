/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>

int main(){
	int x, y, aux, X, Y;
	printf("\nDigite dois numeros inteiros positivos: ");
	scanf("%d %d",&x,&y);
	X = x;
	Y = y;
	while(x%y != 0){
		aux = y;
		y = x%y;
		x = aux;
	}
	printf("O MDC entre %d e %d é: %d",X,Y,y);
		
	return 0;
}
