/*
* Lista de exercícios - semana 8
* Problema 3 - Esse sim é piloto
* Alguns pilotos de Fórmula 1 vez ou outra conseguem algumas façanhas. Em 1983, no grande prêmio do
* Oeste dos Estados Unidos, John Watson largou em 22º lugar e conseguiu terminar em primeiro! Você então
* resolveu escrever um programa que facilite a identificação de pilotos que conseguem ganhar muitas posições.

* Escreva um programa que leia um número inteiro n representando a quantidade de pilotos em uma corrida
* de Fórmula 1 (1 ≤ n ≤ 20). Em seguida faça a leitura de n inteiros, representando a ordem de largada e,
* depois, n inteiros, representando a ordem de chegada. Os pilotos são identificados pelos números de 1
* a n. O programa deve em seguida escrever na tela o identificador do piloto que mais ganhou posições. Se
* houver empate entre vários pilotos ou se ninguém ganhou posições, escreva empate.

*/

#include <stdio.h>
#include <windows.h> 

int main() {
  SetConsoleOutputCP(65001); // para imprimir acentos corretamente no terminal do windows
  
  int n, i, j; // n- número de pilotos, i e j- contadores 
  int largada[20], chegada[20], posicoesGanhas[20]; // 
  int maxPosicoesGanhas = 0, pilotoMaxPosicoesGanhas = 0, empate = 0; 

  printf("Digite o número de pilotos: ");
  scanf("%d", &n);

  printf("Digite a ordem de largada: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &largada[i]);
    posicoesGanhas[i] = 0; // inicia o vetor de posições ganhas    
  }

  printf("Digite a ordem de chegada: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &chegada[i]);
    for (j = 0; j < n; j++) {
      if (largada[j] == chegada[i]) {
        posicoesGanhas[j] = j - i;
        break;
      }
    }
  }  

  for (i = 0; i < n; i++) {  // verifica qual piloto ganhou mais posições
    if (posicoesGanhas[i] > maxPosicoesGanhas) {
      maxPosicoesGanhas = posicoesGanhas[i];
      pilotoMaxPosicoesGanhas = largada[i];
      empate = 0;
    } else if (posicoesGanhas[i] == maxPosicoesGanhas) 
      empate = 1;    
  }

  printf("\n");

  // imprime o resultado
  if (empate || maxPosicoesGanhas == 0) 
    printf("empate\n");
  else 
    printf("Piloto que mais ganhou posições: %d\n", pilotoMaxPosicoesGanhas);

  printf("\n");

  return 0;
}