#include <stdio.h>
#include <stdlib.h>
#include "../../work_with_array/work_with_array.h"


int main()
{
    int array[1000], size_of_array, p, index, i;
    printf("Enter p: ", &p);
    scanf("%d", &p);
    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    FillArray(array, size_of_array);
    OutputArray(array, size_of_array);
    printf("\n");

    index = LastEvenPozitiveP(array, size_of_array, p);
    if(index == -1)
    {
        printf("This element not found!");
    }
    else
    {
        for(i = index; i < size_of_array; i++)
        {
            if(i+1 == size_of_array)
            {
                array[i] = index;
            }
            else
            {
                array[i] = array[i+1];
            }
        }
        OutputArray(array, size_of_array);
        printf("\n");
    }
    return 0;
}
