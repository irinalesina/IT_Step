#include <stdio.h>
#include <stdlib.h>

int main()
{
    double number;
    printf("Enter a number: ");
    scanf("%lf", &number);
    int stepen;
    printf("Enter stepen: ");
    scanf("%d", &stepen);
    double r = 1.0, q = number;
    int bit = 1;
    while(bit <= abs(stepen))
    {
        if(abs(stepen) & bit)
        {
            r *= q;
            q *= q;
        }
        else
        {
            q *= q;
        }
        bit <<= 1;
    }

    printf("%f", stepen >= 0 ? r : 1/r);

    return 0;
}
