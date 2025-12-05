/*
* Lista de exercícios - semana 3 
* Problema 1 - Classificação de IMC
* Calcular o IMC, também classifique o resultado de
acordo com a tabela:
  Abaixo de 18.5: "Abaixo do peso"
  Entre 18.5 e 24.9: "Peso normal"
  Entre 25.0 e 29.9: "Sobrepeso"
  30.0 ou mais: "Obesidade"
*/


#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  
  float peso, altura, imc; 

  // Entrada de dados
  printf("Digite o peso (em Kg) de uma pessoa: ");
  scanf("%f", &peso); 

  printf("Digite a altura (em metros) de uma pessoa: ");
  scanf("%f", &altura);

  // Cálculo do IMC
  imc = peso / (altura * altura);

  printf("\n");

  // Validação dos valores de entrada
  if (peso <= 0 || altura <= 0) {
    printf("Valores inválidos. O peso deve ser maior que zero e a altura deve ser maior que zero.\n");
    return 1;
  }

  // Classificação do IMC
  if (imc < 18.5) {
    printf("Abaixo do peso\n");
  } else if (imc >= 18.5 && imc <= 24.9) {
    printf("Peso normal\n");
  } else if (imc >= 25.0 && imc <= 29.9) {
    printf("Sobrepeso\n");
  } else 
    printf("Obesidade\n");


  return 0;
}