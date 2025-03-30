/**
 * @file main.c
 * @brief Programa principal para gerenciar uma lista de antenas.
 *
 * Este programa permite ao usu�rio inserir, remover e mostrar antenas em uma grade.
 * As antenas s�o armazenadas em uma lista ligada.
 */

#define _CRT_SECURE_NO_WARNINGS

#include "Dados.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "Funcoes.h"

int main() {
    int opcao = -1; // Op��o escolhida pelo usu�rio.
    char freq; // Frequ�ncia da antena.
    int x, y; // Coordenadas da antena.
    Antenna* inicio = NULL; // Ponteiro para o in�cio da lista de antenas.
    Antenna* aux; // Ponteiro auxiliar para a nova antena.
    Nefasto* ini1 = NULL; // Ponteiro para o in�cio da lista de efeitos nefastos.

    while (opcao != 0) {
        // Exibe o menu de op��es
        printf("1 - Inserir Antena\n");
        printf("2 - Remover Antena\n");
        printf("3 - Mostrar grid\n");
        printf("0 - Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            // Inserir uma nova antena
            inicio = LerAntenas();
            printf("Frequ�ncia:\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada.
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
            aux = CriaAntena(freq, x, y); // Cria uma nova antena
            inicio = insertAntenna(inicio, aux); // Atualiza o ponteiro inicio.
            debugPrintAntennas(inicio); // Mostra a lista de antenas.
            guardarAntenas(inicio); // Guarda a lista de antenas no arquivo.
            break;
        case 2:
            // Remover uma antena existente
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
            guardarAntenas(inicio); // Guarda a lista de antenas no arquivo.
            break;
        case 3:
            // Mostrar a grade de antenas
            inicio = LerAntenas(); // Carregar antenas do arquivo
            DestroiLista(&ini1); // Limpa a lista de efeitos nefastos
            efeitoNefasto(inicio, &ini1); // Aplica efeitos nefastos
            printAntennas(inicio, ini1); // Mostra a lista de antenas e efeitos nefastos
            break;
        default:
            // Op��o inv�lida
            printf("Op��o inv�lida!\n");
            break;
        }
    }

    // Limpar a lista de antenas antes de sair
    DestroiListaAntenas(&inicio);

    // Limpar a lista de efeitos nefastos antes de sair
    DestroiLista(&ini1);

    return 0;
}