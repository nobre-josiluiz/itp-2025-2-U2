
/*
* Lista de exercícios - semana 9
* Problema 3 - Campeonato de empates
* Um campeonato de futebol conta com M times, numerados de 0 a M ≠ 1. Cada time enfrenta cada um
* dos outros times uma única vez. Os resultados são armazenados em uma matriz, onde o elemento aij
* (0 <= i, j <= M - 1) representa quantos gols o time i fez contra o time j. Portanto, o resultado da partida
* i x j (ou j x i, tanto faz pois é uma única partida) é aij gols para i e aji gols para j. No exemplo abaixo, o
* resultado do time 3 contra o time 0 foi a30 para o time 3 e a03 para o time 0, ou seja, 3 x 1.
* Implemente um programa que leia um inteiro M (M <= 20), seguidos de M x M inteiros. Como um time não
* enfrenta ele próprio, assuma que os elementos da diagonal são sempre 0. O programa deve escrever quantas
* partidas terminaram empatadas.


*/

#include <stdio.h>

int main() {
  int M, i, j, empates = 0;
  int partida[20][20]; 

  printf("Digite o número de times: ");
  scanf("%d", &M);

  // Leitura dos resultados das partidas na matriz
  printf("Digite os resultados de cada partida:\n");
  for (i = 0; i < M; i++) 
    for (j = 0; j < M; j++)
      scanf("%d", &partida[i][j]);

  // Contagem de empates
  for (i = 0; i < M; i++) 
    for (j = 0; j < M; j++) 
      if (i != j && partida[i][j] == partida[j][i]) 
        empates++;
    // Cada empate é contado duas vezes, então dividimos por 2
    empates /= 2;
    printf("\n");
    printf("Empates: %d\n", empates);

  
    
  
  return 0;
}