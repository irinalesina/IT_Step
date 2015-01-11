#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a, b;
    char character;
    scanf("%lf%c%lf", &a, &character, &b);
    printf("%f", character == '+' ? a+b : (character == '-' ? a-b : (character == '*' ? a*b : a/b)));
    return 0;
}
