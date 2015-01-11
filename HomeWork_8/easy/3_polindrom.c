
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long number, number_revers = 0, number_copy, multiplier = 1;
    printf("Enter a number = ");
    scanf("%I64d", &number);

    number_copy = number;
    int amount_of_numbers = 0, i;
    while(number >= multiplier)
    {
        multiplier *= 10;
        amount_of_numbers++;
    }

    multiplier /= 10;

    for(i = 0; i < amount_of_numbers; i++)
    {
        number_revers += (number_copy % 10)*multiplier;
        number_copy = number_copy / 10;
        multiplier /= 10;
    }

    printf(number == number_revers? "\nYour number is polindrom!\n" : "\nYour number is not polindrom!\n");

    return 0;
}
