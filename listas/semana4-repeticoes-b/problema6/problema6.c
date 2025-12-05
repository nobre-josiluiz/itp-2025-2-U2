/******************************************************************************

Lista de exercícios - semana 4

Problema 5 - Trio pitagórico

Programa que escreve na tela todos os
trios pitagóricos onde o maior número é menor que 1000. 
Três números naturais a, b e c
formam um trio pitagórico caso: a^2 + b^2 = c^2.
*******************************************************************************/


#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  int i, j, k; // índices

  //Construção dos trios
  printf("\nTodos os trios pitagóricos: \n");
  for (int i = 5; i < 1000; i++) {
    for (int j = 1; j < i; j++) {
      for (int k = 1; k < j; k++) {
        if(i*i == j*j + k*k)
          printf(" %d, %d, %d \n", k, j, i);
      }
    }  
  }

  return 0;
}