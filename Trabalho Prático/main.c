#include "RBTree.h"

int main(){
    NoRBTree *RB = NULL;

    // imprime(RB, 0);

    RB = insereNo(RB, 8, "Mala", 7);
    RB = insereNo(RB, 5, "Notebook", 7);
    RB = insereNo(RB, 10, "Cama", 7);
    RB = insereNo(RB, 12, "Sofa", 7);
    RB = insereNo(RB, 16, "Sofa", 7);
    RB = insereNo(RB, 16, "Sofa", 7);

    
    imprime(RB, 0);

    free(RB);

    return 0;
}