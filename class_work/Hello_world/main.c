#include <stdio.h>
#include <stdlib.h>
#include "myfuns.h"

int main()
{
    int a, b;
    printf("Enter a numbers\n");
    scanf("%d%d", &a, &b);
    system("cls");
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("lcm(%d, %d) = %d\n", a, b, lcm(a,b));
    return 0;
}
