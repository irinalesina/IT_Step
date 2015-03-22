#include <stdio.h>
#include <stdlib.h>
#define N 7

void OutputArr(int *arr, int size_of_arr);
int Descending(const void *a, const void *b);
int AscendingSumOfDigits(const void *a, const void *b);
int AscendingAmountOfDenominators(const void *a, const void *b);

int main()
{
    int size_of_arr = N, arr[N] = {11, 65, 21, 34, 28, 7, 19};

    qsort(arr, size_of_arr, sizeof(int), Descending);
    printf("Sort array descending:\n");
    OutputArr(arr, size_of_arr);

    qsort(arr, size_of_arr, sizeof(int), AscendingSumOfDigits);
    printf("Sort array ascending sum of digits:\n");
    OutputArr(arr, size_of_arr);

    qsort(arr, size_of_arr, sizeof(int), AscendingAmountOfDenominators);
    printf("Sort array ascending amount of denominators:\n");
    OutputArr(arr, size_of_arr);

    return 0;
}


int Descending(const void *a, const void *b)
{
    int x = *((int*)a), y = *((int *)b);
    if(x < y) return 1;
    if(x == y) return 0;
    return -1;
}

int AscendingSumOfDigits(const void *a, const void *b)
{
    int x = *((int*)a), y = *((int*)b);
    int sum_x = 0, sum_y = 0;
    while(x != 0)
    {
        sum_x += x % 10;
        x /= 10;
    }
    while(y != 0)
    {
        sum_y += y % 10;
        y /= 10;
    }
    if(sum_x < sum_y) return -1;
    if(sum_x == sum_y) return 0;
    return 1;
}
int AmountOfDenominators(int number);
int AscendingAmountOfDenominators(const void *a, const void *b)
{
    int x = *((int*)a), y = *((int*)b);
    int denomin_x = AmountOfDenominators(x), denomin_y = AmountOfDenominators(y);
    if(denomin_x < denomin_y) return -1;
    if(denomin_x == denomin_y) return 0;
    return 1;
}


int AmountOfDenominators(int number)
{
    int denomin = 1, denomin_number = 0;
    while(denomin != number && number != 0)
    {
        if(number % denomin == 0)
        {
            denomin_number++;
        }
        denomin++;
    }
    return denomin_number;
}


void OutputArr(int *arr, int size_of_arr)
{
    int i;
    for(i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
