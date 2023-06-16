#include "RBTree.h"

int main(){
    NoRBTree *RBTree = NULL;

    RBTree = insere(RBTree, 7, "Cadeira", 2);
    RBTree = insere(RBTree, 2, "Mesa", 3);
    RBTree = insere(RBTree, 3, "Mala", 7);
    // RBTree = insere(RBTree, 12, "Mesa", 3);
    // RBTree = insere(RBTree, 15, "Mesa", 3);
    // RBTree = insere(RBTree, 18, "Mesa", 3);
    // RBTree = insere(RBTree, 21, "Mesa", 3);
    
    imprime(RBTree, 0);

    free(RBTree);

    return 0;
}