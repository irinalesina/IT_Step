#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "max_found_one_time.h"
#include <limits.h>

int main()
{
    int array[1000], size_of_array, max;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");
    max = MaxFoundOneTime(array, size_of_array);
    if(max == INT_MIN)
    {
        printf("Error: element not found!");
    }
    else
    {
        printf("Max element, found one time = %d", max);
    }

    return 0;
}
