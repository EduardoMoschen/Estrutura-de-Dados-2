#include <stdio.h>
#include <stdlib.h>

/*
Recebe um array de inteiros, um índice de início e um índice de fim como parâmetros. Ela divide o
array em duas partes, e essa divisão é feita de forma recursiva.
*/
void divide(int array[], int start, int end);

/*
Recebe um array de inteiros, um índice para o início, um índice intermediário e um índice de fim
como parâmetros. É feita a comparação dos elementos de cada subarray e adiciona o menor ao array
temporário. Em seguida, move os elementos do array temporário para o array original.
*/
void mergeSort(int array[], int start, int middle, int end);

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. Por fim, imprime os elementos do
array na tela.
*/
void printArray(int array[], int arraySize);


int main(){
    int array[] = {12, 6, 3, 7, 17, 8, 10, 1};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    printArray(array, arraySize);

    divide(array, 0, arraySize - 1);

    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

void divide(int array[], int start, int end){
    int middle;
    
    // Verifica se o índice inicial é menor que o índice final. Se for, significa que o array ainda
    // não foi totalmente divido.
    if(start < end){
        middle = (start + end) / 2; // Divide o array pela metade.
        divide(array, start, middle); // Chama a função para a primeira parte do array.
        divide(array, middle + 1, end); // Chama a função para a segunda parte do array.
        
        // Chama a função responsável por ordenar e mesclar as partes do array.
        mergeSort(array, start, middle, end);
    }
}

void mergeSort(int array[], int start, int middle, int end){
    // Cria um array temporário para guardar or valores ordenados do array original.
    int i, j, k;
    int *temporaryArray;
    temporaryArray = (int*)malloc(sizeof(int) * (end - start + 1));
    i = start; // Índice inicial do array original.
    j = middle + 1; // índice final do array original.
    k = 0;
    
    // Comparação das duas partes e adiciona o menor no array temporário.
    while(i <= middle && j <= end){
        // Verifica se o elemento da parte inicial é menorque o elemento da parte final. Se for, o
        // elemento é adicionado ao array temporário.
        if(array[i] < array[j]){
            temporaryArray[k] = array[i];
            k++;
            i++;
        }else{ // Se o elemento da parte final for maior que o da parte inicial, o elemento é
        // adicionado ao array temporário.
            temporaryArray[k] = array[j];
            k++;
            j++;
        }
    }
    
    // Caso alguns dos subarrays não estejam totalmente percorridos.
    while(i <= middle){
        temporaryArray[k] = array[i];
        k++;
        i++;
    }

    while(j <= end){
        temporaryArray[k] = array[j];
        k++;
        j++;
    }

    // Para cada elemento do array original, o elemento correspondende no array temporário é
    // adicionado ao array original.
    for(i = start; i<= end; i++)
        array[i] = temporaryArray[i - start];
    
    free(temporaryArray);
}

void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
}