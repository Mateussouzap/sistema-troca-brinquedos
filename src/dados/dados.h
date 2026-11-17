
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