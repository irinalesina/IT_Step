#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int answer;
    char vibor, MAX_MIN;
    do
    {
        int computer_number = 50, a = 100;
        int amount_of_step = 1;
        printf("This  number = %d? - ", computer_number);
        scanf(" %c", &vibor);

        printf("This  number LESS?(y/n) - ", MAX_MIN);
        scanf(" %c", &MAX_MIN);

        if(MAX_MIN ==  'y')
        {
            do
            {
                amount_of_step += 1;
                if(MAX_MIN == 'n')
                {
                    computer_number += (a - computer_number)/2;
                    a = computer_number + (a - computer_number);
                }
                else if(MAX_MIN == 'y')
                {
                    computer_number /= 2;
                    a = computer_number * 2;
                }

                printf("This  number = %d - ", computer_number);
                scanf(" %c", &vibor);

                printf("This  number LESS?(y/n) - ", MAX_MIN);
                scanf(" %c", &MAX_MIN);
            } while(vibor == 'n');

        }
        else
        {
            do
            {
                amount_of_step += 1;
                if(MAX_MIN == 'n')
                {
                    computer_number += (a - computer_number)/2;
                    a = computer_number -(a - computer_number)/2 ;
                }
                else if(MAX_MIN == 'y')
                {
                    computer_number -= (computer_number - a)/2;
                    a = computer_number + (computer_number - a)/2;
                }

                printf("This  number = %d - ", computer_number);
                scanf(" %c", &vibor);

                printf("This  number LESS?(y/n) - ", MAX_MIN);
                scanf(" %c", &MAX_MIN);
            } while(vibor == 'n');
        }

            printf("Computer find a number from %d steps.\n",amount_of_step);

            printf("Do you wont to repeat the game?(1-yes/0-no) ");
            scanf("%d", &answer);

    } while(answer);

    return 0;
}

