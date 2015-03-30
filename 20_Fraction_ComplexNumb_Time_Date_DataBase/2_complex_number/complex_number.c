#include "complex_number.h"
#include <math.h>


void Input(ComplexNumber *number)
{
    printf("Enter complex number:\n");
    printf("integer part = ");
    scanf("%d", &number->integer);
    printf("imaginary part = ");
    scanf("%d", &number->imaginary);
}


void Output(ComplexNumber number)
{
    if(number.integer == 0)
    {
        printf("%di\n", number.imaginary);
    }
    else if(number.imaginary == 0)
    {
        printf("%d\n", number.integer);
    }
    else
    {
        if(number.imaginary < 0)
        {
            printf("%d - %di\n", number.integer, abs(number.imaginary));
        }
        else
        {
            printf("%d + %di\n", number.integer, number.imaginary);
        }
    }
}


ComplexNumber MathComplexAndComplex(ComplexNumber a, ComplexNumber b, char operation)
{
    ComplexNumber c;
    switch(operation)
    {
    case '+':
        c.integer = a.integer + b.integer;
        c.imaginary = a.imaginary + b.imaginary;
        break;
    case '-':
        c.integer = a.integer - b.integer;
        c.imaginary = a.imaginary - b.imaginary;
        break;
    case '*':
        c.integer = a.integer * b.integer - a.imaginary * b.imaginary;
        c.imaginary = a.integer * b.imaginary + a.imaginary * b.integer;
        break;
    case '/':
        c.integer = (a.integer * b.integer + a.imaginary * b.imaginary)/(pow(b.integer, 2) + pow(b.imaginary, 2));
        c.imaginary = (a.imaginary * b.integer - a.integer * b.imaginary)/(pow(b.integer, 2) + pow(b.imaginary, 2));
        break;
    }

    return c;
}


ComplexNumber MathComplexAndNumber(ComplexNumber a, int b, char operation)
{
    ComplexNumber c = {0, 0};
    switch(operation)
    {
    case '+':
        c.integer = a.integer + b;
        c.imaginary = a.imaginary;
        break;
    case '-':
        c.integer = a.integer - b;
        c.imaginary = a.imaginary;
        break;
    case '*':
        c.integer = a.integer * b;
        c.imaginary = a.imaginary * b;
        break;
    case '/':
        c.integer = a.integer / b;
        c.imaginary = a.imaginary / b;
        break;
    case '^':
        {
            int i;
            c = a;
            for(i = 0; i < b - 1; i++)
            {
                c = MathComplexAndComplex(a, c, '*');
            }
            break;
        }
    }
    return c;
}

