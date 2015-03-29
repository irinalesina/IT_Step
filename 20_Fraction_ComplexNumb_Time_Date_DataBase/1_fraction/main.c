#include <stdio.h>
#include <stdlib.h>
#include "mixed_fraction.h"

int main()
{
    Fraction a, b;
    int c = 3;
    char operation, enter;
    InputFraction(&a);
    OutputFraction(a);
    printf("this fraction in double = %.4f\n", ConvertInDouble(a));
    printf("Enter operation: ");
    scanf("%c%c", &enter, &operation);
    InputFraction(&b);
    OutputFraction(b);
    OutputFraction(MathOperationFractionAndFraction(a, b, operation));
    OutputFraction(MathOperationFractionAndDigit(a, c, operation));
    return 0;
}
