#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int CheckArray(int array[], int size);
void SortingArrayStupid(int array[], int size);
void OutputArray(int array[], int size);
void FillArrayRandom(int array[], int size);
void FastSorting(int array[], int size);

int main()
{
    srand(time(NULL));
    int array[N];
    FillArrayRandom(array, N);
    OutputArray(array, N);
    while(CheckArray(array, N) == 0)
    {
        SortingArrayStupid(array, N);
    }
    printf("\ntrue\n");
    OutputArray(array, N);
    return 0;
}

int CheckArray(int array[], int size)
{
    int i;
    for(i = 0; i < size - 1; i++)
    {
        if(array[i] > array[i+1])
        {
            return 0;
        }
    }
    return 1;

}

void SortingArrayStupid(int array[], int size)
{
    int i, j, helper;
    i = rand() % size;
    j = rand() % size;
    helper = array[i];
    array[i] = array[j];
    array[j] = helper;
}

void OutputArray(int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void FillArrayRandom(int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

void FastSorting(int array[], int size)
{
    int i, j = 0, helper, oporn_element;
    oporn_element = array[size-1];
    for(i = 1; i < size; i++)
    {
        if(array[i] < oporn_element)
        {
            helper = array[i];
            array[i] = array[j];
            array[j] = helper;
            j++;
        }
    }
}
