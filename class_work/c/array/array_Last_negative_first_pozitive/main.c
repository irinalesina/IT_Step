#include <stdio.h>
#include <stdlib.h>
#include "array_last_negativa_first_pozitive.h"
#include "../../HomeWork_12/1.1_standart_random/random.h"
#include "../../HomeWork_12/2_work_with_array/array_io.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    int length_of_array = 1000, length;
    int array[length_of_array];
    printf("length of array = ");
    scanf("%d", &length);

    char answer;
    printf("Do you want to fill array? yes/no\n");

    scanf(" %c", &answer);
    if(answer == 'y')
    {
        InputArray(array, length);
    }
    else
    {
        int i;
        for(i = 0; i <= length; i++)
        {
            array[i] = Random()%300-100 + rand()%300-100;
        }
    }

    OutputArray(array, length);

    LastNegative(array, length) == -1 ? printf("\nNot found last negative number in your array!\n") : printf("\nLast negative = %d...index = %d\n", array[LastNegative(array, length)], LastNegative(array, length)+1);
    FirstPozitive(array, length) == -1 ? printf("Not found pozitive number in your array!\n") : printf("First pozitive = %d...index = %d\n", array[FirstPozitive(array, length)], FirstPozitive(array, length)+1);

    return 0;
}
