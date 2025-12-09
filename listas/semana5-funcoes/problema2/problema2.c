/*
* Lista de exercícios - semana 5
* Problema 2 - Primos triplos
* Programa que escreve todos os trios de primos até 50000 quase instaneamente! 
* A saída do programa deve ser todos os trios de primos na forma (x, x + 2, x + 6) até 50000, um por linha, no
formato (x, x+2, x+6). Ou seja, as 4 primeiras linhas da saída devem ser:
(5, 7, 11)
(11, 13, 17)
(17, 19, 23)
(41, 43, 47)
* Função que retorna se um determinado número passado como parâmetro é primo ou não!
*/

#include <stdio.h>
#include <windows.h>

// Função que retorna se um número é primo ou não
int ehPrimo(int num) {
  if (num <= 1) return 0;
  else 
    for (int i = 2; i < num; i++) {
      if (num % i == 0) return 0;          
    }
  return 1;
}

// Escrevendo os trios de primos (x, x + 2, x + 6).
int main() {
  SetConsoleOutputCP(65001);
  int x = 5, contador = 1;

  do {
    if (ehPrimo(x) && ehPrimo(x + 2) && ehPrimo(x + 6)) {
      printf("( %d, %d, %d)\n", x, x + 2, x + 6);
      contador++;
    }
    x++;  // Incrementando x para testar o próximo número
  } while (contador <= 50);

  return 0;
}

