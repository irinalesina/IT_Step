#include <time.h>

void OutputMatrix(int *matrix, int rows, int columns)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("%2d ", matrix[i*columns+j]);
        }
        printf("\n");
    }
}


void FillMatrix(int *matrix, int rows, int columns)
{
    int i, amount_of_elements = rows * columns;
    srand(time(NULL));
    for(i = 0; i < amount_of_elements; i++)
    {
        matrix[i] = rand()%100;
    }
}


int MinElementInRow(int *matrix, int i, int rows, int columns);

int SaddlePoint(int *matrix, int rows, int columns, int *result)
{
    int i, j, min = 0, amount_of_saddle_point = 0;
    for(i = 0; i < rows; i++)
    {
        min = MinElementInRow(matrix, i, rows, columns);
        for(j = 0; j < rows; j++)
        {
            if(j * columns + (min - i * columns) == min)
            {
                continue;
            }
            if(matrix[j * columns + (min - i * columns)] > matrix[min])
            {
                break;
            }
        }
        if(j == rows)
        {
            result[amount_of_saddle_point++] = min;
        }
    }
    return amount_of_saddle_point;
}

int MinElementInRow(int *matrix, int i, int rows, int columns)
{
    int j, min_index = i*columns;
    for(j = i * columns + 1; j < i * columns + columns; j++)
    {
        min_index = matrix[j] < matrix[min_index] ? j : min_index;
    }
    return min_index;
}
