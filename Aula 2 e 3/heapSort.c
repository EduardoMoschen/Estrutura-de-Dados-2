#include <stdio.h>

/*
Recebe um array de inteiros, o tamanho do array e o índice do nó raiz como parâmetros.
Essa função compara o nó raiz com seus filhos esquerdo e direito e encontra o maior
entre eles. Caso o maior seja diferente do nó raiz, os valores são trocados e a
função é chamada recursivamente no maior nó.
*/
void maxHeapify(int array[], int arraySize, int rootNodeIndex);

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. Esta função é
responsável por organizar os itens no array paar serem ordenados de acordo com a
estrutura de heap (árvore).
*/
void heapSort(int array[], int arraySize);

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. Por fim, imprime
os elementos do array na tela.
*/
void printArray(int array[], int arraySize);


int main(){
    int array[] = {10, 7, 8, 9, 1, 5};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    printArray(array, arraySize);
    
    heapSort(array, arraySize);

    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

void maxHeapify(int array[], int arraySize, int rootNodeIndex){
    int largest = rootNodeIndex;  // Inicializa o maior como nó raiz.
    int left = 2 * rootNodeIndex + 1; // Encontrando o filho esquerdo.
    int right = 2 * rootNodeIndex + 2; // Encontrando o filho direito.
    
    // Se o filho esquerdo é maior que o nó raiz.
    if(left < arraySize && array[left] > array[largest])
        largest = left;
    
    // Se o filho direito for maior que o maior até agora.
    if(right < arraySize && array[right] > array[largest])
        largest = right;
    
    // Se o maior valor não é o nó raiz.
    if(largest != rootNodeIndex){
        int swap = array[rootNodeIndex];
        array[rootNodeIndex] = array[largest];
        array[largest] = swap;
    
        // Chama a função novamente.
        maxHeapify(array, arraySize, largest);
    }
}

void heapSort(int array[], int arraySize){
    int rootNodeIndex;
    
    // Contrução do heap.
    for(rootNodeIndex = arraySize / 2 - 1; rootNodeIndex >= 0; rootNodeIndex--)
        maxHeapify(array, arraySize, rootNodeIndex);
    
    for(rootNodeIndex = arraySize - 1; rootNodeIndex >= 0; rootNodeIndex--){
        int swap = array[0]; // Move o nó raiz para o final.
        array[0] = array[rootNodeIndex];
        array[rootNodeIndex] = swap;
        
        // Chama a função no Heap reduzido.
        maxHeapify(array, rootNodeIndex, 0);
    }
}

void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
}