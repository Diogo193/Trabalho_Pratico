/**
* @file Dados.h
* @brief Defini��o das estruturas de dados utilizadas no programa.
* 
* Este arquivo cont�m a defini��o das estruturas de dados utilizadas no programa.
*
*/
#pragma once

#include <stdbool.h>

#pragma region Antenas
/**
 * @brief Estrutura que representa uma antena.
 */
typedef struct Antenna {
	char frequency; // Frequ�ncia da antena.
	int x, y; // Coordenadas da antena.
	struct Antenna* next; // Ponteiro para a pr�xima antena.
} Antenna;

/**
 * @brief Estrutura que representa uma lista de antenas.
 */
typedef struct Antennas {
	struct Antenna* inicio; // Ponteiro para o in�cio da lista de antenas.
	int totalAntennas; // N�mero total de antenas na lista.
}Antennas;

#pragma endregion

#pragma region Efeitos Nefastos
/**
 * @brief Estrutura que representa um efeito nefasto.
 */
typedef struct Nefasto {
    float x, y; // Coordenadas do efeito nefasto.
	struct Nefasto* next; // Ponteiro para o pr�ximo efeito nefasto.
} Nefasto;

/**
 * @brief Estrutura que representa uma lista de efeitos nefastos.
 */
typedef struct Nefastos {
	struct Nefasto* inicio; // Ponteiro para o in�cio da lista de efeitos nefastos.
	int totalHarmfulLocations; // N�mero total de efeitos nefastos na lista.
};

#pragma endregion