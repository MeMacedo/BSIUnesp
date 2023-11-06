#include <stdio.h>
   int main()
{
	char resposta;
	printf("O animal é:\n\n");
	printf("M - Mamifero\n");
	printf("A - Ave\n");
	printf("R - Réptil\n");
	scanf("%c",&resposta);

	if (resposta == 'M'){
			printf("O animal é:\n\n");
			printf("Q - Quadrúpede\n");
			printf("B - Bípede\n");
			printf("V - Voador\n");
			printf("A - Aquático\n");
			scanf("%c",&resposta);

			if (resposta == 'Q') {
				printf("O animal é:\n\n");
				printf("C - Carnívoro\n");
				printf("H - Herbívoro\n");
				scanf("%c",&resposta);

				if (resposta == 'C')
					printf("O animal é o Leão\n	");
				else if(resposta =='H')
					printf("O animal é o Cavalo\n");
				else 
					printf("Você digitou uma opção inválida\n");
		
			}else if(resposta == 'B'){
				printf("O animal é:\n\n");
				printf("O - Onívoro\n");
				printf("F - Frutívoro\n");
				scanf("%c",&resposta);
			
				if (resposta == 'O')
					printf("O animal é o Homem\n");
				else if (resposta == 'F')
					printf("O animal é o Macaco\n");
				else 
					printf("Você digitou uma opção inválida\n");
			}else if (resposta == 'V')
				printf("O animal é o Morcego\n");
			else if (resposta == 'A')
				printf("O animal é a Baleia\n");	
	}else if (resposta == 'A'){
		printf("O animal é:\n\n");
		printf("V - Não voador\n");
		printf("N - Nadador\n");
		printf("R - De rapina\n");
		scanf("%c",&resposta);
	
		if (resposta == 'V'){
			printf("O Animal é:\n\n");
			printf("T - Tropical\n");
			printf("P - Polar \n");
			scanf("%c",&resposta);
			if (resposta =='T')
				printf("O animal é o Avestruz\n");
			else if (resposta =='P')
				printf("O animal é o Pinguim\n");
			else
				printf("Você digitou uma opção inválida\n");
		
		}else if(resposta == 'N')
			printf("O animal é o Pato\n");
		else if (resposta == 'R')
			printf("O animal é a Águia\n");
	}else if (resposta == 'R'){
		printf("O animal é:\n\n");
		printf("A - Com Casco\n");
		printf("C - Carnívoro\n");
		printf("S - Sem patas\n");
		scanf("%c",resposta);
	
		if (resposta == 'A')
			printf("O animal é a Tartaruga\n");
		else if (resposta == 'C')
			printf("O animal é o Crocodilo\n");
		else if (resposta == 'S')
			printf("O animal é a Cobra\n");
		else 
			printf("Você digitou uma opção inválida\n");


	}else 
		printf("Você digitou uma opção inválida\n");



}
 
 