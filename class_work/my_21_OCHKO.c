#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    //my game

    int human_score = rand()%11+1;
    do
    {
        printf("You score = %d\n",human_score);
        printf("Would you like take a new card?(y/n): ");
        char answer, unused;
        scanf("%c%c",&answer,&unused);
        if(answer == 'n')
        {
            break;
        }
        human_score += rand()%11+1;
    } while(human_score <= 21);
    printf("You score = %d\n",human_score);

    //computer game

    int computer_score = rand()%11+1;
    do
    {
        if(computer_score < 17)
        {
            computer_score += rand()%11+1;
        }
        else
        {
            break;
        }
    } while(computer_score <= 21);
    printf("Computer score = %d\n",computer_score);

    //analyze results

    if((human_score > 21 && computer_score > 21) || (human_score == computer_score))
    {
        printf("Draw!\n");
    }
    else if(human_score > 21 && computer_score < 21)
    {
        printf("You lose!");
    }
     else if(human_score < 21 && computer_score > 21)
    {
        printf("You win!");
    }
    else if(human_score > computer_score)
    {
        printf("You win!");
    }
    else
    {
        printf("You lose!");
    }

    return 0;
}

