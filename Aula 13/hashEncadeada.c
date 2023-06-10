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

void criaTabela(){
    THash *hashT = malloc(sizeof(THash));
    int i;
    for(i = 0; i < TAMANHO; i++)
        hashT -> posicao[i] = NULL;
}

int indiceHash(int valor){
    return valor % TAMANHO;
}

No *criaNo(int valor){
    No *novoNo = (No*)calloc(1, sizeof(No));

    if(novoNo == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }

    novoNo -> chave = valor;
    return novoNo;
}

void insereInicio(THash *hashT, int valor){
    int indice = indiceHash(valor);
    No *novoNo = criaNo(valor);
    
    if(hashT -> posicao[indice] == NULL)
        hashT -> posicao[indice] = novoNo;
    else{
        novoNo -> proximo = hashT -> posicao[indice];
        hashT -> posicao[indice] = novoNo;
    }
}

void imprimeTabela(THash *hashT){
    int i;
    for(i = 0; i < TAMANHO; i++){
        No *auxiliar = hashT -> posicao[i];
        printf("Posicao %d: ", i);

        if(hashT -> posicao[i] == NULL)
            printf("NULL");
        else{
            while(auxiliar != NULL){
                printf("%d -> ", auxiliar -> chave);
                auxiliar = auxiliar -> proximo;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

int main(){
    THash *hashT = malloc(sizeof(THash));
    criaTabela();
    
    printf("\nCriando a Tabela Hash...\n\n");
    imprimeTabela(hashT);
    
    int valores[] = {5, 28, 19, 15, 20, 33, 12, 7, 10};
    int quantidadeValores = sizeof(valores) / sizeof(valores[0]);

    int i;
    for(i = 0; i < quantidadeValores; i++)
        insereInicio(hashT, valores[i]);
    
    printf("\n\nImprimindo a Tabela Hash após a inserção...\n\n");
    imprimeTabela(hashT);

    free(hashT);

    return 0;
}