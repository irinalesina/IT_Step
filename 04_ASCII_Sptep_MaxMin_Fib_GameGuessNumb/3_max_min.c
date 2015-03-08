#include <stdio.h>
#include <stdlib.h>

int main()
{
    //enter amount of numbers
    int amount_of_numbers;
    do
    {
        printf("amount of numbers > 0: ");
        scanf("%d",&amount_of_numbers);
        if(amount_of_numbers == 1)
        {
            printf("You enter one number! Please enter MORE then one number!");
        }
    } while(amount_of_numbers < 2);

    //enter numbers
    int number, n = 1;
    printf("%d, Enter a number: ", n);
    scanf("%d", &number);
    int max = number, min = number;
    for(n = 2; n <= amount_of_numbers; n++)
    {
        printf("%d, Enter a number: ", n);
        scanf("%d", &number);

        max = number >= max ? number : max;
        min = number < min ? number : min;

    }
    printf("max = %d\nmin = %d\n", max, min);

    return 0;
}
