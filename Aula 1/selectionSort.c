#include <stdio.h>

/*
Recebe um array de inteiros e o taamnho do array como parâmetros. O algoritmo funciona comparando um
elemento com todos os outros eleemntos e encontrando o menor. O elemento menor é então trocado com o
elemento da posição atual e esse processo se repete até que o array esteja todo ordenado.
*/
void selectionSort(int array[], int arraySize);

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. Por fim, imprime os elementos do
array na tela.
*/
void printArray(int array[], int arraySize);

int main(){
    int array[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int arraySize = sizeof(array) / sizeof(array[0]);
    
    printf("Unsorted array: ");
    printArray(array, arraySize);

    selectionSort(array, arraySize);

    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

void selectionSort(int array[], int arraySize){
    int i, j, minimumIndex, temporary;
    
    // Percorre todos os elementos do array.
    for(i = 0; i < arraySize; i++){
        minimumIndex = i; // Define o íncide do elemento mínimo como o índice atual.

        // Compara o elemento atual com os outros elementos.
        for(j = i + 1; j < arraySize; j++){
            // Verifica se o elemento atual é menor que o elemento mínimo.
            if(array[j] < array[minimumIndex])
                minimumIndex = j; // Atualiza o índice do elemento mínimo.
        }
        temporary = array[i]; // Armazena o elemento atual na variávl temporária.
        array[i] = array[minimumIndex]; // Substitui o elemento atual pelo elemento mínimo.
        // Substitui o elemento mínimo pelo elemento armazenado na variável temporária.
        array[minimumIndex] = temporary; 
    }
}

void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
       printf("%d ", array[i]);
    printf("\n"); 
}