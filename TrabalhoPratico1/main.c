/**
 * @file main.c
 * @brief Programa principal para gerenciar uma lista de antenas.
 *
 * Este programa permite ao usuário inserir, remover e mostrar antenas em uma grade.
 * As antenas são armazenadas em uma lista ligada.
 */

#define _CRT_SECURE_NO_WARNINGS

#include "Dados.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "Funcoes.h"

int main() {
    int opcao = -1; // Opção escolhida pelo usuário.
    char freq; // Frequência da antena.
    int x, y; // Coordenadas da antena.
    Antenna* inicio = NULL; // Ponteiro para o início da lista de antenas.
    Antenna* aux; // Ponteiro auxiliar para a nova antena.
    Nefasto* ini1 = NULL;

    while (opcao != 0) {
        printf("1 - Inserir Antena\n");
        printf("2 - Remover Antena\n");
        printf("3 - Mostrar grid\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            inicio = LerAntenas();
            printf("Frequência:\n");
            while (getchar() != '\n'); //Limpa o buffer de entrada.
            if (scanf("%c", &freq) != 1) {
                while (getchar() != '\n');
                continue;
            }
            printf("Coordenada x:\n");
            if (scanf("%d", &x) != 1) {
                while (getchar() != '\n');
                continue;
            }
            printf("Coordenada y:\n");
            if (scanf("%d", &y) != 1) {
                while (getchar() != '\n');
                continue;
            }
            aux = CriaAntena(freq, x, y);
            inicio = insertAntenna(inicio, aux); // Atualiza o ponteiro inicio.
            debugPrintAntennas(inicio); // Mostra a lista de antenas.
            guardarAntenas(inicio);
            break;
        case 2:
            inicio = LerAntenas();

            printf("Coordenada x:\n");
            if (scanf("%d", &x) != 1) {
                while (getchar() != '\n');
                continue;
            }
            printf("Coordenada y:\n");
            if (scanf("%d", &y) != 1) {
                while (getchar() != '\n');
                continue;
            }
            inicio = removeAntenna(inicio, x, y); // Atualiza o ponteiro inicio.
            debugPrintAntennas(inicio); // Mostra a lista de antenas.
            guardarAntenas(inicio);
            break;
        case 3:
            // Carregar antenas do arquivo
            inicio = LerAntenas();
            DestroiLista(&ini1);
            efeitoNefasto(inicio, &ini1);
            printAntennas(inicio, ini1);
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }

    // Limpar a lista de antenas antes de sair
    DestroiListaAntenas(&inicio);

    // Limpar a lista de efeitos nefastos antes de sair
    DestroiLista(&ini1);

    return 0;
}