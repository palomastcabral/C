// Programa para verificar se dois vetores são colineares
#include<stdio.h>
#include<locale.h>

void separador();

int main()
{
    setlocale(LC_ALL, "");

    float u_abscissa, u_ordenada, v_abscissa, v_ordenada, k_abscissas, k_ordenadas;

    printf("\t\t===== VETORES COLINEARES =====\n");
    printf("\n[Obs.: Insira números inteiros ou decimais (até 2 casas decimais)]\n");
    separador();
    printf("\n |Vetor u:\n");
    printf("   Abscissa (x): ");
    scanf("%f", &u_abscissa);
    printf("   Ordenada (y): ");
    scanf("%f", &u_ordenada);
    separador();
    printf("\n |Vetor v:\n");
    printf("   Abscissa (x): ");
    scanf("%f", &v_abscissa);
    printf("   Ordenada (y): ");
    scanf("%f", &v_ordenada);
    separador();

    k_abscissas = u_abscissa / v_abscissa;
    k_ordenadas = u_ordenada / v_ordenada;

    printf("\n\n |Vetor u = (%.2f , %.2f)", u_abscissa, u_ordenada);
    printf("\n |Vetor v = (%.2f , %.2f)\n", v_abscissa, v_ordenada);

    if(k_abscissas == k_ordenadas)
    {
        if(k_abscissas == 1)
        {
            printf("\n |Cte de proporcionalidade:");
            printf("\n   k = 1\n");
            printf("\n |Os vetores são iguais (colineares)\n\n");
        }
        else
        {
            printf("\n |Cte de proporcionalidade:");
            printf("\n   k = [x(u) / x(v)] = [y(u) / y(v)]");
            printf("\n   k = %.2f\n", k_abscissas);
            printf("\n |Os vetores são paralelos (colineares)\n\n");
        }
    }
    else
    {
        printf("\n |Os vetores não são colineares\n\n");
    }
    return 0;
}

void separador()
{
    printf("______________________\n");
}
