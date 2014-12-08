#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int human_score = 0, computer_score = 0;
    do
    {
        human_score = rand()%11+1 + rand()%11+1;
        computer_score = rand()%11+1 + rand()%11+1;
    }
    while(human_score > 21 || computer_score > 21);
    //-------
    if(computer_score < 11)
    {
        computer_score += rand()%11+1;
    }
    if(human_score < 11)
    {
        human_score += rand()%11+1;
    }
    //-------
    printf("Your score = %d\n", human_score);
    char answer = 'y';
    printf("Would you like take a one new card?(y/n): ");
    scanf("%c", &answer);
    if(answer == 'y')
    {
        human_score += rand()%11+1;
    }
    //-------
    int comp_will_take = 1;
    if(computer_score > 11)
    {
        comp_will_take = 21 - computer_score > rand()%21;
    }
    if(comp_will_take)
    {
        computer_score += rand()%11+1;
    }
    //-------mistake
    while(answer == 'y' && human_score < 21 )
    {
        printf("Your score = %d\n", human_score);
        printf("Would you like take a one new card?(y/n): ");
        scanf("%c", &answer);
        if(answer == 'y')
        {
            human_score += rand()%11+1;
        }
    }
    //-------
    while(comp_will_take && computer_score < 21)
    {
        printf("we are here\n");
        comp_will_take = 1;
        if(computer_score > 11)
        {
            comp_will_take = 21 - computer_score > rand()%21;
        }
        if(comp_will_take)
        {
            computer_score += rand()%11+1;
        }
    }
    if(human_score == 21)
    {
        printf("You win!\n");
    }
    else if(computer_score <= 21 && human_score < computer_score)
    {
        printf("Game over!\n");
    }
    else if(human_score > 21)
    {
        printf("Game over!\n");
    }
    else if(human_score == computer_score)
    {
        printf("Draw!\n");
    }


    return 0;
}
