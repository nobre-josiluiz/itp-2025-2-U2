/******************************************************************************

Lista de exercícios - semana 4

Problema 5 - sequência em escada

Programa que lê um número n (que representa o número de linhas) e escreve
na tela uma sequência de números em formato de escada.
*******************************************************************************/


#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  int num_linhas, i, j, k = 1; // índices

  //Dados de entrada
  printf("Digite a quantidade de linhas: ");
  scanf(" %d", &num_linhas);

  //Validação
  if(num_linhas <= 0) {
    printf("Cuidado, digite um valor válido.");
    return 1;
  }

  //Construção da sequência
  for (int i = 1; i <= num_linhas; i++) {
    for (int j = 1; j <= i; j++)
      printf("  %-3d ", k++);
    printf("\n");
  }    

  return 0;
}