#include <stdio.h>
#include <string.h>

void binaryInsertionSort(int array[], int arraySize);

void printArray(int array[], int arraySize);

int main(){
    int array[] = {7, 9, 5, 4, 6, 2, 3, 1, 8, 0};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    printArray(array, arraySize);

    binaryInsertionSort(array, arraySize);

    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

void binaryInsertionSort(int array[], int arraySize){
    int i, j, currentValue;

    // Percorre o array do segundo até o último elemento.
    for(i = 1; i < arraySize; i++){
        currentValue = array[i];
        int left = 0; // Limite esquerdo para busca binária.
        int right = i - 1; // Limite direito para busca binária.
    
        // Realiza a busca binária para encontrar a posição correta de inserção.
        while (left <= right) {
            int middle = (left + right) / 2; // Ponto médio da busca.
            
            if (currentValue < array[middle]) 
                right = middle - 1; // O elemento a ser inserido está à esquerda.
            else
                left = middle + 1; // O elemento a ser inserido está à direita ou igual.
        }
        
        if(i - left > 0)
            memcpy(&array[left + 1], &array[left], (i - left) * sizeof(int));

        array[left] = currentValue; // Insere o elemento na posição correta.
    }
}


void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
}