/*
Sugira uma estrutura de dados (struct) para representar uma árvore Rubro Negra.
Considere que a estrutura deve armazenar tanto a chave quanto o conteúdo
associado a esta chave
*/

typedef struct tree{
    int chave; // Valor a ser armazenado.
    int cor; // Cor do nó, sendo 1 para rubro e 0 para negro.
    struct tree *direita;
    struct tree *esquerda;
}TreeRN;