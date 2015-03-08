
int AmountOfElementsFoundSometimes(int array[], int size_of_array)
{
    int amount = 0, i, j, k, helper[1000];
    for(i = 0; i < size_of_array; i++)
    {
        for(j = 0; j < size_of_array; j++)
        {
            if(i != j && array[i] == array[j])
            {
                int indicator = 0;
                for(k = 0; k < amount; k++)
                {
                    if(array[j] == helper[k])
                    {
                        indicator++;
                        break;
                    }
                }
                if(indicator)
                {
                    break;
                }
                helper[amount++] = array[j];
            }
        }
    }
    return amount;
}
