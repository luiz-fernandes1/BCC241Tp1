#include <stdio.h>
#include <stdlib.h>

void geraVetores(int n)
{
    int i, vetor[19];
    for (i = 0; i <= 19; i++)
    {
        vetor[i] = (rand() % n);
        printf("%d ", vetor[i]);
    }
}

int main()
{
    geraVetores(10);
    return 0;
}