#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compareMyType(const void *a, const void *b) {
  int valueA = *(int *)a;
  int valueB = *(int *)b;

  if (valueA < valueB) return -1;
  if (valueA > valueB) return 1;
  return 0;
}

double calcularTempo(clock_t inicio, clock_t fim){
  return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

int main() {
  // int array[] = {2, 21 ,40, 37, 29, 1, 10, 22, 34, 11, 23, 9, 3, 38, 4, 39, 16, 13, 31, 19, 7, 33, 15, 32, 18, 36, 24, 20, 27, 30, 28, 25, 12, 5, 8, 14, 17, 6, 26, 35};
  int array[] = {3, 4, 4, 1, 6, 6, 8, 3, 5, 5, 9, 8, 1, 10, 7, 10, 6, 7, 8, 9, 10, 1, 9, 9, 3, 10, 7, 3, 2, 5, 8, 2, 7, 4, 2, 4, 6, 2, 5, 1};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Array antes da ordenação:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  clock_t inicio = clock(); // Captura o tempo inicial

  qsort(array, size, sizeof(int), compareMyType);

  clock_t fim = clock(); // Captura o tempo final

  printf("Array depois da ordenação:\n");
  for (int i = 0; i < size; i++) {
      printf("%d ", array[i]);
  }
  printf("\n");

  double tempo = calcularTempo(inicio, fim);
  printf("Tempo de execução: %.6f segundos\n", tempo);

  return 0;
}