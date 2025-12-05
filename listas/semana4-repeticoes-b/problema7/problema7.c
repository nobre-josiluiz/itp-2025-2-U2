/******************************************************************************

Lista de exercícios - semana 4

Problema 7 - Primos num intervalo

Programa que lê dois números inteiros a e b. 
O programa só deve prosseguir quando a > b. 
Em seguida, o programa deve escrever na tela todos os números primos
entre a e b.
*******************************************************************************/



#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  int a, b, i, j, divisor; // índices

  //Dados de entrada
  printf("Digite dois números inteiros com (a < b) separados por espaço: ");
  scanf(" %d %d", &a, &b);

  //Validação
  if(a >= b || a < 0 || b <= 0) {
    printf("Cuidado, digite valores válidos e no formato a < b.");
    return 1;
  }

  //Construção: busca por primos
  for (i = a + 1; i < b; i++) {
    divisor = 0;
    for (j = 1; j <= i; j++) {
      if(i % j == 0) divisor++; // se o resto da divisão for zero, o número é divisor
    }  
    if(divisor == 2) printf(" %d ", i);   // se o número de divisores for 2, o número é primo
  }  
  return 0;
}