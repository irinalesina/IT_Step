#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "amount_of_elements_found_sometimes.h"

int main()
{
    int array[1000], size_of_array, min;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);

    FillArray(array, size_of_array);
    printf("\n");
    OutputArray(array, size_of_array);
    printf("\n");
    printf("Amount of elements found sometimes: %d\n", AmountOfElementsFoundSometimes(array, size_of_array));
    return 0;
}
