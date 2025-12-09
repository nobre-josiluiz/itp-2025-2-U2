/*
* Problema 4 - Uma pechincha!
* Você está planejando uma viagem (somente ida) de uma cidade X para uma cidade Z. Para isso você está
* pesquisando passagens de avião que sejam as mais baratas possível, nem que para isso seja necessário passar
* por uma cidade Y. Foi possível coletar preços de passagens com diversas origens e destinos que foram
* armazenados em uma matriz M x M de inteiros, onde o valor aij representa o preço em reais para ir da
* cidade i para a cidade j. 
* Implemente um programa que leia um inteiro M (M <= 10), seguidos de M x M inteiros, um inteiro X e um inteiro Z. 
* O programa deve escrever o custo da viagem de X para Z, passando
* por no máximo 1 cidade intermediária, com menor custo total. Esse custo deve ser precedido pelas cidades
* separadas por traço (vide exemplo abaixo).
*/


#include <stdio.h>
#include <windows.h>  

int main() {
  SetConsoleOutputCP(65001);
  int M, X, Z, i, j, k, custo, menorCusto = 0;
  int matrizPreco[10][10]; 

  // Leitura do valor de M (M <= 10)
  printf("Digite o valor de M: ");
  scanf("%d", &M);

  // Leitura dos preços das passagens
  printf("Digite os preços das passagens:\n");
  for (i = 0; i < M; i++) 
    for (j = 0; j < M; j++) 
      scanf("%d", &matrizPreco[i][j]);

  // Leitura dos valores de X e Z
  printf("Digite o valor de X e Z, respectivamente separados por espaço: ");
  scanf("%d %d", &X, &Z);

  // Inicialização do menor custo
  menorCusto = matrizPreco[X][Z];

  // Análise do menor custo passando por uma cidade intermediária
  for (k = 0; k < M; k++) {
    // Verifica se a cidade intermediária é diferente de X e Z
    if (k != X && k != Z) {
      // Calcula o custo passando pela cidade intermediária k
      custo = matrizPreco[X][k] + matrizPreco[k][Z];
      // Atualiza o menor custo, se necessário
      if (custo < menorCusto) { 
        menorCusto = custo;
        printf("%d-%d-%d R$ %d\n", X, k, Z, menorCusto);
                       
      }
    }    
  }
   
  
  
  return 0;
}