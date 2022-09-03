#include<stdbool.h>
#include<string.h>
#include<time.h>

#include "mergeSort.h"
#include "selectionSort.h"

void geraVetores(int n)
{
    int i, vetor[n];
    int *aux = (int *)malloc(n * sizeof(int));

    for (i = 0; i <= n; i++)
    {
        vetor[i] = (rand() % n);
        printf("%d ", vetor[i]);
    }
    aux = vetor;
    print(aux);
}

int main()
{
    int escolha;
    double tempo;
    int vetor[10]; 
    geraVetores(10);

    clock_t start, end;

    printf("Escolha qual método quer utilizar\n");
    printf("Digite: 1 - MergeSort, 2 - RadixSort, 3 - SelectionSort\n");
    scanf("%d", &escolha);

    if (escolha != 1 && escolha != 2 && escolha != 3){
        printf("Por favor, escolha uma opção válida:\n");
        printf("1 para MergeSort\n");
        printf("2 para RadixSort\n");
        printf("3 para SelectionSort\n");
        scanf("%d", &escolha);
    }else if (escolha == 1){
        start = clock();
        mergeSort();
        end = clock();
    }else if(escolha == 2){
        start = clock();
        radixSort();
        end = clock();
    }else if(escolha == 3){
        start = clock();
        selectionSort();
        end = clock();
    }

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.4lf\n", tempo);
        
    return 0;
}