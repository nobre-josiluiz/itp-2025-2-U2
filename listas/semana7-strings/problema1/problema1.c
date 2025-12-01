/*
* Problema 1 - Campo minado 1D
A entrada do programa consiste em uma palavra com até 20 caracteres composta somente por . e x, onde o
primeiro representa um espaço vazio e o segundo representa uma bomba. 
Depois o programa deve ler um inteiro representando um índice na palavra (começando de 0) e escrever 
na tela bum! caso nesse índice haja uma bomba ou escrever na tela um inteiro representando quantas 
bombas há na adjacência do índice em questão.
*/


#include <stdio.h>
#include <string.h> // Para usar strlen()
#include <windows.h> // Para usar SetConsoleOutputCP(65001)

int main() { 
  SetConsoleOutputCP(65001); // Configura o console para usar UTF-8 

  char campoMinado[21]; // Tamanho máximo da palavra + 1 para o caractere nulo
  int indice, bombasAdjacentes = 0;  

  printf("Digite uma palavra formada por (espaço) ou x do campo minado (até 20 caracteres): ");
  fgets(campoMinado, sizeof(campoMinado), stdin); // Lendo a palavra do campo minado


  printf("Digite um índice no intervalo [0, 20]: ");   
  scanf("%d", &indice);

  // Verifica se o índice é válido
  if (indice < 0 || indice >= strlen(campoMinado)) {
    printf("Índice inválido.\n");
    return 1;    
  }

  // Verifica se há uma bomba no índice especificado
  if (campoMinado[indice] == 'x') {
    printf("bum!\n");
    return 0;
  } else { 
    if (indice > 0 && campoMinado[indice - 1] == 'x') bombasAdjacentes++;
    if (indice <= strlen(campoMinado) - 1 && campoMinado[indice + 1] == 'x') bombasAdjacentes++;
  }  
  printf("%d\n", bombasAdjacentes);
  
  return 0;
}