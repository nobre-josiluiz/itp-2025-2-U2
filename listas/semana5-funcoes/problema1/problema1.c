/*
* Lista de exercícios - semana 5
* Problema 1 - Horários das rondas

* A entrada do programa consiste em 2 inteiros contendo horas e minutos da
primeira ronda (sempre no formato 24h), seguidos de um inteiro, tal que 0
significa escrever os horários das rondas no formato 24h e 1 no formato 12h. O
programa deve escrever na saída os horários de todas as rondas obedecendo os
seguintes acréscimos em relação ao horário da primeira ronda: 1h, 2h10m, 4h40m e
12h5m.

Para resolver essa questão, seu programa deve implementar uma função que escreve
um horário na tela, tratando os casos em que as horas e/ou os minutos estão fora
do intervalo. Por exemplo, se o horário passado for 25 horas e 10 minutos, a
função deve escrever 1 hora e 10 minutos (passou de um dia para o outro) – isso
deve facilitar bastante a programação do resto.
*/

#include <stdio.h>
#include <time.h>
#include <windows.h>


int transformarHora(int hora) {
  if (hora >= 0 && hora < 13) return hora;
  else if (hora >= 13 && hora < 24) return hora - 12;
  else if (hora >= 24 && hora < 36) return hora - 24;
  else if (hora >= 36 && hora < 48) return hora - 36;  
  else return hora - 48;
}

void adequarHorario(int hora, int minuto, int escolha) {
  if (escolha == 0) {
    if (hora >= 24 && minuto >= 60) {
      minuto = minuto - 60;
      hora = hora - 24;
      printf("%02d:%02d \n", hora, minuto);
    } else if (hora >= 24 && minuto < 60) {
      hora = hora - 24;
      printf("%02d:%02d \n", hora, minuto);
    } else if (hora >= 12 && hora < 24 && minuto >= 60) {
      minuto = minuto - 60;
      hora = hora + 1;
      printf("%02d:%02d \n", hora, minuto);
    } else if (hora >= 0 && hora < 12 && minuto >= 60) {
      minuto = minuto - 60;
      hora = hora + 1;
      printf("%02d:%02d \n", hora, minuto);
    } else {
      printf("%02d:%02d \n", hora, minuto);
    }
  } else if (escolha == 1) {
    if (hora >= 24 && minuto >= 60) {
      minuto = minuto - 60;
      hora = hora - 24 + 1;
      printf("%02d:%02d AM\n", transformarHora(hora), minuto);
    } else if (hora >= 24 && minuto < 60) {
      hora = hora - 24;
      printf("%02d:%02d AM\n", transformarHora(hora), minuto);
    } else if (hora >= 12 && hora < 24 && minuto >= 60) {
      minuto = minuto - 60;
      hora = hora + 1;
      printf("%02d:%02d PM\n", transformarHora(hora), minuto);
    } else if (hora >= 0 && hora < 12 && minuto >= 60) {
      minuto = minuto - 60;
      hora = hora + 1;
      printf("%02d:%02d AM\n", transformarHora(hora), minuto);
    } else if (hora >= 0 && hora < 12 && minuto < 60) {
      printf("%02d:%02d AM\n", transformarHora(hora), minuto);
    } else {
      printf("%02d:%02d PM\n", transformarHora(hora), minuto);
    }
  } else {
    printf("Formato inválido!\n");
  }
}




// Função principal
int main() {
  SetConsoleOutputCP(65001);

  int h, m, f;

  printf("Digite a hora, minuto e formato(0 ou 1): ");
  scanf("%d %d %d", &h, &m, &f);  

  adequarHorario(h, m, f);
  adequarHorario(h + 1, m, f);
  adequarHorario(h + 2, m + 10, f);
  adequarHorario(h + 4, m + 40, f);
  adequarHorario(h + 12, m + 5, f);

  return 0;

} 