/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>

int main(){
	int dia, mes, ano;
	
	char Mes[15];
	
	printf("Digite dia, mês e ano (dd/m/aaaa): ");
	scanf("%d/%d/%d", &dia, &mes, &ano);
	
	if(mes == 1) printf("%d de %s de %d", dia, "Janeiro", ano);
	else if(mes == 2)printf("%d de %s de %d", dia, "Fevereiro", ano);
	else if(mes == 3)printf("%d de %s de %d", dia, "Março", ano);
	else if(mes == 4)printf("%d de %s de %d", dia, "Abril", ano);
	else if(mes == 5)printf("%d de %s de %d", dia, "Maio", ano);
	else if(mes == 6)printf("%d de %s de %d", dia, "Junho", ano);
	else if(mes == 7)printf("%d de %s de %d", dia, "Julho", ano);
	else if(mes == 8)printf("%d de %s de %d", dia, "Agosto", ano);
	else if(mes == 9)printf("%d de %s de %d", dia, "Setembro", ano);
	else if(mes == 10)printf("%d de %s de %d", dia, "Outubro", ano);
	else if(mes == 11)printf("%d de %s de %d", dia, "Novembro", ano);
	else printf("%d de %s de %d", dia, "Dezembro", ano);
	
	if(ano%4) printf("\nAno não é bissexto");
	else printf("\nAno é bissexto");
		
	return 0;
}
