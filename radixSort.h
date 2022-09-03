#ifndef radixSort_H
#define radixSort_H

#include <stdio.h>
#include <stdlib.h>

void radixSort(int *v, int n, int base, int num_digitos);
int digito(int value, int w, int base);

#endif