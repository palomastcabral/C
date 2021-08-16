/* Programa para a realização de cálculos de funções estudadas em Cálculo I (em andamento)
    1. Função afim
    2. Função quadrática
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

    strcpy(mensagem, "CALCULAR FUNÇÕES");
    imprimirInterface(mensagem);
    printf("\n 1. Afim");
    printf("\n 2. Quadrática");
    printf("\n 0. Sair");
    printf("\n\n -> Opção: ");
    return;
}

void imprimirTelaFuncaoEscolhida(int opcaoMenuInicial, int topicoEscolhido)
{
    char mensagem[50];

    switch(opcaoMenuInicial)
    {
        case 1: do
                {
                    strcpy(mensagem, "CALCULAR FUNÇÃO AFIM");
                    imprimirInterface(mensagem);
                    imprimirDefinicaoFuncao(opcaoMenuInicial);
                    imprimirTopicoMenuSecundario(opcaoMenuInicial);  // função ainda será alterada
                    lerTopicoFuncaoEscolhida(&topicoEscolhido);
                }
                while(topicoEscolhido != 0);
                break;
        case 2: strcpy(mensagem, "CALCULAR FUNÇÃO QUADRÁTICA");
                imprimirInterface(mensagem);
                imprimirDefinicaoFuncao(opcaoMenuInicial);
                imprimirTopicoMenuSecundario(opcaoMenuInicial);  // função ainda será alterada
                lerTopicoFuncaoEscolhida(&topicoEscolhido);
                break;
        case 0: printf("\n\n [Sistema encerrado]\n\n");
                //system("pause");
                break;
        default:
                printf("\n\a [Opção inválida!]");
                sleep(1);
                break;
    }
    return;
}

void imprimirTopicoMenuSecundario(int opcaoMenuInicial)  // função ainda será alterada
{
    switch (opcaoMenuInicial)
    {
        case 1: // em construção
                printf("\n 0. Voltar\n");
                printf("\n  -> Opção:");
                break;
        case 2: // em construção
                printf("\n 0. Voltar\n");
                printf("\n  -> Opção: ");

        default:
                break;
     }
}

void imprimirDefinicaoFuncao(int opcaoMenuInicial)
{
    switch(opcaoMenuInicial)
    {
        case 1: printf("f(x) = a.x + b  |  a,b -> R, a diferente de 0\n\n");  //Função Afim
                break;
        case 2: printf("f(x) = a.x + b + c |  a,b,c -> R, a diferente de 0\n\n");  //Função Quadrática
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