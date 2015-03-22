#include <stdio.h>
#include <stdlib.h>
#include "f_time.h"


int main()
{
    printf("Enter time from space(h m s): ");
    Time time_1, time_2;

    InputTime(&time_1);
    printf("Time 1: ");
    OutputTime(&time_1);

    printf("\nEnter amount of seconds: ");
    int amount_of_seconds;
    scanf("%d", &amount_of_seconds);

    AddSeconds(&time_1, amount_of_seconds);
    printf("Time 1 + %d seconds: ", amount_of_seconds);
    OutputTime(&time_1);

    printf("\nEnter time from space(h m s): ");
    InputTime(&time_2);
    printf("Time 2: ");
    OutputTime(&time_2);

    int difference = DifferenceBetweenTheTime(&time_1, &time_2);
    printf("\nDifference between the time1 and time 2: %d seconds\n", difference);


    return 0;
}
