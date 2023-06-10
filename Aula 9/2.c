/*
Escreva as funções para balancear uma árvore AVL em cada situação enumerada na
questão 1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int chave;
    int altura;
    struct node *direita;
    struct node *esquerda;
}Node;

Node *createNode(int valor);
int max(int a, int b);
int altura(Node *node);
int fatorBalanceamento(Node *node);
Node *rotacaoDireita(Node *no);
Node *rotaçãoEsquerda(Node *no);
Node *insertNode(Node *node, int valor);
void printTree(Node *node, int espaco);

int main(){
    Node *raiz = NULL;

    raiz = insertNode(raiz, 10);
    raiz = insertNode(raiz, 20);
    raiz = insertNode(raiz, 30);
    raiz = insertNode(raiz, 40);
    raiz = insertNode(raiz, 50);
    raiz = insertNode(raiz, 25);

    printTree(raiz, 0);

    free(raiz);

    return 0;
}

Node *createNode(int valor){
    Node *newNode = (Node*)calloc(1, sizeof(Node));
    if(newNode == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    newNode -> chave = valor;
    newNode -> altura = 1;
    return newNode;
}

int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(Node *node){
    if(node == NULL)
        return 0;
    else
        return node -> altura;
}

int fatorBalanceamento(Node *node){
    if(node == NULL)
        return 0;
    else
        return altura(node -> esquerda) - altura(node -> direita);
}

Node *rotacaoDireita(Node *no){
    Node *novoNo = no -> esquerda;
    Node *subArvore = novoNo -> direita;

    novoNo -> direita = no;
    no -> esquerda = subArvore;

    no -> altura = max(altura(no -> esquerda), altura(no -> direita)) + 1;
    novoNo -> altura = max(altura(novoNo -> esquerda), altura(novoNo -> direita)) + 1;

    return novoNo;
}

Node *rotaçãoEsquerda(Node *no){
    Node *novoNo = no -> direita;
    Node *subArvore = novoNo -> esquerda;

    novoNo -> esquerda = no;
    no -> direita = subArvore;

    no -> altura = max(altura(no -> esquerda), altura(no -> direita)) + 1;
    novoNo -> altura = max(altura(novoNo -> esquerda), altura(novoNo -> direita)) + 1;

    return novoNo;
}

Node *insertNode(Node *node, int valor){
    Node *newNode = createNode(valor);

    if(node == NULL)
        return newNode;

    if(valor < node -> chave)
        node-> esquerda = insertNode(node -> esquerda, valor);
    else if(valor > node -> chave)
        node -> direita = insertNode(node -> direita, valor);
    else{
        free(newNode);
        return node;
    }
    
    node -> altura = max(altura(node -> esquerda), altura(node -> direita)) + 1;

    int fator = fatorBalanceamento(node);

    // Rotação simples à direita.
    if(fator > 1 && valor < node -> esquerda -> chave)
        return rotacaoDireita(node);

    // Rotação simples à esquerda.
    if(fator < -1 && valor > node -> direita -> chave)
        return rotaçãoEsquerda(node);

    // Rotação dupla à direita.
    if(fator > 1 && valor > node -> esquerda -> chave){
        node -> esquerda = rotaçãoEsquerda(node -> esquerda);
        return rotacaoDireita(node);
    }

    // Rotação dupla à esquerda.
    if(fator < -1 && valor < node -> direita -> chave){
        node -> direita = rotacaoDireita(node -> direita);
        return rotaçãoEsquerda(node);
    }

    return node;
}

void printTree(Node *node, int espaco){
    if(node == NULL)
        return;
    else{
        espaco += 4;
        printTree(node -> direita, espaco);

        printf("\n");
        
        int i;
        for(i = 0; i < espaco; i++)
            printf(" ");
        
        printf("%d\n", node -> chave);

        printTree(node -> esquerda, espaco);
    }
}