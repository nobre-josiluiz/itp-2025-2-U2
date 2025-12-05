/*
* Lista de exercícios - semana 3
* Problema 5 - Calculadora de desconto progressivo
* Uma loja oferece descontos progressivos baseados no valor da compra:
  * Até R$ 100,00: sem desconto
  * De R$ 100,01 a R$ 500,00: 10% de desconto
  * De R$ 500,01 a R$ 1000,00: 15% de desconto
  * Acima de R$ 1000,00: 20% de desconto
* Crie um programa que leia o valor da compra e calcule:
  * O valor do desconto
  * O valor final a ser pago
  * A porcentagem de desconto aplicada
*/

#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float valorCompra, valorDesconto;

  printf("Digite o valor da compra: ");
  scanf("%f", &valorCompra);

  printf("\n");

  // Avaliando o desconto progressivo
  if (valorCompra <= 0) {
    printf("Valor inválido, digite um valor positivo!\n");
    return 1;
  } else if (valorCompra > 0 && valorCompra < 0.01) {
    printf("Cuidado, digite um valor com até duas casas decimais!\n");
    return 1;
  } else if (valorCompra >= 0.01 && valorCompra <= 100) valorDesconto = 0;
  else if (valorCompra >= 100.01 && valorCompra <= 500) valorDesconto = valorCompra * 0.1;
  else if (valorCompra >= 500.01 && valorCompra <= 1000) valorDesconto = valorCompra * 0.15;
  else valorDesconto = valorCompra * 0.2;

  // Resultados obtidos
  printf("Valor do desconto: R$ %.2f\n", valorDesconto);
  printf("Valor final a ser pago: R$ %.2f\n", valorCompra - valorDesconto);
  if (valorDesconto == 0) return 1;
  else  printf("Porcentagem de desconto aplicada: %.0f%%\n", (valorDesconto / valorCompra) * 100);

  return 0;
}