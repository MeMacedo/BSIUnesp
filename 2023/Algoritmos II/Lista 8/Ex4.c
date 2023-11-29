#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Entregando agora com alguns bons problemas ainda. Depois da aula tento reentregar*/

typedef struct
{
    char nome[50];
    double tel;
    int estadoSaude;
} Paciente;

int upperSearch(int *estadosSaude, int inicio, int final, int k)
{
    int l = inicio, r = final - 1;

    while (l < r)
    {
        int m = (l + r) / 2;
        int aux = estadosSaude[m];

        if (k >= aux)
        {
            l = m + 1;
        }
        else
            r = m;
    }
    return r;
}

int lowerSearch(int *estadosSaude, int inicio, int final, int k)
{
    int l = inicio, r = final - 1;
    int lower = 0;
    while (l < r)
    {
        int m = (l + r) / 2;
        int aux = estadosSaude[m];
        if (k > aux)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return l;
}

void adicionaPaciente(int *estadosSaude, Paciente *pacientes, Paciente paciente, int *final, int *inicial)
{
    if (paciente.estadoSaude == 1)
    {
        if (*final == 99)
            return;
        estadosSaude[*final] = paciente.estadoSaude;
        pacientes[*final] = paciente;
        (*final)++;
    }
    if (paciente.estadoSaude == 3)
    {
        if (*inicial == 0)
            return;
        int lower = lowerSearch(estadosSaude, *inicial, *final, 2);
        for (int i = *inicial; i < lower; i++)
        {
            estadosSaude[i - 1] = estadosSaude[i];
            pacientes[i - 1] = pacientes[i];
        }
        estadosSaude[lower - 1] = 3;
        estadosSaude[lower - 1] = 3;
        (*inicial)--;
    }
    if (paciente.estadoSaude == 2)
    {
        if (*inicial == 0)
            return;
        int lower = lowerSearch(estadosSaude, *inicial, *final, 1);
        for (int i = *inicial; i < lower; i++)
        {
            estadosSaude[i - 1] = estadosSaude[i];
            pacientes[i - 1] = pacientes[i];
        }
        estadosSaude[lower - 1] = 3;
        estadosSaude[lower - 1] = 3;
        (*inicial)--;
    }
}

int main()
{
    char r;
    Paciente paciente;
    int estadosSaude[100];
    Paciente pacientes[100];
    int final = 100 / 2;
    int inicial = 100 / 2;
    printf("Deseja adicionar um paciente a lista? (s/n): ");
    scanf("%c", &r);
    fflush(stdin);

    if (tolower(r) != 's')
        return 0;

    do
    {
        printf("Escreva o nome do paciente: ");
        fgets(&(paciente.nome), sizeof(paciente.nome) - 1, stdin);
        printf("Escreva o telefone do paciente: ");
        scanf("%lf", &(paciente.tel));
        printf("Agora qual o estado dele? regular = 1; ruim = 2; péssimo=3;");
        scanf("%d", &(paciente.estadoSaude));

        fflush(stdin);

        adicionaPaciente(estadosSaude, pacientes, paciente, &final, &inicial);

        printf("Deseja adicionar mais um paciente a lista? (s/n): ");
        scanf("%c", &r);
        fflush(stdin);
    } while (tolower(r) == 's');

    return 0;
}
