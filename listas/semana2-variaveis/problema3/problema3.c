/*
* Lista de exercícios - semana 2 
* Problema 3 - Cálculo de juros compostos 
* Programa que lê o capital inicial, a taxa de juros (em porcentagem) e o tempo (em anos).
* Calcula e exibe o montante final usando a fórmula de juros compostos.
* Fórmula: Montante = Capital × (1 + taxa/100)^tempo
*/

#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() { 
  SetConsoleOutputCP(65001);
  float capital, taxa, montante;
  int tempo;

  // Entrada de dados
  printf("Digite o valor do capital inicial: ");
  scanf("%f", &capital);

  printf("Digite a taxa de juros (em porcentagem): ");
  scanf("%f", &taxa);

  printf("Digite o tempo (em anos): ");
  scanf("%d", &tempo);

  // Validação de dados de entrada 
  if (capital <= 0 || taxa < 0 || tempo <= 0) {
    printf("Valores inválidos. O capital deve ser maior que zero, a taxa de juros deve ser não negativa e o tempo deve ser maior que zero.\n");
    return 1;
  }

  // Cálculo do montante
  montante = capital * pow((1 + taxa/100),tempo);
  printf(" \n");
  printf("O montante final é: R$ %.2f\n", montante);

  return 0;
}