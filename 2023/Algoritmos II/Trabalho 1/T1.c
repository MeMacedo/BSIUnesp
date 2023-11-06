#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

typedef struct
{
	int cod;
	char nome[50];
	int idade;
	char end[100];
	int telefone;
} Cliente;

typedef struct
{
	int horas;
	int minutos;
} Hora;

typedef struct
{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct
{
	int cod_cliente;

	char nome_cliente[50];
	Data data;
	Hora hora;
	int existe;

} Consulta;

int procura_cliente(FILE *arquivo, int cod)
{
	Cliente cliente;
	int achou = 0;
	while (fread(&cliente, sizeof(cliente), 1, arquivo))
	{
		if (cliente.cod == cod)
			achou = 1;
	}
	return achou;
}

void cadastrar()
{
	printf("\nCADASTRAR CLIENTE\n");
	Cliente cliente, cliente_aux;
	FILE *clientes;

	clientes = fopen("clientes.dat", "a+b");
	if (!clientes)
	{
		printf("\nErro ao abrir arquivo de clientes\n\n");
		return;
	}

	printf("Codigo do cliente: ");
	scanf("%d", &cliente.cod);
	if (procura_cliente(clientes, cliente.cod))
	{
		printf("\nCodigo ja existente, escolha outro.\n\n");
		return;
	}
	fflush(stdin);
	printf("Nome: ");
	fgets(cliente.nome, 49, stdin);
	printf("Idade: ");
	scanf("%d", &cliente.idade);
	fflush(stdin);
	printf("Endereco: ");
	fgets(cliente.end, 99, stdin);
	printf("Telefone: ");
	scanf("%d", &cliente.telefone);

	fwrite(&cliente, sizeof(cliente), 1, clientes);
	fclose(clientes);

	printf("Cliente cadastrado.\n\n");
}

void alterar()
{
	printf("\nALTERAR CLIENTE\n");
	int cod, cont = 0;
	Cliente cliente;
	FILE *clientes;

	clientes = fopen("clientes.dat", "r+b");
	if (!clientes)
	{
		printf("\nErro ao abrir arquivo de clientes\n\n");
		return;
	}
	printf("Insira o codigo do cliente: ");
	scanf("%d", &cod);

	while (fread(&cliente, sizeof(cliente), 1, clientes))
	{
		if (cliente.cod == cod)
		{
			fflush(stdin);
			printf("Nome: ");
			fgets(cliente.nome, 49, stdin);
			printf("Idade: ");
			scanf("%d", &cliente.idade);
			fflush(stdin);
			printf("Endereco: ");
			fgets(cliente.end, 99, stdin);
			printf("Telefone: ");
			scanf("%d", &cliente.telefone);

			fseek(clientes, -(long)sizeof(cliente), SEEK_CUR);
			fwrite(&cliente, sizeof(cliente), 1, clientes);

			cont++;
			break;
		}
	}
	fclose(clientes);
	if (!cont)
		printf("Cliente nao encontrado.\n\n");
	else
		printf("Cliente alterado.\n\n");
}

void marcar()
{

	printf("\nMARCAR CONSULTA\n");
	int cod, achou = 0;

	Cliente cliente;
	Data data;
	Hora hora;
	Consulta consulta;
	FILE *clientes, *consultas;

	printf("Insira o codigo do cliente: ");
	scanf("%d", &cod);

	clientes = fopen("clientes.dat", "r+b");
	if (!clientes)
	{
		printf("\nErro ao abrir arquivo de clientes\n\n");
		return;
	}
	if (!procura_cliente(clientes, cliente.cod))
	{
		printf("\nCliente nao encontrado. Cliente precisa estar cadastrado pra marcar a consulta.\n\n");
		return;
	}

	fclose(clientes);
	printf("Digite a data da consulta no formato dd/mm/aaaa: ");
	scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

	printf("Digite a hora da consulta no formato hh:mm : ");
	scanf("%d:%d", &hora.horas, &hora.minutos);

	consulta.cod_cliente = cod;
	strcpy(consulta.nome_cliente, cliente.nome);
	consulta.hora = hora;
	consulta.data = data;
	consulta.existe = 1;

	consultas = fopen("consultas.dat", "a+b");
	if (!consultas)
	{
		printf("\nErro ao abrir arquivo de consultas\n\n");
		return;
	}
	fwrite(&consulta, sizeof(consulta), 1, consultas);
	fclose(consultas);

	printf("\nConsulta marcada.\n\n");
}

void desmarcar()
{
	printf("\nDESMARCAR CONSULTA\n");
	int achou;
	int c_codigo;
	char res;
	Data data;
	Hora hora;
	Consulta consulta;
	FILE *consultas;

	printf("Digite o codigo do cliente\n");
	scanf("%d", &c_codigo);
	printf("Digite a data da consulta a ser desmarcada no formato dd/mm/aaaa:\n");
	scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
	printf("Digite o horario da consulta  a ser desmarcada no formato hh:mm: \n ");
	scanf("%d:%d", &hora.horas, &hora.minutos);

	consultas = fopen("consultas.dat", "r+b");
	if (consultas == NULL)
	{
		printf("Erro ao abrir arquivo de consultas");
		return;
	}

	while (fread(&consulta, sizeof(Consulta), 1, consultas) == 1)
	{
		int mesmadata = ((consulta.data.dia == data.dia) && (consulta.data.mes == data.mes) && (consulta.data.ano == data.ano));

		int mesmahora = ((consulta.hora.horas == hora.horas) && (consulta.hora.minutos == hora.minutos));

		if (c_codigo == consulta.cod_cliente && mesmadata && mesmahora && consulta.existe)
		{

			achou = 1;
			printf("Consulta encontrada\n Codigo:%d Data:%d/%d/%d Hora: %d:%d\n", c_codigo, consulta.data.dia, consulta.data.mes, consulta.data.ano, consulta.hora.horas, consulta.hora.minutos);
			printf("Quer excluir essa consulta S ou N\n");
			fflush(stdin);
			scanf("%c", &res);
			if (tolower(res) == 's')
			{
				consulta.existe = 0;

				fseek(consultas, -(long)sizeof(Consulta), SEEK_CUR);

				fwrite(&consulta, sizeof(Consulta), 1, consultas);

				printf("Consulta removida com sucesso!\n\n");
				break;
			}
		}
	}
	fclose(consultas);
	if (!achou)
		printf("Consulta não encontrada\n\n");
}

void apagarq()
{

	Consulta consulta;
	FILE *consultas, *arq;

	consultas = fopen("consultas.dat", "r+b");
	arq = fopen("aux.bak", "wb");

	while (fread(&consulta, sizeof(Consulta), 1, consultas) == 1)
	{
		if (consulta.existe)
		{
			fwrite(&consulta, sizeof(Consulta), 1, arq);
		}
	}
	fclose(consultas);
	fclose(arq);

	remove("consultas.dat");

	rename("aux.bak", "consultas.dat");

	getch();
}

void mapa()
{
	printf("\nMAPA DE HORÁRIOS\n");

	int achou;
	Data data;
	Consulta consulta;
	FILE *consultas;

	printf("Digite a data pra saber as consultas do dia (formato dd/mm/aaaa): ");
	scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

	consultas = fopen("consultas.dat", "r+b");

	if (!consultas)
	{
		printf("\nErro ao abrir arquivo de consultas\n\n");
		return;
	}

	while (fread(&consulta, sizeof(consulta), 1, consultas))
	{
		int mesmaData = (consulta.data.dia == data.dia) && (consulta.data.mes == data.mes) && (consulta.data.ano == data.ano);
		if (mesmaData)
		{
			if (consulta.existe)
			{
				achou = 1;
				consulta.nome_cliente[strcspn(consulta.nome_cliente, "\n")] = 0;
				printf("Consulta de %s, codigo %d, as %d:%d  \n", &consulta.nome_cliente, (&consulta)->cod_cliente, (&consulta)->hora.horas, (&consulta)->hora.minutos);
			}
		}
	}

	if (!achou)
		printf("Nao ha consulta nessa data.\n\n");
	else
		printf("\n\n");
}

void consulta()

{
	int c_cliente, achou;
	char nome_cliente[50];
	Data hoje;
	Consulta consulta;
	FILE *consultas, *clientes;
	achou = 0;

	printf("Digite a data de hoje:\n");
	scanf("%d/%d/%d", &hoje.dia, &hoje.mes, &hoje.ano);

	printf("Digite o nome do cliente:\n");
	fgets(nome_cliente, 49, stdin);
	fflush(stdin);

	printf("Digite o codigo do cliente:\n");
	scanf("%d", &c_cliente);

	printf("Consultas de %s\n", nome_cliente);

	clientes = fopen("clientes.dat", "rb");

	if (!procura_cliente(clientes, c_cliente))
	{
		printf("\nCliente nao encontrado. Cliente precisa estar cadastrado ter consultas.\n\n");
		return;
	}
	fclose(clientes);
	consultas = fopen("consultas.dat", "rb");
	printf("Consultas de %s\n", nome_cliente);

	while (fread(&consulta, sizeof(Consulta), 1, consultas) == 1)
	{
		achou = 1;
		struct tm data1 = {0};
		struct tm data2 = {0};

		data1.tm_year = hoje.ano - 1900;
		data1.tm_mday = hoje.dia;
		data1.tm_mon = hoje.mes - 1;

		data2.tm_year = consulta.data.ano - 1900;
		data2.tm_mday = consulta.data.dia;
		data2.tm_mon = consulta.data.mes - 1;

		time_t segundos1 = mktime(&data1);
		time_t segundos2 = mktime(&data2);

		// para garantir que são consultas passadas
		double diferenca = difftime(segundos1, segundos2);

		if (diferenca > 0 && (consulta.cod_cliente == c_cliente) && (consulta.existe == 1))
		{
			printf("Data %d/%d/%d\n", consulta.data.dia, consulta.data.mes, consulta.data.ano);
			printf("horas: %d:%d\n", consulta.hora.horas, consulta.hora.minutos);
		}
	}
	if (!achou)
		printf("Nao ha consultas anteriores para esse cliente.");

	printf("\n\n");
}

int DifMes(Data atual, Data marcada)
{
	int difAnos = atual.ano - marcada.ano;
	int difMeses = atual.mes - marcada.mes;
	int difDias = atual.dia - marcada.dia;

	if (difDias < 0)
	{
		difMeses--;
		difDias += 30;
	}

	difMeses += difAnos * 12;

	return difMeses;
}
void meses()
{
	FILE *consultas;
	FILE *clientes;

	consultas = fopen("consultas.dat", "rb");
	clientes = fopen("clientes.dat", "rb");

	if (!consultas || !clientes)
	{
		printf("Erro ao abrir arquivos de consultas ou clientes.\n");
		return;
	}

	Data hoje;
	printf("Insira a data de hoje (formato dd/mm/aaaa): ");
	scanf("%d/%d/%d", &hoje.dia, &hoje.mes, &hoje.ano);
	Consulta consulta;
	Cliente cliente;

	printf("Lista de clientes com mais de 50 anos atendidos ha mais de 6 meses:\n\n");

	while (fread(&cliente, sizeof(Cliente), 1, clientes))
	{
		if (cliente.idade <= 50)
			continue;
		while (fread(&consulta, sizeof(Consulta), 1, consultas))
		{
			if (consulta.cod_cliente == cliente.cod && consulta.existe)
			{
				int diferencaMeses = DifMes(hoje, consulta.data);
				if (diferencaMeses <= 6)
				{
					break;
				}
				printf("Nome: %s Telefone: %d\n", cliente.nome, cliente.telefone);
				break;
			}
		}
	}
	rewind(consultas);

	fclose(consultas);
	fclose(clientes);
}

int menu()
{
	char aux;

	printf("Selecione uma opcao abaixo:\n");
	printf("(1) Cadastrar cliente\n");
	printf("(2) Alterar dados de cliente\n");
	printf("(3) Marcar consulta\n");
	printf("(4) Desmarcar a consulta\n");
	printf("(5) Escrever mapa de horarios para um determinado dia\n");
	printf("(6) Escrever o nome e as datas em que um cliente foi consultado\n");
	printf("(7) Escrever o nome e o telefone de todos os clientes cuja ultima consulta ocorreu ha mais de 6 meses e que tem idade superior a 50 anos\n");
	printf("(8) Sair\n");

	fflush(stdin);
	aux = getchar();

	switch (aux)
	{
	case '1':
		cadastrar();
		break;
	case '2':
		alterar();
		break;
	case '3':
		marcar();
		break;
	case '4':
		desmarcar();
		break;
	case '5':
		mapa();
		break;
	case '6':
		consulta();
		break;
	case '7':
		meses();
		break;
	case '8':
		return -1;
	}
	return aux;
}

int main()
{
	setlocale(LC_ALL, "");
	int aux;

	do
	{
		aux = menu();
	} while (aux != -1);

	apagarq();
}
