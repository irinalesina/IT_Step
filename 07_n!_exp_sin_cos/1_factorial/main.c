#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, factorial = 1, i;
    printf("Enter number:\nn = ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    printf("%d! = %d", n, factorial);
    return 0;
}
