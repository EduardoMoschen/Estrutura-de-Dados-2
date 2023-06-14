#include "RBTree.h"

NoRBTree *criaNo(int id, char *produto, int quantidade){
    // Aloca memória para o novo nó e faz o casting para o tipo NoRBTree.
    NoRBTree *novoNo = (NoRBTree*)calloc(1, sizeof(NoRBTree));
    
    // Faz a verificação para ver se a alocação ocorreu sem problemas.
    if(novoNo == NULL){
        printf("Erro de alocacao\n");
        exit(1); // Caso ocorra algum erro, é retornado a confirmação deste erro.
    }

    // Recebe o valor do id passado na main e armazena na variável id.
    novoNo -> id = id;
    // Recebe o nome do produto passado na main e armazena na variável nomeProduto.
    strcpy(novoNo -> nomeProduto, produto);
    // Recebe a quantidade que será armazenada no estoque passada na main e armazena na variável quantidadeProdutoEstoque.
    novoNo -> quantidadeProdutoEstoque = quantidade;
    // Todo nó a ser inserido é rubro.
    novoNo -> cor = RED;

    return novoNo; // Retorna o nó da Árvore Rubro-Negra contendo os dados armazenados.
}

NoRBTree *rotacaoEsquerda(NoRBTree *noTree){
    NoRBTree *novaRaiz = noTree -> direita;
    noTree -> direita = novaRaiz -> esquerda;
    novaRaiz -> esquerda = noTree;

    return noTree;
}

int identificaCor(NoRBTree *noTree){
    if(noTree == NULL)
        return BLACK;
    
    return (noTree -> cor = RED);
}

void trocaCor(NoRBTree *no1, NoRBTree *no2){
    int corAuxiliar = no1 -> cor; // Atribui a cor do nó 1 à uma variável auxiliar.
    no1 -> cor = no2 -> cor; // Atribui a cor do nó 2 ao nó 1.
    no2 -> cor = corAuxiliar; // Atribui a cor da variável auxiliar ao nó 2.
}

NoRBTree *insereNo(NoRBTree *Tree, int id, char *produto, int quantidade){
    NoRBTree *novoNo = criaNo(id, produto, quantidade);
    
    if(Tree == NULL){
        Tree = novoNo;
        novoNo -> cor = BLACK;
    }else{
        if(id < Tree -> id)
            Tree -> esquerda = insereNo(Tree -> esquerda, id, produto, quantidade);
        else if(id > Tree -> id)
            Tree -> direita = insereNo(Tree -> direita, id, produto, quantidade);
        else if(id == Tree -> id){
            printf("Produto ja cadastrado\n");
            Tree -> quantidadeProdutoEstoque += quantidade;
        }
    }

    return Tree;
   
}

void imprime(NoRBTree *no, int espaco){
    if(no == NULL)
        return;
    else{
        espaco += 4;
        imprime(no -> direita, espaco);
        printf("\n");

        int i;
        for(i = 0; i < espaco; i++)
            printf(" ");

        printf("ID: %d ", no ->id); //Produto: %s | Quantidade em Estoque: %d ", no -> id, no -> nomeProduto, no -> quantidadeProdutoEstoque);

        if(no -> cor == BLACK)
            printf("(B)\n");
        else
            printf("(R)\n");

        imprime(no -> esquerda, espaco);
    }
}