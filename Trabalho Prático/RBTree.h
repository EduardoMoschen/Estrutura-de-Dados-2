#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK 0
#define RED 1

typedef struct noRBTree {
    int id;
    char nomeProduto[100];
    int quantidadeProdutoEstoque;
    int cor;
    struct noRBTree *direita;
    struct noRBTree *esquerda;
}NoRBTree;

/*
Função que recebe como parâmetros o ID do produto, nome do produto e sua quantidade. Após
receber esses parâmetros, é feita a alocação de memória do nó que será armazenado na
árvore. Por fim, é armazenado os dados no nó e retornado o nó criado.
*/
NoRBTree *criaNo(int id, char *produto, int quantidade);

/*

*/
NoRBTree *rotacaoEsquerda(NoRBTree *noTree);

int identificaCor(NoRBTree  *noTree);

/*
Função que recebe dois nós do tipo NoRBTree como parâmetros e faz a troca de cores
através da troca de ponteiros.
*/
void trocaCor(NoRBTree *no1, NoRBTree *no2);

/*

*/
NoRBTree *insereNo(NoRBTree *Tree, int id, char *produto, int quantidade);

/*

*/
void imprime(NoRBTree *no, int espaco);