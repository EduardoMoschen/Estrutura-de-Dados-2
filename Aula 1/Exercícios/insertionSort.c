/*
Utilize o algoritmo Insertion Sort para ordenar a seguinte sequência de caracteres: {e,x,e,m,p,l,o,d,e,o,r,d,e,n,a,c,a,o}. 
*/

#include <stdio.h>

void insertionSort(char array[], int arraySize);

void printArray(char array[], int arraySize);

int main(){
    char array[] = {'e','x','e','m','p','l','o','d','e','o','r','d','e','n','a','c','a','o'};
    int arraySize = sizeof(array) / sizeof(array[0]);
    
    printf("Unsorted array: ");
    printArray(array, arraySize);

    insertionSort(array, arraySize);
    
    printf("Sorted array: ");
    printArray(array, arraySize);
    return 0;
}

void insertionSort(char array[], int arraySize){
    int i, j, k;

    for(i = 1; i < arraySize; i++){
        k = array[i];
        j = i - 1;

        while(j >= 0 && k < array[j]){
            array[j + 1] = array [j];
            j--;
        }

        array[j + 1] = k;
    }
}

void printArray(char array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%c ", array[i]);
    printf("\n");
}
