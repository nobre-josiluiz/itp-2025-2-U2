/*****************************************************************************************
******************************************************************************************
* PROGRAMA SIMULANDO UMA CALCULADORA DE MATRIZES
* OPERAÇÕES:
* 1 - SOMA
* 2 - SUBTRAÇÃO
* 3 - MULTIPLICAÇÃO
* 4 - TRANSPORTE
* 5 - DETERMINANTE(MÉTODO DE LAPLACE)
* 6 - DETERMINANTE(MÉTODO LU)
* 7 - COFATOR, ADJUNTA E INVERSA
* 8 - CAÇA PALAVRAS
* 9 - SAIR
*
******************************************************************************************
******************************************************************************************/

#include <stdio.h> // Incluir a biblioteca stdio.h
#include <stdlib.h>
#include <math.h>
#include <string.h> // Para strlen
#include <ctype.h>  // Para isspace - verificar se é espaço em branco, para a função caça palavras
#include <windows.h>

/****************************************************************************
Declaração das funções: alocando matrizes 
*****************************************************************************/

// Função alocando matrizes
float** alocaMatriz(int linhas, int colunas) {

    float **matriz = (float **)malloc(linhas * sizeof(int*)); 
    
    if (matriz == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para a matriz.\n");
        return NULL;
    }
    for (int i = 0; i < linhas; i++){ // Aloca memória para cada linha da matriz
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
        free(matriz[i]);  // Libera a memória alocada para cada linha da matriz
        matriz[i] = NULL; 
    } 
    free(matriz);  // Libera a memória alocada para o vetor de ponteiros
    matriz = NULL;  // Define o ponteiro para NULL para evitar problemas futuros
}


/****************************************************************************
Escopo das funções para realizar as operações com matrizes
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
        printf("As matrizes não têm o mesmo tamanho. Não é possível realizar a soma.\n");
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
        printf("As matrizes não têm o mesmo tamanho. Não é possível realizar a soma.\n");
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

// Função determinante de matrizes por Laplace - recursiva
float determinanteSubmatriz(float **matriz, int linha, int coluna) {
    float determinante = 0;
    if (linha == 1 && coluna == 1) {
        determinante = matriz[0][0];
    } else if (linha == 2 && coluna == 2) {
        determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    } else if ( linha > 2 && coluna > 2) {
        for (int i = 0; i < linha; i++) {
            float **submatriz = alocaMatriz(linha - 1, coluna - 1);
            int aux1 = 0;
            for (int j = 1; j < linha; j++) {
                int aux2 = 0;
                for (int k = 0; k < linha; k++) {
                    if (k != i) {
                        submatriz[aux1][aux2] = matriz[j][k];
                        aux2++;
                    }
                }
                aux1++;
            }
            determinante += pow(-1, i) * matriz[0][i] * determinanteSubmatriz(submatriz, linha - 1, coluna - 1);
            //desalocaMatriz(linha - 1, submatriz);
        }
    }
    //desalocaMatriz(linha, matriz);
    return determinante;  
} 

// Função determinante de matrizes por Laplace
float determinanteMatrizesLaplace(float **matriz) {
    int linha, coluna;
    float **matrizD;
    float **submatriz;
    float determinante = 0;
    int aux1, aux2;


    printf("Digite o tamanho da matriz separados por espaco (linha coluna): ");
    scanf(" %d %d", &linha, &coluna);
    printf("\n");
    // Verificar se a matriz é quadrada
    if (linha != coluna) {
        printf("A matriz não é quadrada. Não é possível calcular o determinante.\n");
        printf("\n");
        return 1;
    }

    // Alocando memória para a matriz
    matrizD = alocaMatriz(linha, coluna);
    // Digitando a matriz
    digitarMatriz(linha, coluna, matrizD);
    printf("\n");
    imprimirMatriz(linha, coluna, matrizD);
    printf("\n");

    // Laço do determinante das matrizes
    //determinante = 0;
    if (linha == 1 && coluna == 1) {
        determinanteSubmatriz(matrizD, linha, coluna);
    }
    for (int i = 0; i < linha; i++) {
        submatriz = alocaMatriz(linha - 1, coluna - 1);
        aux1 = 0; // Linha da submatriz
        for (int j = 1; j < linha; j++) {
            aux2 = 0; // Coluna da submatriz
            for (int k = 0; k < linha; k++) {
                if (k != i) {
                    submatriz[aux1][aux2] = matrizD[j][k];
                    aux2++;
                }
            }
            aux1++;
        }
      
        determinante += pow(-1, i) * matrizD[0][i] * determinanteSubmatriz(submatriz, linha - 1, coluna - 1);
        
        desalocaMatriz(linha - 1, submatriz);

    }

    printf("O determinante da matriz é: %.2f\n", determinante);
    desalocaMatriz(linha, matrizD);
    printf("\n");
    return determinante;

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

// Função matriz dos cofatores, adjunta e inversa
void matrizInversa() {
    int linhaA, colunaA;
    float **matrizA;
    float **submatriz;
    float **matrizInversa;
    float **matrizAdjunta;
    float **matrizCofatores;
    int aux1, aux2;

    printf("Digite o tamanho da matriz separados por espaco (linha coluna): ");
    scanf(" %d %d", &linhaA, &colunaA);

    // Verificar se a matriz é quadrada
    if (linhaA != colunaA) {
        printf("A matriz não é quadrada. Não é possível prosseguir.\n");
        printf("\n");
        return;
    }

    // Alocando memória para a matriz
    matrizA = alocaMatriz(linhaA, colunaA);
    // Digitando a matriz
    digitarMatriz(linhaA, colunaA, matrizA);
    printf("\n");
    //printf("Matriz original:\n");
    imprimirMatriz(linhaA, colunaA, matrizA);
    printf("\n");

    // Verificando se o determinante é diferente de zero    
    if (determinanteSubmatriz(matrizA, linhaA, colunaA) == 0) {
        printf("O determinante da matriz é zero. Não é possível calcular a matriz inversa.\n");
        return;
    } 

    printf("Determinante %5.2f \n", determinanteSubmatriz(matrizA, linhaA, colunaA));

    // Caso especial: matriz 1x1
    if (linhaA == 1 && colunaA == 1) {
        if (matrizA[0][0] == 0) {
            printf("Matriz unitária nula. Não é possível calcular a matriz inversa.\n");
        } else {
            printf("A matriz inversa de uma matriz 1x1 é: %5.2f\n", 1 / matrizA[0][0]);    
        }        
        desalocaMatriz(linhaA, matrizA);
        printf("\n");
        return;
    }

    // Alocando memória para cofatores e adjunta
    matrizCofatores = alocaMatriz(linhaA, colunaA);
    matrizAdjunta = alocaMatriz(linhaA, colunaA);
    matrizInversa = alocaMatriz(linhaA, colunaA);

    // Calculando a matriz de cofatores
    for (int i = 0; i < linhaA; i++) {
        for (int j = 0; j < colunaA; j++) {
        // Alocando submatriz para cada elemento
            submatriz = alocaMatriz(linhaA - 1, colunaA - 1);
            aux1 = 0;

            // Criando submatriz removendo linha i e coluna j
            for (int k = 0; k < linhaA; k++) {
                if (k != i) {
                    aux2 = 0;
                    for (int l = 0; l < colunaA; l++) {
                        if (l != j) {
                            submatriz[aux1][aux2] = matrizA[k][l];
                            aux2++;
                        }
                    }
                aux1++;
                }
            }

            // Calculando cofator: (-1)^(i+j) * determinante da submatriz
            matrizCofatores[i][j] = pow(-1, i + j) * determinanteSubmatriz(submatriz, linhaA - 1, colunaA - 1);

            // Desalocando submatriz
            desalocaMatriz(linhaA - 1, submatriz);
        }
    }

    // A matriz adjunta é a transposta da matriz de cofatores
    for (int i = 0; i < linhaA; i++) {
        for (int j = 0; j < colunaA; j++) {
            matrizAdjunta[j][i] = matrizCofatores[i][j];
        }
    }

    // Calculando a matriz inversa: adjunta / determinante
    for (int i = 0; i < linhaA; i++) {
        for (int j = 0; j < colunaA; j++) {
            matrizInversa[i][j] = matrizAdjunta[i][j] / determinanteSubmatriz(matrizA, linhaA, colunaA);
        }
    }

        // Imprimindo resultados
    printf("--------------------------------\n");
    printf("Matriz dos cofatores:\n");
    imprimirMatriz(linhaA, colunaA, matrizCofatores);
    printf("\n");
    printf("--------------------------------\n");

    printf("Matriz adjunta (transposta dos cofatores):\n");
    imprimirMatriz(linhaA, colunaA, matrizAdjunta);
    printf("\n");
    printf("--------------------------------\n");

    printf("Matriz inversa:\n");
    imprimirMatriz(linhaA, colunaA, matrizInversa);
    printf("\n");
    printf("--------------------------------\n");

    // Desalocando matrizes
    desalocaMatriz(linhaA, matrizA);
    desalocaMatriz(linhaA, matrizCofatores);
    desalocaMatriz(linhaA, matrizAdjunta);
    desalocaMatriz(linhaA, matrizInversa);


}


//------------------

/* Função caça palavras: encontrar palavras pela disposição de letras 
aleatorias dispostas numa matriz. */ 
void cacaPalavras() {
    int linha, coluna;
    char **matriz;
    char palavra[100];
    int tamPalavra; // tamanho da palavra
    int dirAtual = 0;
    int posLinha, posColuna; // posicão linha e coluna
    int dirLinha, dirColuna; // direção linha e coluna
    int i, j, k;

    printf("Digite o tamanho da matriz separados por espaco (linha coluna): "); 
    scanf(" %d %d", &linha, &coluna);
    printf("\n");

    // Alocando memória para a matriz de strings
    matriz = (char **)malloc(linha * sizeof(char *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        return;
    }
    for (i = 0; i < linha; i++) {
        matriz[i] = (char *)malloc(coluna * sizeof(char));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d da matriz.\n", i);
            return;
        }         
    }
    // Gerando a matriz com letras aleatórias
    printf("-------------------------------\n");
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            matriz[i][j] = 'A' + rand() % 26;
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------\n");

    // Digitando a palavra a ser encontrada
    printf("\nDigite a palavra a ser encontrada sem espaços: ");
    getchar(); // Limpa o '\n'(espaço) 
    fgets(palavra, sizeof(palavra), stdin); // Lê a linha inteira, incluindo espaços e o enter

    // Removendo o '\n'(espaço) do final da string
    tamPalavra = strlen(palavra);
    if (tamPalavra > 0 && palavra[tamPalavra - 1] == '\n') {
        palavra[tamPalavra - 1] = '\0';
        tamPalavra--; 
    }
    printf("\n");

    // Verificando se a palavra é válida: apenas letras de (A-Z), sem espaços e sem caracteres especiais 
    for (j = 0; palavra[j] != '\0'; j++) { 
        // Verificando se a palavra tem espaços primeiro
        if (isspace((unsigned char)palavra[j])) {  
            printf("Palavra inválida. Digite uma palavra sem espaços.\n");
            printf("\n");
            return;
        }
        // Convertendo para maiúscula para comparar com a matriz
        if (palavra[j] >= 'a' && palavra[j] <= 'z') {
            palavra[j] = palavra[j] - 32; // Converte minúscula para maiúscula
        }
        // Verificando se é uma letra válida (A-Z)
        if (palavra[j] < 'A' || palavra[j] > 'Z') {
            printf("Palavra inválida. Digite uma palavra apenas com letras (sem números ou caracteres especiais).\n");
            printf("\n");
            return;
        }      
    }     
    

    // Procurando a palavra na matriz
    int achou = 0;
    for ( i = 0; i < linha && !achou; i++) { // !achou nega a condição, enquanto não achar
        for (j = 0; j < coluna && !achou; j++) { 
            // Verificando se a primeira letra da palavra corresponde à posição atual da matriz
            if (matriz[i][j] == palavra[0]) { 
                // Verificando todas as direções possíveis
                for (dirLinha = -1; dirLinha <= 1 && !achou; dirLinha++) { 
                    for (dirColuna = -1; dirColuna <= 1 && !achou; dirColuna++) { 
                        if (dirLinha != 0 || dirColuna != 0) {  // Ignorando a direção (0,0)
                            posLinha = i;  
                            posColuna = j;  
                            dirAtual = 1; // Variável que verifica se a string está na direção atual
                            // Verificando o resto da palavra
                            for (k = 1; k < tamPalavra && dirAtual; k++) { 
                                posLinha += dirLinha; // Atualiza as posições atuais da linha e coluna
                                posColuna += dirColuna;
                                // Verificando se a posição está dentro dos limites da matriz e se a string corresponde
                                if (posLinha < 0 || posLinha >= linha || posColuna < 0 || posColuna >= coluna ) dirAtual = 0;
                                else if (matriz[posLinha][posColuna] != palavra[k]) dirAtual = 0;                               
                            }
                            if (dirAtual) achou = 1; // Se a palavra foi achada na direção atual e marca como achada
                        }
                    }
                }
            }
        }
    }    
    
    if (achou) {
        printf("Palavra encontrada!\n");
    } else { 
        printf("Palavra não encontrada.\n");
    }   
    
    // Desalocando matriz 
    for (i = 0; i < linha; i++) {
        free(matriz[i]);
        matriz[i] = NULL;
    } 
    free(matriz);

    printf("\n");
} 



/****************************************************************************
Main do programa
**************************************************************************** */ 

int main() {
  SetConsoleOutputCP(65001);
  int operacao = 3; // Variável para armazenar a operação a ser realizada;
  float **matriz;

  do {
    printf("Qual a operação a ser realizada com matrizes?\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Transporte\n");
    printf("5 - Determinante(Método de Laplace)\n");
    printf("6 - Determinante(Método LU)\n");
    printf("7 - Cofator, Adjunta e Inversa\n");
    printf("8 - Caça palavras\n");
    printf("9 - Sair\n");
    printf("escolha: ");
    scanf(" %d", &operacao);

    // Executar a operação selecionada
    switch (operacao) {
      case 1: {
        printf("Operação de soma selecionada.\n");
        somaMatrizes();
        break;
      }
      case 2: {
        printf("Operação de subtração selecionada.\n");
        // Chame a função para realizar a subtração de matrizes
        subtracaoMatrizes();
        break;
      }
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
        determinanteMatrizesLaplace(matriz);
        break;
      }
      case 6: {
        printf("Operação de determinante selecionada.\n");
        // Chame a função para realizar o determinante usando a decomposição LU de matrizes
        determinanteMatrizesLU();
        break;
      }
      case 7: {
        printf("Operação de matriz dos cofatores, adjunta e inversa selecionada.\n");
        // Chame a função para realizar a adjunta, cofator e inversa de matrizes
        //A matriz adjunta é a transposta da matriz de cofatores de uma matriz quadrada original.
        // Matriz inversa é a adjunta dividida pelo determinante da matriz original.
        matrizInversa();
        break;
      }
      case 8: {
        printf("Operação de caça palavras selecionada.\n");
        // Chame a função para realizar o caça palavras com matrizeszes
        cacaPalavras();
        break;
      }
      case 9: {
        printf("Saindo do programa.\n");
        break;
      }
      default: {
        printf("Operação inválida. Tente novamente.\n");
        break;
      }
    } 
    } while (operacao != 9);

    return 0;
}
