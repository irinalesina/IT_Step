

void SortingSelection(int array[], int size_of_array)
{
    int helper, i, j;
    for(i = 0; i < size_of_array; i++)
    {
        for(j = 0 + i; j < size_of_array - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                helper = array[j];
                array[j] = array[j+1];
                array[j+1] = helper;
            }
        }
    }
}


void SortingBuble(int array[], int size_of_array)
{
    int helper, i, j;
    for(i = 0; i < size_of_array; i++)
    {
        for(j = 0; j < size_of_array - 1 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                helper = array[j];
                array[j] = array[j+1];
                array[j+1] = helper;
            }
        }
    }
}


void SortingInsertion(int array[], int size_of_array)
{
    int helper, i, j;
    for(i = 1; i < size_of_array; i++)
    {
        for(j = i - 1; j >= 0; j--)
        {
            if(array[j+1] < array[j])
            {
                helper = array[j];
                array[j] = array[j+1];
                array[j+1] = helper;
            }
        }
    }
}


void SortingMerge(int array[], int from, int to)
{
    int i, j, array_r, array_l;
    if(from < to)
    {
        SortingMerge(array, from, (from + to)/2);
        SortingMerge(array, (from + to)/2+1, to);
    }


}


void SortingQuick(int array[], int size_of_array)
{

}


void SortingHeap(int array[], int size_of_array)
{

}


int CheckSortingArray(int array[], int size_of_array)
{
    int i;
    for(i = 0; i < size_of_array-1; i++)
    {
        if(array[i] > array[i+1])
        {
            return i;
        }
    }
    return -1;
}

