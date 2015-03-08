#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static int array[100][100], i, j;

void FillArray(int line, int column)
{
    srand(time(NULL));

    for(i = 0; i < line; i++)
    {
        for(j = 0; j < column; j++)
        {
            array[i][j] = rand() % 100;
        }
    }
}


void SortingArray(int line, int column)
{
    int step_line = 0, step_column = 0, min = array[0][0], helper;
    do
    {
        for(i = step_line; i < line; i++)
        {
            for(j = (i == step_line) ? step_column : 0; j < column; j++)
            {
                if(min > array[i][j])
                {
                    helper = min;
                    min = array[i][j];
                    array[i][j] = helper;
                }
            }
        }
        array[step_line][step_column] = min;

        step_column++;
        if(step_column == column)
        {
            step_column = 0;
            step_line++;
        }

        min = array[step_line][step_column];

    }while(step_line < line);
}


void OutputArray(int line, int column)
{
    for(i = 0; i < line; i++)
    {
        for(j = 0; j < column; j++)
        {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}
