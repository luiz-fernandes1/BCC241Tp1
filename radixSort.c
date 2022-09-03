#include "radixSort.h"

//Função pra pegar a maior chave do vetor
int getMax(int* vetor, int n) {
    int max = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    return max;
}

void countingSort(int* vetor, int length, int expo) {
    int max = getMax(vetor, length);
    int* countingArray = calloc(max + 1, sizeof(int));
    int* sortedArray = calloc(length + 1, sizeof(int));

    for (int i = 0; i < length; i++) {  // Custo 2 * (n + 1)
        int idx = (vetor[i] / expo) % 10;
        countingArray[idx] += 1;
    }

    for (int i = 1; i <= max; i++) {  // Custo K
        countingArray[i] += countingArray[i - 1];
    }

    for (int i = max - 1; i >= 0; i--) {  // Custo K
        int idx = (vetor[i] / expo) % 10;
        int pos = countingArray[idx];

        sortedArray[pos - 1] = vetor[i];
        countingArray[idx] -= 1;
    }

    // Copiando os elementos ordenados no vetor original
    for (int i = 0; i < length; i++) {  // Custo 2 * (n + 1)
        vetor[i] = sortedArray[i];
    }

    free(countingArray);
    free(sortedArray);
}

void radixSort(int* vetor, int size) {
    int max = getMax(vetor, size);

    for (int place = 1; (max / place) > 0; place *= 10) {  // Custo P
        countingSort(vetor, size, place);
    }
}
// // Printando vetor
// void printArray(int vetor[], int size)
// {
//     for (int i = 0; i < size; ++i)
//     {
//         printf("%d  ", vetor[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int vetor[] = {121, 432, 564, 23, 1, 45, 788};
//     int n = sizeof(vetor) / sizeof(vetor[0]);
//     radixsort(vetor, n);
//     printArray(vetor, n);
// }