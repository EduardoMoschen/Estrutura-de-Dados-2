#include "hash.h"

void criaTabela(){
    THash *hashT = malloc(sizeof(THash));
    int i;
    for(i = 0; i < TAMANHO; i++)
        hashT -> posicao[i] = NULL; // Inicia todas as posições da tabela como NULL;
}

int indiceHash(int valor){
    return valor % TAMANHO; // Retorna o índice da tabela após o cálculo pelo Método da Divisão.
}

No *criaNo(int valor){
    No *novoNo = (No*)calloc(1, sizeof(No));

    if(novoNo == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }

    novoNo -> chave = valor; // Define um valor para o nó.
    return novoNo;
}

void insereInicio(THash *hashT, int valor){
    int indice = indiceHash(valor);
    No *novoNo = criaNo(valor);
    
    if(hashT -> posicao[indice] == NULL)
        hashT -> posicao[indice] = novoNo; // Insere o nó diretamente, caso esteja vazia.
    else{
        // Havendo colisão, o nó a ser inserido será no início da lista.
        novoNo -> proximo = hashT -> posicao[indice];
        hashT -> posicao[indice] = novoNo;
    }
}

No *busca(THash *hashT, int valor){
    int indice = indiceHash(valor);
    No *auxiliar = hashT -> posicao[indice];

    while(auxiliar != NULL){
        if(auxiliar -> chave == valor)
            return auxiliar; // Retorna o nó encontrado.
        
        auxiliar = auxiliar -> proximo;
    }

    return NULL; // Não encontrando, retorna NULL.
}

void removeChave(THash *hashT, int valor){
    int indice = indiceHash(valor);
    No *auxiliar = hashT -> posicao[indice];
    No *anterior = NULL;

    if(auxiliar == NULL)
        return; // Se a posição estiver vazia, não há o que retornar.
    
    while(auxiliar != NULL){
        if(auxiliar -> chave == valor){
            if(anterior == NULL)
                hashT -> posicao[indice] = auxiliar -> proximo; // Remove o primeiro nó da lista.
            else
                anterior -> proximo = auxiliar -> proximo; // Remove o nó intermediário ou o último.
            
            free(auxiliar); // Libera a memória do nó removido.
            return;
        }
        anterior = auxiliar;
        auxiliar = auxiliar -> proximo;
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

