
/*
IMplemente o algoritmo do Merge Sort visto em aula.
*/

#include <stdio.h>
#include <stdlib.h>

void divide(int array[], int start, int end);

void mergeSort(int array[], int start, int middle, int end);

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

    if(start < end){
        middle = (start + end) / 2;
        divide(array, start, middle);
        divide(array, middle + 1, end);

        mergeSort(array, start, middle, end);
    }
}

void mergeSort(int array[], int start, int middle, int end){
    int i, j, k;
    int *temporaryArray;
    temporaryArray = (int*)malloc(sizeof(int) * (end - start + 1));

    i = start;
    j = middle + 1;
    k = 0;

    while(i <= middle && j <= end){
        if(array[i] <= array[j]){
            temporaryArray[k] = array[i];
            k++;
            i++;
        }else{
            temporaryArray[k] = array[j];
            k++;
            j++;
        }
    }

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

    for(i = start; i <= end; i++)
        array[i] = temporaryArray[i - start];
    
    free(temporaryArray);
}

void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
}