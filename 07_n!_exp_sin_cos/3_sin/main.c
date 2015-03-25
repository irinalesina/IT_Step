#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x_from = -2.0, x_to = 2.0, step = 0.1, eps;
    printf("Enter precision of calculation:\neps = ");
    scanf("%lf", &eps);

    double i;
    for(i = x_from; i <= x_to + 0.1; i += step)
    {
        double adition = i, my_sin = adition;
        int j = 1;
        do
        {
            adition *= -i*i/((j+1)*(j+2));
            j += 2;
            my_sin += adition;
        }while(fabs(adition) >= eps);
        double standart_sin = sin(i);
        printf("x = %5.1f | my_sin = %7.4f | sin = %7.4f | my_sin - sin = %7.4f\n", i, my_sin, standart_sin, my_sin-standart_sin);
    }

    return 0;
}
