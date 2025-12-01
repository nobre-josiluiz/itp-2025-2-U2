/*
* Lista de exercícios - semana 7
* Problema 2 - Detecção de placas
* Você está implementando um detector de placas de carro. Uma das coisas que facilitará a busca na base
* de dados é saber se a placa está no padrão brasileiro ou no padrão mercosul. A tabela a seguir especifica o
* formato relativo aos dois padrões (L indica uma letra maiúscula e A um algarismo).

* Programa que lê uma palavra (sem espaços) de até 10 caracteres e escreva “brasileiro” ou “mercosul”
* se estiver de acordo com um padrão ou outro, ou ainda “inválido” caso não se enquadre em nenhum dos dois.
*/


#include <stdio.h>
#include <string.h> 
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001); // Configura o console para exibir caracteres UTF-8
  char palca[10]; // 10 caracteres para armazenar a palavra
  int indice;  

  printf("Digite uma palavra no formato de placa(sem espaços) do tipo (LLL-AAAA), (LLLALAA): "); 
  scanf("%s", palca);

  if (strlen(palca) == 8) { // Verifica se a palavra tem 8 caracteres
    // Verifica se os caracteres estão no formato correto para uma placa brasileira
    if (palca[0] >= 'A' && palca[0] <= 'Z' && palca[1] >= 'A' && palca[1] <= 'Z' && palca[2] >= 'A' && palca[2] <= 'Z' && palca[3] == '-' && palca[4] >= '0' && palca[4] <= '9' && palca[5] >= '0' && palca[5] <= '9' && palca[6] >= '0' && palca[6] <= '9' && palca[7] >= '0' && palca[7] <= '9')
      printf("brasileiro\n");
    else printf("inválido\n");       
    // Verifica se os caracteres estão no formato correto para uma placa mercosul
  } else if (strlen(palca) == 7) {
    if (palca[0] >= 'A' && palca[0] <= 'Z' && palca[1] >= 'A' && palca[1] <= 'Z' && palca[2] >= 'A' && palca[2] <= 'Z' && palca[3] >= '0' && palca[3] <= '9' && palca[4] >= 'A' && palca[4] <= 'Z' && palca[5] >= '0' && palca[5] <= '9' && palca[6] >= '0' && palca[6] <= '9') 
      printf("mercosul\n");
    else printf("inválido\n");
  } else printf("inválido\n");
  
  return 0;
}