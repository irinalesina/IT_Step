
int LongestSiteWithZero(int*array, int size_of_array)
{
    int last_index = -1, last_index_help, amount_of_zero = 0, amount_of_zero_help = 0, i;
    for(i = 0; i < size_of_array; i++)
    {
        if(array[i] == 0)
        {
            amount_of_zero_help++;
            if(array[i+1] != 0)
            {
                last_index_help = i;
            }
        }
        else
        {
            last_index = amount_of_zero_help > amount_of_zero ? last_index_help : last_index;
            amount_of_zero_help = 0;
        }
    }
    return last_index;
}
