#include "Dados.h"
#include "Funcoes.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Cria uma nova antena com a frequ�ncia e coordenadas especificadas.
 *
 * @param freq A frequ�ncia da antena.
 * @param x A coordenada x da antena.
 * @param y A coordenada y da antena.
 * @return Antenna* Um ponteiro para a nova antena criada.
 */
Antenna* CriaAntena(char freq, int x, int y) {
    Antenna* aux;
	aux = (Antenna*)malloc(sizeof(Antenna)); //Aloca mem�ria para a nova antena.
	if (aux != NULL) {
		aux->frequency = freq; //Define a frequ�ncia da antena.
		aux->x = x; //Define a coordenada x da antena.
		aux->y = y; //Define a coordenada y da antena.
		aux->next = NULL; //Inicializa o ponteiro next como NULL.
	}
	return (aux); //Retorna o ponteiro para a nova antena.
}

/**
 * @brief Insere uma nova antena no in�cio da lista de antenas.
 *
 * @param inicio O ponteiro para o in�cio da lista de antenas.
 * @param novo O ponteiro para a nova antena a ser inserida.
 * @return Antenna* O ponteiro para o in�cio atualizado da lista de antenas.
 */
Antenna* insertAntenna(Antenna* inicio, Antenna* novo) {;
	if (inicio == NULL) {
		inicio = novo; //Se a lista estiver vazia, o in�cio � a nova antena.
	}
	else {
		novo->next = inicio; // A nova antena aponta para o in�cio da lista.
		inicio = novo; // O in�cio da lista � atualizado para a nova antena.
	}
	return inicio; //Retorna o ponteiro para o in�cio da lista de antenas.

}

/**
 * @brief Remove uma antena da lista de antenas com base nas coordenadas especificadas.
 *
 * @param inicio O ponteiro para o in�cio da lista de antenas.
 * @param x A coordenada x da antena a ser removida.
 * @param y A coordenada y da antena a ser removida.
 * @return Antenna* O ponteiro para o in�cio atualizado da lista de antenas.
 */
Antenna* removeAntenna(Antenna* inicio, int x, int y) {
    Antenna* current = inicio, * prev = NULL;
    while (current != NULL) {
		if (current->x == x && current->y == y) { // Encontra a antena com as coordenadas especificadas.
			if (prev == NULL) inicio = current->next; // Se for a primeira antena, atualiza o in�cio.
            else prev->next = current->next; // Caso contr�rio, ajusta o ponteiro next da antena anterior.
			free(current); // Libera a mem�ria alocada para a antena que se quer remover.
			return inicio; // Retorna o ponteiro para o in�cio da lista de antenas.
        }
		prev = current; // Atualiza o ponteiro prev.
		current = current->next; // Avan�a para a pr�xima antena.
    }
	return inicio; // Retorna o ponteiro para o in�cio da lista (n�o modificado se a antena n�o foi encontrada)
}

/**
 * @brief Imprime o grid com as antenas.
 *
 * @param inicio O ponteiro para o in�cio da lista de antenas.
 */
void printAntennas(Antenna* inicio) {
    printf("Grid\n");
	for (int y = 0; y < 5; y++) { // Percorre as linhas do grid.
		for (int x = 0; x < 5; x++) { // Percorre as colunas do grid.
			Antenna* current = inicio; // Inicializa o ponteiro current com o in�cio da lista.
			char found = '.'; // Inicializa found com '.' (sem antena).
            while (current != NULL) {
				if (current->x == x && current->y == y) { // Verifica se a antena est� na posi��o atual.
					found = current->frequency; // Atualiza found com a frequ�ncia da antena.
                    break;
                }
				current = current->next; // Avan�a para a pr�xima antena.
            }
			printf("%c", found); // Imprime o caractere encontrado.
        }
		printf("\n"); // Pula para a pr�xima linha.
    }
}

/**
 * @brief Imprime as antenas.
 *
 * @param inicio O ponteiro para o in�cio da lista de antenas.
 */
void debugPrintAntennas(Antenna* inicio) {
    Antenna* current = inicio;
    while (current != NULL) {
		printf("Antena: freq=%c, x=%d, y=%d\n", current->frequency, current->x, current->y); // Imprime os dados da antena.
		current = current->next; // Avan�a para a pr�xima antena.
    }
}

Nefasto* CriaNefasto(float x, float y) {
	Nefasto* aux;
	aux = (Nefasto*)malloc(sizeof(Nefasto)); //Aloca mem�ria para o novo efeito nefasto.
	if (aux != NULL) {
		aux->x = x; //Define a coordenada x do efeito nefasto.
		aux->y = y; //Define a coordenada y do efeito nefasto.
		aux->next = NULL; //Inicializa o ponteiro next como NULL.
	}
	return (aux); //Retorna o ponteiro para o novo efeito nefasto.
}

/**
 * @brief Insere um novo efeito nefasto no in�cio da lista de efeitos nefastos.
 *
 * @param inicio O ponteiro para o in�cio da lista de efeitos nefastos.
 * @param novo O ponteiro para o novo efeito nefasto a ser inserido.
 * @return Nefasto* O ponteiro para o in�cio atualizado da lista de efeitos nefastos.
 */
Nefasto* insertNefasto(Nefasto* inicio, Nefasto* novo) {
	if (novo == NULL) {
		// Verifica se o novo elemento � NULL
		fprintf(stderr, "Erro: Tentativa de inserir um elemento NULL na lista de efeitos nefastos.\n");
		return inicio;
	}

	if (inicio == NULL) {
		inicio = novo; // Se a lista estiver vazia, o in�cio � o novo efeito nefasto.
	}
	else {
		novo->next = inicio; // O novo efeito nefasto aponta para o in�cio da lista.
		inicio = novo; // O in�cio da lista � atualizado para o novo efeito nefasto.
	}
	return inicio; // Retorna o ponteiro para o in�cio da lista de efeitos nefastos.
}
/**
 * @brief Remove um efeito nefasto da lista de efeitos nefastos com base nas coordenadas especificadas.
 *
 * @param inicio O ponteiro para o in�cio da lista de efeitos nefastos.
 * @param x A coordenada x do efeito nefasto a ser removido.
 * @param y A coordenada y do efeito nefasto a ser removido.
 * @return Nefasto* O ponteiro para o in�cio atualizado da lista de efeitos nefastos.
 */
Nefasto* removeNefasto(Nefasto* inicio, int x, int y) {
	Nefasto* current = inicio, * prev = NULL;
	while (current != NULL) {
		if (current->x == x && current->y == y) { // Encontra o efeito nefasto com as coordenadas especificadas.
			if (prev == NULL) inicio = current->next; // Se for o primeiro efeito nefasto, atualiza o in�cio.
			else prev->next = current->next; // Caso contr�rio, ajusta o ponteiro next do efeito nefasto anterior.
			free(current); // Libera a mem�ria alocada para o efeito nefasto que se quer remover.
			return inicio; // Retorna o ponteiro para o in�cio da lista de efeitos nefastos.
		}
		prev = current; // Atualiza o ponteiro prev.
		current = current->next; // Avan�a para o pr�ximo efeito nefasto.
	}
	return inicio; // Retorna o ponteiro para o in�cio da lista (n�o modificado se o efeito nefasto n�o foi encontrado)
}

void efeitoNefasto(Antenna* inicio, Nefasto** ini) {
	Nefasto* aux;
	Antenna* current = inicio;

	while (current != NULL && current->next != NULL) {
		if ((current->x == current->next->x) && (current->y != current->next->y)) {
			int subtracao = current->y - current->next->y;
			float nefy = current->y + subtracao;
			float nefy1 = current->next->y - subtracao;
			aux = CriaNefasto(current->x, nefy);
			*ini = insertNefasto(*ini, aux);
			aux = CriaNefasto(current->next->x, nefy1);
			*ini = insertNefasto(*ini, aux);
		}
		else if ((current->x != current->next->x) && (current->y == current->next->y)) {
			int subtracao = current->x - current->next->x;
			float nefx = current->x + subtracao;
			float nefx1 = current->next->x - subtracao;
			aux = CriaNefasto(nefx, current->y);
			*ini = insertNefasto(*ini, aux);
			aux = CriaNefasto(nefx1, current->next->y);
			*ini = insertNefasto(*ini, aux);
		}
		else if ((current->x != current->next->x) && (current->y != current->next->y)) {
			int subtracaox = current->x - current->next->x;
			int subtracaoy = current->y - current->next->y;
			float nefx = current->x + subtracaox;
			float nefx1 = current->next->x - subtracaox;
			float nefy = current->y + subtracaoy;
			float nefy1 = current->next->y - subtracaoy;
			aux = CriaNefasto(nefx, nefy);
			*ini = insertNefasto(*ini, aux);
			aux = CriaNefasto(nefx1, nefy1);
			*ini = insertNefasto(*ini, aux);
		}
		current = current->next;
	}
	return *ini;
}

void DestroiLista(Nefasto** ini) {
	if (ini != NULL) {
		Nefasto* aux;
		while (*ini) {
			aux = *ini;
			*ini = (*ini)->next;
			free(aux);
		}
	}
	return ini;
}


void debugPrintNefasto(Nefasto* inicio) {
	Nefasto* current = inicio;
	while (current != NULL) {
		printf("Nefasto: x=%.2f, y=%.2f\n", current->x, current->y); // Imprime os dados do efeito nefasto.
		current = current->next; // Avan�a para o pr�ximo efeito nefasto.
	}
}