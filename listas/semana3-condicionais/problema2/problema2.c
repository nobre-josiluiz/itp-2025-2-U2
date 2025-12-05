/*
* Lista de exercícios - semana 3
* Problema 2 - Calculadora de energia elétrica
* Uma companhia de energia cobra da seguinte forma:
    Residencial: R$ 0,60 por kWh
    Comercial: R$ 0,48 por kWh
    Industrial: R$ 1,29 por kWh
  Além disso, há uma taxa fixa de R$ 15,00 para todos os tipos.
  Crie um programa que leia o consumo em kWh e o tipo de consumidor (R para
residencial, C para comercial, I para industrial) e calcule o valor total da
conta.

*/

#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float consumo, valorTotal;
  char tipoConsumidor;

  // Entrada de dados
  printf("Digite o consumo em kWh: ");
  scanf("%f", &consumo);

  printf("Digite o tipo de consumidor (R para residencial, C para comercial, I para industrial): ");
  scanf(" %c", &tipoConsumidor);

  printf("\n");

  // Validação dos valores de entrada
  if (consumo < 0 || (tipoConsumidor != 'R' && tipoConsumidor != 'C' && tipoConsumidor != 'I')) {
    printf("Valores inválidos. O consumo deve ser maior do que zero e o tipo de consumidor deve ser R, C ou I.\n");
    return 1;
  }

  // Cálculo do valor total da conta
  if (tipoConsumidor == 'R') valorTotal = consumo * 0.60 + 15;
  else if (tipoConsumidor == 'C') valorTotal = consumo * 0.48 + 15;
  else if (tipoConsumidor == 'I') valorTotal = consumo * 1.29 + 15;
  
  printf("\n");
  printf("O valor total da conta é: R$ %.2f\n", valorTotal);

  return 0;
}