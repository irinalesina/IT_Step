#include <stdio.h>
#include <stdlib.h>


int main()
{
    double *array = NULL;
    int size;
    qsort(array, size, sizeof(double), func);

    return 0;
}

int func(const void *a, const void *b)
{
    double x = *((const double*)a), y = *((const double *)b);
    if(x < y) return 1;
    if(x == y) return 0;
    return -1;
    //return *((const double *)a) - *((const double *)b);
}

