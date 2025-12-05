/******************************************************************************

Lista de exercícios - semana 4

Problema 2 - salve o homem aranha
O homem aranha tem levado algumas quedas enquanto perambula pela cidade, pois às vezes a teia não é
longa o suficiente para alcançar o prédio. Então ele resolveu pedir a sua ajuda. 
Seu programa deve ler como
entrada:
    1. A coordenada inicial do homem aranha (x, y)
    2. O comprimento máximo da teia (float)
    3. Um inteiro n representando a quantidade de alvos onde ele vai lançar a teia
    4. n coordenadas dos alvos (x, y)
Todos os componentes das coordenadas devem ser declarados como float.
Estando o alvo em (ax, ay) e o homem aranha em (x, y), se ele conseguir fixar a teia no alvo, sua nova
coordenada (x′, y′) será:
(x′, y′) = (2ax − x, y)
*******************************************************************************/


#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float x, y, a_x, a_y, comprimento_teia, dist; // valores das coordenadas
  int n, i; // n-quantidade de alvos

  //Inserindo os valores de entrada.
  printf("Digite a posição, separados por espaço, inicial do homem aranha (x, y): ");
  scanf(" %f %f", &x, &y);

  printf("Digite o comprimento máximo da teia: ");
  scanf(" %f", &comprimento_teia);

  // Validando valores de entrada 
  if (comprimento_teia <= 0) {
    printf("\nCuidado! O comprimento da teia precisa ser positivo.");
    return 1;
  }

  printf("Digite a quantidade de alvos: ");
  scanf(" %d", &n);

  //Laço de alvos
  for (int i = 1; i <= n; i++) {
    printf("Digite o próximo alvo (x, y): ");
    scanf(" %f %f", &a_x, &a_y);
    dist = sqrt(pow((x - a_x),2) + pow((y - a_y),2));
      if (dist <= comprimento_teia) x = 2*a_x - x;
      else {
        printf("\n N");
        return 1;
      }
  }

  printf("\n S");

  return 0;
}