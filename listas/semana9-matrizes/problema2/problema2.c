/*
* Lista de exercícios - semana
* Problema 2 - Sugestão de amigos
* Você foi contratado para ajudar na implementação de uma rede social que conta
* com M usuários cadastrados. Um recurso que você quer implementar é a sugestão de
* amigos. Um usuário B deverá ser sugerido para A se eles não forem amigos, mas
* ambos possuirem pelo menos um amigo em comum. As amizades estão armazenadas em
* uma matriz M x M de inteiros, onde o valor aij é igual a 1 se o usuário i (0 <= i
* < M) for amigo do usuário j (0 <= j < M) e 0 caso contrário. Assuma que a matriz
* sempre é simétrica, então aij = aji. Além disso não é possível ser amigo de si,
* então aii = 0. Implemente um programa que leia um inteiro M (M <= 100), seguidos
* de M x M inteiros e um inteiro x. O programa deve escrever todas as sugestões de
*amizades para o usuário x em ordem numérica crescente.
*/

#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  int M, i, j, x, matrizAmizades[100][100];
  int amigosComuns = 0;

  printf("Digite o número de usuários(M <= 100): "); 
  scanf("%d", &M);

  // Leitura da matriz de amizades: 1 - são amigos, 0 - não são amigos
  printf("Digite a matriz de amizades:\n");
  for (i = 0; i < M; i++) {
    for (j = 0; j < M; j++) {
      scanf("%d", &matrizAmizades[i][j]);
    }
  }

  printf("Digite o usuário para o qual deseja sugerir amigos: ");
  scanf("%d", &x);

  // Verifica as sugestões de amigos para o usuário x
  for (i = 0; i < M; i++) {
    if (i != x && matrizAmizades[x][i] == 0) {
      int amigosComuns = 0;
      for (j = 0; j < M; j++) {
        // Verifica se o usuário i tem um amigo em comum com o usuário x
        if (matrizAmizades[x][j] == 1 && matrizAmizades[i][j] == 1) {
          amigosComuns++;
          // Se encontrou um amigo em comum, imprime o usuário sugerido e sai do loop
          if (amigosComuns >= 1) {
            printf("%d\n", i);
            break;
            // Se já encontrou um amigo em comum, não precisa verificar mais
            // amigos para esse usuário
            // Imprime o usuário sugerido e sai do loop interno
            
          }  
        }  
      }  
    } 
  }  
  printf("\n");  

  return 0;
}