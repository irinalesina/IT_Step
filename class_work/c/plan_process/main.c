#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>  //многопроцессорность
#include <sys/types.h>


int main()
{
    pid_t p;

    p = fork();
    if(p == -1)
    {
        fprintf(stderr, "Error, fork don't created!\n");
        return 1;
    }
    else if(p == 0)
    {
        pid_t p1 = fork();
        if(p1 == -1)
        {
            fprintf(stderr, "Error, fork don't created!\n");
            return 1;
        }
        else if(p1 == 0)
        {
            pid_t p2 = getpid();
        }
        else
        {
            p1 = getpid();
        }
    }
    else
    {
        p = getpid();
    }




    return 0;
}

//https://vk.com/doc15295425_387231768?hash=2161e6cf4f5e8c5000&dl=ee2020f301c8a40f78
