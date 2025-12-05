/*
* Lista de exercícios - semana 8 
* Problema 1 - Estou com sorte (ou não)
* A megasena é um jogo de aposta em que são sorteadas 6 dezenas e em cada cartela o jogador anota 6 dezenas
* (aposta mínima). Na lotomania, o jogador marca 50 dezenas e são sorteadas 20. Escreva um programa
* que leia um inteiro m (1 ≤ m ≤ 30), um inteiro n (m ≤ n ≤ 50), representando a quantidade de números
* sorteados e a quantidade de números de uma aposta, respectivamente. Em seguida deve ler os m números
* sorteados, os n números da aposta e escrever na tela quantos números o jogador acertou. Note que o intervalo
* dos números sorteados/apostados é desconhecido (vide exemplo 3). Assuma que um número não aparece
* mais de uma vez no mesmo sorteio nem na mesma aposta.
*/

#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  
  int m, n, i, j, sorteados[50], aposta[50]; 

  // Entrada de dados
  printf("Digite um número inteiro (1 <= m <= 30): ");
  scanf("%d", &m); // Leitura da quantidade de números sorteados 

  printf("Digite outro número inteiro (m <= n <= 50): ");
  scanf("%d", &n); // Leitura da quantidade de números da aposta  

  // validação dos valores de m e n
  if (m < 1 || m > 30 || n < m || n > 50) {
    printf("Valores inválidos para m e/ou n.\n");
    return 1;
  }

  // Leitura dos números sorteados
  printf("Digite os %d números sorteados:\n", m);
  for (i = 0; i < m; i++) 
    scanf(" %d", &sorteados[i]);

  // Leitura da aposta
  printf("Digite os %d números da aposta:\n", n);
  for (i = 0; i < n; i++) 
    scanf(" %d", &aposta[i]);

  // Quantidade de números acertados
  int acertos = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (sorteados[i] == aposta[j]) {
        acertos++;
        break;
      }
    }
  }

  printf("O jogador acertou %d números.\n", acertos);

  return 0;
}