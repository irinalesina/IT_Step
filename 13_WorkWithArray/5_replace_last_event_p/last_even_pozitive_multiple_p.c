
int LastEvenPozitiveP(int*array, int size_of_array, int p)
{
    int i;
    for(i = size_of_array - 1; i >= 0; i--)
    {
        if(array[i] % 2 == 0 && array[i] % p == 0 && array[i] > 0)
        {
            return i;
        }
    }
    return -1;
}
