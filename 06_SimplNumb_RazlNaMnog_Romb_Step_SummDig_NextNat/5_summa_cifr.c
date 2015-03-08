#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, summa = 0;
    printf("Enter a number : ");
    scanf("%d", &number);
    while(number)
    {
        summa += number % 10;
        number /= 10;
    }
    printf("%d\n", summa);
    return 0;
}
