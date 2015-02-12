

void FillArrayMeanElements(int*array, int size_of_array)
{
    double array_help[1000], sum = 0;
    int i;
    for(i = 0; i < size_of_array; i++)
    {
        sum += array[i];
        array_help[i] = sum / (i + 1);
    }
    printf("\nNew array:\n");
    OutputDoubleArray(array_help, size_of_array);
}

void OutputDoubleArray(double array[], int size_of_array)
{
    int i;
    for(i = 0; i < size_of_array; i++)
    {
        printf("%.2f  ", array[i]);
    }
    printf("\n");
}
