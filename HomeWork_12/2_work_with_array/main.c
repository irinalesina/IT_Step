#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "array_io.h"

int main()
{
    int size_of_array = 7, number;
    int array[size_of_array];
    printf("Enter array: ");

    InputArray(array, size_of_array);
    OutputArray(array, size_of_array);

    printf("\nEnter a number: ");
    scanf("%d", &number);
    printf("Index %d = %d\n", number, Search(array, number, size_of_array));

    return 0;
}
