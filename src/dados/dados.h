#ifndef DADOS_H
#define DADOS_H
typedef enum {
    disponivel,
    negociacao,
    emprestado,
} situacaoBrinquedo;

typedef struct Brinquedo {
    int id_brinquedo;
    int id_pai_dono;
    char nome[50];
    char link_fotos[50];
    char condicao[50];
    char descricao[150];
    situacaoBrinquedo situacao;
} brinquedo;

typedef struct Pai {
    int id_pai;
    char nome[50];
    char telefone[20];
} pai;

brinquedo *alocarVetorBrinquedos(int capacidade_inicial);
void cadastrarBrinquedo(brinquedo **vetor, int *quantidade, int *capacidade, brinquedo novo);
void desalocarVetorBrinquedos(brinquedo *vetor);

pai *alocarVetorPais(int capacidade_inicial);
void cadastrarPai(pai **vetor, int *quantidade, int *capacidade, pai novo);
void desalocarVetorPais(pai *vetor);

int buscarbrinquedo(brinquedo *vetor, int quantidade, int id_buscado);
void removerBrinquedo(brinquedo *vetor, int *quantidade, int id_remover);

#endif