#include <stdio.h>
#include <stdlib.h>
#include "work_with_dinamic_matrix_v1.h"

int main()
{
    int rows, columns, *matrix, *result, amount_of_saddle_point;
    printf("Enter amount of elements: ");
    scanf("%d%d", &rows, &columns);

    matrix = (int*)malloc(rows * columns * sizeof(int));
    if(matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    result = (int*)malloc(rows * columns/2 * sizeof(int));
    if(result == NULL)
    {
        free(matrix);
        matrix = NULL;
        printf("Memory allocation failed!\n");
        exit(1);
    }

    FillMatrix(matrix, rows, columns);
    OutputMatrix(matrix, rows, columns);

    amount_of_saddle_point = SaddlePoint(matrix, rows, columns, result);
    if(amount_of_saddle_point == NULL)
    {
        printf("You don't have saddle point!\n");
    }
    else
    {
        amount_of_saddle_point > 1 ? printf("You have %d saddle points:\n", amount_of_saddle_point) : printf("You have %d saddle point:\n", amount_of_saddle_point);
        int i;
        for(i = 0; i < amount_of_saddle_point; i++)
        {
            printf("%d. %d[%d, %d]", i+1, matrix[result[i]], result[i]/columns, result[i]%columns);
        }
    }
    return 0;
}
