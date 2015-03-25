#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x_from = -2.0, x_to = 2.0, step = 0.1, eps;
    printf("Enter precision of calculation:\neps = ");
    scanf("%lf", &eps);
    double i;
    for(i = x_from; i <= x_to; i += step)
    {
        double adition = 1, my_exp = 1.0;
        int j = 1;
        do
        {
            adition *= i/j;
            j++;
            my_exp += adition;
        }while(abs(adition) >= eps);
        double standart_exp = exp(i);
        printf("x = %5.1f | my_exp = %7.4f | exp = %7.4f | my_exp - exp = %7.4f\n", i, my_exp, standart_exp, my_exp-standart_exp);
    }

    return 0;
}
