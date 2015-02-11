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

static int helper[100];

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
   // shift %= column;
    if(shift == 0)
    {
        return;
    }
    if(position == 3)
    {

    }
    else
    {
        for(i = 0; i < line; i++)
        {
            printf(" l %d",i);
            for(j = 0; j < shift; j++)
            {
                helper[j] = array[i][j];
            }
            for(j = 0; j < column - shift; j++)
            {
                array[i][j] = array[i][j + shift];
            }
            for(j = 0; j < shift; j++)
            {
                array[i][column - shift + j] = helper[j];
            }
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
