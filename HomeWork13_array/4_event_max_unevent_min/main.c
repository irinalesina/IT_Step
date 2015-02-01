#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "../../HomeWork_12/3_array_min_max/array_min_max.h"

int main()
{
    int array[1000], size_of_array, index, i, max, min;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");
    max = MaxInArray(array, size_of_array);
    min = MinInArray(array, size_of_array);
    for(i = 0; i < size_of_array; i++)
    {
        if(array[i] % 2 == 0)
        {
            array[i] = max;
        }
        else
        {
            array[i] = min;
        }
    }
    OutputArray(array, size_of_array);
    printf("\n");
    return 0;
}
