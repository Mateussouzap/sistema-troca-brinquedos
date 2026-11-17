#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

brinquedo *alocarVetorBrinquedos(int capacidade_inicial) {
    brinquedo *vetor;

    vetor = (brinquedo *) malloc(capacidade_inicial * sizeof(brinquedo));

    if (vetor == NULL) {
        printf("Erro: memória insuficiente para iniciar.\n");
        return NULL;
    }

    return vetor;
}

void cadastrarBrinquedo(brinquedo **vetor, int *quantidade, int *capacidade, brinquedo novo) {

    if (*quantidade == *capacidade) {
        *capacidade *= 2;

        brinquedo *tmp = (brinquedo *) realloc(*vetor, (*capacidade) * sizeof(brinquedo));

        if (tmp == NULL) {
            printf("Erro: memória insuficiente para expandir");
            return NULL;
        }

        *vetor = tmp;
    }
    (*vetor)[*quantidade] = novo;
    (*quantidade)++;
}

void desalocarVetorBrinquedos(brinquedo *vetor) {
    
    if (vetor != NULL) {
        free(vetor);
    }
}