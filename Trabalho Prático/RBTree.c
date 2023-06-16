#include "RBTree.h"

NoRBTree *criaNo(int id, char *produto, int quantidade){
    // Aloca memória para o novo nó e faz o casting para o tipo NoRBTree.
    NoRBTree *novoNo = (NoRBTree*)calloc(1, sizeof(NoRBTree));
    
    // Faz a verificação para ver se a alocação ocorreu sem problemas.
    if(novoNo == NULL){
        printf("Erro de alocacao\n");
        exit(1);  // Caso ocorra algum erro, é retornado a confirmação deste erro.
    }

    // Recebe o valor do id passado na main e armazena na variável id.
    novoNo -> id = id;
    // Recebe o nome do produto passado na main e armazena na variável nomeProduto.
    strncpy(novoNo -> nomeProduto, produto, 99);
    novoNo -> nomeProduto[99] = '\0';  // Certifica que o último caractere será nulo.
    // Recebe a quantidade que será armazenada no estoque passada na main e armazena na variável quantidadeProdutoEstoque.
    novoNo -> quantidadeProdutoEstoque = quantidade;
    // Todo nó a ser inserido é rubro.
    novoNo -> cor = RED;

    return novoNo; // Retorna o nó da Árvore Rubro-Negra contendo os dados armazenados.
}

NoRBTree *rotacaoEsquerda(NoRBTree *noTree){
    NoRBTree *novaRaiz = noTree -> direita;
    NoRBTree *subArvoreEsquerda = novaRaiz -> esquerda;
    
    novaRaiz -> esquerda = noTree;
    noTree -> direita = subArvoreEsquerda;

    trocaCor(noTree, novaRaiz);

    return novaRaiz;
}

NoRBTree *rotacaoDireita(NoRBTree *noTree){
    NoRBTree *novaRaiz = noTree -> esquerda;
    NoRBTree *subArvoreDireita = novaRaiz -> direita;

    novaRaiz -> direita = noTree;
    noTree -> esquerda = subArvoreDireita;

    trocaCor(noTree, novaRaiz);

    return novaRaiz;
}

int identificaCor(NoRBTree *noTree){
    if(noTree == NULL)
        return BLACK;
    
    return noTree -> cor;
}

void trocaCor(NoRBTree *no1, NoRBTree *no2){
    int corAuxiliar = no1 -> cor;  // Atribui a cor do nó 1 à uma variável auxiliar.
    no1 -> cor = no2 -> cor;  // Atribui a cor do nó 2 ao nó 1.
    no2 -> cor = corAuxiliar;  // Atribui a cor da variável auxiliar ao nó 2.
}

int verificaQuantidadeNosPretos(NoRBTree *raiz){
    if(raiz == NULL)
        return 0;
    else{
        int esquerda = verificaQuantidadeNosPretos(raiz -> esquerda);
        int direita = verificaQuantidadeNosPretos(raiz -> direita);

        int corAtual = 0;
        if(raiz -> cor == BLACK)
            corAtual += 1;

        return esquerda + direita + corAtual;
    }
}



NoRBTree *insere(NoRBTree *Tree, int id, char *produto, int quantidade){
    NoRBTree *novoNo = criaNo(id, produto, quantidade);
    
    // Caso a árvore esteja vazia, será inserido o primeiro nó e será da cor rubro.
    if(Tree == NULL){
        Tree = novoNo;
        novoNo -> cor = BLACK;
    }
    else{
        // Com a raiz preenchida, é feita a verificação pelo número do ID do produto. Caso seja menor que o ID, será inserido à esquerda.
        if(id < Tree -> id){
            Tree -> esquerda = insere(Tree -> esquerda, id, produto, quantidade);
            Tree -> esquerda -> cor = RED;  // Obedecendo à regra, todos os nós a serem inseridos são rubros.
        // Com a raiz preenchida, é feita a verificação pelo número do ID do produto. Caso seja maior que o ID, será inserido à direita.
        }else if(id > Tree -> id){
            Tree -> direita = insere(Tree -> direita, id, produto, quantidade);
            Tree -> direita -> cor = RED;  // Obedecendo à regra, todos os nós a serem inseridos são rubros.
        // Com a raiz preenchida, é feita a verificação pelo número do ID do produto. Caso seja igual ao ID, não será inserido o produto, apenas a quantidade atualizada.
        }else if(id == Tree -> id)
            Tree -> quantidadeProdutoEstoque += quantidade;
        
        // ===================== rotacionando ==============

        if((Tree -> direita != NULL && Tree -> direita -> cor == RED) && (Tree -> esquerda == NULL && Tree -> esquerda == BLACK))
            Tree = rotacaoEsquerda(Tree);

        if((Tree -> esquerda != NULL && Tree -> esquerda -> cor == RED) && (Tree -> direita == NULL && Tree -> direita == BLACK))
            Tree = rotacaoDireita(Tree);

        // Faz a verificação se o filho à direita é vermelho e se o filho à esquerda é preto. 
        // if(identificaCor(Tree -> direita) && !identificaCor(Tree -> esquerda)){
        //     // Caso seja, é feita a rotação.
        //     Tree = rotacaoEsquerda(Tree);
            
        //     // Faz a troca da cor do filho à esquerda, onde será sempre vermelho.
        //     trocaCor(Tree, Tree ->  esquerda);
        // }
        
        // if(identificaCor(Tree -> esquerda) && identificaCor(Tree -> esquerda -> esquerda)){
        //     Tree = rotacaoDireita(Tree);

        //     trocaCor(Tree, Tree -> direita);
        // }
        
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

        printf("%d ", no ->id); //Produto: %s | Quantidade em Estoque: %d ", no -> id, no -> nomeProduto, no -> quantidadeProdutoEstoque);

        if(no -> cor == BLACK)
            printf("(B)\n");
        else
            printf("(R)\n");

        imprime(no -> esquerda, espaco);
    }
}
