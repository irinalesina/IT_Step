#include <stdio.h>

void output(const int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
}
