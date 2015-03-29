#include "mixed_fraction.h"

void CheckFraction(Fraction *a);
int NOD(int a, int b);

void InputFraction(Fraction *a)
{
    printf("Enter fraction:\n");
    do
    {
        printf("integer part = ");
        scanf("%d", &a->integer_part);
        printf("numerator = ");
        scanf("%d", &a->numerator);
        printf("denominator = ");
        scanf("%d", &a->denominator);
        if(a->denominator == 0)
        {
            printf("Error, you can not divide by zero!\n");
        }
    }while(a->denominator == NULL);
    CheckFraction(a);
}


void OutputFraction(Fraction a)
{
    printf("%d(%d/%d)\n", a.integer_part, a.numerator, a.denominator);
}


double ConvertInDouble(Fraction a)
{
    double result;
    result = a.integer_part + (double)a.numerator / a.denominator;
    return result;
}


Fraction MathOperationFractionAndFraction(Fraction a, Fraction b, char operation)
{
    Fraction c;
    double stepen;
    switch(operation)
    {
    case '+':
        c.integer_part = a.integer_part + b.integer_part;
        c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        c.denominator = a.denominator * b.denominator;
        break;
    case '-':
        c.integer_part = a.integer_part - b.integer_part;
        c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
        c.denominator = a.denominator * b.denominator;
        break;
    case '*':
        c.integer_part = a.integer_part * b.integer_part;
        c.numerator = a.numerator * b.numerator;
        c.denominator = a.denominator * b.denominator;
        break;
    case '/':
        c.integer_part = 0;
        c.numerator = (a.integer_part * a.denominator + a.numerator) * b.denominator;
        c.denominator = (b.integer_part * b.denominator + b.numerator) * a.denominator;
        break;
    case '^':
        stepen = ConvertInDouble(b);
        c.integer_part = 0;
        c.numerator = pow((a.integer_part * a.denominator + a.numerator), stepen);
        c.denominator = pow(a.denominator, stepen);
        break;
    }
    CheckFraction(&c);
    return c;
}


Fraction MathOperationFractionAndDigit(Fraction a, int b, char operation)
{
    Fraction c;
    switch(operation)
    {
    case '+':
        c.integer_part = a.integer_part + b;
        c.numerator = a.numerator;
        c.denominator = a.denominator;
        break;
    case '-':
        c.integer_part = a.integer_part - b;
        c.numerator = a.numerator;
        c.denominator = a.denominator;
        break;
    case '*':
        c.integer_part = a.integer_part * b;
        c.numerator = a.numerator * b;
        c.denominator = a.denominator;
        break;
    case '/':
        c.integer_part = 0;
        c.numerator = a.integer_part * a.denominator + a.numerator;
        c.denominator = a.denominator * b;
        break;
    case '^':
        c.integer_part = 0;
        c.numerator = pow((a.integer_part * a.denominator + a.numerator), b);
        c.denominator = pow(a.denominator, b);
        break;
    }
    CheckFraction(&c);
    return c;
}


void CheckFraction(Fraction *a)
{
    if(a->numerator > a->denominator)
    {
        a->integer_part += a->numerator/a->denominator;
        a->numerator = a->numerator % a->denominator;
    }
    int nod = NOD(a->numerator, a->denominator);
    if(nod-1)
    {
        a->numerator /= nod;
        a->denominator /= nod;
    }
}


int NOD(int a, int b)
{
    int answer;
    while(a % b != 0)
    {
        answer = a % b;
        a = b;
        b = answer;
    }
    return b;
}
