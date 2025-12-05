/******************************************************************************
* Lista de exercícios - semana 3
* Problema 6 - Diagnóstico médico simples
* Programa que ajude num diagnóstico médico básico baseado em sintomas. O programa
  deve perguntar:
* Tem febre? (S/N)
* Tem dor de cabeça? (S/N)
* Tem dor no corpo? (S/N)
* Tem tosse? (S/N)

* Com base nas respostas, o programa deve sugerir:
* Febre + Dor de cabeça + Dor no corpo: "Possível gripe"
* Tosse + Febre: "Possível resfriado"
* Apenas dor de cabeça: "Possível enxaqueca"
* Apenas febre: "Consulte um médico"
* Nenhum sintoma: "Você parece estar bem"
* Qualquer outra combinação: "Consulte um médico para avaliação"
*******************************************************************************/


#include <stdio.h> // Incluir a biblioteca stdio.h
#include <windows.h>

int main() { 
  SetConsoleOutputCP(65001);
  char condicao1, condicao2, condicao3, condicao4; // Variável para armazenar a condicao do pacientee

  printf("Tem febre(S/N): ");
  scanf(" %c", &condicao1); // Lê um inteiro e armazena em 'idade'

  if (condicao1 != 'S' && condicao1 != 'N') {
    printf("\nInválido! Digite S ou N.");
    return 1;
  }

  printf("Tem dor de cabeça(S/N): ");
  scanf(" %c", &condicao2); // Lê um float e armazena em 'altura'

  if (condicao2 != 'S' && condicao2 != 'N') {
    printf("\nInválido! Digite S ou N.");
    return 1;
  }

  printf("Tem dor no corpo(S/N): ");
  scanf(" %c", &condicao3); // Lê um caractere e armazena em 'inicial' 

  if (condicao3 != 'S' && condicao3 != 'N') {
    printf("\nInválido! Digite S ou N.");
    return 1;
  }

  printf("Tem tosse(S/N): ");
  scanf(" %c", & condicao4);

  if (condicao4 != 'S' && condicao4 != 'N') {
    printf("\nInválido! Digite S ou N.");
    return 1;
  }

  if (condicao1 == 'S' && condicao2 == 'S' && condicao3 == 'S' && condicao4 == 'N') 
    printf("\nPossivel gripe.");
  else if (condicao1 == 'S' && condicao2 == 'N' && condicao3 == 'N' && condicao4 == 'S') 
    printf("\nPossível resfriado");
  else if (condicao1 == 'N' && condicao2 == 'S' && condicao3 == 'N' && condicao4 == 'N') 
    printf("\nPossível enxaqueca");
  else if (condicao1 == 'S' && condicao2 == 'N' && condicao3 == 'N' && condicao4 == 'N') 
    printf("\nConsulte um médico");
  else if (condicao1 == 'N' && condicao2 == 'N' && condicao3 == 'N' && condicao4 == 'N') 
    printf("\nVocê parece estar bem");
  else printf("\nConsulte um médico para avaliação");
  
  return 0;
}