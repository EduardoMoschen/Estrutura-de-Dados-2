/*
Utilize o algoritmo Selection Sort para ordenar a seguinte sequência de caracteres: {e,x,e,m,p,l,o,d,e,o,r,d,e,n,a,c,a,o}. 
*/

#include <stdio.h>

void selectionSort(char array[], int arraySize);

void printArray(char array[], int arraySize);

int main(){
    char array[] = {'e','x','e','m','p','l','o','d','e','o','r','d','e','n','a','c','a','o'};
    int arraySize = sizeof(array) / sizeof(array[0]);
    
    printf("Unsorted array: ");
    printArray(array, arraySize);

    selectionSort(array, arraySize);
    
    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

void selectionSort(char array[], int arraySize){
    int i, j, minimumIndex, temporary;

    for(i = 0; i < arraySize; i++){
        minimumIndex = i;
        
        for(j = i + 1; j < arraySize; j++){
            if(array[j] < array[minimumIndex])
                minimumIndex = j;
        }

        temporary = array[i];
        array[i] = array[minimumIndex];
        array[minimumIndex] = temporary;
    }
}

void printArray(char array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%c ", array[i]);
    printf("\n");
}