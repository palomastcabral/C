/* Programa para realizar c�lculos de fun��es estudadas em C�lculo I (em andamento)
    1. Fun��o pot�ncia
    2. Fun��o afim
    3. Fun��o quadr�tica
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
void imprimirMenuIntroFuncoes();
void imprimirMenuFuncaoAfim();
void imprimirDefinicaoFuncao(int opcaoMenuInicial);
void imprimirTopicoIntroFuncoes(int topicoEscolhido);
void imprimirTopicoFuncaoAfim(int topicoEscolhido);
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
    printf("\n 1. Introdu��o �s fun��es");
    printf("\n 2. Pot�ncia");
    printf("\n 3. Afim");
    printf("\n 4. Quadr�tica");
    printf("\n 0. Sair");
    printf("\n\n -> Op��o: ");
    return;
}

void imprimirTelaFuncaoEscolhida(int opcaoMenuInicial, int topicoEscolhido)
{
    char mensagem[50];

    switch(opcaoMenuInicial)
    {
        case 1: strcpy(mensagem, "INTRODU��O �S FUN��ES");
                imprimirInterface(mensagem);
                imprimirMenuIntroFuncoes();
                lerTopicoFuncaoEscolhida(&topicoEscolhido);
                break;
        case 2: strcpy(mensagem, "CALCULAR FUN��O POT�NCIA");
                imprimirInterface(mensagem);
                imprimirDefinicaoFuncao(opcaoMenuInicial);
                //Implementar: criar fun��o para receber valores
                //Implementar ciclo com mesma lei
                break;
        case 3: do
                {
                    strcpy(mensagem, "CALCULAR FUN��O AFIM");
                    imprimirInterface(mensagem);
                    imprimirDefinicaoFuncao(opcaoMenuInicial);
                    imprimirMenuFuncaoAfim();
                    lerTopicoFuncaoEscolhida(&topicoEscolhido);
                    imprimirTopicoFuncaoAfim(topicoEscolhido);
                }
                while(topicoEscolhido != 0);
                break;
        case 4: strcpy(mensagem, "CALCULAR FUN��O QUADR�TICA");
                imprimirInterface(mensagem);
                imprimirDefinicaoFuncao(opcaoMenuInicial);
                break;
        case 0: printf("\n\n [Sistema encerrado]\n\n");
                break;
        default:
                printf("\n\a [Op��o inv�lida!]");
                sleep(1);
                break;
    }
    return;
}

void imprimirMenuIntroFuncoes()
{
    printf("\n 1. O que s�o fun��es?");
    printf("\n 2. Condi��o para fun��o");
    printf("\n 3. Maneiras de representa��o");
    printf("\n 4. Dom�nio");
    printf("\n 5. Restri��es no dom�nio");
    printf("\n 6. Contradom�nio");
    printf("\n 7. Imagem");
    printf("\n 0. Voltar\n");
    printf("\n  -> T�pico:");
}

void imprimirMenuFuncaoAfim()
{
    printf("\n|Escolha um t�pico:\n");
    printf("\n 1. Introdu��o");
    printf("\n 2. Dom�nio e contradom�nio");
    printf("\n 3. Gr�ficos da fun��o afim");
    printf("\n 4. Coeficientes angular e linear");
    printf("\n 5. Encontrando a e b");
    printf("\n 6. Zero da fun��o e interse��o com o eixo y");
    printf("\n 7. Estudo do sinal");
    printf("\n 0. Voltar\n");
    printf("\n  -> T�pico: ");
}

void imprimirDefinicaoFuncao(int opcaoMenuInicial)
{
    switch(opcaoMenuInicial)
    {
        case 2: printf("f(x) = k.(x^a)  |  k,a -> R*\n\n");  //Fun��o Pot�ncia
                break;
        case 3: printf("f(x) = a.x + b  |  a,b -> R, a diferente de 0\n\n");  //Fun��o Afim
                break;
        case 4: printf("f(x) = a.x + b + c |  a,b,c -> R, a diferente de 0\n\n");  //Fun��o Quadr�tica
                break;
    }
    return;
}

void imprimirTopicoIntroFuncoes(int topicoEscolhido)  //Imprimir tela com o t�pico escolhido do menu de introdu��o �s fun��es
{
    char mensagem[40];

    switch(topicoEscolhido)
    {
        case 1: strcpy(mensagem, "DEFINI��O DE FUN��O");
                imprimirInterface(mensagem);
                printf("\n -> Fun��o � uma rela��o de depend�ncia entre duas vari�veis.\n");
                break;
        case 2: strcpy(mensagem, "CONDI��O PARA FUN��O");
                imprimirInterface(mensagem);
                break;
        case 3: strcpy(mensagem, "MANEIRAS DE REPRESENTA��O");
                imprimirInterface(mensagem);
                break;
        case 4: strcpy(mensagem, "DOM�NIO");
                imprimirInterface(mensagem);
                break;
        case 5: strcpy(mensagem, "RESTRI��ES NO DOM�NIO");
                imprimirInterface(mensagem);
                break;
        case 6: strcpy(mensagem, "CONTRADOM�NIO");
                imprimirInterface(mensagem);
                break;
        case 7: strcpy(mensagem, "IMAGEM");
                imprimirInterface(mensagem);
                break;
        case 0:
                break;
        default:printf("\n\a [Op��o inv�lida]\n");
                sleep(1);
                break;
    }
    if((topicoEscolhido >= 1) && (topicoEscolhido <= 7))
    {
        printf("\n\n [Pressione qualquer tecla para voltar]\n");
        getch();
    }
    return;
}

void imprimirTopicoFuncaoAfim(int topicoEscolhido)  //Imprimir tela com o t�pico escolhido do menu da fun��o Afim
{
    char mensagem[40];

    switch(topicoEscolhido)
    {
        case 1: strcpy(mensagem, "INTRODU��O");
                imprimirInterface(mensagem);
                break;
        case 2: strcpy(mensagem, "DOM�NIO E CONTRADOM�NIO");
                imprimirInterface(mensagem);
                break;
        case 3: strcpy(mensagem, "GR�FICOS");
                imprimirInterface(mensagem);
                break;
        case 4: strcpy(mensagem, "COEFICIENTES ANGULAR E LINEAR");
                imprimirInterface(mensagem);
                break;
        case 5: strcpy(mensagem, "ENCONTRANDO A E B");
                imprimirInterface(mensagem);
                break;
        case 6: strcpy(mensagem, "ZERO DA FUN��O E INTERSE��O COM O EIXO Y");
                imprimirInterface(mensagem);
                break;
        case 7: strcpy(mensagem, "ESTUDO DO SINAL");
                imprimirInterface(mensagem);
                break;
        case 0:
                break;
        default:printf("\n\a [Op��o inv�lida]\n");
                sleep(1);
                break;
    }
    if((topicoEscolhido >= 1) && (topicoEscolhido <= 7))
    {
        printf("\n\n [Pressione qualquer tecla para voltar]\n");
        getch();
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