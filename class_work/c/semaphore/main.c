#include <stdio.h>
#include <stdlib.h>

#define N 5


int forks[N] = {1};//forks on the table

typedef struct _Thinker
{
    int left_fork;
    int right_fork;
    int eat;
    int think;
    int action;//0-think, 1-eat
}Thinker;

Thinker thinkers[N];


int thinking[N] = {7, 2, 5, 0, 4};
int eating[N] = {1, 8, 4, 2, 6};


void Thinking(int position);
void Eating(int position);

int main()
{
    int i;
    for(i = 0; i < N; i++)
    {
        thinkers[i].action = 0;
        thinkers[i].eat = 0;
        thinkers[i].left_fork = 0;
        thinkers[i].right_fork = 0;
        thinkers[i].think = 0;
    }
    while(1)
    {
        int i;
        for(i = 0 ; i < N; i++)
        {
            //fill
            if(thinkers[i].think == 0)
            {
                if(thinkers[i].eat == 0 && thinkers[i].action == 0)
                {
                    thinkers[i].think = thinking[i];
                    thinkers[i].action = 1;
                }
                else if(thinkers[i].eat == 0 && thinkers[i].action != 0)
                {
                    thinkers[i].eat = thinking[i];
                    thinkers[i].action = 0;
                }
            }

            //actions
            if(thinkers[i].think != 0)
                Thinking(i);
            else if(thinkers[i].eat != 0)
                Eating(i);

        }
    }

    return 0;
}

void Thinking(int position)
{
    printf("%d>>%d  ", position, thinkers[position].think);

    thinkers[position].think--;
}


void Eating(int position)
{
    if(thinkers[position].left_fork == 0 && forks[position] == 1)
    {
        thinkers[position].left_fork = 1;
        forks[position] = 0;
    }
    if(thinkers[position].right_fork == 0 && forks[(position + 1) % position] == 1)
    {
        thinkers[position].right_fork = 1;
        forks[(position + 1) % position] = 0;
    }

    //check
    if(thinkers[position].left_fork != 0 && thinkers[position].right_fork != 0)
    {
        printf("%d>>%d  ", position, thinkers[position].eat);

        thinkers[position].eat--;
        if(thinkers[position].eat == 0)
        {
            thinkers[position].right_fork = 0;
            thinkers[position].left_fork = 0;
            forks[position] = 1;
            forks[(position + 1) % position] = 1;
        }
    }
}











