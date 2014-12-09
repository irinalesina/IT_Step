#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, p;
    printf("Enter a number x = ");
    scanf("%d", &x);
    printf("Enter a stage of number p = ");
    scanf("%d", &p);
    printf("%d",(int)pow(x,p));

    return 0;
}
