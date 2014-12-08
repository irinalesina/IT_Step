#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a, b, c, d;
    printf("Enter 1 number: a = ");
    scanf("%d",&a);
    printf("Enter 2 number: b = ");
    scanf("%d",&b);
    printf("Enter 3 number: c = ");
    scanf("%d",&c);
    printf("Enter 4 number: d = ");
    scanf("%d",&d);
    printf("%*d\n%*d\n%*d\n%*d\n", 4, a*2, 5, b*2, 6, c*2, 7, d*2);
    return 0;
}
