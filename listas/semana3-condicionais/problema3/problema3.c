/*
* Lista de exercícios - semana 3
* Problema 3 - Sistema de notas
* Desenvolver um programa que leia três notas de um aluno e calcule sua média. O programa deve:
    # Calcular a média aritmética
    # Determinar se o aluno foi aprovado (média ≥ 7.0), reprovado (média < 4.0) ou está em recuperação
      (4.0 ≤ média < 7.0)
    # Se estiver em recuperação, calcular qual nota precisa tirar na prova final para ser aprovado (média
      final ≥ 5.0, onde média final = (média + nota final)/2)

*/

#include <stdio.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);
  float nota1, nota2, nota3, media, notaFinal;

  printf("Digite as três notas do aluno: ");
  scanf("%f  %f  %f", &nota1, &nota2, &nota3);

  printf("\n");

  // Validação dos valores de entrada
  if (nota1 < 0 || nota2 < 0 || nota3 < 0) {
    printf("Valores inválidos. As notas devem ser não negativas.\n");
    return 1;
  }

  // Cálculo da média
  media = (nota1 + nota2 + nota3) / 3; 

  // Determinar a situação do aluno 
  if (media >= 7.0) {
    printf("O aluno foi aprovado com média %.2f.\n", media);
  } else if (media < 4.0) {
    printf("O aluno foi reprovado com média %.2f.\n", media);
  } else if (media >= 4.0 && media < 7.0) {
    printf("O aluno está em recuperação com média %.2f.\n", media);
    notaFinal = (5.0 * 2) - media;

  printf("O aluno precisa tirar %.2f na prova final para ser aprovado.\n", notaFinal);

  }
  return 0;
}