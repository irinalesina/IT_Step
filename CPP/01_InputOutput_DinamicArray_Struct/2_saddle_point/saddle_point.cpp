#include <time.h>
#include "saddle_point.h"


void OutputMatrix(int *matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout.width(2);
            cout << matrix[i*columns+j] << ' ';
        }
        cout << endl;
    }
}


void FillMatrix(int *matrix, int rows, int columns)
{
    int amount_of_elements = rows * columns;
    srand(time(NULL));
    for(int i = 0; i < amount_of_elements; i++)
    {
        matrix[i] = rand()%100;
    }
}


int MinElementInRow(int *matrix, int i, int rows, int columns);

int SaddlePoint(int *matrix, int rows, int columns, int *result)
{
    int j, min = 0, amount_of_saddle_point = 0;
    for(int i = 0; i < rows; i++)
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
    int min_index = i*columns;
    for(int j = i * columns + 1; j < i * columns + columns; j++)
    {
        min_index = matrix[j] < matrix[min_index] ? j : min_index;
    }
    return min_index;
}
