#include <stdio.h>

static int i;
void InputArray(int* array, int size_of_array)
{
    for(i = 0; i < size_of_array; i++)
    {
        scanf("%d", array+i/*&array[i]*/);
    }
}

void OutputArray(int* array, int size_of_array)
{
    for(i = 0; i < size_of_array; i++)
    {
        printf("%d, ", *(array + i)/*array[i]*/);
    }
}
