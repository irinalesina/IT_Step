#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter a number >= 2: ");
    scanf("%d", &number);

    int i = 1, amount = 0;
    for(i, amount; amount <= 2, i <= number; i++)
    {
        if(number % i == 0)
        {
            amount++;
        }
    }
    if(amount == 2)
    {
        printf("Your number is prime\n");

    }
    else
    {
        printf("Your number is composite\n");
    }
    return 0;
}
