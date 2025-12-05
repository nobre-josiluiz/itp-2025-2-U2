/******************************************************************************

Lista de exercícios - semana 3
Problema 7 - Sistema de equações do 2º grau
Programa que resolve equações do segundo grau (ax² + bx + c = 0). O programa deve:
    Ler os coeficientes a, b e c
    Verificar se é uma equação do segundo grau (a ≠ 0)
    Calcular o discriminante (Δ = b² - 4ac)
    Determinar e exibir as raízes conforme o caso:
        Se Δ > 0: duas raízes reais distintas
        Se Δ = 0: uma raiz real
        Se Δ < 0: não possui raízes reais

    Fórmula das raízes: x = (-b ± √Δ) / (2a)

*******************************************************************************/


#include <stdio.h> // Incluir a biblioteca stdio.h 
#include <math.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float a, b, c, delta; // coeficientes da equação do 2º e discriminante

  printf("Digite o valor do coeficiente do termo x² da equação do 2º grau (a): ");
  scanf(" %f", &a);
  if (a == 0) {
    printf("\nInválido! Nesse caso, não representa uma equação do 2º. Digite um valor diferente de zero.");
    return 1;
  }

  printf("Digite o valor do coeficiente do 2º termo x da equação (b): ");
  scanf(" %f", &b);

  printf("Digite o valor do termo independente da equação (c): ");
  scanf(" %f", &c); 

  printf("\n %.1fx² + %.1fx + %.1f = 0", a, b, c);
  // Cálculo das raízes

  delta = b*b - 4*a*c;

  if (delta >= 0) {
    if (delta == 0) {
      printf("\nA equação possui uma única raiz: x = %.1f ", (b*(-1))/2*a);
    } else {
      printf("\nA equação possui duas raízes distintas: x' = %.1f e x'' = %.1f ", ((-b - sqrt(delta))/2*a), ((-b + sqrt(delta))/2*a) );
    }
  } else printf("\nA equação não possui raízes reais.");

  return 0;
}