
int MinInArray(int* array , int length)
{
    int min = array[0] , i;
    for(i = 1; i < length; i++)
    {
        min = array[i] < min ? array[i]: min;
    }
    return min;

}

int MaxInArray(int * array, int length)
{
    int max = array[0], i;
    for(i = 1; i < length; i++)
    {
        max = array[i] > max ? array[i] : max;
    }
    return max;

}

