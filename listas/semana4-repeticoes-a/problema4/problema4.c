/******************************************************************************

Lista de exercícios - semana 4

Problema 4 - jogo de dardos
Cansados das mesmas regras do jogo de dardos, um grupo de amigos resolveu inovar: ganha pontos não
só quem acerta mais perto do alvo, mas ganha também uma pontuação bônus (metade da principal) quem
acerta próximo do último lançamento. Afinal, quem lança errado sempre no mesmo lugar também tem boa
pontaria, ela só não está calibrada.
O seu programa deve ler as coordenadas (x, y), dois números reais, de 10 lançamentos e escrever na tela a
pontuação total.
Distância Pontuação principal Pontuação bônus
[0, 1] +10 pts +5 pts
]1, 2] +6 pts +3 pts
]2, 3] +4 pts +2 pts
Acima de 3 0 pts 0 pts
O centro do alvo sempre está em (0, 0), a distância é dada pela distância euclidiana
(https://pt.wikipedia.org/wiki/Dist%C3%A2ncia_euclidiana) e, claro, não há pontuação bônus para o
primeiro lançamento, pois não há lançamento anterior.
*******************************************************************************/


#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float x, y, dist; // valores das coordenadas
  int pontuacao = 0, i, cont1 = 0, cont2 = 0, cont3 = 0; // n-quantidade de alvos

  // loop para ler as coordenadas e calcular a pontuação
  for (int i = 1; i < 11; i++) {
    printf("\n Digite as coordenadas, separadas por espaço, do lançamento %d: ", i);
    scanf(" %f %f", &x, &y);
    dist = sqrt( x*x + y*y);

    // condicionais para calcular a pontuação
    if (dist >= 0 && dist <= 1) {
      pontuacao += 10;
      cont1++;
      if (cont1 > 1) pontuacao += 5;
    } else if (dist > 1 && dist <= 2) {
      pontuacao += 6;
      cont2++;
      if (cont2 > 1) pontuacao += 3;
    } else if (dist > 2 && dist <= 3) {
      pontuacao += 4;
      cont3++;
      if (cont3 > 1) pontuacao += 2;
    } else pontuacao += 0;    
  }    
  printf("\n A pontuação total será de: %d pontos.", pontuacao);
  
  return 0;
}