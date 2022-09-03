#include "radixSort.h"

/*
v = vetor a ser ordenado
n = quantidade de chaves
base = base dos números (seria base 10)
num_digitos = digitos das chaves
*/

void radixSort(int *v, int n, int base, int num_digitos)
{
    int i, j, w, count[base + 1], d, posicao;
    int *aux = (int *)malloc(n * sizeof(int));
    for (w = 1; w <= num_digitos; w++)
    {
        for (j = 0; j < base; j++)
            count[j] = 0;
        for (i = 0; i < n; i++)
        {
            d = digito(v[i], w, base);
            count[d + 1]++;
        }
        for (j = 1; j < base; j++)
            count[j] += count[j - 1];
        for (i = 0; i < n; i++)
        {
            d = digito(v[i], w, base);
            posicao = count[d];
            count[d] += 1;
            aux[posicao] = v[i];
        }
        for (i = 0; i < n; i++)
            v[i] = aux[i];
    }
}

int digito(int valor, int w, int base)
{
    printf("\nDigito:%d", valor / (w*10) % base);
    return (valor / (w*10)) % base;
}