/******************************************************************************

Lista de exercícios - semana 4

Problema 1 - dobrando até não poder mais
    * Problema: precisa dobrar uma folha na metade algumas vezes para que caiba em seu bolso. 
    * lê o comprimeiro, a largura da folha e o comprimento do bolso (declare como float). 
    * Calcular quantas vezes será necessário dobrar a folha para que caiba no bolso (um dos 
lados da folha dobrada deve ser menor que o comprimento do bolso). 
    * Para facilitar a dobra, considere que você sempre dobra a folha para reduzir o maior dos lados.        
*******************************************************************************/

#include <stdio.h> 
#include <windows.h>  

int main() {
  SetConsoleOutputCP(65001); //Para imprimir acentos corretamente no terminal do Windows
  float comprimento, largura, comprimento_bolso; // dimensões da folha e comprimento do bolso
  int cont = -1; // contador de dobras

  //Inserindo os valores de entrada.
  printf("Digite as dimensões, separados por espaço, da folha no formato (comprimento, largura): ");
  scanf(" %f %f", &comprimento, &largura);

  // Validando valores de entrada 
  if (comprimento <= 0 || largura <= 0) {
    printf("\nCuidado! Os valores precisam ser positivos, pois são medidas.");
    return 1;
  }

  printf("Digite a medida do comprimento do bolso: ");
  scanf(" %f", &comprimento_bolso);

  // Validando valores de entrada 
  if (comprimento_bolso <= 0) {
    printf("\nCuidado! O valor do comprimento do bolso precisa ser positivo.");
    return 1;
  }

  //Caso em que não precisa dobrar
  if (comprimento <= comprimento_bolso || largura <= comprimento_bolso) {
    printf("\nNão será necessário dobrar, pois pelo menos um dos lado é menor do que o comprimento do bolso.");
    return 1;
  }

  //Laço de contagem de dobras
  while (comprimento > comprimento_bolso || largura > comprimento_bolso) {
    if (comprimento >= largura) comprimento = comprimento/2;
    else largura = largura/2;
    cont++;
  }
  printf("\nSerá necessário dobrar %d vez(es) a folha para que caiba no bolso.", cont);

  return 0;
}