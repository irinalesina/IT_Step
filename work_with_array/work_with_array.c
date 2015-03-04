#include <stdio.h>
#include <time.h>

static int i;
void InputArray(int* array, int size_of_array)
{
    for(i = 0; i < size_of_array; i++)
    {
        scanf("%d", array+i/*&array[i]*/);
    }
}

void InputCharArray(char array[], int size_of_array)
{
    for(i = 0; i < size_of_array; i++)
    {
        scanf("%c", &array[i]);
    }
}

void OutputArray(int* array, int size_of_array)
{
    for(i = 0; i < size_of_array; i++)
    {
        printf("%d, ", *(array + i)/*array[i]*/);
    }
}

void FillArray(int* array, int size_of_array)
{
    srand(time(NULL));
    char answer;
    printf("Do you want to fill array? y/n\n");
    scanf(" %c", &answer);

    if(answer == 'y')
    {
        InputArray(array, size_of_array);
    }
    else
    {

        int i;
        for(i = 0; i <= size_of_array; i++)
        {
            array[i] = rand()%300-100;
        }
    }
}
