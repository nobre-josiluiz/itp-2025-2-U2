/*****************************************************************************************
******************************************************************************************
* PROGRAMA SIMULANDO UMA CALCULADORA DE MATRIZES
* OPERAÇÕES:
* 1 - SOMA
* 2 - SUBTRAÇÃO
* 3 - MULTIPLICAÇÃO
* 4 - TRANSPORTE
* 5 - DETERMINANTE
* 6 - INVERSA
* 7 - ORTOGONAL
* 8 - EQUAÇÃO MATRICIAL
* 9 - SAIR
*
******************************************************************************************
******************************************************************************************/

#include <stdio.h> // Incluir a biblioteca stdio.h
#include <stdlib.h>
#include <math.h>
#include <windows.h> 

// Declaração das funções: alocando matrizes 

// Função alocando matrizes
float** alocaMatriz(int linhas, int colunas) {

  float **matriz = (float **)malloc(linhas * sizeof(int*));
  int linha, coluna;

  //printf("Digite os elementos da matriz:\n");
  //printf("Digite o tamanho da matriz separados por espaco (linha coluna): ");
  //scanf(" %d %d", &linha, &coluna);

  if (matriz == NULL) {
    printf("Erro ao alocar memória para a matriz.\n");
    return NULL;
  }
  for (int i = 0; i < linhas; i++){
    matriz[i] = (float *)malloc(colunas * sizeof(int));
    if (matriz[i] == NULL) {
      printf("Erro ao alocar memória para a linha %d da matriz.\n", i);
    }
  }
  return matriz;
}



// Função para digitar matrizes
void digitarMatriz(int linhas, int colunas, float **matriz) {
  printf("Digite os elementos da matriz:\n"); 
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }
  //printf("Digite os elementos da matriz:\n"); 
}

// Imprimindo matrizes
void imprimirMatriz(int linhas, int colunas, float **matriz) {
  //printf("\nResultado da matriz:\n");
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%5.2f\t", matriz[i][j]); 
    }
    printf("\n");
  }
  printf("\n");  
}

// Desalocando matrizes
void desalocaMatriz(int linhas, float **matriz) {
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]); 
    matriz[i] = NULL; 
  } 
  free(matriz);
  matriz = NULL;
}


/****************************************************************************
Funções para realizar as operações com matrizes
*****************************************************************************/ 

// Soma de Matrizes
void somaMatrizes() {

  int linhaA, colunaA, linhaB, colunaB;
  float **matrizA;         
  float **matrizB;         
  float **matrizResultado; 


  // Leitura das dimensões da primeira matriz
  printf("Digite os elementos da primeira matriz:\n");
  printf("Digite o tamanho da primeira matriz (linha coluna): ");
  scanf(" %d %d", &linhaA, &colunaA);
  // Chama a função para digitar a matriz
  matrizA = alocaMatriz(linhaA, colunaA);
  digitarMatriz( linhaA, colunaA, matrizA);
  printf("\n");
  imprimirMatriz(linhaA, colunaA, matrizA);
  printf("\n");

  // Leitura das dimensões da segunda matriz
  printf("Digite os elementos da segunda matriz:\n");
  printf("Digite o tamanho da segunda matriz (linha coluna): ");  
  scanf(" %d %d", &linhaB, &colunaB);

  // Verificar se as matrizes têm o mesmo tamanho
  if (linhaA != linhaB || colunaA != colunaB) {
    printf("As matrizes não têm o mesmo tamanho. Não é possível realizar a "
           "soma.\n");
    return;
  }

  matrizB = alocaMatriz(linhaB, colunaB);
  digitarMatriz(linhaB, colunaB, matrizB);
  printf("\n");
  imprimirMatriz(linhaB, colunaB, matrizB);
  printf("\n");

  // Alocando memória para a matriz resultado
  matrizResultado = alocaMatriz(linhaA, colunaA);
  for (int i = 0; i < linhaA; i++) {
    for (int j = 0; j < colunaA; j++) {
      matrizResultado[i][j] = matrizA[i][j] + matrizB[i][j];
    }
  } 




  if(matrizResultado == NULL) {
    printf("Erro ao alocar memória para a matriz resultado.\n");
  } 



  printf("\nA soma das matrizes é:\n");
  imprimirMatriz(linhaA, colunaA, matrizResultado);


  // Desalocando matrizes
  desalocaMatriz(linhaA, matrizA);
  desalocaMatriz(linhaB, matrizB);
  desalocaMatriz(linhaA, matrizResultado);

}

// Subtração de Matrizes
void subtracaoMatrizes() {

  int linhaA, colunaA, linhaB, colunaB;
  float **matrizA;         
  float **matrizB;         
  float **matrizResultado; 

  // Leitura das dimensões da primeira matriz
  printf("Digite os elementos da primeira matriz:\n");
  printf("Digite o tamanho da primeira matriz (linha coluna): ");
  scanf(" %d %d", &linhaA, &colunaA);
  // Chama a função para digitar a matriz
  matrizA = alocaMatriz(linhaA, colunaA);
  digitarMatriz( linhaA, colunaA, matrizA);
  printf("\n");
  imprimirMatriz(linhaA, colunaA, matrizA);
  printf("\n");

  // Leitura das dimensões da segunda matriz
  printf("Digite os elementos da segunda matriz:\n");
  printf("Digite o tamanho da segunda matriz (linha coluna): ");  
  scanf(" %d %d", &linhaB, &colunaB);

  // Verificar se as matrizes têm o mesmo tamanho
  if (linhaA != linhaB || colunaA != colunaB) {
    printf("As matrizes não têm o mesmo tamanho. Não é possível realizar a "
           "soma.\n");
    return;
  }

  matrizB = alocaMatriz(linhaB, colunaB);
  digitarMatriz(linhaB, colunaB, matrizB);
  printf("\n");
  imprimirMatriz(linhaB, colunaB, matrizB);
  printf("\n");

  // Alocando memória para a matriz resultado
  matrizResultado = alocaMatriz(linhaA, colunaA);
  for (int i = 0; i < linhaA; i++) {
    for (int j = 0; j < colunaA; j++) {
      matrizResultado[i][j] = matrizA[i][j] - matrizB[i][j];
    }
  } 

  if(matrizResultado == NULL) {
    printf("Erro ao alocar memória para a matriz resultado.\n");
  } 



  printf("\nA subtração das matrizes é:\n");
  imprimirMatriz(linhaA, colunaA, matrizResultado);


  // Desalocando matrizes
  desalocaMatriz(linhaA, matrizA);
  desalocaMatriz(linhaB, matrizB);
  desalocaMatriz(linhaA, matrizResultado);

}

// Produto de Matrizes
void produtoMatrizes() {
  int linhaA, colunaA, linhaB, colunaB;
  float **matrizA;         
  float **matrizB;         
  float **matrizResultado; 

  // Leitura das dimensões da primeira matriz
  printf("Digite os elementos da primeira matriz:\n");
  printf("Digite o tamanho da primeira matriz (linha coluna): ");
  scanf(" %d %d", &linhaA, &colunaA);
  matrizA = alocaMatriz(linhaA, colunaA);
  digitarMatriz(linhaA, colunaA, matrizA);
  imprimirMatriz(linhaA, colunaA, matrizA);
  printf("\n");

  // Leitura das dimensões da segunda matriz
  printf("Digite os elementos da segunda matriz:\n");
  printf("Digite o tamanho da segunda matriz (linha coluna): ");
  scanf(" %d %d", &linhaB, &colunaB);

  // Verificar se as matrizes podem ser multiplicadas
  if (colunaA != linhaB) {
    printf("O número de colunas da primeira matriz é diferente do número de "
           "linhas da segunda. Não é possível realizar o produto.\n");
    return;
  }

  matrizB = alocaMatriz(linhaB, colunaB);
  digitarMatriz(linhaB, colunaB, matrizB); 
  imprimirMatriz(linhaB, colunaB, matrizB);
  printf("\n");

  // Inicializando a matriz de resultados com zeros para uso a seguir
  matrizResultado = alocaMatriz(linhaA, colunaB);
  for (int i = 0; i < linhaA; i++) {
    for (int j = 0; j < colunaB; j++)
      matrizResultado[i][j] = 0;
  }

  // Realizando o produto das matrizes
  for (int i = 0; i < linhaA; i++) {
    for (int j = 0; j < colunaB; j++) {
      for (int k = 0; k < colunaA; k++)
        matrizResultado[i][j] += matrizA[i][k] * matrizB[k][j];
    }  
  }

  printf("A produto das matrizes é:\n");
  imprimirMatriz(linhaA, colunaB, matrizResultado);

    // Desalocando matrizes
  desalocaMatriz(linhaA, matrizA);
  desalocaMatriz(linhaB, matrizB);
  desalocaMatriz(linhaA, matrizResultado);
}

// Função transporte de matrizes
void transporteMatrizes() {
  int linha, coluna;
  float **matrizT;
  float **matrizResultado;

  // Leitura das dimensões da matriz
  /*printf("Digite os elementos da matriz:\n");
  printf("Digite o tamanho da matriz separados por espaco (linha coluna): ");
  scanf(" %d %d", &linha, &coluna); */

  // Alocando memória para a matriz
  matrizT = alocaMatriz(linha, coluna);
  digitarMatriz(linha, coluna, matrizT);
  printf("\n");
  imprimirMatriz(linha, coluna, matrizT);

  // Alocando memória para a matriz resultado
  matrizResultado = alocaMatriz(coluna, linha);
  // Laço do transporte das matrizes
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++)
      matrizResultado[j][i] = matrizT[i][j];
  }

  printf("\nA matriz transporte será:\n");
  imprimirMatriz(coluna, linha, matrizResultado);

  // Desalocando matrizes
  desalocaMatriz(linha, matrizT);
  desalocaMatriz(coluna, matrizResultado);

}

// Função determinante de matrizes por Laplace
void determinanteMatrizesLaplace() {
  int linha, coluna;
  float **matrizD;
  int determinante = 1; 
  int aux1, aux2;
  float termo = 1;

  //printf("Digite os elementos da matriz:\n");
  printf("Digite o tamanho da matriz separados por espaco (linha coluna): ");
  scanf(" %d %d", &linha, &coluna);

  // Verificar se a matriz é quadrada
  if (linha != coluna) {
    printf("A matriz não é quadrada. Não é possível calcular o determinante.\n");
    printf("\n");
    return;
  }

  // Alocando memória para a matriz
  matrizD = alocaMatriz(linha, coluna);

  // Digitando a matriz
  digitarMatriz(linha, coluna, matrizD);  
  printf("\n");
  imprimirMatriz(linha, coluna, matrizD);

  // Laço do determinante das matrizes
  if(linha == 1 && coluna == 1) {
    determinante = matrizD[0][0];
  } else if (linha == 2 && coluna == 2) {
    determinante = (matrizD[0][0] * matrizD[1][1]) - (matrizD[0][1] * matrizD[1][0]);
  } else {  
    // Laço para transformar a matriz em triangular superior
    for (int k = 0; k < linha; k++) {
      for (int i = k + 1; i < linha; i++) {
        if (matrizD[k][k] == 0) {
          determinante = 0;
          break;
        } 
        termo = (float)matrizD[i][k] / matrizD[k][k];
        for (int j = k; j < linha; j++) {
          matrizD[i][j] -=  termo * matrizD[k][j];
          //matrizD[i][j] = aux;
          //matrizD[i][j] + = aux;
          printf("matrizD[%d][%d]: %d\n", i, j, matrizD[i][j]);
        }
      }
      //printf("termo: %f\n", termo);
      imprimirMatriz(linha, coluna, matrizD);
        }

        // Escrevendo a matriz triangular superior
        imprimirMatriz( linha, coluna, matrizD);
        printf("\n");

        // Cálculo do determinante, usando a diagonal principal da matriz triangular superior
        for (int i = 0; i < linha; i++) {
          determinante *= matrizD[i][i];
        }

      }

      printf("O determinante da matriz é: %d\n", determinante);
      desalocaMatriz(linha, matrizD);
      printf("\n");
    }

  

// Função determinante de matrizes por LU
void determinanteMatrizesLU() {
  float **matrizP;
  int linha, coluna, pivot, aux, sinal = 1, k;
  float maxCol, termo = 1.0, determinante = 1;

  // Dados de entrada
  printf("Digite o tamanho da matriz separados por espaco (linha coluna): ");
  scanf(" %d %d", &linha, &coluna);

  printf("\n");

  // Verificar se a matriz é quadrada
  if (linha != coluna) {
    printf("A matriz não é quadrada. Não é possível calcular o determinante.\n");
    printf("\n");
    return;
    
  }
  // Alocando a matrizP
  matrizP = alocaMatriz(linha, coluna);

  // Digitando e imprimindo a matriz
  digitarMatriz(linha, coluna, matrizP);
  imprimirMatriz(linha, coluna, matrizP);
  printf("\n");

  // Processo de decomposição LU
  // Laço para transformar a matriz em triangular superior
  /* Script:
   1. Buscar maior valor da coluna: max_col do valor absoluto
   2. Trocar linha, se necessário
   3. Transformar em triangular superior
   4. Calcular o determinante */

  for (int i = 0; i < linha - 1; i++) {
    maxCol = fabs(matrizP[i][i]); // Maior valor da coluna
    pivot = i; // Posição do maior valor diferente de zero
    for (int k = i + 1; k < linha; k++) {
      if (fabs(matrizP[k][i]) > maxCol) {
        maxCol = fabs(matrizP[k][i]);
        pivot = k;
      }
    }
    // Trocar linha, se necessário
    if (pivot != i) {
      for (int k = i; k < linha; k++) {
        aux = matrizP[i][k]; 
        matrizP[i][k] = matrizP[pivot][k];
        matrizP[pivot][k] = aux;
      }
      sinal = -sinal; // A cada troca de linha inverte-se o sinal do determinante
    }
    // Verificando se o maior valor da coluna é zero
    if (matrizP[i][i] == 0) {
      determinante = 0;
      return;
    } else {
      // Transformar em triangular superior      
      for (int j = i + 1; j < linha; j++) {
        termo = (float)matrizP[j][i] / matrizP[i][i];
        for (int k = i; k < linha; k++) {
          matrizP[j][k] -= termo * matrizP[i][k];
        }
      }
    } 
  }
  // Escrevendo a matriz triangular superior
  printf("\nA matriz triangular superior é:\n");
  imprimirMatriz(linha, coluna, matrizP);
  printf("\n");

  // Cálculo do determinante, usando a diagonal principal da matriz triangular superior
  for (int i = 0; i < linha; i++) {
    determinante = determinante * matrizP[i][i];
  }
  determinante = determinante * sinal; // Multiplicando pelo sinal do determinante, devido as trocas de linha
  printf("O determinante da matriz é: %.2f\n", determinante);
  printf("\n");

  // Desalocando a matrizP
  desalocaMatriz(linha, matrizP);
}



// Função matriz triangular superior
void matrizTriangularSuperior() {
  int linhaA, colunaA;
  float **matrizA;
  int matrizResultado[10][10];

  printf("Digite os elementos da matriz:\n");
  printf("Digite o tamanho da matriz separados por espaco (linha coluna): ");
  scanf(" %d %d", &linhaA, &colunaA);
  digitarMatriz(linhaA, colunaA, matrizA);
  printf("\n");

  // Laço da matriz triangular superior
  for (int i = 0; i < linhaA; i++) {
    for (int j = 0; j < colunaA; j++) {
      if (i > j)
        matrizResultado[i][j] = 0;
    }  
  }  
}


// Determinante de matrizes usando decomposição LU
//void determinanteMatrizesLU() {}

/****************************************************************************
Main do programa
**************************************************************************** */ 

int main() {
  SetConsoleOutputCP(65001);

  int operacao = 3; // Variável para armazenar a operação a ser realizada;

  do {
    printf("Qual a operação a ser realizada com matrizes?\n");
    //scanf(" %d", &operacao);
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Transporte\n");
    printf("5 - Determinante(Método de Laplace)\n");
    printf("6 - Determinante(Método LU)\n");
    printf("7 - Inversa\n");
    printf("8 - Ortogonal\n");
    //printf("8 - Equação Matricial\n");
    printf("9 - Sair\n");
    printf("escolha: ");
    scanf(" %d", &operacao);

    switch (operacao) {
    case 1:
      printf("Operação de soma selecionada.\n");
      somaMatrizes();
      break;

    case 2:
      printf("Operação de subtração selecionada.\n");
      // Chame a função para realizar a subtração de matrizes
      subtracaoMatrizes();
      break;

    case 3: {
      printf("Operação de multiplicação selecionada.\n");
      // Chame a função para realizar a multiplicação de matrizes
      produtoMatrizes();
      break;
    }
    case 4: {
      printf("Operação de transporte selecionada.\n");
      // Chame a função para realizar o transporte de matrizes
      transporteMatrizes();
      break;
    }
    case 5: {
      printf("Operação de determinante selecionada.\n");
      // Chame a função para realizar o determinante usando o método de laplace de matrizes
      determinanteMatrizesLaplace();
      break;
    }
    case 6: {
      printf("Operação de determinante selecionada.\n");
      // Chame a função para realizar o determinante usando a decomposição LU de matrizes
      determinanteMatrizesLU();
      break;
    }
    case 7: {
      printf("Operação de matriz inversa selecionada.\n");
      // Chame a função para realizar a ortogonal de matrizes
      break;
    }
    case 8: {
      printf("Operação de equação matricial selecionada.\n");
      // Chame a função para realizar a equação matricial de matrizes
      break;
    }
    case 9: {
      printf("Saindo do programa.\n");
      break;
    }
    default:
      printf("Operação inválida. Tente novamente.\n");
      break;
    }

  } while (operacao != 9);

  return 0;
}

