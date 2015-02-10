#include <stdio.h>
#include <stdlib.h>
#include "sorting_array.h"

int main()
{
    int line, column;
    printf("Enter amount of lines in array: ");
    scanf("%d", &line);
    printf("Enter amount of columns in array: ");
    scanf("%d", &column);

    FillArray(line, column);
    OutputArray(line, column);
    SortingArray(line, column);
    printf("\nArray after sorting:\n");
    OutputArray(line, column);

    return 0;
}
