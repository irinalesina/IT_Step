#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "max_length_of_sequence_elements.h"

int main()
{
    int array[1000], size_of_array, length;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);

    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");
    length = MaxLengthOfSequenceElements(array, size_of_array);
    if(length)
    {
        printf("Max length of sequence elements in array = %d\n", length);
    }
    else
    {
        printf("Error, so elements not found!\n");
    }


    return 0;
}
