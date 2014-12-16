#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter a number >= 2: ");
    scanf("%d", &number);

    int i = 2;
    for(; i <= number; i++)
    {
        if(number % i == 0)
        {
            printf("%d ", i);
            number /= i;
            i = 1;
        }
    }

    return 0;
}
