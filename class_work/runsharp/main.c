#include <stdio.h>
#include <stdlib.h>
#include "../windows_vs_linux/compatibity.h"
#include <math.h>

int main()
{
    int position = 0, adding = 1;
    double pi = acos(-1.0);
    while(1)
    {
        int i;
        for(i = 0; i < position; i++)
        {
            printf(" ");
        }
        printf("#\n\n");
        Universal_sleep(1.0/(-4*cos(2*pi*position/36)+20));
        Universal_clear();
        if(position < 0 || position >= 40)
        {
            adding = -adding;
        }
        position += adding;

    }
    return 0;
}
