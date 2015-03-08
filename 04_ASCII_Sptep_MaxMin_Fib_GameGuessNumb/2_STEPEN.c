#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i = 1, stepen = 1;
    printf("Enter a number x = ");
    scanf("%d", &x);
    signed int p;
    printf("Enter a stage of number p = ");
    scanf("%d", &p);
    for(i; i <= abs(p); i++)
    {
        stepen *= x;
    }
    if(p < 0)
    {
        printf("%f",1.0/stepen);
    }
    else
    {
        printf("%d",stepen);
    }


    return 0;
}
