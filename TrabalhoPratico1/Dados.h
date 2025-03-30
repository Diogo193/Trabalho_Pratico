/**
* @file Dados.h
* @brief Definição das estruturas de dados utilizadas no programa.
* 
* Este arquivo contém a definição das estruturas de dados utilizadas no programa.
*
*/
#pragma once

#include <stdbool.h>

#pragma region Antenas
/**
 * @brief Estrutura que representa uma antena.
 */
typedef struct Antenna {
	char frequency; // Frequência da antena.
	int x, y; // Coordenadas da antena.
	struct Antenna* next; // Ponteiro para a próxima antena.
} Antenna;

/**
 * @brief Estrutura que representa uma lista de antenas.
 */
typedef struct Antennas {
	struct Antenna* inicio; // Ponteiro para o início da lista de antenas.
	int totalAntennas; // Número total de antenas na lista.
}Antennas;

#pragma endregion

#pragma region Efeitos Nefastos
/**
 * @brief Estrutura que representa um efeito nefasto.
 */
typedef struct Nefasto {
    float x, y; // Coordenadas do efeito nefasto.
	struct Nefasto* next; // Ponteiro para o próximo efeito nefasto.
} Nefasto;

/**
 * @brief Estrutura que representa uma lista de efeitos nefastos.
 */
typedef struct Nefastos {
	struct Nefasto* inicio; // Ponteiro para o início da lista de efeitos nefastos.
	int totalHarmfulLocations; // Número total de efeitos nefastos na lista.
};

#pragma endregion