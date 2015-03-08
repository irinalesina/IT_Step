#include <limits.h>
int MaxFoundOneTime(int*array, int size_of_array)
{
    int max = INT_MIN, i, j;
    for(i = 0; i < size_of_array; i++)
    {
        if(max < array[i])
        {
            int only_one = 1;
            for(j = 0; j < size_of_array; j++)
            {
                if(array[i] == array[j] && i != j)
                {
                    only_one = 0;
                    break;
                }
            }
            if(only_one)
            {
                max = array[i];
            }
        }
    }
    return max;
}
