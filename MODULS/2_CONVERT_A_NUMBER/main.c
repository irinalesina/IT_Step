#include <stdio.h>
#include <stdlib.h>
#include "CONVERT_FUNCTION.h"

int main()
{
    int number, system_of_number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("In which system to convert a number( <37): ");
    scanf("%d", &system_of_number);

    Convert(number, system_of_number);

    return 0;
}
