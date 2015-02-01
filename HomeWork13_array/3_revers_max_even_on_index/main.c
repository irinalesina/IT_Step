#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "../2_max_even_min_uneven/max_even_min_uneven.h"

int main()
{
    int array[1000], size_of_array, index;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");

    index = MaxEven(array, size_of_array);
    array[index] = index;
    OutputArray(array, size_of_array);
    printf("\n");
    return 0;
}
