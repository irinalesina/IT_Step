#include <stdio.h>

int LastNegative(int* array , int length)
{
    int i;
    for(i = length - 1; i >= 0; i--)
    {
        if(array[i] < 0)
        {
            return  i;
        }
    }
    return -1;
}

int FirstPozitive(int * array, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        if(array[i] > 0)
        {
            return i;
        }
    }
    return -1;
}
