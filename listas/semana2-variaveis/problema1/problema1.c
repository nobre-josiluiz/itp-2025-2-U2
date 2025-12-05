/*
* Lista de exercícios - semana 2 
* Problema 1 - Calculadora de IMC
* Fórmula: IMC = peso / (altura²)
*/

#include <stdio.h>
#include <windows.h> // Para usar SetConsoleOutputCP

int main() {
  SetConsoleOutputCP(65001); // Configura a saída para UTF-8
  
  float peso, altura, imc; 
  // Entrada de dados
  printf("Digite o peso (em Kg) de uma pessoa: ");
  scanf("%f", &peso); 

  printf("Digite a altura (em metros) de uma pessoa: ");
  scanf("%f", &altura);

  // Cálculo do IMC
  imc = peso / (altura * altura);

  // Verificação de valores
  if (peso <= 0 || altura <= 0) {
    printf("Valores inválidos. O peso e a altura devem ser maior que zero.\n");
    return 1;
  }

  printf("O IMC é: %.2f kg/m²\n", imc);

  return 0;
}