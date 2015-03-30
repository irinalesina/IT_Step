#ifndef COMPLEX_NUMBER_H_INCLUDED
#define COMPLEX_NUMBER_H_INCLUDED

typedef struct _ComplexNumber
{
    int integer;
    int imaginary;
}ComplexNumber;

void Input(ComplexNumber *number);
void Output(ComplexNumber number);
ComplexNumber MathComplexAndComplex(ComplexNumber a, ComplexNumber b, char operation);
ComplexNumber MathComplexAndNumber(ComplexNumber a, int b, char operation);

#endif // COMPLEX_NUMBER_H_INCLUDED
