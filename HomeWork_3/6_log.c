#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, L, p, s = 1;
    printf("Enter a number x = ");
    scanf("%d", &x);
    printf("Enter a number L = ");
    scanf("%d", &L);
    for(p = 0; s <= L; p++)
    {
       s *= x;
    }
    printf("%d",p-1);

    return 0;
}

