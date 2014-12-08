#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, p, i, k = 1;
    printf("Enter a number x = ");
    scanf("%d", &x);
    printf("Enter a stage of number p = ");
    scanf("%d", &p);
    for(i = 1; i <= p; i++)
    {
        k *= x;
    }
    printf("%d",k);

    return 0;
}
