#include <stdio.h>
#include <stdlib.h>
#include "calculating.h"

int main(int argc, char *argv[])
{
    printf("Hello!\nThis is calculator!\nFor exit enter 'exit'");
    int i = 1;
    double result;
    while(!strstr(argv[i], "exit"))
    {
        if(Calculating(argv[i], &result))
        {
            printf(" = %.2f\n", result);
        }
        else
        {
            printf("Error. You enter invalid command!\n");
        }
        i++;
    }
    return 0;
}
