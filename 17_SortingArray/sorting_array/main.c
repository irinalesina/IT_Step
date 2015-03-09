#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "sorting_array.h"

#define N 100

int main()
{
    int array[N], size_of_array;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n\n");
    SortingMerge(array, 0, size_of_array - 1);
    OutputArray(array, size_of_array);

    return 0;
}
