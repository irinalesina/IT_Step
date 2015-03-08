#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"


int main()
{
    int size_of_array, array[1000];
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);

    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");

    int revers, first_pozitive, last_negative;
    first_pozitive = FirstPozitive(array, size_of_array);
    last_negative = LastNegative(array , size_of_array);
    if(first_pozitive != -1 && last_negative != -1)
    {
        revers = array[first_pozitive];
        array[first_pozitive] = array[last_negative];
        array[last_negative] = revers;
        OutputArray(array, size_of_array);
        printf("\n");
    }
    else
    {
        printf("You don't have firs pozitive or last negative element!\n");
    }

    return 0;
}
