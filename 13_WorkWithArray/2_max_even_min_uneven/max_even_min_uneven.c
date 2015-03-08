
int MaxEven(int *array, int size_of_array)
{
    int max, i = 0;
    while(array[i] % 2 != 0)
    {
        i++;
    }
    max = i;

    for(i+1; i+1 < size_of_array; i++)
    {
        if(array[i+1] % 2 == 0)
        {
            max = array[max] > array[i+1] ? max : i+1;
        }
    }
    return max;
}

int MinUneven(int *array, int size_of_array)
{
    int min, i = 0;
    while(array[i] % 2 == 0)
    {
        i++;
    }
    min = i;

    for(i+1; i+1 < size_of_array; i++)
    {
        if(array[i+1] % 2 != 0)
        {
            min = array[min] < array[i+1] ? min : i+1;
        }
    }
    return min;
}
