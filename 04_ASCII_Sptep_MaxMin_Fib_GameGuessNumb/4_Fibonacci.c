#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int amount_of_numbers, a1 = 1, a2 = 1, a3, i = 3;
    printf("Enter amount_of_numbers = ");
    scanf("%d", &amount_of_numbers);
    if(amount_of_numbers == 1)
    {
        printf("%d", a1);
    }
    else
    {
        printf("%d %d ", a1, a2);
        for(i; i <= amount_of_numbers ; i++)
        {
            a3 = a2 + a1;
            printf("%u ", a3);

            a1 = a2;
            a2 = a3;
        }
    }
    return 0;
}
