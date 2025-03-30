#include "Dados.h"
#include "Funcoes.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

#define GRID 20

#pragma region Antenas
/**
 * @brief Cria uma nova antena com a frequência e coordenadas especificadas.
 *
 * @param freq A frequência da antena.
 * @param x A coordenada x da antena.
 * @param y A coordenada y da antena.
 * @return Antenna* Um ponteiro para a nova antena criada.
 */
Antenna* CriaAntena(char freq, int x, int y) {
    Antenna* aux;
	aux = (Antenna*)malloc(sizeof(Antenna)); //Aloca memória para a nova antena.
	if (aux != NULL) {
		aux->frequency = freq; //Define a frequência da antena.
		aux->x = x; //Define a coordenada x da antena.
		aux->y = y; //Define a coordenada y da antena.
		aux->next = NULL; //Inicializa o ponteiro next como NULL.
	}
	return (aux); //Retorna o ponteiro para a nova antena.
}

/**
 * @brief Insere uma nova antena no início da lista de antenas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 * @param novo O ponteiro para a nova antena a ser inserida.
 * @return Antenna* O ponteiro para o início atualizado da lista de antenas.
 */
Antenna* insertAntenna(Antenna* inicio, Antenna* novo) {;
	
	if (inicio == NULL) {
		inicio = novo; //Se a lista estiver vazia, o início é a nova antena.
	}
	else {
		novo->next = inicio; // A nova antena aponta para o início da lista.
		inicio = novo; // O início da lista é atualizado para a nova antena.
	}
	return inicio; //Retorna o ponteiro para o início da lista de antenas.

}

/**
 * @brief Remove uma antena da lista de antenas com base nas coordenadas especificadas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 * @param x A coordenada x da antena a ser removida.
 * @param y A coordenada y da antena a ser removida.
 * @return Antenna* O ponteiro para o início atualizado da lista de antenas.
 */
Antenna* removeAntenna(Antenna* inicio, int x, int y) {
    Antenna* current = inicio, * prev = NULL;
    while (current != NULL) {
		if (current->x == x && current->y == y) { // Encontra a antena com as coordenadas especificadas.
			if (prev == NULL) inicio = current->next; // Se for a primeira antena, atualiza o início.
            else prev->next = current->next; // Caso contrário, ajusta o ponteiro next da antena anterior.
			free(current); // Libera a memória alocada para a antena que se quer remover.
			return inicio; // Retorna o ponteiro para o início da lista de antenas.
        }
		prev = current; // Atualiza o ponteiro prev.
		current = current->next; // Avança para a próxima antena.
    }
	return inicio; // Retorna o ponteiro para o início da lista (não modificado se a antena não foi encontrada)
}

/**
 * @brief Imprime o grid com as antenas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 */
void printAntennas(Antenna* inicio, Nefasto* nefastoInicio) {
    printf("Grid\n");
    for (int y = 0; y < GRID; y++) { // Percorre as linhas do grid.
        for (int x = 0; x < GRID; x++) { // Percorre as colunas do grid.
            Antenna* current = inicio; // Inicializa o ponteiro current com o início da lista.
            Nefasto* nefastoCurrent = nefastoInicio; // Inicializa o ponteiro nefastoCurrent com o início da lista de nefastos.
            char found = '.'; // Inicializa found com '.' (sem antena).
            while (current != NULL) {
                if (current->x == x && current->y == y) { // Verifica se a antena está na posição atual.
                    found = current->frequency; // Atualiza found com a frequência da antena.
                    break;
                }
                current = current->next; // Avança para a próxima antena.
            }
            while (nefastoCurrent != NULL) {
                if ((int)nefastoCurrent->x == x && (int)nefastoCurrent->y == y) { // Verifica se o nefasto está na posição atual.
                    found = '#'; // Atualiza found com '#' para indicar a presença de um nefasto.
                    break;
                }
                nefastoCurrent = nefastoCurrent->next; // Avança para o próximo nefasto.
            }
            printf("%c", found); // Imprime o caractere encontrado.
        }
        printf("\n"); // Pula para a próxima linha.
    }
}


void guardarAntenas(Antenna* inicio) {
	FILE* f = fopen("antenas.txt", "w");
	if (f == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
		return;
	}
	for (int y = 0; y < GRID; y++) { // Percorre as linhas do grid.
		for (int x = 0; x < GRID; x++) { // Percorre as colunas do grid.
			Antenna* current = inicio; // Inicializa o ponteiro current com o início da lista.
			char found = '.'; // Inicializa found com '.' (sem antena).
			while (current != NULL) {
				if (current->x == x && current->y == y) { // Verifica se a antena está na posição atual.
					found = current->frequency; // Atualiza found com a frequência da antena.
					break;
				}
				current = current->next; // Avança para a próxima antena.
			}
			fprintf(f, "%c", found); // Escreve o caractere encontrado no arquivo.
		}
		fprintf(f, "\n"); // Pula para a próxima linha no arquivo.
	}
	fclose(f); // Fecha o arquivo após a escrita.
}

Antenna* LerAntenas() {
	FILE* f = fopen("antenas.txt", "r");
	if (f == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
		return NULL;
	}

	Antenna* inicio = NULL;
	char linha[GRID + 2]; // +2 para o caractere nulo e o '\n'
	int y = 0;

	while (fgets(linha, sizeof(linha), f) != NULL && y < GRID) {
		for (int x = 0; x < GRID; x++) {
			if (linha[x] != '.' && linha[x] != '\n') {
				Antenna* novaAntena = CriaAntena(linha[x], x, y);
				inicio = insertAntenna(inicio, novaAntena);
			}
		}
		y++;
	}

	fclose(f);
	return inicio;
}
/**
 * @brief Imprime as antenas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 */
void debugPrintAntennas(Antenna* inicio) {
    Antenna* current = inicio;
    while (current != NULL) {
		printf("Antena: freq=%c, x=%d, y=%d\n", current->frequency, current->x, current->y); // Imprime os dados da antena.
		current = current->next; // Avança para a próxima antena.
    }
}

void DestroiListaAntenas(Antenna** inicio) {
	if (inicio != NULL) {
		Antenna* aux;
		while (*inicio) {
			aux = *inicio;
			*inicio = (*inicio)->next;
			free(aux);
		}
	}
}
#pragma endregion

#pragma region Efeitos Nefastos
Nefasto* CriaNefasto(float x, float y) {
	Nefasto* aux;
	aux = (Nefasto*)malloc(sizeof(Nefasto)); //Aloca memória para o novo efeito nefasto.
	if (aux != NULL) {
		aux->x = x; //Define a coordenada x do efeito nefasto.
		aux->y = y; //Define a coordenada y do efeito nefasto.
		aux->next = NULL; //Inicializa o ponteiro next como NULL.
	}
	return (aux); //Retorna o ponteiro para o novo efeito nefasto.
}

/**
 * @brief Insere um novo efeito nefasto no início da lista de efeitos nefastos.
 *
 * @param inicio O ponteiro para o início da lista de efeitos nefastos.
 * @param novo O ponteiro para o novo efeito nefasto a ser inserido.
 * @return Nefasto* O ponteiro para o início atualizado da lista de efeitos nefastos.
 */
Nefasto* insertNefasto(Nefasto* inicio, Nefasto* novo) {
	if (novo == NULL) {
		// Verifica se o novo elemento é NULL
		fprintf(stderr, "Erro: Tentativa de inserir um elemento NULL na lista de efeitos nefastos.\n");
		return inicio;
	}

	if (inicio == NULL) {
		inicio = novo; // Se a lista estiver vazia, o início é o novo efeito nefasto.
	}
	else {
		novo->next = inicio; // O novo efeito nefasto aponta para o início da lista.
		inicio = novo; // O início da lista é atualizado para o novo efeito nefasto.
	}
	return inicio; // Retorna o ponteiro para o início da lista de efeitos nefastos.
}
/**
 * @brief Remove um efeito nefasto da lista de efeitos nefastos com base nas coordenadas especificadas.
 *
 * @param inicio O ponteiro para o início da lista de efeitos nefastos.
 * @param x A coordenada x do efeito nefasto a ser removido.
 * @param y A coordenada y do efeito nefasto a ser removido.
 * @return Nefasto* O ponteiro para o início atualizado da lista de efeitos nefastos.
 */
Nefasto* removeNefasto(Nefasto* inicio, int x, int y) {
	Nefasto* current = inicio, * prev = NULL;
	while (current != NULL) {
		if (current->x == x && current->y == y) { // Encontra o efeito nefasto com as coordenadas especificadas.
			if (prev == NULL) inicio = current->next; // Se for o primeiro efeito nefasto, atualiza o início.
			else prev->next = current->next; // Caso contrário, ajusta o ponteiro next do efeito nefasto anterior.
			free(current); // Libera a memória alocada para o efeito nefasto que se quer remover.
			return inicio; // Retorna o ponteiro para o início da lista de efeitos nefastos.
		}
		prev = current; // Atualiza o ponteiro prev.
		current = current->next; // Avança para o próximo efeito nefasto.
	}
	return inicio; // Retorna o ponteiro para o início da lista (não modificado se o efeito nefasto não foi encontrado)
}

void efeitoNefasto(Antenna* inicio, Nefasto** ini) {
    Nefasto* aux;
    Antenna* current = inicio;
    Antenna* compare;

    while (current != NULL) {
		compare = current->next;
		while (compare != NULL) {
			if (current->frequency == compare->frequency) {
				if ((current->x == compare->x) && (current->y != compare->y)) {
						int subtracao = current->y - compare->y;
						float nefy = current->y + subtracao;
						float nefy1 = compare->y - subtracao;
						aux = CriaNefasto(current->x, nefy);
						*ini = insertNefasto(*ini, aux);
						aux = CriaNefasto(compare->x, nefy1);
						*ini = insertNefasto(*ini, aux);
				}
				else if ((current->x != compare->x) && (current->y == compare->y)) {
						int subtracao = current->x - compare->x;
						float nefx = current->x + subtracao;
						float nefx1 = compare->x - subtracao;
						aux = CriaNefasto(nefx, current->y);
						*ini = insertNefasto(*ini, aux);
						aux = CriaNefasto(nefx1, compare->y);
						*ini = insertNefasto(*ini, aux);
				}
				else if ((current->x != compare->x) && (current->y != compare->y)) {
						int subtracaox = current->x - compare->x;
						int subtracaoy = current->y - compare->y;
						float nefx = current->x + subtracaox;
						float nefx1 = compare->x - subtracaox;
						float nefy = current->y + subtracaoy;
						float nefy1 = compare->y - subtracaoy;
						aux = CriaNefasto(nefx, nefy);
						*ini = insertNefasto(*ini, aux);
						aux = CriaNefasto(nefx1, nefy1);
						*ini = insertNefasto(*ini, aux);
				}
			}
			compare = compare->next;
		}
		current = current->next;
    }
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
		current = current->next; // Avança para o próximo efeito nefasto.
	}
}

#pragma endregion