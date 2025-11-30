/*
* Lista de exercícios - semana 9
* Problema 1 - Campo Agrícola
* Um campo agrícola possui setores organizados de forma matricial, onde alguns são de terras férteis e outros
* inférteis. Irrigadores ocupam um setor por completo, nunca estão localizados na borda da matriz e irrigam
* cada um dos 4 setores vizinhos (norte, sul, leste, oeste).

* Implemente um programa que leia um inteiro M, um inteiro N (M <= 10, N <= 10), seguidos de MxN inteiros.
* Depois o programa deve escrever quantos setores férteis estão cobertos por pelo menos um irrigador e
* quantos não estão. Um 0 representa um setor infértil, 1 um setor fértil e 2 um setor ocupado por um irrigador.
* O setor onde está localizado o próprio irrigador não deve ser contabilizado.

*/

#include <stdio.h> 
#include <windows.h>
#include <stdlib.h>  // para usar a função abs()

int main() {
  SetConsoleOutputCP(65001);

  int m, n, i, j, naoCoberto, fertil = 0, naofertil = 0, aux = 0; 
  int setores[10][10]; // matriz de setores

  // leitura dos valores de m e n
  printf("Digite os valores de m e n separados por espaço: ");
  scanf("%d %d", &m, &n);
  
  // Formação do campo (matriz) 
  printf("Digite apenas os valores 0 - infértil  , 1 - fértil e 2 - irrigador para cada setor:\n");
  printf("Digite os %d valores e tecle enter, pelas %d linhas, separados por espaço: \n", n, m);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {           
      scanf(" %d", &setores[i][j]);         
    }    
  }
  
  // 0 - infértil, 1 - fértil, 2 - irrigador
  for (i = 1; i < m - 1; i++) {
    for (j = 1; j < n - 1; j++) {
      if (setores[i][j] == 2) {
        if (setores[i - 1][j] == 1) 
          fertil++;          
        else if (setores[i - 1][j] == 0) 
          naofertil++;
        
        if (setores[i + 1][j] == 1) 
          fertil++;
        else if (setores[i + 1][j] == 0)
          naofertil++;
        
        if (setores[i][j - 1] == 1) 
          fertil++;
        else if (setores[i][j - 1] == 0)
          naofertil++;
        
        if (setores[i][j + 1] == 1) 
          fertil++;
        else if (setores[i][j + 1] == 0)
          naofertil++;
        
      } else if (setores[i][j] == 0) {
        aux++;
      }
    }
  } 
          

  naoCoberto = abs(naofertil - aux);
  printf("\nSetores férteis cobertos por pelo menos um irrigador e não cobertos por irrigador, respectivamente: %d e %d. \n", fertil, naoCoberto);
  

  return 0;
}