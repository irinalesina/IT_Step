#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"
#include "found_longest_site_with_zero.h"

int main()
{
    int array[1000], size_of_array, first_index, last_index;
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");
    last_index = LongestSiteWithZero(array, size_of_array);
    if(last_index == -1)
    {
        printf("Zero is not found!");
    }
    else
    {
        first_index = last_index;
        while(array[first_index] == 0)
        {
            first_index--;
        }
        printf("First index = %d\n", first_index + 1);
        printf("Last index = %d\n", last_index);
    }
    return 0;
}
