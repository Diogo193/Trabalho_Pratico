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
	Nefasto* ini1 = NULL;

	while (opcao != 0) {
		printf("1 - Inserir Antena\n");
		printf("2 - Remover Antena\n");
		printf("3 - Mostrar grid\n");
		printf("0 - Sair\n");
		printf("Op��o: ");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			printf("Frequ�ncia:\n");
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
			break;
		case 2:
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
			break;
		case 3:
			printAntennas(inicio); // Mostra o grid de antenas. Futuramente mostrar� o efeito nefasto tamb�m
			break;
		case 4:
			DestroiLista(&ini1);
			efeitoNefasto(inicio, &ini1);
			debugPrintNefasto(ini1);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			break;
		default:
			printf("Op��o inv�lida!\n");
			break;
		}
	}
}