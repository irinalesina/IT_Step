#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "fill_array_mean_elements.h"

int main()
{
    int array[1000], size_of_array;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);

    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");
    FillArrayMeanElements(array, size_of_array);
    return 0;
}
