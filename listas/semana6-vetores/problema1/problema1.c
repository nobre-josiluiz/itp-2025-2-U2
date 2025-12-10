/*
* Lista de exercícios - semana 6
* Problema 1 - MEC

* Programa que leia um número inteiro n representando o número de questões (1 ≤ n ≤ 20).
* Em seguida leia as n respostas do gabarito e, em seguida, as n respostas do aluno.
* Assuma que as respostas estão sempre entre 1 e 5.
* Depois o programa deve escrever na tela quantas questões o aluno acertou e a string “acertos” ou “acerto” (para 1 acerto).

*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001); // para imprimir caracteres especiais no terminal
  int n, i, j, k, acertos = 0;
  int gabarito[20], res[20]; // vetores para armazenar as respostas do gabarito e do aluno

  printf("Digite o número de questões: ");
  scanf(" %d", &n);


  printf("Digite as respostas do gabarito(1 a 5): \n");
  for (i = 0; i < n; i++) { // loop para ler as respostas do gabarito
    printf("gab [%d]: ", i);
    scanf(" %d", &gabarito[i]);
    if (gabarito[i] < 1 || gabarito[i] > 5) { // verifica se a resposta está entre 1 e 5
      printf("Resposta inválida! Digite novamente: ");
      return 1;
    }
  }
  printf("Digite as respostas do aluno(1 a 5): \n");
  for (j = 0; j < n; j++) { // loop para ler as respostas do aluno
    printf("resp [%d]: ", j);
    scanf(" %d", &res[j]);
  }  

  for (k = 0; k < n; k++) {   // loop para comparar as respostas do gabarito e do aluno
    //printf(" %d %d\n", gabarito[k], res[k]);
    //printf(" %d\n", res[k]);
    if (gabarito[k] == res[k]) {
      acertos++;
    }
  }

  printf("\n");
  if (acertos <= 1) { // verifica se o aluno acertou 1 ou mais questões
    printf("%d acerto\n", acertos);
  } else {
    printf("%d acertos\n", acertos);
  }
  return 0;
}

