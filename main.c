#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>

#include "mergeSort.h"
#include "radixSort.h"
#include "selectionSort.h"

void printVet(int *v)
{
    for (int i = 0; i <= sizeof(v); i++)
    {
        printf("%d ", v[i]);
    }
}

int* geraVetores(int intervalo)
{   
    srand(time(NULL));
    int *vetor = (int *)malloc(19 * sizeof(int));

    for (int i = 0; i <= sizeof(vetor); i++)
    {
        vetor[i] = (rand() % 100);
    }
    return vetor;
}

void copiaVetores(int *v1, int *v2, int *v3){
    for (int i = 0; i <= sizeof(v1); i++)
    {
        v2[i] = v1[i];
        v3[i] = v1[i];
    }
    
}

int main()
{
    int i, n = 20;

    int *vetorinicial = (int*)malloc(sizeof(int) * n);
    int *vetormerge = (int*)malloc(sizeof(int) * n);
    int *vetorselec = (int*)malloc(sizeof(int) * n);
    
    vetorinicial = geraVetores(n);
    vetormerge = vetorinicial;
    vetorselec = vetorinicial;

    printf("\nCONTEUDO VETORINIT:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetorinicial[i]);
    }
    printf("\n");

    mergeSort(vetormerge, n);
    printf("\nCONTEUDO VETORMERGE:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetormerge[i]);
    }
    printf("\n");
    
    selectionSort(vetorselec, n);
    printf("\nCONTEUDO VETORSELEC:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetorselec[i]);
    }
    printf("\n");

    

    
    /*double tempor, tempom, tempos;
    int n = 20;
    int intervalo, teste[4];
    clock_t startr, startm, starti, endr, endm, endi;

    //printf("Digite a quantidade o intervalo das chaves: ");
    //scanf("%d", &intervalo);
    
    int *vetormerge = (int *)malloc(sizeof(int) * n);
    int *vetorselection = (int*)malloc(sizeof(int) * n);
    
    
    copiaVetores(vetorinicial, vetormerge, vetorselection);
    
    printf("CONTEUDO VETORINICIAL:");
    printVet(vetorinicial);
    printf("\nCONTEUDO VETORMERGE:");
    printVet(vetormerge);
    printf("\nCONTEUDO VETORSELECTION:");
    printVet(vetorselection);

//-------------------------------------------------------
    printf("\n\n--Resultado RadixSort--");
    int qtd_digitos = (int)(log10((double)intervalo)) + 1;
    startr = clock();
    radixSort(vetorinicial, n, 10, qtd_digitos);
    endr = clock();
    printf("\nCONTEUDO ORDENADO:");
    printVet(vetorinicial);
    tempor = (double)(endr - startr) / CLOCKS_PER_SEC;
    printf("\n Tempo:%.4lf", tempor);
    
//-------------------------------------------------------
    printf("\n\n--Resultado MergeSort--");
    startm = clock();
    mergeSort(vetorinicial, n);
    endm = clock();
    printf("\nCONTEUDO ORDENADO:");
    printVet(vetorinicial);
    tempom = (double)(endm - startm) / CLOCKS_PER_SEC;
    printf("\n Tempo:%.4lf", tempom);
    
//-------------------------------------------------------
    /*printf("\n\n--Resultado SelectionSort--");
    startm = clock();
    selectionSort(vetorinicial, n);
    endm = clock();
    printf("\nCONTEUDO ORDENADO:");
    printVet(vetorinicial);
    tempom = (double)(endm - startm) / CLOCKS_PER_SEC;
    printf("\n Tempo:%.4lf", tempom);
    */
    return 0;
}