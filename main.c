#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>

#include "mergeSort.h"
#include "radixSort.h"
#include "selectionSort.h"

int* geraVetores(int intervalo)
{   
    srand(time(NULL));
    int *vetor = (int *)malloc(intervalo * sizeof(int));

    for (int i = 0; i < intervalo; i++)
    {
        vetor[i] = (rand() % intervalo + 1);
    }
    return vetor;
}

int main()
{
    int n;
    clock_t startr, startm, starts, endr, endm, ends;
    double tempor, tempom, tempos;

    printf("Digite a quantidade de chaves e intervalo: ");
    scanf("%d", &n);
    int *vetorinicial = (int*)malloc(sizeof(int) * n);
    int *vetormerge = (int*)malloc(sizeof(int) * n);
    int *vetorselec = (int*)malloc(sizeof(int) * n);
    int *vetorradix = (int*)malloc(sizeof(int) * n);
  
    vetorinicial = geraVetores(n);
    vetormerge = vetorinicial;
    vetorselec = vetorinicial;
    vetorradix = vetorinicial;

    printf("\nQUANTIDADE DE CHAVES:%d\n", n);
    printf("\nCONTEUDO VETORINIT:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", vetorinicial[i]);
    // }
    printf("\n");

    //merge
    startm = clock();
    mergeSort(vetormerge, n);
    endm = clock();
    tempom = (double)(endm - startm) / CLOCKS_PER_SEC;
    
    printf("\nCONTEUDO VETORMERGE:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetormerge[i]);
    }
    printf("\n Tempo:%.4lf", tempom);
    printf("\n");

    //selection
    starts = clock();
    selectionSort(vetorselec, n);
    ends = clock();
    tempos = (double)(ends - starts) / CLOCKS_PER_SEC;

    printf("\nCONTEUDO VETORSELEC:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetorselec[i]);
    }
    printf("\n Tempo:%.4lf", tempos);
    printf("\n");

    //radix
    startr = clock();
    radixSort(vetorradix, n);
    endr = clock();
    tempor = (double)(endr - startr) / CLOCKS_PER_SEC;

    printf("\nCONTEUDO VETORRADIX:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetorradix[i]);
    }
    printf("\n Tempo:%.4lf", tempor);
    printf("\n");
    

    return 0;
}