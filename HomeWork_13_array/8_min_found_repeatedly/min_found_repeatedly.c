#include <limits.h>

int MinFoundRepeatebly(int*array, int size_of_array)
{
    int i, j, ignore = 0, min = INT_MAX;

    for(i = 0; i < size_of_array; i++)
    {
        ignore = 0;
        for(j = i+1; j < size_of_array; j++)
        {
            if(array[i] == array[j])
            {
                ignore++;
                break;
            }
        }
        if(ignore)
        {
            min = min < array[i] ? min : array[i];
        }
    }

    return min;
}
