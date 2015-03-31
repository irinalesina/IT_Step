#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main()
{
    Date date_1, date_2;

    Input(&date_1);
    Output(date_1);

    Input(&date_2);
    Output(date_2);

    printf("Difference between dates = %d\n", DifferenceBetweenDates(date_1, date_2));
    return 0;
}
