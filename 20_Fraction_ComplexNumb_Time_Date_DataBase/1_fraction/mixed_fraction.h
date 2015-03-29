#ifndef MIXED_FRACTION_H_INCLUDED
#define MIXED_FRACTION_H_INCLUDED
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Fraction
{
    int integer_part;
    int numerator;
    int denominator;
}Fraction;

void InputFraction(Fraction *a);
void OutputFraction(Fraction a);
double ConvertInDouble(Fraction a);

Fraction MathOperationFractionAndFraction(Fraction a, Fraction b, char operation);
Fraction MathOperationFractionAndDigit(Fraction a, int b, char operation);


#endif // MIXED_FRACTION_H_INCLUDED
