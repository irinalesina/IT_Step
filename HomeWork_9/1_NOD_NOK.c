#include <stdio.h>
#include <stdlib.h>

int nod(int, int);
int nok(int, int);

int main()
{
    int a, b;
    printf("Enter number: a = ");
    scanf("%d", &a);
    printf("Enter number b = ");
    scanf("%d", &b);
    printf("nod = %d\n", nod(a, b));
    printf("nok = %d\n", nok(a, b));
    return 0;
}
int nod(int a, int b)
{
    int max, min, answer;
    max = a > b ? a : b;
    min = a < b ? a : b;

    while(max % min != 0)
    {
        answer = max % min;
        max = min;
        min = answer;

    }
    return min;
}
int nok(int a, int b)
{
    return a*b/nod(a, b);
}
