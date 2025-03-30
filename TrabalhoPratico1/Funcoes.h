#include "Dados.h"

#pragma once

/**
 * @brief Cria uma nova antena com a frequência e coordenadas especificadas.
 *
 * @param freq A frequência da antena.
 * @param x A coordenada x da antena.
 * @param y A coordenada y da antena.
 * @return Antenna* Um ponteiro para a nova antena criada.
 */
Antenna* CriaAntena(char freq, int x, int y); 

/**
 * @brief Insere uma nova antena no início da lista de antenas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 * @param novo O ponteiro para a nova antena a ser inserida.
 * @return Antenna* O ponteiro para o início atualizado da lista de antenas.
 */
Antenna* insertAntenna(Antenna* inicio, Antenna* novo); 

/**
 * @brief Remove uma antena da lista de antenas com base nas coordenadas especificadas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 * @param x A coordenada x da antena a ser removida.
 * @param y A coordenada y da antena a ser removida.
 * @return Antenna* O ponteiro para o início atualizado da lista de antenas.
 */
Antenna* removeAntenna(Antenna* inicio, int x, int y); 

/**
 * @brief Imprime o grid com as antenas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 */
void printAntennas(Antenna* inicio); 

/**
 * @brief Imprime as antenas para fins de depuração.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 */
void debugPrintAntennas(Antenna* inicio); 

Nefasto* CriaNefasto(float x, float y);
Nefasto* insertNefasto(Nefasto* inicio, Nefasto* novo);
Nefasto* removeNefasto(Nefasto* inicio, int x, int y);
void efeitoNefasto(Antenna* inicio, Nefasto** ini);
void DestroiLista(Nefasto** ini);
void debugPrintNefasto(Nefasto* inicio);