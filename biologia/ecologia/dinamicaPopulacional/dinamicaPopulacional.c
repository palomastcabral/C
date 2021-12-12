/*[EM ANDAMENTO] Programa que calcula a densidade Populacional, verifica se população encontra-se em crescimento ou declínio e calcula taxa de crescimento absoluto e relativo*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");
  char especie[50], espaco[50], tempo[20];
  int opcaoTipoAmbiente, qntdIndividuos;
  float area, volume, densidadePopulacional;
  
  printf("| Densidade Populacional\n");
  printf("\n Espécie: ");
  scanf("%49[^\n]s", especie);
  do
  {
      printf(" Ambiente terrestre [1] ou aquático [2]? ");
      scanf("%d", &opcaoTipoAmbiente);
      if(opcaoTipoAmbiente != 1 && opcaoTipoAmbiente != 2)
      {
        printf("\n Opção inválida!\n");
      }
  }
  while((opcaoTipoAmbiente != 1) && (opcaoTipoAmbiente != 2));
  printf(" Quantidade de indivíduos = ");
  scanf("%d", &qntdIndividuos);
  if(opcaoTipoAmbiente == 1)
  {
    printf(" Área (em m^2)= ");
    scanf("%f", &area); 
    densidadePopulacional = qntdIndividuos / area;
    printf(" -> Densidade Populacional = %.2f indivíduo(s) (espécie: %s) por mˆ2\n\n", especie, densidadePopulacional);
  }
  else
  {
    printf(" Volume (em m^3)= ");
    scanf("%f", &volume);
    densidadePopulacional = qntdIndividuos / volume;
    printf(" -> Densidade Populacional = %.2f indivíduo(s) (espécie: %s) por mˆ3\n\n", especie, densidadePopulacional);
  }
  return 0;
}
