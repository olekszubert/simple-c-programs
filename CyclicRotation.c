#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
/*
Cyclic rotation of an array.
*/

void cyclicRotation(int* array, int size, int iter)
{
    int* arrayTmp = (int*)malloc(size * sizeof(int)); 
    if (!arrayTmp) return;

    for (int i = 0; i < size; i++)
        arrayTmp[i] = array[i];

    //copy and move
    for (int i = 0; i < size; i++)     
        array[(i + iter) % size] = arrayTmp[i];

    free(arrayTmp);
    arrayTmp = NULL;
}

int main() 
{
    int arrayA[5] = { 3,8,9,7,6 };

    cyclicRotation(arrayA, sizeof(arrayA) / sizeof(arrayA[0]), 2);

    for (int i = 0; i < sizeof(arrayA)/sizeof(arrayA[0]); ++i)
        printf("%d, ", arrayA[i]);

    return 0;
}

