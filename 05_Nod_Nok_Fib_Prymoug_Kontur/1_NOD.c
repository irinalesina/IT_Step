#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, max, min, answer;
    printf("Enter number: a = ");
    scanf("%d", &a);
    printf("Enter number b = ");
    scanf("%d", &b);
    max = a > b ? a : b;
    min = a < b ? a : b;

    while(max % min != 0)
    {
        answer = max % min;
        max = min;
        min = answer;

    }
    printf("%d", min);
    return 0;
}
