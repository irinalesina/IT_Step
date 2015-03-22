#include <stdio.h>
#include <stdlib.h>

void comparison(int, int);
int main()
{
    int a, b;
    printf("Enter a numbers a, b:\n");
    scanf("%d%d", &a, &b);
    comparison(a, b);
    return 0;
}
void comparison( int a, int b)
{
    a % b == 0 ? printf("a / b\nb !/ a") : printf("b / a\na !/ b");
}
