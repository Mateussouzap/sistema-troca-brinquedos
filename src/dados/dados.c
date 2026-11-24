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

        brinquedo *tmp;
        
        tmp = (brinquedo *) realloc(*vetor, (*capacidade) * sizeof(brinquedo));

        if (tmp == NULL) {
            printf("Erro: memória insuficiente para expandir");
            return;
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

pai *alocarVetorPais(int capacidade_inicial) {
    pai *vetor;

    vetor = (pai *) malloc(capacidade_inicial * sizeof(pai));

    if (vetor == NULL) {
        return NULL;
    }

    return vetor;
}

void cadastrarPai(pai **vetor, int *quantidade, int *capacidade, pai novo) {

    if (*quantidade == *capacidade) {
        *capacidade *= 2;
    
    
        pai *tmp;
        
        tmp = (pai *) realloc(*vetor, (*capacidade) * sizeof(pai));

        if (tmp == NULL) {
            printf("Erro: memória insuficiente para expandir.");
            return;
        }

        *vetor = tmp;
    }
    (*vetor)[*quantidade] = novo;
    (*quantidade)++;
}

void desalocarVetorPais(pai *vetor) {

    if (vetor != NULL) {
        free(vetor);
    }
}

int buscarBrinquedo(brinquedo *vetor, int quantidade, int id_buscado) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (vetor[i].id_brinquedo == id_buscado) {
            return i;
        }
    }

    return -1;
}

void removerBrinquedo(brinquedo *vetor, int *quantidade, int id_remover) {
    int i;
    int indice = buscarbrinquedo(vetor, *quantidade, id_remover);

    if (indice == -1) {
        return 0;
    }

    for (i = indice; i < (*quantidade) - 1; i++) {
        vetor[i] = vetor[i+1];
    }
    (*quantidade)--;
}