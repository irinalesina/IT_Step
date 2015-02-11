#include <stdio.h>
#include <stdlib.h>
#include "work_with_matrix.h"

int main()
{
    int array[100][100], line, column, shift, position;

    printf("Enter amount of lines in array: ");
    scanf("%d", &line);
    printf("Enter amount of columns in array: ");
    scanf("%d", &column);

    printf("Enter amount of shift array: ");
    scanf("%d", &shift);
    printf("Enter position of shift(up-1, down-2, right-3, left-4): ");
    scanf("%d", &position);

    FillArrayRandom(array, line, column);
    OutputArray(array, line, column);

    if(position < 3)
    {
        //ShiftArrayUD(array, line, column, shift, position);
    }
    else
    {
        ShiftArrayRL(array, line, column, shift, position);
    }

    printf("Array after shift:\n");
    OutputArray(array, line, column);

    return 0;
}
