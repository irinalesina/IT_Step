#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static int i, j;


void FillArrayRandom(int array[][100], int line, int column)
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

static int helper;

/*void ShiftArrayUD(int array[][100], int line, int column, int shift, int position)
{
    for(i = 0; i < ; i++)
    {
        if(line % shift == 0)
            {
                break;
            }
        for(j = 0; j < column)
        {

        }
    }
}*/


void ShiftArrayRL(int array[][100], int line, int column, int shift, int position)
{
    shift %= column;
    if(shift == 0)
    {
        return;
    }

    for(i = 0; i < line; i++)
    {
        if(position == 3) //right
        {
            for(int k = 0; k < shift; ++k)
            {
                j = 0;
                helper = array[i][j];
            }
        }
        else //left
        {
            helper = array[i][j];
            array[i][j] = array[i][j > column - shift ? j -  : column - shift + j];
            array[i][j < shift ? column - shift + j : j - shift] = helper;
        }
    }
}


void OutputArray(int array[][100], int line, int column)
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
