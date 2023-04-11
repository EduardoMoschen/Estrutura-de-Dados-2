#include <stdio.h>

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. A função
percorre o array várias vezes, comparando e trocando os elementos sempre quando
necessário, até conseguir a ordenação.
*/
void bubbleSort(int array[], int arraySize);

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. Por fim,
imprime os elementos do array na tela.
*/
void printArray(int array[], int arraySize);

int main(){
    int array[] = {7, 3, 5, 9, 1, 4};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    printArray(array, arraySize);

    bubbleSort(array, arraySize);
    
    printf("Sorted array: ");
    printArray(array, arraySize);
    return 0;
}

void bubbleSort(int array[], int arraySize){
    int i, j, auxiliar;
    
    // Percorre o array do primeiro elemento até o último.
    for(i = 0; i < arraySize; i++){
        // Percorre o array do segundo elemento até o último.
        for(j = i + 1; j < arraySize; j++){

            // Se o elemento atual for menor que o elemento anterior, eles são trocados.
            if(array[j] < array[i]){
                auxiliar = array[i];

                // O valor do elemento anterior é armazenado temporariamente em uma variável auxiliar,
                // para que possa ser atribuído ao elemento posterior.
                array[i] = array[j];
                array[j] = auxiliar;
            }
        }
    }
}

void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
}