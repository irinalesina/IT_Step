
int MaxLengthOfSequenceElements(int*array, int size_of_array)
{
    int length = 0, i, j;
    for(i = 0; i < size_of_array; i++)
    {
        int length_work = 1;
        for(j = i+1; j < size_of_array; j++)
        {
            if(array[i] == array[j])
            {
                length_work++;
            }
            else
            {
                break;
            }
        }
        length = length > length_work ? length : length_work;
    }
    return length;
}
