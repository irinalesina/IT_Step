#include <stdio.h>
#include <stdlib.h>
#include "../1_work_with_number/work_with_number.h"


int main()
{
    int number, result, amount_of_selection = 1, amount_of_digit;
    printf("Enter number: ");
    scanf("%d", &number);
    int i;
    amount_of_digit = AmountOfDigit(number);
    for(i = 2; i <= amount_of_digit; i++)
    {
        amount_of_selection *= i;
    }
    printf("Amount of permutation = %d\n", amount_of_selection);
    Permutation(number, 0);
    return 0;
}
