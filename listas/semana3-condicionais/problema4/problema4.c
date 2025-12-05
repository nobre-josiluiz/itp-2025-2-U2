/*
* Lista de exercícios - semana 3
* Problema 4 - Jogo: pedra, papel, tesoura
* Programa que simula uma partida de "pedra, papel, tesoura". O programa deve:
  # Ler a jogada do jogador 1 (P para pedra, A para papel, T para tesoura)
  # Ler a jogada do jogador 2 (P para pedra, A para papel, T para tesoura)
  # Determinar e exibir o vencedor seguindo as regras:
    Pedra vence Tesoura
    Tesoura vence Papel
    Papel vence Pedra
    Jogadas iguais resultam em empate
*/

#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  char jogador1, jogador2;  //(P para pedra, A para papel, T para tesoura)

  printf("Digite a jogada do jogador 1 (P para pedra, A para papel, T para tesoura): ");
  scanf(" %c", &jogador1);

  // Validação dos valores de entrada do jogador 1
  if (jogador1 != 'P' && jogador1 != 'A' && jogador1 != 'T') {
    printf("\nJogada inválida para o jogador 1. Use P, A ou T.\n");
    return 1;
  }

  // Validação dos valores de entrada do jogador 2
  printf("Digite a jogada do jogador 2 (P para pedra, A para papel, T para tesoura): ");
  scanf(" %c", &jogador2);

  if (jogador2 != 'P' && jogador2 != 'A' && jogador2 != 'T') {
    printf("\nJogada inválida para o jogador 2. Use P, A ou T.\n");
    return 1;
  }  
  printf("\n");
  
  // Exibindo o vencedor ou empate
  if (jogador1 == jogador2) {
    printf("Empate entre os jogadores!\n");
  } else if ((jogador1 == 'P' && jogador2 == 'T') || (jogador1 == 'T' && jogador2 == 'A') || (jogador1 == 'A' && jogador2 == 'P')) {
    printf("O Jogador 1 é o vencedor!\n");
  } else { 
    printf("O Jogador 2 é o vencedor!\n");
  }

  return 0;
}