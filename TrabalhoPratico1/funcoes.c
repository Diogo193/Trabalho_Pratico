/**
* @file funcoes.c
* @brief Implementação das funções para gerenciar uma lista de antenas.
* 
* Este arquivo contém a implementação das funções para criar, inserir, remover e imprimir antenas.
* 
*/

#include "Dados.h"
#include "Funcoes.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

#define GRID 20 // Tamanho do grid.

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
Antenna* insertAntenna(Antenna* inicio, Antenna* novo, bool *res) {;
*res = false;
	if (inicio == NULL) {
		inicio = novo; //Se a lista estiver vazia, o início é a nova antena.
	}
	else {
		novo->next = inicio; // A nova antena aponta para o início da lista.
		inicio = novo; // O início da lista é atualizado para a nova antena.
	}
	*res = true;
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

/**
 * @brief Guarda as antenas no arquivo "antenas.txt".
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 */
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

/**
 * @brief Lê as antenas de um arquivo e cria uma lista de antenas.
 *
 * Esta função abre um arquivo chamado "antenas.txt" para leitura e lê as antenas
 * armazenadas no arquivo. Para cada antena encontrada, cria uma nova antena com
 * a frequência e coordenadas especificadas e insere essa antena na lista de antenas.
 *
 * @return Antenna* O ponteiro para o início da lista de antenas.
 */
Antenna* LerAntenas() {
    FILE* f = fopen("antenas.txt", "r"); // Abre o arquivo "antenas.txt" para leitura.
    if (f == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n"); // Imprime uma mensagem de erro se o arquivo não puder ser aberto.
        return NULL; // Retorna NULL se o arquivo não puder ser aberto.
    }

    Antenna* inicio = NULL; // Inicializa o ponteiro para o início da lista de antenas como NULL.
    char linha[GRID + 2]; // Buffer para armazenar cada linha lida do arquivo (+2 para o caractere nulo e o '\n').
    int y = 0; // Inicializa a coordenada y.

    while (fgets(linha, sizeof(linha), f) != NULL && y < GRID) {
		// Lê cada linha do arquivo até o final ou até atingir o tamanho do grid.
        for (int x = 0; x < GRID; x++) {
			// Percorre cada caractere da linha.
            if (linha[x] != '.' && linha[x] != '\n') {
				// Verifica se o caractere não é um ponto (.) ou uma nova linha (\n).
                Antenna* novaAntena = CriaAntena(linha[x], x, y); // Cria uma nova antena com a frequência e coordenadas especificadas.
                inicio = insertAntenna(inicio, novaAntena); // Insere a nova antena na lista de antenas.
            }
        }
        y++; // Incrementa a coordenada y.
    }

    fclose(f); // Fecha o arquivo após a leitura.
    return inicio; // Retorna o ponteiro para o início da lista de antenas.
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

/**
 * @brief Destroi a lista de antenas.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 */
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
/**
 * @brief Cria um novo efeito nefasto com as coordenadas especificadas.
 *
 * @param x A coordenada x do efeito nefasto.
 * @param y A coordenada y do efeito nefasto.
 * @return Nefasto* O ponteiro para o novo efeito nefasto criado.
 */
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
 * @brief Aplica os efeitos nefastos entre antenas com a mesma frequência.
 *
 * Esta função percorre a lista de antenas e verifica se há antenas com a mesma frequência.
 * Se encontrar antenas com a mesma frequência, calcula as coordenadas dos efeitos nefastos
 * e insere esses efeitos na lista de nefastos.
 *
 * @param inicio O ponteiro para o início da lista de antenas.
 * @param ini O ponteiro para o ponteiro do início da lista de efeitos nefastos.
 */
Nefasto efeitoNefasto(Antenna* inicio, Nefasto* ini) {
    Nefasto* aux;
    Antenna* current = inicio;
    Antenna* compare;

    while (current != NULL) {
        compare = current->next;
        while (compare != NULL) {
            if (current->frequency == compare->frequency) {
                if ((current->x == compare->x) && (current->y != compare->y)) {
                    // Antenas na mesma coluna, mas em linhas diferentes
					int subtracao = current->y - compare->y; // Calcula a diferença entre as coordenadas y.
					float nefy = current->y + subtracao; // Calcula a coordenada y do efeito nefasto.
					float nefy1 = compare->y - subtracao; // Calcula a coordenada y do efeito nefasto.
					aux = CriaNefasto(current->x, nefy); // Cria o efeito nefasto.
					*ini = insertNefasto(*ini, aux); // Insere o efeito nefasto na lista.
					aux = CriaNefasto(compare->x, nefy1); // Cria o efeito nefasto.
					*ini = insertNefasto(*ini, aux); // Insere o efeito nefasto na lista.
                }
                else if ((current->x != compare->x) && (current->y == compare->y)) {
                    // Antenas na mesma linha, mas em colunas diferentes
					int subtracao = current->x - compare->x; // Calcula a diferença entre as coordenadas x.
					float nefx = current->x + subtracao; // Calcula a coordenada x do efeito nefasto.
					float nefx1 = compare->x - subtracao; // Calcula a coordenada x do efeito nefasto.
					aux = CriaNefasto(nefx, current->y); // Cria o efeito nefasto.
					*ini = insertNefasto(*ini, aux); // Insere o efeito nefasto na lista.
					aux = CriaNefasto(nefx1, compare->y); // Cria o efeito nefasto.
				ini = insertNefasto(*ini, aux); // Insere o efeito nefasto na lista.
                }
                else if ((current->x != compare->x) && (current->y != compare->y)) {
                    // Antenas em posições diferentes
					int subtracaox = current->x - compare->x; // Calcula a diferença entre as coordenadas x.
					int subtracaoy = current->y - compare->y; // Calcula a diferença entre as coordenadas y.
					float nefx = current->x + subtracaox; // Calcula a coordenada x do efeito nefasto.
					float nefx1 = compare->x - subtracaox; // Calcula a coordenada x do efeito nefasto.
					float nefy = current->y + subtracaoy; // Calcula a coordenada y do efeito nefasto.
					float nefy1 = compare->y - subtracaoy; // Calcula a coordenada y do efeito nefasto.
					aux = CriaNefasto(nefx, nefy); // Cria o efeito nefasto.
					*ini = insertNefasto(*ini, aux); // Insere o efeito nefasto na lista.
					aux = CriaNefasto(nefx1, nefy1); // Cria o efeito nefasto.
					*ini = insertNefasto(*ini, aux); // Insere o efeito nefasto na lista.
                }
            }
			compare = compare->next; // Avança para a próxima antena.
        }
		current = current->next; // Avança para a próxima antena.

		return ini;
    }
}

/**
 * @brief Destroi a lista de efeitos nefastos.
 *
 * Esta função percorre a lista de efeitos nefastos e libera a memória alocada para cada efeito.
 *
 * @param ini O ponteiro para o ponteiro do início da lista de efeitos nefastos.
 */
void DestroiLista(Nefasto** ini) {
    if (ini != NULL) {
        Nefasto* aux; 
        while (*ini) {
            aux = *ini; 
            *ini = (*ini)->next; 
            free(aux);
        }
    }
}

/**
 * @brief Imprime os efeitos nefastos.
 *
 * Esta função percorre a lista de efeitos nefastos e imprime as coordenadas de cada efeito.
 *
 * @param inicio O ponteiro para o início da lista de efeitos nefastos.
 */
void debugPrintNefasto(Nefasto* inicio) {
    Nefasto* current = inicio;
    while (current != NULL) {
        printf("Nefasto: x=%.2f, y=%.2f\n", current->x, current->y); // Imprime os dados do efeito nefasto.
        current = current->next; // Avança para o próximo efeito nefasto.
    }
}

#pragma endregion