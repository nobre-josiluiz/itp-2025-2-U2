/*
* Lista de exercícios - semana 8
* Problema 2 - Os dias mais chuvosos
* Escreva um programa que leia 12 inteiros, representando a quantidade de chuva em cada um desses meses
* (de Janeiro até Dezembro). O programa deve em seguida escrever na tela um ranking ordenado do mês com
* mais chuva para o mês com menos chuva. Em cada linha da saída deve constar o mês e a quantidade de
* chuva. Você pode utilizar o arquivo q2inicial.c disponível no github como código inicial. Para simplificar a
* questão, você pode assumir que não há dois meses com a mesma quantidade de chuva.
* Para ordenar, utilize um desses três algoritmos: bubble sort, selection sort ou insertion sort.
*/


#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    int quantidadeChuva[12];
    char mes[12][10] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char tempoMes[10];  

    printf("Digite a quantidade de chuva (em mm) para cada mês:\n");
    for (int i = 0; i < 12; i++) {
        printf("Digite a quantidade de chuva para o mês de %s: ", mes[i]);
        scanf("%d", &quantidadeChuva[i]);    
    }

         // colocando a quantidade de chuva em ordem decrescente, usando o algoritmo bubble sort.
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12 - 1; j++) {
            if (quantidadeChuva[j] < quantidadeChuva[j + 1]) {
                int temp = quantidadeChuva[j];
                quantidadeChuva[j] = quantidadeChuva[j + 1];
                quantidadeChuva[j + 1] = temp;
                strcpy(tempoMes, mes[j]);
                strcpy(mes[j], mes[j + 1]);
                strcpy(mes[j + 1], tempoMes);
            }
        }
    }
    printf("\n");

    // Resultado do ranking
    printf("Ranking dos meses mais chuvosos em mm:\n");
    for (int i = 0; i < 12; i++) 
        printf("%s %d \n", mes[i], quantidadeChuva[i]);

  

    return 0;
}