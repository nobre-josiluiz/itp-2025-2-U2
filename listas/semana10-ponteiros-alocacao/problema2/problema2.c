/*
* Lista de exercícios - semana 10
* Problema 2 - Ocorrências no vetor
* No código exemplo12.c (parte 4) vimos como criar uma função que retorna indiretamente o maior número de
um vetor de inteiros e o respectivo índice. Agora você deverá fazer algo parecido. 
* A função deve retornar o endereço base de um vetor contendo todos os índices de um determinado número buscado no vetor. Você
também deve acrescentar um retorno indireto através de ponteiro para armazenar a quantidade de ocorrências.
* A função deve seguir a seguinte assinatura:
int * buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd)
onde v é o endereço base do vetor de inteiros a ser analisado, n a quantidade de inteiros nesse vetores,
valor representa o valor buscado no vetor e qtd um ponteiro para inteiro que contém o endereço onde será
armazenado a quantidade de ocorrências desse inteiro buscado. A função deve retornar NULL caso não
encontre ocorrências.

A função main deve ler um inteiro n que representa a quantidade de elementos do vetor de inteiros. O vetor
deve ser alocado dinamicamente. Em seguida, o programa deve ler do usuário os n inteirose um valor inteiro
a ser buscado. Depois o programa deve obter os índices de todas as ocorrências desse valor informado. O
programa deve escrever na saída a quantidade de ocorrências e os índices. Lembre-se de liberar todos os
vetores alocados dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


// Função que busca um valor no vetor e retorna os índices das ocorrências
int * buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd) {
  // Aloca dinamicamente um vetor para armazenar os índices das ocorrências
  int *indices = (int *) malloc(n * sizeof(int));   // Aloca um vetor com n posições
  int i, j = 0;
  // Percorre o vetor e armazena os índices das ocorrências
  for (i = 0; i < n; i++) {    
    if (v[i] == valor) {      
      indices[j] = i;
      j++;
    }
  }
  // Se não encontrou nenhuma ocorrência, libera o vetor e retorna NULL
  if (j == 0) {
    free(indices);
    return NULL;
  } 
  // Atualiza a quantidade de ocorrências e retorna o vetor de índices
  *qtd = j;
  return indices;
}

int main() {
  SetConsoleOutputCP(65001); // Configura a codificação de saída para UTF-8
  
  int n, i, valor, qtd;
  int *v, *indices;

  // Leitura da quantidade de elementos do vetor
  printf("Digite a quantidade de elementos do vetor: ");
  scanf("%d", &n);

  // Alocação dinâmica do vetor
  v = (int *) malloc(n * sizeof(int));

  // Leitura dos elementos do vetor
  printf("Digite os elementos do vetor: ");  
  for (i = 0; i < (n - 1); i++) 
    scanf("%d", &v[i]);   
  // Leitura do último elemento do vetor
  // (para evitar que o último scanf leia o \n)
  scanf("%d", &v[n - 1]);

  // Leitura do valor a ser buscado
  printf("Digite o valor a ser buscado: ");
  scanf("%d", &valor);

  // Busca do valor no vetor
  indices = buscaNoVetor(v, n, valor, NULL, &qtd);

  // Verificação se o valor foi encontrado
  if (indices == NULL)
    printf("Valor nao encontrado no vetor.\n");
  else 
    printf("O valor %d foi encontrado %d vezes nos indices: ", valor, qtd);
    for (i = 0; i < qtd; i++) {
      printf("%d ", indices[i]);
    }
    printf("\n");

   // Liberação da memória alocada para o vetor de índices
  if (indices != NULL) 
    free(indices);
  // Liberação da memória alocada para o vetor
  free(v);  

  
  return 0;
}