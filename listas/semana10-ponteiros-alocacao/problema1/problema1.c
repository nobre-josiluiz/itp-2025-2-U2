/*
* Lista de exercícios - semana 10
* Problema 1 - Soma de Vetores
* Quando temos dois vetores de mesma dimensão ˛u = (u0, u1, u2, ..., un) e ˛v = (v0, v1, v2, ..., vn), a soma ˛u + ˛v
* é dada por:
* ˛u + ˛v = (u0 + v0, u1 + v1, u2 + v2, ..., un + vn)
* Partindo do código q2inicial.c, preencha as funções não implementadas e na função main:
* ler do usuário um inteiro n1, um inteiro n2
* alocar dinamicamente um vetor u de n1 números inteiros e outro v de n2 números inteiros usando a
* função alocarVetor
* ler n1 inteiros para u e n2 inteiros para v
* chamar a função somaVetores
* escrever na tela o vetor resultante da soma dos dois vetores ou ‘dimensoes incompativeis’ caso n1 ”= n2
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


// função que soma dois vetores de mesmo tamanho
int* somaVetores(int *a, int n1, int *b, int n2) {
  int *soma; // vetor que armazenará a soma dos vetores u e v
  // alocação do vetor soma
  soma = malloc(n1 * sizeof(int));
  for (int i = 0; i < n1; i++) 
    soma[i] = a[i] + b[i];
  
  return soma;
  
}

int main() {   
  SetConsoleOutputCP(65001);

  int n1, n2, i;
  int *u, *v;
  int *somaVetor;

  // leitura do tamanho dos vetores   
  printf("Digite o tamanho do vetor u e v, respectivamente e separadas por espaço: ");
  scanf("%d %d", &n1, &n2);

  // Tamanho dos vetores diferentes
  if (n1 != n2) {
    printf("dimensões incompatíveis\n");
  } else {
    // alocação dos vetores
    u = malloc(n1 * sizeof(int));
    v = malloc(n2 * sizeof(int));

    // leitura do vetor u
    printf("Digite os elementos do vetor u: "); 
    //  n1-1 para não ler o último elemento do vetor u
    // para não pular a leitura do vetor v
    for (i = 0; i < (n1 - 1); i++) 
      scanf("%d", &u[i]);
    // leitura do último elemento do vetor u
    scanf("%d", &u[n1 - 1]);

    // leitura do vetor v
    printf("Digite os elementos do vetor v: ");
    //  n2-1 para não ler o último elemento do vetor v
    // para não pular a leitura do vetor v
    for (i = 0; i < (n2 - 1); i++)
      scanf("%d", &v[i]);
    scanf("%d", &v[n2 - 1]);

    // soma dos vetores
    somaVetor = somaVetores(u, n1, v, n2);

    // escrita do vetor resultante
    printf("\nVetor resultante: ");
    for (i = 0; i < n1; i++)
      printf("%d ", somaVetor[i]);
    printf("\n");
  }

  // liberação da memória alocada
  free(u);
  free(v);
  free(somaVetor); 

  
  return 0;
}