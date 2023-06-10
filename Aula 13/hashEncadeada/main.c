#include "hash.h"

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
    
    printf("\n\nImprimindo a Tabela Hash após a insercao...\n\n");
    imprimeTabela(hashT);
    
    printf("\nBuscando uma chave...\n\n");
    No *noEncontrado = busca(hashT, 15);
    if(noEncontrado != NULL)
        printf("Chave encontrada: %d\n", noEncontrado -> chave);
    else
        printf("Chave nao encontrada\n");
    
    printf("\nRemovendo uma chave...");
    removeChave(hashT, 19);

    printf("\n\nImprimindo a Tabela Hash após a remocao...\n\n");
    imprimeTabela(hashT);

    free(hashT);

    return 0;
}