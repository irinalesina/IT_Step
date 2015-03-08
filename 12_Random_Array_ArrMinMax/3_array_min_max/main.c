#include <stdio.h>
#include <stdlib.h>
#include "array_min_max.h"
#include "../1.1_standart_random/random.h"
#include "../2_work_with_array/array_io.h"

int main()
{
    int length_of_array = 1000, left_border_of_array, right_border_of_array;
    int array[length_of_array];
    printf("left_border_of_array = ");
    scanf("%d", &left_border_of_array);
    printf("right_border_of_array = ");
    scanf("%d", &right_border_of_array);

    int i;
    for(i = left_border_of_array; i <= right_border_of_array; i++)
    {
        array[i] = Random()%1000;
    }

    OutputArray(array + left_border_of_array, right_border_of_array - left_border_of_array);

    printf("\nMin = %d\n", MinInArray(&array[left_border_of_array], right_border_of_array - left_border_of_array));
    printf("Max = %d\n", MaxInArray(&array[left_border_of_array], right_border_of_array - left_border_of_array));

    return 0;
}
