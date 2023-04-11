#include <stdio.h>

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. É usado para
percorrer os elementos do array e, a cada iteração, insere um elemento na usa
posição correta e ordenando-o.
*/
void insertionSort(int array[], int arraySize);

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. Por fim, imprime
os elementos do array na tela.
*/
void printArray(int array[], int arraySize);


int main(){
    int array[] = {7, 9, 5, 4, 6, 2, 3, 1, 8, 0};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    printArray(array, arraySize);

    insertionSort(array, arraySize);

    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

void insertionSort(int array[], int arraySize){
    int i, j, k;
    
    // Percorre o array do segundo até o último elemento.
    for(i = 1; i < arraySize; i++){
        k = array[i]; // Valor atual.
        j = i - 1; // Valor anterior;
    
        // Compara o valor atual com os valores anteriores;
        while(j >= 0 && k < array[j]){
            array[j + 1] = array[j]; // Se necessário, desloca os elementos para a esquerda.
            j--;
        }

        array[j + 1] = k; // Insere o elemento na posição correta.
    }
}

void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
}