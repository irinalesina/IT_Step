


int Calculating(char argv[], int *result)
{
    int priority = 0, i, size_of_str;
    size_of_str = strlen(argv);
    UniversalStack *numbers, *operations;

    //memory allocation
    Initialize(numbers, sizeof(double), size_of_str);
    Initialize(operations, sizeof(char), size_of_str);

    char operation[] = "()+-*/^";
    for(i = 0; i < size_of_str; i++)
    {
        if(strchr(operation, argv[i])
        {

        }
        else
        {

        }
    }




    //free memory
    Uninitialize(numbers);
    Uninitialize(operations);
}
