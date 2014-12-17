#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double eps = 1e-10;
    double x, result = 0.0, adding = 1.0;
    printf("Enter exponent: x = ");
    scanf("%lf", &x);
    int i = 1;
    while(fabs(adding) >= eps)
    {
        result += adding;
        adding *= x/i;
        i++;
    }
    printf("My exponent = %f, exp = %f, diff = %f", x, result, result - exp(x));
    return 0;
}
