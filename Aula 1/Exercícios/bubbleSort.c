/*
Utilize o algoritmo BubbleSort para ordenar a seguinte sequência de caracteres: {e,x,e,m,p,l,o,d,e,o,r,d,e,n,a,c,a,o}. 
*/

#include <stdio.h>

void bubbleSort(char array[], int arraySize);

void printArray(char array[], int arraySize);

int main(){
    char array[] = {'e','x','e','m','p','l','o','d','e','o','r','d','e','n','a','c','a','o'}; 
    int arraySize = sizeof(array) / sizeof(array[0]);
    
    printf("Unsorted array: ");
    printArray(array, arraySize);

    bubbleSort(array, arraySize);
    
    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

void bubbleSort(char array[], int arraySize){
    int i, j;

    for(i = 0; i < arraySize; i++){
        for(j = i + 1; j < arraySize; j++){
            if(array[j] < array[i]){
                char auxiliar = array[i];
                array[i] = array[j];
                array[j] = auxiliar;
            }
        }
    }
}

void printArray(char array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%c ", array[i]);
    printf("\n");
}
