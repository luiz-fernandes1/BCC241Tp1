#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>

#include "mergeSort.h"
#include "radixSort.h"

void printVet(int *v)
{
    for (int i = 0; i <= sizeof(v); i++)
    {
        printf("%d ", v[i]);
    }
}

int* geraVetores(int intervalo)
{   
    int *vetor = (int *)malloc(19 * sizeof(int));
    int i;
    

    for (i = 0; i <= sizeof(vetor); i++)
    {
        vetor[i] = (rand() % intervalo);
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
    double tempor, tempom, tempos;
    int n = 19;
    int intervalo = 0;
    clock_t startr, startm, starti, endr, endm, endi;

    printf("Digite a quantidade o intervalo das chaves: ");
    scanf("%d", &intervalo);
    int *vetorinicial = (int *)malloc(n * sizeof(int));
    int *vetormerge = (int *)malloc(n * sizeof(int));
    int *vetorselection = (int *)malloc(n * sizeof(int));
    
    vetorinicial = geraVetores(intervalo);
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
    mergeSort(vetormerge, n);
    endm = clock();
    printf("\nCONTEUDO ORDENADO:");
    printVet(vetormerge);
    tempom = (double)(endm - startm) / CLOCKS_PER_SEC;
    printf("\n Tempo:%.4lf", tempom);

//-------------------------------------------------------
    printf("\n\n--Resultado SelectionSort--");
        
    return 0;
}