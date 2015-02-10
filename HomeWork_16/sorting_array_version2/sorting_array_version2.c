#include <time.h>

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


void SortingArrayVersion2(int line, int column)
{
        int helper = -1;
        for(i = 0; i < line; i++)
        {
            for(j = 0; j < column; j++)
            {
                if(j == column - 1)
                {
                    if(i == line - 1)
                    {
                        break;
                    }
                    else if(array[i][j] > array[i+1][0])
                    {
                        helper = array[i][j];
                        array[i][j] = array[i+1][0];
                        array[i+1][0] = helper;
                    }
                }
                else if(array[i][j] > array[i][j+1])
                {
                    helper = array[i][j];
                    array[i][j] = array[i][j+1];
                    array[i][j+1] = helper;
                }
            }
        }
        if(helper != -1)
        {
            return SortingArrayVersion2(line, column);
        }
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
