#include "sorting_array.h"

void SortingSelection(int *array, int size_of_array)
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


void SortingBuble(int *array, int size_of_array)
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


void SortingInsertion(int *array, int size_of_array)
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


void SortingMerge(int *array, int left, int right)
{
    if(left < right)
    {
        SortingMerge(array, left, (left + right)/2);
        SortingMerge(array, (left + right)/2+1, right);
        int array_left[N], array_right[N], i, j;
        for(i = left, j = 0; i <= (left+right)/2; i++, j++)
        {
            array_left[j] = array[i];
        }
        for(i = (left+right)/2 +1, j = 0; i <= right; i++, j++)
        {
            array_right[j] = array[i];
        }
        int k;
        i = left, j = 0, k = 0;
        while(j <= (left+right)/2 - left && k <= right - (left+right)/2 - 1)
        {
            if(array_left[j] < array_right[k])
            {
                array[i] = array_left[j];
                ++j;
            }
            else
            {
                array[i] = array_right[k];
                ++k;
            }
            ++i;
        }
        while(j <= (left+right)/2 - left)
        {
            array[i] = array_left[j];
            ++j;
            ++i;
        }
        while(k <= right - (left+right)/2 - 1)
        {
            array[i] = array_right[k];
            ++k;
            ++i;
        }
    }

}

int Partition(int *array, int left, int right);

void SortingQuick(int *array, int left, int right)
{
    if(left < right)
    {
        int index = Partition(array, left, right);
        SortingQuick(array, left, index - 1);
        SortingQuick(array, index + 1, right);
    }
}


void SortingHeap(int *array, int size_of_array)
{

}


int CheckSorting(int *array, int size_of_array)
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

int Partition(int *array, int left, int right)
{
    int i = left;
    while(array[i] < array[right])
    {
        i++;
    }
    int temp, j;
    for(j = i; j < right; j++)
    {
        if(array[j] < array[right])
        {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i++;
        }
    }
    temp = array[i];
    array[i] = array[right];
    array[right] = temp;
    return i;
}
