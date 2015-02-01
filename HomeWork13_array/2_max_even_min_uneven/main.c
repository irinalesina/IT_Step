#include <stdio.h>
#include <stdlib.h>
#include "max_even_min_uneven.h"

int main()
{
    int array[1000], size_of_array;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\nMax even in array: %d\n", array[MaxEven(array, size_of_array)]);
    printf("Min uneven in array: %d\n", array[MinUneven(array, size_of_array)]);
    return 0;
}
