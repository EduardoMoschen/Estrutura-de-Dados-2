#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK 0
#define RED 1

typedef struct NoRBTree {
    int id;
    char nomeProduto[100];
    int quantidadeProdutoEstoque;
    int cor;
    struct NoRBTree *direita;
    struct NoRBTree *esquerda;
} NoRBTree;

/*
Função que recebe como parâmetros o ID do produto, NoRBTreeme do produto e sua quantidade. Após
receber esses parâmetros, é feita a alocação de memória do nó que será armazenado na
árvore. Por fim, é armazenado os dados NoRBTree nó e retornado o nó criado.
*/
NoRBTree *criaNoRBTree(int id, char *produto, int quantidade);

/*

*/
NoRBTree *rotacaoEsquerda(NoRBTree *NoRBTreeTree);

/*

*/
NoRBTree *rotacaoDireita(NoRBTree *NoRBTreeTree);

/*

*/
int identificaCor(NoRBTree *NoRBTreeTree);

/*
Função que recebe dois nós do tipo NoRBTreeRBTree como parâmetros e faz a troca de cores
através da troca de ponteiros.
*/
void trocaCor(NoRBTree *NoRBTree1, NoRBTree *NoRBTree2);

int verificaQuantidadeNosPretos(NoRBTree *raiz);

/*

*/
NoRBTree *insere(NoRBTree *Tree, int id, char *produto, int quantidade);

/*

*/
void imprime(NoRBTree *NoRBTree, int espaco);