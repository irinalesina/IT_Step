#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter a number x = ");
    scanf("%d", &x);
    signed int p;
    printf("Enter a stage of number p = ");
    scanf("%d", &p);
    printf("%f", pow(x,p));

    return 0;
}
