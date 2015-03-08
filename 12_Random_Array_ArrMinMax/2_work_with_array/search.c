
int Search(int* array, int number, int size_of_array)
{
    int i;
    for(i = 0; i < size_of_array; i++)
    {
        if(array[i] == number)
        {
            return i;
        }
    }
    return -1;
}
