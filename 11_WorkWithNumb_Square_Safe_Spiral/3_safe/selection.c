#include "selection.h"
#include "../1_work_with_number/work_with_number.h"

void Permutation(int number, int reserv)
{
    int i, num_of_digits = AmountOfDigit(number);
    if(num_of_digits == 1)
    {
        return;
    }

    for(i = 0; i < num_of_digits; i++)
    {
        if(num_of_digits > 2)
        {
            reserv = NumberWithDigit(reserv, FirstDigit(number));
            int n = AllDigitsWithoutFirst(number);
            Permutation(n, reserv);
        }
        else if(num_of_digits == 2)
        {
            printf("%d%d\n", reserv, number);
        }

        if (num_of_digits != 2)
            reserv /= 10;   //delete last digit

        number = CyclicShift(number);
    }
}
