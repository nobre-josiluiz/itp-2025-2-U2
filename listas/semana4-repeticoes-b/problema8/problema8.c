/******************************************************************************

Lista de exercícios - semana 4

Problema 8 - Compras de fornecedores

Você está trabalhando em uma empresa e está responsável pela compra de placas de
alumúnio. Seu chefe pediu para que uma certa quantia de dinheiro fosse gasto em unidades
dessas placas de 2 fornecedores diferentes, mas ele quer que o dinheiro restante seja o menor
possível. Cada fornecedor pode vender no máximo 10 unidades. Como o prazo está em
cima, você pensou em testar no papel todas as possibilidades, mas logo viu que são 121
combinações e será mais rápido escrever um programa com estruturas de repetição em C
para resolver o seu problema. 
Escreva um programa que faça a leitura: do preço de cada
unidade do material do primeiro fornecedor, do preço do segundo fornecedor e da quantia
disponível para compra. Em seguida o programa deve escrever na tela quanto resta em
cada uma das possibilidades, desde que a compra seja possível.
*******************************************************************************/



#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float preco_fornecedor1, preco_fornecedor2, quantia_disponivel, total;
  int i, j; // índices

  //Dados de entrada
  printf("Digite o preço do primeiro fornecedor: ");
  scanf(" %f", &preco_fornecedor1);

  printf("Digite o preço do segundo fornecedor: ");
  scanf(" %f", &preco_fornecedor2);

  printf("Digite a quantia disponível: ");
  scanf(" %f", &quantia_disponivel);

  //Validação
  if(preco_fornecedor1 <= 0 || preco_fornecedor2 <= 0 || quantia_disponivel <= 0) {
    printf("Cuidado, digite valores positivos.");
    return 1;
  }

  //Construção: bloco principal
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      total = preco_fornecedor1*i + preco_fornecedor2*j; 
      if(total - quantia_disponivel <= 0)  // se a compra for possível    
        printf("Comprando %d do primeiro e %d do segundo resta: %.2f \n", i, j, quantia_disponivel - total);
    }   
  }
  return 0;
}