/*
Implementação da Tabela Hash com tratamento de colisões por encadeamento.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 9

typedef struct no {
    int chave;
    struct no *proximo;
}No;

typedef struct hash {
    No *posicao[TAMANHO];
}THash;

void criaTabela();

int indiceHash(int valor);

No *criaNo(int valor);

void insereInicio(THash *hashT, int valor);

No *busca(THash *hashT, int valor);

void removeChave(THash *hashT, int valor);

void imprimeTabela(THash *hashT);