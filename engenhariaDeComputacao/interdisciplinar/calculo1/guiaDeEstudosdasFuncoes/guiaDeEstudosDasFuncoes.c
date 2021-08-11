/* Programa para realizar cálculos de funções estudadas em Cálculo I (em andamento)
    1. Função potência
    2. Função afim
    3. Função quadrática
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

    strcpy(mensagem, "CALCULAR FUNÇÕES");
    imprimirInterface(mensagem);
    printf("\n 1. Introdução às funções");
    printf("\n 2. Potência");
    printf("\n 3. Afim");
    printf("\n 4. Quadrática");
    printf("\n 0. Sair");
    printf("\n\n -> Opção: ");
    return;
}

void imprimirTelaFuncaoEscolhida(int opcaoMenuInicial, int topicoEscolhido)
{
    char mensagem[50];

    switch(opcaoMenuInicial)
    {
        case 1: strcpy(mensagem, "INTRODUÇÃO ÀS FUNÇÕES");
                imprimirInterface(mensagem);
                imprimirMenuIntroFuncoes();
                lerTopicoFuncaoEscolhida(&topicoEscolhido);
                break;
        case 2: strcpy(mensagem, "CALCULAR FUNÇÃO POTÊNCIA");
                imprimirInterface(mensagem);
                imprimirDefinicaoFuncao(opcaoMenuInicial);
                //Implementar: criar função para receber valores
                //Implementar ciclo com mesma lei
                break;
        case 3: do
                {
                    strcpy(mensagem, "CALCULAR FUNÇÃO AFIM");
                    imprimirInterface(mensagem);
                    imprimirDefinicaoFuncao(opcaoMenuInicial);
                    imprimirMenuFuncaoAfim();
                    lerTopicoFuncaoEscolhida(&topicoEscolhido);
                    imprimirTopicoFuncaoAfim(topicoEscolhido);
                }
                while(topicoEscolhido != 0);
                break;
        case 4: strcpy(mensagem, "CALCULAR FUNÇÃO QUADRÁTICA");
                imprimirInterface(mensagem);
                imprimirDefinicaoFuncao(opcaoMenuInicial);
                break;
        case 0: printf("\n\n [Sistema encerrado]\n\n");
                break;
        default:
                printf("\n\a [Opção inválida!]");
                sleep(1);
                break;
    }
    return;
}

void imprimirMenuIntroFuncoes()
{
    printf("\n 1. O que são funções?");
    printf("\n 2. Condição para função");
    printf("\n 3. Maneiras de representação");
    printf("\n 4. Domínio");
    printf("\n 5. Restrições no domínio");
    printf("\n 6. Contradomínio");
    printf("\n 7. Imagem");
    printf("\n 0. Voltar\n");
    printf("\n  -> Tópico:");
}

void imprimirMenuFuncaoAfim()
{
    printf("\n|Escolha um tópico:\n");
    printf("\n 1. Introdução");
    printf("\n 2. Domínio e contradomínio");
    printf("\n 3. Gráficos da função afim");
    printf("\n 4. Coeficientes angular e linear");
    printf("\n 5. Encontrando a e b");
    printf("\n 6. Zero da função e interseção com o eixo y");
    printf("\n 7. Estudo do sinal");
    printf("\n 0. Voltar\n");
    printf("\n  -> Tópico: ");
}

void imprimirDefinicaoFuncao(int opcaoMenuInicial)
{
    switch(opcaoMenuInicial)
    {
        case 2: printf("f(x) = k.(x^a)  |  k,a -> R*\n\n");  //Função Potência
                break;
        case 3: printf("f(x) = a.x + b  |  a,b -> R, a diferente de 0\n\n");  //Função Afim
                break;
        case 4: printf("f(x) = a.x + b + c |  a,b,c -> R, a diferente de 0\n\n");  //Função Quadrática
                break;
    }
    return;
}

void imprimirTopicoIntroFuncoes(int topicoEscolhido)  //Imprimir tela com o tópico escolhido do menu de introdução às funções
{
    char mensagem[40];

    switch(topicoEscolhido)
    {
        case 1: strcpy(mensagem, "DEFINIÇÃO DE FUNÇÃO");
                imprimirInterface(mensagem);
                printf("\n -> Função é uma relação de dependência entre duas variáveis.\n");
                break;
        case 2: strcpy(mensagem, "CONDIÇÃO PARA FUNÇÃO");
                imprimirInterface(mensagem);
                break;
        case 3: strcpy(mensagem, "MANEIRAS DE REPRESENTAÇÃO");
                imprimirInterface(mensagem);
                break;
        case 4: strcpy(mensagem, "DOMÍNIO");
                imprimirInterface(mensagem);
                break;
        case 5: strcpy(mensagem, "RESTRIÇÕES NO DOMÍNIO");
                imprimirInterface(mensagem);
                break;
        case 6: strcpy(mensagem, "CONTRADOMÍNIO");
                imprimirInterface(mensagem);
                break;
        case 7: strcpy(mensagem, "IMAGEM");
                imprimirInterface(mensagem);
                break;
        case 0:
                break;
        default:printf("\n\a [Opção inválida]\n");
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

void imprimirTopicoFuncaoAfim(int topicoEscolhido)  //Imprimir tela com o tópico escolhido do menu da função Afim
{
    char mensagem[40];

    switch(topicoEscolhido)
    {
        case 1: strcpy(mensagem, "INTRODUÇÃO");
                imprimirInterface(mensagem);
                break;
        case 2: strcpy(mensagem, "DOMÍNIO E CONTRADOMÍNIO");
                imprimirInterface(mensagem);
                break;
        case 3: strcpy(mensagem, "GRÁFICOS");
                imprimirInterface(mensagem);
                break;
        case 4: strcpy(mensagem, "COEFICIENTES ANGULAR E LINEAR");
                imprimirInterface(mensagem);
                break;
        case 5: strcpy(mensagem, "ENCONTRANDO A E B");
                imprimirInterface(mensagem);
                break;
        case 6: strcpy(mensagem, "ZERO DA FUNÇÃO E INTERSEÇÃO COM O EIXO Y");
                imprimirInterface(mensagem);
                break;
        case 7: strcpy(mensagem, "ESTUDO DO SINAL");
                imprimirInterface(mensagem);
                break;
        case 0:
                break;
        default:printf("\n\a [Opção inválida]\n");
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