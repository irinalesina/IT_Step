#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include <limits.h>

int main()
{
    int array[1000], size_of_array, min;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);

    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");

    min = MinFoundRepeatebly(array, size_of_array);
    if(min == INT_MAX)
    {
        printf("Error, you dont have reapeatedly elements!");
    }
    else
    {
        printf("Min, found repeatebly = %d\n", min);
    }

    return 0;
}
