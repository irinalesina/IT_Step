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
        double adition = 1, my_cos = 1;
        int j = 1;
        do
        {
            adition *= -i*i/(j*(j+1));
            j += 2;
            my_cos += adition;
        }while(fabs(adition) >= eps);
        double standart_cos = cos(i);
        printf("x = %5.1f | my_cos = %7.4f | cos = %7.4f | my_cos - cos = %7.4f\n", i, my_cos, standart_cos, my_cos-standart_cos);
    }

    return 0;
}
