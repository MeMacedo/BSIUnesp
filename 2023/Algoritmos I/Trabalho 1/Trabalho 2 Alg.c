/*Trabalho 2 de Algoritmos. Entregar um jogo
  Alunos: Melissa de Macedo
          Leonardo Vicentini
  Fizemos o jogo jokenpo, mas como era muito fácil, adicionamos uma historinha no meio pra poder usar mais do que aprendemos na disciplina.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <conio.h>

int choiceHandler()
{
    int wentWrong = rand() % 2;

    return wentWrong;
}

void printPuzzle()
{
    printf("Na sua casa, seus familiares preocupados te procuram mas só encontram uma peça de quebra-cabeça em cima de seu travisseiro.\n\n");
    printf("\t\t\t         _    \n"
           "\t\t\t     ___| |__ \n"
           "\t\t\t    (_      (_\n"
           "\t\t\t     _)  15  _)\n"
           "\t\t\t    (_______(\n\n");
    printf("\t\t\t\t.\n\t\t\t\t.\n\t\t\t\t.\n\t\t\t\t.\nMas tudo bem porque tudo não passou de um sonho, quem mandou ver tanto filme de terror no fim de semana? Bom dia!");
}

void printJokenpoLose(int wasOption)
{
    if (!wasOption)
    {
        printf("\nEssa não era uma opção... Sinto muito, mas sua jornada termina aqui.\n\n");
    }
    else
    {
        printf("Pelo visto a sorte não estava do seu lado. Espero que tenha tido uma boa vida\n\n");
    }

    printf("POW. Você houve o som da arma atirando. Uma dor excruciante toma o seu peito por alguns segundos,\n"
           "enquanto um boneco de rosto branco e espirais vermelhas na bochecha se aproxima com um triciclo. Então, tudo se torna preto.\n\n");

    printPuzzle();
}

void printJokenpoWin()
{
    printf("Parabéns, você venceu.\n"
           "*A porta atrás do homem a sua frente se abre e você sai correndo por ela. O céu está claro e o sol bate quente no seu rosto.\n"
           "Um barulho estridente começa a tocar ao fundo, cada vez mais próximo.\nTRIM\nTRIMM\nTRIMMMMMM\n"
           "É aí que você se dá conta: é o seu despertador; bom dia, preparado para mais um semana?");
}

void playJokenpo()
{
    printf("Parece que você chegou ao final do jogo! Escute bem: para sair daqui, você só precisa vencer.\nHá um homem em sua frente, com uma arma na mão e uma porta atrás dele. Ele te pede pra jogar jokenpo\n");

    int jogador = 0, pc;
    char jogadaPC[8];
    printf("Digite 1 para Tesoura, 2 para Pedra e 3 para Papel: ");
    scanf("%d", &jogador);

    printf("\n");
    pc = rand() % 3 + 1;

    if (pc == 1)
    {
        strcpy(jogadaPC, "Tesoura");
    }
    else if (pc == 2)
    {
        strcpy(jogadaPC, "Pedra");
    }
    else
    {
        strcpy(jogadaPC, "Papel");
    }

    if (jogador < 1 || jogador > 3)
    {
        printJokenpoLose(0);
        return;
    }

    printf("Seu adversário jogou %s", jogadaPC);

    if (jogador == pc)
    {

        printJokenpoLose(1);
    }
    else if (jogador == 1)
    {
        if (pc == 2)
        {
            printJokenpoLose(1);
        }
    }
    else if (jogador == 2)
    {
        if (pc == 3)
        {
            printJokenpoLose(1);
        }
    }
    else if (jogador == 3)
    {
        if (pc == 1)
        {
            printJokenpoLose(1);
        }
    }
    else
    {

        printJokenpoWin();
    }
}

int labSecondChoice()

{
    int c;
    printf("Ao perambular pelo local, você encontra duas portas com a placa de saída em cima. ");

    printf("\n"
           "\t   ,-' ;  ! `-.\t           ,-' ;  ! `-.\n"
           "\t  / :  !  :  . \\\t  / :  !  :  . \\\n"
           "\t |_ ;   __:  ;  |\t |_ ;   __:  ;  |\n"
           "\t |  .  :)(.  !  |\t |  .  :)(.  !  |\n"
           "\t |     (  )  _  |\t |     (  )  _  |\n"
           "\t |  :  ;`'  (_) (\t |  :  ;`'  (_) (\n"
           "\t |  :  :  .     |\t |  :  :  .     |\n"
           "\t |  !  ,  ;  ;  |\t |  !  ,  ;  ;  |\n"
           "\t |  .  .  :  :  |\t |  .  .  :  :  |\n"
           "\t |\" .  |  :  .  |\t |\" .  |  :  .  |\n"
           "\t |____.----.____|\t |____.----.____|\n");

    printf("Use as teclas do teclado para decidir em qual porta entrar\n\n");

    c = getch();
    if (c == 0 || c == 0xE0)
        c = getch();

    if (c == 77)
    {
        printf("A porta se abre, revelando um longo corredor escuro.\n\n");
        return 0;
    }
    else
    {
        printf("Você passa pela porta e cai direto em buraco. Fim de jogo.\n");
        printPuzzle();
        return 1;
    }
}

int labFirstChoice()
{
    int choice, wentWrong;

    printf("Sem que seja notado, alguém chega por trás de você e te desacorda. Horas passam até que você acorde num banheiro sujo de rodoviária, com um dos pés algemado a uma privada.\n"
           "O cheiro indica que o lugar não é limpo há dias e não há vestígios de que alguém sequer tenha passado por lá nos últimos meses. Na sua frente, uma serra. O que você vai fazer? \n\n");

    printf("\t\t                                           __\n"
           "\t\t                               _____....--' .'\n"
           "\t\t                     ___...---'._ o      -`(\n"
           "\t\t           ___...---'            \\   .--.  `)\n"
           "\t\t ___...---'                      |   \\   \\ `|\n"
           "\t\t|                                |o o |  |  |\n"
           "\t\t|                                 \\___'.-`.  '.\n"
           "\t\t|                                      |   `---'\n"
           "\t\t'^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^'\n");

    printf("Digite 1 para serrar seu pé e qualquer outro número para esperar por ajuda: ");

    scanf("%d", &choice);

    wentWrong = choiceHandler();

    if (choice == 1)
    {
        if (wentWrong)
        {
            printf("\nO corte foi grande demais. Mesmo saindo do banheiro, você se sente cada vez mais fraco ao caminhar pelos corredores do que parece o subsolo da tal rodoviária.\n"
                   "Pela perda de sangue, você desmaia e com o passar do tempo, perece sozinho nesse lugar escuro.\n\n");
            printPuzzle();
        }
        else
        {
            printf("\nVocê percebe que as correntes da algema estão tão enfurrujadas que é possível cortar. Escapando delas, você sai pela porta do banheiro e agora se vê caminhado pelo que parece o subsolo da rodoviária.\n");
        }
    }
    else
    {
        if (wentWrong)
        {
            printf("\nA rodoviária já tinha sido abandonada há muito tempo. Você esperou, esperou e esperou, mas ninguém veio.\n\n");
            printPuzzle();
        }
        else
        {
            printf("\nAlgumas horas depois, uma moça usando um avental cinza e empurrando um carrinho com utensílios de limpeza abre a porta enquanto reclama do serviço.\n"
                   "Ela te encontra e o ajuda a escapar, enquanto conta que faz meses desde que a empresa rodoviária demitiu o último zelador.\n\n"
                   "Ao escapar de lá, Um barulho estridente começa a tocar ao fundo, cada vez mais próximo.\nTRIM\nTRIMM\nTRIMMMMMM\n"
                   "É aí que você se dá conta: é o seu despertador; bom dia, preparado para mais uma semana?");

            wentWrong = 1;
        }
    }

    return wentWrong;
}

void startLabirinth()
{

    int firstWentWrong = labFirstChoice();

    if (firstWentWrong)
    {
        return;
    }

    int secondWentWrong = labSecondChoice();

    if (secondWentWrong)
    {
        return;
    }

    playJokenpo();
}

void initGame()
{
    char resp;

    printf("\t\t─────▄██▀▀▀▀▀▀▀▀▀▀▀▀▀██▄─────\n"
           "\t\t────███───────────────███────\n"
           "\t\t───███─────────────────███───\n"
           "\t\t──███───▄▀▀▄─────▄▀▀▄───███──\n"
           "\t\t─████─▄▀────▀▄─▄▀────▀▄─████─\n"
           "\t\t─████──▄████─────████▄──█████\n"
           "\t\t█████─██▓▓▓██───██▓▓▓██─█████\n"
           "\t\t█████─██▓█▓██───██▓█▓██─█████\n"
           "\t\t█████─██▓▓▓█▀─▄─▀█▓▓▓██─█████\n"
           "\t\t████▀──▀▀▀▀▀─▄█▄─▀▀▀▀▀──▀████\n"
           "\t\t███─▄▀▀▀▄────███────▄▀▀▀▄─███\n"
           "\t\t███──▄▀▄─█──█████──█─▄▀▄──███\n"
           "\t\t███─█──█─█──█████──█─█──█─███\n"
           "\t\t███─█─▀──█─▄█████▄─█──▀─█─███\n"
           "\t\t███▄─▀▀▀▀──█─▀█▀─█──▀▀▀▀─▄███\n"
           "\t\t████─────────────────────████\n"
           "\t\t─███───▀█████████████▀───████\n"
           "\t\t─███───────█─────█───────████\n"
           "\t\t─████─────█───────█─────█████\n"
           "\t\t───███▄──█────█────█──▄█████─\n"
           "\t\t─────▀█████▄▄███▄▄█████▀─────\n"
           "\t\t──────────█▄─────▄█──────────\n");
    printf("Olá, olá, você aí... Deseja jogar um jogo? (S/n)\n");

    scanf("%c", &resp);

    switch (resp)
    {
    case 'S':
    case 's':
        printf("\nMuito bem. Preste bem atenção às regras: \n\n");
        break;
    default:
        printf("\nTentando fugir? Não me lembro de dar essa opção. Se prepare para o jogo da sua vida: \n\n");
    }

    printf("Você está prestes a entrar em um labirinto, onde a cada esquina você pode encontrar novos perigos. Seu desafio é sair vivo. Boa sorte.\n\n");
}

int main()
{
    initGame();

    startLabirinth();

    printf("\nFIM ;)");
}
