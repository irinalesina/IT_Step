#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int a1 = 1, a2 = 1, a3, i = 1;
    for(i; i <= 40 ; i++)
    {
        a3 = a2 + a1;
        printf("%f\t%f\n", 1.0*a2/a1, 1.0*a1/a2);
        a1 = a2;
        a2 = a3;


    }

    return 0;
}
