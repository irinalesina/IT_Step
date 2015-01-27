#include <stdio.h>
#include <stdlib.h>

void comparison(int, int, int);
int main()
{
    int a, b, c;
    printf("Enter a numbers a, b, c:\n");
    scanf("%d%d%d", &a, &b, &c);
    comparison(a, b, c);
    return 0;
}
void comparison( int a, int b, int c)
{
    a + b >= c ? printf("a + b >= c") : printf("a + b < c");
}
