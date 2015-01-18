#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "KUBIK_FUNCTION.h"

int main()
{
    srand(time(NULL));
    int score, answer = 1;
    int i, j;
    while(answer)
    {
        int computer_score = 0, user_score = 0;
        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                if(i == 0)
                {
                    if(j == 0)
                    {
                        printf("You score:\n\n");
                    }
                    score = rand()%6+1;
                    Kubik(score);
                    user_score += score;
                }
                else
                {
                    if(j == 0)
                    {
                        printf("Computer score:\n\n");
                    }
                    score = rand()%6+1;
                    Kubik(score);
                    computer_score += score;
                }
            }
        }
        if(user_score == computer_score )
        {
            printf("Drow!\n");
        }
        else
        {
            printf(user_score > computer_score ? "You win!\n" : "You lose!\n");
        }
        printf("Do you want to repeat the game? (1-yes/0-no)\n");
        scanf("%d", &answer);
        system("cls");
    }
    return 0;
}
