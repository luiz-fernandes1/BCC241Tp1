#include "selectionSort.h"

void selectionSort_troca(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int vet[], int n){
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++){
        min_idx = i;
        
        for(j = i+1; j < n; j++){
            if(vet[j] < vet[min_idx]){
                min_idx = j;
            }
        }

        if(min_idx != i){
            selectionSort_troca(&vet[min_idx], &vet[i]);
        }
    }
}

void imprimeVetor(int vet[], int tam){
    int i;

    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
}