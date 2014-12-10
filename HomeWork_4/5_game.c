#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int answer;
    do
    {
        int my_number;
        int computer_number = rand()%99 + 1;
        int amount_of_step = 1;
        do
        {
            printf("Enter a number from 1 to 99: ",my_number);
            scanf("%d",&my_number);
            if(my_number == computer_number)
            {
                break;
            }
            amount_of_step += 1;

            if(my_number > computer_number)
            {
                printf("This number MORE then need!\n");
            }
            else
            {
                printf("This number LESS then need!\n");
            }

            } while(my_number != computer_number);
            printf("Congratulations! Your amount of steps = %d \n",amount_of_step);

            printf("Do you wont to repeat the game?(1-yes/0-no) ");
            scanf("%d", &answer);

    } while(answer);

    return 0;
}

