/*
* Lista de exercícios - semana 2 
* Problema 4 - Operações aritméticas básicas 
* Programa que lê dois números inteiros e exibe:
    A soma dos números
    A diferença (primeiro menos segundo)
    O produto
    A divisão real (resultado em float)
    O resto da divisão inteira
    A média aritmética 
*/

#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  int int1, int2; 
  float div; // Variável para armazenar a divisão real 

  // Entrada de dados
  printf("Digite um número inteiro: ");
  scanf("%d", &int1); // Leitura do primeiro número inteiro 

  printf("Digite outro número inteiro: ");
  scanf("%d", &int2); // Leitura do segundo número inteiro 

  div = (float)int1 / int2;

  // Exibiçao dos resultados
  printf(" \n");
  printf("A soma e a diferença dos números são, respectivamente: %d e %d.\n", int1 + int2, int1 - int2);
  printf("O produto e a média aritmética dos números são, respectivamente: %d e %.2f.\n", int1 * int2, (float)(int1 + int2) / 2);

  // Verificação de divisão por zero
  if (int2 == 0) {
    printf("Não é possível dividir por zero.\n");
    return 1;     
  }

  printf("O resto da divisão inteira dos números é: %d.\n",  int1 % int2 );

  printf("A divisão real dos números é: %.2f .\n", div);

  return 0;
}