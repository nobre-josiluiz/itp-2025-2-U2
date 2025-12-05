/*
* Lista de exercícios - semana 2 
* Problema 2 - Conversão de temperatura
* Fórmula: Fahrenheit = (Celsius × 9/5) + 32
           Kelvin = Celsius + 273.15
*/


#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float celsius, fahrenheit, kelvin; 

  // Entrada de dados
  printf("Conversão de temperatura\n\n");
  printf("Digite a temperatura em graus Celsius: ");
  scanf("%f", &celsius); 

  // Convertendo para Fahrenheit e Kelvin
  fahrenheit = (celsius * 9/5) + 32;
  kelvin = celsius + 273.15; 
  printf("\n");
  printf("A temperatura em Fahrenheit é igual a %.1f °F\n", fahrenheit);
  printf("A temperatura em Kelvin é igual a %.1f °K\n", kelvin);

  return 0;
}