#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Enter 1 number a = ");
    scanf("%d",&a);
    printf("Enter 2 number b = ");
    scanf("%d",&b);
    printf("%d + %d = %d\n", a, b, a+b );
    printf("%d - %d = %d\n", a, b, a-b );
    printf("%d * %d = %d\n", a, b, a*b );
    printf("%d / %d = %d\n", a, b, a/b );
    printf("%d %% %d = %d\n", a, b, a%b );
    return 0;
}
