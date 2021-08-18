#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void imprimirInterface(char mensagem[]);
void imprimirOpcoes();
void imprimirMatrizEscolhida(int opcaoEscolhida);
void imprimirMatrizLinha();
void imprimirMatrizNula();
void imprimirMatrizQuadrada();
void imprimirMatrizTriangSuperior();
void imprimirMatrizTriangInferior();
void imprimirMatrizDiagonal();
void imprimirMatrizEscalar();
void imprimirMatrizIdentidade();
void imprimirMatrizTransposta();

int main()
{
    setlocale(LC_ALL, "");
    int opcaoEscolhida;
    char mensagem[30];

    do{
        srand(time(NULL));
        strcpy(mensagem, "TIPOS DE MATRIZES");
        imprimirInterface(mensagem);
        imprimirOpcoes();
        scanf("%d", &opcaoEscolhida);
        imprimirMatrizEscolhida(opcaoEscolhida);
    }
    while(opcaoEscolhida != 0);
    return 0;
}

void imprimirInterface(char mensagem[])
{
    int contador, tamanhoTituloDaTela, qntdCaracteresBorda;

    tamanhoTituloDaTela = strlen(mensagem);
    system("cls");
    for(contador=0; contador<(tamanhoTituloDaTela * 2); contador++)
    {
        printf("=");
    }
    printf("\n");
    for(contador=0; contador<(tamanhoTituloDaTela/2); contador++)
    {
        printf(" ");
    }
    printf("%s\n", mensagem);
    for(contador=0; contador<(tamanhoTituloDaTela * 2); contador++)
    {
        printf("=");
    }
    printf("\n\n");
    return;
}

void imprimirOpcoes()
{
    printf("\n 01. Linha");
    printf("\n 02. Coluna");
    printf("\n 03. Nula");
    printf("\n 04. Quadrada");
    printf("\n 05. Triangular superior");
    printf("\n 06. Triangular inferior");
    printf("\n 07. Diagonal");
    printf("\n 08. Escalar");
    printf("\n 09. Identidade");
    printf("\n 10. Transposta");
    printf("\n 00. Sair");
    printf("\n\n -> Opção: ");
    return;
}

void imprimirMatrizEscolhida(int opcaoEscolhida)
{
    char mensagem[30];

    switch(opcaoEscolhida)
    {
        case 1: strcpy(mensagem, "MATRIZ LINHA");
                imprimirInterface(mensagem);
                imprimirMatrizLinha();
                break;
        case 2: strcpy(mensagem, "MATRIZ COLUNA");
                imprimirInterface(mensagem);
                imprimirMatrizColuna();
                break;
        case 3: strcpy(mensagem, "MATRIZ NULA");
                imprimirInterface(mensagem);
                imprimirMatrizNula();
                break;
        case 4: strcpy(mensagem, "MATRIZ QUADRADA");
                imprimirInterface(mensagem);
                imprimirMatrizQuadrada();
                break;
        case 5: strcpy(mensagem, "MATRIZ TRIANGULAR SUPERIOR");
                imprimirInterface(mensagem);
                imprimirMatrizTriangSuperior();
                break;
        case 6: strcpy(mensagem, "MATRIZ TRIANGULAR INFERIOR");
                imprimirInterface(mensagem);
                imprimirMatrizTriangInferior();
                break;
        case 7: strcpy(mensagem, "MATRIZ DIAGONAL");
                imprimirInterface(mensagem);
                imprimirMatrizDiagonal();
                break;
        case 8: strcpy(mensagem, "MATRIZ ESCALAR");
                imprimirInterface(mensagem);
                imprimirMatrizEscalar();
                break;
        case 9: strcpy(mensagem, "MATRIZ IDENTIDADE");
                imprimirInterface(mensagem);
                imprimirMatrizIdentidade();
                break;
        case 10:strcpy(mensagem, "MATRIZ TRANSPOSTA");
                imprimirInterface(mensagem);
                imprimirMatrizTransposta();
                break;
        case 0: printf("\n\n [Sistema encerrado]\n\n");
                break;
        default:printf("\n\a [Opção inválida]");
                sleep(1);
                break;
    }
    if(opcaoEscolhida >= 1 && opcaoEscolhida <=10)
    {
        printf("\n\n [Pressione qualquer tecla para voltar]");
        getch();
    }
    return;
}

void imprimirMatrizLinha()
{
    int totalColunas, indiceLinha=1, indiceColuna;

    printf("\n|Possui 1 linha e n colunas\n\n");
    totalColunas = (rand() % 9) + 1;
    printf(" A1x%d:\n\n", totalColunas);
    printf("  [ ");
    for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
    {
        printf("a%d%d ", indiceLinha, indiceColuna);
    }
    printf("]\n");
    return;
}

void imprimirMatrizColuna()
{
    int totalLinhas, indiceLinha, indiceColuna=1;

    printf("\n|Possui m linhas e 1 coluna\n\n");
    totalLinhas = (rand() % 9) + 1;
    printf(" A%dx1:\n\n", totalLinhas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ a%d%d ]\n", indiceLinha, indiceColuna);
    }
    return;
}

void imprimirMatrizNula()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1;

    printf("\n|Todos os elementos são nulos\n\n");
    totalLinhas = (rand() % 9) + 1;
    totalColunas = (rand() % 9) + 1;
    printf(" A%dx%d:\n\n", totalLinhas, totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            printf("0 ", indiceLinha, indiceColuna);
        }
        printf("]\n");
    }
    return;
}

void imprimirMatrizQuadrada()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1;

    printf("\n|Número de linhas é igual ao número de colunas (m=n)\n\n");
    totalColunas = (rand() % 9) + 1;
    totalLinhas = totalColunas;
    printf(" A%dx%d:\n\n", totalLinhas, totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            printf("0 ", indiceLinha, indiceColuna);
        }
        printf("]\n");
    }
    return;
}

void imprimirMatrizTriangSuperior()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1, elementoNulo=0;

    printf("\n|Elementos abaixo da diagonal principal (i>j) são nulos\n\n");
    totalLinhas = (rand() % 8) + 2;
    totalColunas = totalLinhas;
    printf(" A%d%d:\n\n", totalLinhas, totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            if(indiceLinha > indiceColuna)
            {
                printf("%3d ", elementoNulo);
            }
            else
            {
                printf("a%d%d ", indiceLinha, indiceColuna);
            }
        }
        printf("]\n");
    }
    return;
}

void imprimirMatrizTriangInferior()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1, elementoNulo=0;

    printf("\n|Elementos acima da diagonal principal (i<j) são nulos\n\n");
    totalLinhas = (rand() % 8) + 2;
    totalColunas = totalLinhas;
    printf(" A%d%d:\n\n", totalLinhas, totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            if(indiceLinha < indiceColuna)
            {
                printf("%3d ", elementoNulo);
            }
            else
            {
                printf("a%d%d ", indiceLinha, indiceColuna);
            }
        }
        printf("]\n");
    }
    return;
}

void imprimirMatrizDiagonal()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1, elementoNulo=0;

    printf("\n|Todos os elementos fora da diagonal principal (i diferente de j) são nulos\n\n");
    totalLinhas = (rand() % 8) + 2;
    totalColunas = totalLinhas;
    printf(" A%d%d:\n\n", totalLinhas, totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            if(indiceLinha != indiceColuna)
            {
                printf("%3d ", elementoNulo);
            }
            else
            {
                printf("a%d%d ", indiceLinha, indiceColuna);
            }
        }
        printf("]\n");
    }
    printf("\n  Obs.: Os elementos da diagonal principal podem ser nulos (sendo também uma matriz nula e escalar)\n");
    return;
}

void imprimirMatrizEscalar()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1, escalarK;

    printf("\n|É uma matriz diagonal, sendo que elementos da diagonal principal (com i=j) são iguais a um escalar k\n\n");
    escalarK = rand() % 10;
    totalLinhas = (rand() % 8) + 2;
    totalColunas = totalLinhas;
    printf(" A%dx%d:\n\n", totalLinhas, totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            if(indiceLinha != indiceColuna)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", escalarK);
            }
        }
        printf("]\n");
    }
    printf("\n  Obs.: Os elementos da diagonal principal podem ser nulos (sendo também uma matriz nula)\n");
    return;
}

void imprimirMatrizIdentidade()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1;

    printf("\n|Todos os elementos fora da diagonal principal (i diferente de j) são nulos");
    printf("\n|Todos os elementos da diagonal principal (i=j) são iguais a 1\n\n");
    totalColunas = (rand() % 8) + 2;
    totalLinhas = totalColunas;
    printf(" I%d:\n\n", totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            if(indiceLinha == indiceColuna)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ", indiceLinha, indiceColuna);
            }
        }
        printf("]\n");
    }
    return;
}

void imprimirMatrizTransposta()
{
    int totalLinhas, totalColunas, indiceLinha, indiceColuna=1;

    printf("\n|A ordem das linhas e colunas é alterada:");
    printf("\n Amxn -> Anxm  ||  [aij] -> [aji]\n\n\n");
    totalLinhas = (rand() % 8) + 2;
    totalColunas = (rand() % 8) + 2;
    printf(" A%dx%d:\n\n", totalLinhas, totalColunas);
    for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
    {
        printf("  [ ");
        for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
        {
            printf("a%d%d ", indiceLinha, indiceColuna);
        }
        printf("]\n");
    }
    printf("\n\n At = A%dx%d:\n\n", totalColunas, totalLinhas);
    for(indiceColuna=1; indiceColuna<=totalColunas; indiceColuna++)
    {
        printf("  [ ");
        for(indiceLinha=1; indiceLinha<=totalLinhas; indiceLinha++)
        {
            printf("a%d%d ", indiceLinha, indiceColuna);
        }
        printf("]\n");
    }
    return;
}
