/*
Pior caso do Quick Sort.
*/

#include <stdio.h>

/*
A função é usada para separar um array fornecido em partições. São passados três
parâmetros: o array para ordenar, o índice de início e o índice do final do array.
Por fim, a função retorna o índice da partição.
*/
int partition(int array[], int startIndex, int endIndex);

/*
São passados três parâmetros para a função: o array para ordenar, o índice do início
e o índice do final do array. Esta função usa a técnica de divisão e conquista
para ordenar um array fornecido. É feita a chamada recursiva para fazer a divisão
do array em partições e ordenar as partições.
*/
void quickSort(int array[], int startIndex, int endIndex);

/*
Recebe um array de inteiros e o tamanho do array como parâmetros. Por fim, imprime
os elementos do array na tela.
*/
void printArray(int array[], int arraySize);

int main(){
    int array[] = {10, 7, 8, 9, 1, 5};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    printArray(array, arraySize);

    quickSort(array, 0, arraySize - 1);

    printf("Sorted array: ");
    printArray(array, arraySize);

    return 0;
}

int partition(int array[], int startIndex, int endIndex){
    int pivot = array[endIndex]; // Escolhe o último elemento do array como pivô.
    int j, i = startIndex - 1; // i é usado para armazenar a partição.
    
    // Percorre todos os elementos do array.
    for(j = startIndex; j <= endIndex - 1; j++){
        // Verifica se o elemento atual é menor ou igual ao pivô.
        if(array[j] <= pivot){
            // Incrementa o índice do menor elemento.
            i++;

            // Troca o elemento pelo menor elemento.
            int temporary = array[i];
            array[i] = array[j];
            array[j] = temporary;
        }
    }
    // Troca o pivô com o elemento na posição i + 1.
    int temporary = array[i + 1];
    array[i + 1] = array[endIndex];
    array[endIndex] = temporary;
    return i + 1; // Retorna a partição.
}

void quickSort(int array[], int startIndex, int endIndex){
    // Verifica se o array tem ao menos dois elementos.
    if(startIndex < endIndex){
        // partitionIndex é a variável que indica o índice da partição atual. 
        int partitionIndex = partition(array, startIndex, endIndex);
        
        // Chama a função quickSort para as duas partições.
        quickSort(array, startIndex, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, endIndex);
    }
}

void printArray(int array[], int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
}