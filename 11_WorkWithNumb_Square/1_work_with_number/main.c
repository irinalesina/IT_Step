#include <stdio.h>
#include <stdlib.h>
#include "work_with_number.h"

int main()
{
    int number, digit;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Amount of digits in %d = %d\n", number, AmountOfDigit(number));
    printf("First digit in %d = %d\n", number, FirstDigit(number));
    printf("All digits without first in %d = %d\n", number, AllDigitsWithoutFirst(number));

    printf("Enter a digit: ");
    scanf("%d", &digit);
    printf("%d with %d  = %d\n", number, digit, NumberWithDigit(number, digit));

    printf("Cyclic shift in %d = %d\n", number, CyclicShift(number));

    return 0;
}
