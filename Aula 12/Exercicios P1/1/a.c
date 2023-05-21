#include <stdio.h>

void selectionSort(int array[], int arraySize);

void printArray(int array[], int arraySize);

int main(){
    int array[] = {5, 2, 8, 5, 9};
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