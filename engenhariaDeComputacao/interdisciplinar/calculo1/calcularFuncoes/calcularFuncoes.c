/* Programa para a realiza��o de c�lculos de fun��es estudadas em C�lculo I (em andamento)
    1. Fun��o afim
    2. Fun��o quadr�tica
    ...*/
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>

void imprimirInterface(char mensagem[]);
void imprimirMenuInicial();
void imprimirTelaFuncaoEscolhida(int opcaoMenuInicial, int topicoEscolhido);
void imprimirTopicoMenuSecundario(int opcaoMenuInicial);
void imprimirDefinicaoFuncao(int opcaoMenuInicial);
void lerOpcaoMenuInicial(int *opcaoMenuInicialPtr);
void lerTopicoFuncaoEscolhida(int *topicoEscolhidoPtr);
float calcularDelta(float a, float b, float c);
void calcularFuncaoQuadratica(float delta, float a, float b, float *x1Ptr, float *x2Ptr);

int main()
{

    setlocale(LC_ALL, "");
    int opcaoMenuInicial, topicoEscolhido;
    char mensagem[50];

    do
    {
        imprimirInterface(mensagem);
        imprimirMenuInicial();
        lerOpcaoMenuInicial(&opcaoMenuInicial);
        imprimirTelaFuncaoEscolhida(opcaoMenuInicial, topicoEscolhido);
    }
    while(opcaoMenuInicial != 0);
    return 0;
}

void imprimirInterface(char mensagem[])
{
    int contador, tamanhoTituloDaTela;

    tamanhoTituloDaTela = strlen(mensagem);
    system("cls");
    for(contador=0; contador<(tamanhoTituloDaTela*2); contador++)
    {
        printf("=");
    }
    printf("\n");
    for(contador=0; contador<(tamanhoTituloDaTela/2); contador++)
    {
        printf(" ");
    }
    printf("%s\n", mensagem);
    for(contador=0; contador<(tamanhoTituloDaTela*2); contador++)
    {
        printf("=");
    }
    printf("\n\n");
    return;
}

void imprimirMenuInicial()
{
    char mensagem[40];

    strcpy(mensagem, "CALCULAR FUN��ES");
    imprimirInterface(mensagem);
    printf("\n 1. Afim");
    printf("\n 2. Quadr�tica");
    printf("\n 0. Sair");
    printf("\n\n -> Op��o: ");
    return;
}

void imprimirTelaFuncaoEscolhida(int opcaoMenuInicial, int topicoEscolhido)
{
    char mensagem[50];

    switch(opcaoMenuInicial)
    {
        case 1: do
                {
                    strcpy(mensagem, "CALCULAR FUN��O AFIM");
                    imprimirInterface(mensagem);
                    imprimirDefinicaoFuncao(opcaoMenuInicial);
                    imprimirTopicoMenuSecundario(opcaoMenuInicial);  // fun��o ainda ser� alterada
                    lerTopicoFuncaoEscolhida(&topicoEscolhido);
                }
                while(topicoEscolhido != 0);
                break;
        case 2: strcpy(mensagem, "CALCULAR FUN��O QUADR�TICA");
                imprimirInterface(mensagem);
                imprimirDefinicaoFuncao(opcaoMenuInicial);
                imprimirTopicoMenuSecundario(opcaoMenuInicial);  // fun��o ainda ser� alterada
                lerTopicoFuncaoEscolhida(&topicoEscolhido);
                break;
        case 0: printf("\n\n [Sistema encerrado]\n\n");
                //system("pause");
                break;
        default:
                printf("\n\a [Op��o inv�lida!]");
                sleep(1);
                break;
    }
    return;
}

void imprimirTopicoMenuSecundario(int opcaoMenuInicial)  // fun��o ainda ser� alterada
{
    switch (opcaoMenuInicial)
    {
        case 1: // em constru��o
                printf("\n 0. Voltar\n");
                printf("\n  -> Op��o:");
                break;
        case 2: // em constru��o
                printf("\n 0. Voltar\n");
                printf("\n  -> Op��o: ");

        default:
                break;
     }
}

void imprimirDefinicaoFuncao(int opcaoMenuInicial)
{
    switch(opcaoMenuInicial)
    {
        case 1: printf("f(x) = a.x + b  |  a,b -> R, a diferente de 0\n\n");  //Fun��o Afim
                break;
        case 2: printf("f(x) = a.x + b + c |  a,b,c -> R, a diferente de 0\n\n");  //Fun��o Quadr�tica
                break;
    }
    return;
}

void lerOpcaoMenuInicial(int *opcaoMenuInicialPtr)
{
    scanf("%d", &*opcaoMenuInicialPtr);
}

void lerTopicoFuncaoEscolhida(int *topicoEscolhidoPtr)
{
    scanf("%d", &*topicoEscolhidoPtr);
}

float calcularDelta(float a, float b, float c)
{
    int delta;

    delta = pow(b,2) - 4*a*c;
    return delta;
}

void calcularFuncaoQuadratica(float delta, float a, float b, float *x1Ptr, float *x2Ptr)
{
    *x1Ptr = (-b + sqrt(delta)) / 2*a;
    *x2Ptr = (-b - sqrt(delta)) / 2*a;
    return;
}