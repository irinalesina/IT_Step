#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, p = 1;
    printf("Enter amount of  numbers: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        int number;
        printf("Enter %d number: ",i);
        scanf("%d", &number);
        p *= number;
    }
    printf("%d",p);
    return 0;
}
