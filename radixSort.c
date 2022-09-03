#include <stdio.h>
int getMax(int vetor[], int n);
void countingSort(int vetor[], int size, int place);
void radixsort(int vetor[], int size);

//Função pra pegar a maior chave do vetor
int getMax(int vetor[], int n)
{
    int max = vetor[0];
    for (int i = 1; i < n; i++)
        if (vetor[i] > max)
            max = vetor[i];
    return max;
}

void countingSort(int vetor[], int size, int place)
{
    int output[size + 1];
    int max = (vetor[0] / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((vetor[i] / place) % 10) > max)
            max = vetor[i];
    }
    int count[max + 1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Contagem de elementos
    for (int i = 0; i < size; i++)
        count[(vetor[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Colocando os elementos ordenados
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(vetor[i] / place) % 10] - 1] = vetor[i];
        count[(vetor[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        vetor[i] = output[i];
}

void radixsort(int vetor[], int size)
{
    int max = getMax(vetor, size);

    //Usando countingsort pra ordenar os valores paseados na posição
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(vetor, size, place);
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