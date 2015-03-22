#include <stdio.h>
#include <stdlib.h>

double stage_of_number(double, int);
int main()
{
    double number;
    printf("Enter a number = ");
    scanf("%lf", &number);
    signed int p;
    printf("Enter a stage of number p = ");
    scanf("%d", &p);

    printf("%f^%d = %f", number, p, stage_of_number(number, p));

    return 0;
}
double stage_of_number(double number, int p)
{
    int i;
    double stepen = 1.0;
    for(i = 0; i < abs(p); i++)
    {
        stepen *= number;
    }
    return p > 0 ? stepen : 1/stepen;
}
