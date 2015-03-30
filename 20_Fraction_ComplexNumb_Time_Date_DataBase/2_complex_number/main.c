#include <stdio.h>
#include <stdlib.h>
#include "complex_number.h"

int main()
{
    ComplexNumber a, b;
    Input(&a);
    Input(&b);
    Output(a);
    Output(b);
    Output(MathComplexAndNumber(a, 3, '^'));
    return 0;
}
